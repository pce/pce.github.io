---
layout: post
title: Smart Pointers
description: from new and delete to smart pointer 
tags: c++
---


## unique, shared and weak pointer 

C++11 Smart Pointers

- The unique pointer `std::unique_ptr` (owns a resource exclusively) 
- The shared pointer `std::shared_ptr` (does not own it, but with internal reference count) 
- The weak pointer `std::weak_ptr` (shared, but without the reference counter)


Before C++11 introduced those, `std::auto_ptr` tries to resolve the same (with unusual copy semantics that behaves like move semantics) and is now deprecated and removed in C++17, the `std::unique_ptr` is preferred.    

> It's all about Scope

The shared pointer behaves like a garbage collector, the last one to stop using it will implicitly delete the object. Prefer local objects over using a shared pointer.


`shared_ptr` Example of assign, reset and copy. 

```c++
#include <iostream>
#include <memory>

using std::cout;
using std::endl;

void smartReset(std::shared_ptr<int>& sharedIndex){
  cout << "smartReset() sharedIndex.use_count(): " << sharedIndex.use_count() << endl;
  // magic: reset replaces the managed object 
  sharedIndex.reset(new int(256));
  cout << "smartReset() sharedIndex.use_count(): " << sharedIndex.use_count() << endl;
  cout << "smartReset() sharedIndex: " << *sharedIndex << endl;
}

void smartInc(std::shared_ptr<int>& sharedIndex){
  *sharedIndex += 128;
  // smartInc() sharedIndex: 384
  cout << "smartInc() sharedIndex: " << *sharedIndex << endl;
}

int main() {
  auto sharedIndex = std::make_shared<int>(42);
  // sharedIndex: 42 
  cout << "sharedIndex: " << *sharedIndex << endl;
  // Copy 
  auto secondSharedIndex = sharedIndex;
  // sharedIndex.use_count(): 2
  cout << "sharedIndex.use_count(): " << sharedIndex.use_count() << endl;
  smartReset(sharedIndex);  
  smartInc(sharedIndex);  
  cout << "secondSharedIndex.use_count(): " << secondSharedIndex.use_count() << endl;
  // secondSharedIndex: 42
  cout << "secondSharedIndex: " << *secondSharedIndex << endl;
  // sharedIndex: 384
  cout << "sharedIndex: " << *sharedIndex << endl;
}
```


### Moving smart pointers

When we transfer ownership from one object to an object of another class, we can use "move semantics".
Depending on the case, constant references with `move` can be faster and safer even in multi-threaded environments, since move does not rely on a reference count of a `shared_pr`. 

In this example, `move` also makes it clear that passing ownership is intended:

```c++
void CompilerInstance::setInvocation(
    std::shared_ptr<CompilerInvocation> Value) {
  // move, instead of: Invocation = Value;
  Invocation = std::move(Value);
}
```

 The move semantics allows, for example, moving an object to another object (and scope) without an ownership relation, i.e. the "origin" scope is no longer responsible for memory allocation and deallocation.


### Exclusive Ownership

In RAII there is single and shared ownership, or in implementation `unique_ptr` vs. `shared_ptr`. 
Most RAII classes have unique ownership, such as `std::vector`.

Ownership is also bound to the scope and lifetime of the variable.
A `unique_ptr` clears itself when it falls out of scope. When a `shared_ptr` falls out of scope, the references are decremented and cleaned up when the reference count is 0 (which causes their own destruction).

### Smartpointer rules

[C++ Core Guidelins of Smart pointers](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#rsmart-smart-pointers) regarding ownership and passing parameters to functions (R.30-37).  


-  [R.20: Use unique_ptr or shared_ptr to represent ownership](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r20-use-unique_ptr-or-shared_ptr-to-represent-ownership)
-  [R.21: Prefer unique_ptr over shared_ptr unless you need to share ownership](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r21-prefer-unique_ptr-over-shared_ptr-unless-you-need-to-share-ownership)
-  [R.22: Use make_shared() to make shared_ptrs](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r22-use-make_shared-to-make-shared_ptrs)
-  [R.23: Use make_unique() to make unique_ptrs](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r23-use-make_unique-to-make-unique_ptrs)
-  [R.24: Use std::weak_ptr to break cycles of shared_ptrs](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r24-use-stdweak_ptr-to-break-cycles-of-shared_ptrs)
- [R.30: Take smart pointers as parameters only to explicitly express lifetime semantics](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r30-take-smart-pointers-as-parameters-only-to-explicitly-express-lifetime-semantics)


