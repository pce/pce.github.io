---
layout: post
title: templates in c++
description: generic programming with templates in c++ 
tags: c++
---


## Templates in C++

> Generic programming is programming using types and algorithms parameterized by types, values, and algorithms. 
[Templates Core Guidelines](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-templates)

Note: Use Templates if you have a realistic need for more than one template argument type.


In this "prototype" example, the keywords `template` to specify a generic function and `typename` (could also be `class`) a generic type, which get expanded at **compile time** to code with types that are passed as parameters. 

```cpp
template<typename T, typename U>
T Min(T a, T b)
{
  return (a < b) ? a : b;
}
```

```cpp
assert(Min<double>(3.5,5.0) == 3.5);
assert(Min<int>(4,2) == 2);
```


### Deduction

Without explicitly identifying the types, [deduction](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rt-deduce) occurs:

```cpp
assert(Min(3.5,5.0) == 3.5);
assert(Min(4,2) == 2);
```


### Template Class

A templatized class uses a "templatized" constructor, for example vector is a generic class.


### Concepts

Templates can express anything (at compile time), but had "lousy" interfaces. 
To precisely express requirements of templates C++20 introduces [concepts](https://en.cppreference.com/w/cpp/language/constraints). 

