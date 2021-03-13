---
layout: post
title: Copy Semantics
description: new and delete, copy semantics 
tags: c++
---



## new and delete 

Allocate memory with [new](http://www.cplusplus.com/reference/new/operator%20new/) or `new []` (array), free the memory with [delete](http://www.cplusplus.com/reference/new/operator%20delete/) or `delete []`.
`new` throws an execption, when the requested memory could not allocated. 
   
```c++

int32 *inc = new (std::nothrow) int32;

// * dereference to set value (not address to pointer) 
*inc = 42;

delete inc;

```

Like in C, where every allocation (`malloc`, `realloc`) needs a `free`. 
One should not loose the given base-pointer by `new` to `delete` the reserved memory. An enhancement of the C++ dynamic Memory Administration is to think in blocks, not bytes. `new` returns a base-pointer (pointer to the start-address) to a memeroy-block of the size of the Data-Type. 



## Copy Semantics

Example of Resources, where manual memory management is often wrapped in a Manager-Class are multi-threaded locks, file handles, network sockets, database connections.


#### Default Copy Constructor

Members, which allocate memory on the heap and free it in the deconstructor, will double free it, because the  Object on the stack that first releases the memory on the heap will result in a "double free or corruption" error. 
  
The default Constructor Copy  performs a Shallow Copy.


### Copy Ownership Policy

#### No copying policy 

The No-Copy Policy is (prevents copying or assignment) used for example in C++11 Standard Library (multi-threaded syncronization).

#### Exclusive ownership policy

The source pointer is set to nullptr to make ownership exclusive


#### Deep copying policy


Instead of null_pointer, allocate memory for contents of source and copied into it (assignment operator and the copy constructor have been overloaded)


#### Shared ownership policy

Copying the handle, while keeping track of the resource (unique_ptr)



