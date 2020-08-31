---
layout: post
title: types and typecasts in c++
description: intro to types and typecasts 
tags: c++ 
---

## Types

Every C++ Variable [1] needs a name and to know what kind of data [2] is stored as zero and ones in a portion of memory. We do not need to know where in memory the value is stored, because we can refer to the value by name, the identifier. 


### Primary Types

- Integer `int`
- Character `char`
- Boolean `bool` true or false
- Floating Point `float`
- Double Floating Point `double`
- Void `void`
- Wide Character `wchar_t`   


> **Note**: Like in C, the width of integers are not fixed 

One Solution is to use a type with a fixed width, for example: when you need a 64bit integer type, use int64_t or uint64_t.  


The `nullptr` keyword is usable without including the header `<cstddef>`, unless you must use  `std::nullptr_t`.



### Derived Types

- Function 
- Array
- Pointer
- References

### User-defined Types 

- Class
- Structure
- Union
- Enum
- Typedef - `typedef` is to declare types 

The identifier `class` in C++ is inspired by Simula (mathematicans).
Structures are like Classes. Compared to Classes, they are identical, except Structs have public members and public inheritance by default.

`typeid` of `<typeinfo>` may return a mangled name, but can be used to debug.


1. [c++ variables](http://www.cplusplus.com/doc/tutorial/variables/)
2. [types](https://en.cppreference.com/w/cpp/language/types)
3. [type](https://en.cppreference.com/w/cpp/language/type)
4. [integer](https://en.cppreference.com/w/cpp/types/integer)


## TypeCasts

A `Cast` is to convert between types:

- static_cast
- reintepret
- C-Style Cast 
- Remove const-cast
- dynamic_cast


### Static Cast

`static_cast<int*>` 

compile-time cast, no runtime check.


### Remove const-cast

Casting away the constness of a read-only const variable. [1]


### C-Style cast

For Example `(int)` or `(int*)`

> **Warning**: Think before you use C-Style Casts, prefer a `static_cast` which is explicit and easier to find

In C++ the C-Style Cast is accepted by the Compiler as long as a `const_cast`, `static_cast` and `reintepret_cast` or a combination is applicable [2]. This can for example led to Compiler-Portability Issues. 


### dynamic_cast

polymorphic cast on Runtime. 
For Example for downcasts (from base to derived class) and crosscasts (accross the object hierarchy) of pointers to polymorphic objects. 

Beyond the C++ Standard Library: Boost provides also polymorphic casts [3].


1. [const_cast](https://en.cppreference.com/w/cpp/language/const_cast)
2. [explicit_cast](https://en.cppreference.com/w/cpp/language/)
3. [boost:  polymorphic_casts](https://www.boost.org/doc/libs/1_74_0/doc/html/conversion/polymorphic_casts.html)
