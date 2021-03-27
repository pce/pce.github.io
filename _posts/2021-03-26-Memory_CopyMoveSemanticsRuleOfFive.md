---
layout: post
title: Copy/Move Semantics
description: Rule of Three/Five 
tags: c++
---



## Move Semantics

Most of the time, resources are already managed in an existing class, such as `std::string`, where the handling of `char*` is already done. 


### lvalue, rvalue and &&

- lvalue: anything that can takes an assignment 
- rvalue: temporary expression without an address 
- &&: to store and modify an rvalue


#### lvalue

```c++ 
int32 index;
// index is a lvalue
index = 42;
```

```c++ 
int32 index;
int32& getIndex() {
    return index;
}
// getIndex is a lvalue
getIndex() = 42;
```

#### rvalue

If a function does return a temporary object, not a fixed location or reference, it is a rvalue:

```c++ 
int32 getIndex() {
    return 42;
}
// getIndex is a rvalue
int32 index = getIndex();
```

#### &&

In C++11 the rvalue reference `&&` to bind a mutable reference to an rvalue.  

```c++ 
// rvalue reference can be const or no const
const int32&& index = getIndex();
int32&& index = getIndex();
```

It is often used for move constructor and move assignment operator.

Despite that, rvalue reference is a modern technique to optimize the processing speed and memory usage.
How?   
In an lvalue assignment a new rvalue is created and copied the result to the memory location of the lvalue.  
More efficient is an rvalue reference that assigns the address of the temporary objects, while supporting exclusive ownership.

```c++
    int a = 1; 
    int b = 2; 
    // lval=3 over copies
    int lval = a + b; 
    // rvalref=3 over references
    int &&rvalref = a + b; 
``` 


### Rule of Three

A rule of thumb, before C++11, that claims, if a class defines any of the follwoing, then it should explicitly define all three:

-  destructor
-  copy constructor
-  copy assignment operator

Why explicit? Good Question. 
Because the implicit behaviour is a "shallow copy". 
An explicit implementation (even a modern and short version of it) also indicates the intended desired behaviour.    


### Rule of Five

Since C++11 implements move semantics (new moving members: move constructor and move assignment operator), the rule of five we have the following special members:

-  destructor
-  copy constructor
-  copy assignment operator
-  move constructor
-  move assignment operator

Move Sematics allows destination objects to grab (or steal) data from temporary objects. 
