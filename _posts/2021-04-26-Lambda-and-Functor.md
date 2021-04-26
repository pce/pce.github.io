---
layout: post
title: lambda and function object in cpp 
description: lambda and function object and the most vexing parse 
tags: c++
---


### Functor

A functor (or function object) is a class that implements the function call operator.

```c++
#include <iostream>
#include <thread>

class MyFunctor
{
public:
  // implements the function call operator
  void operator()()
  {
    std::cout << "MyFunctor object has been created \n" << std::endl;
  }
};


int main()
{
    std::thread t(MyFunctor()); // error: C++'s most vexing parse
    t.join();

    return 0;
}

```

#### the most vexing parse

The "most vexing parse" is a resolution of syntax ambiguity.
The "most vexing parse" comes from a rule in C++ that says that anything that could be considered a function declaration should be parsed by the compiler as a function declaration--even if it could be interpreted as something else.

```c++
    std::thread t(MyFunctor()); // "most vexing parse" it as a function declaration
```

##### How to fix the most vexing parse:

1. C++11 uniform initialization, calling constructors with curly braces {} instead of parentheses ()

```c++
    std::thread t{MyFunctor()};
```


2. copy initialization (or "auto to stick") syntax

```c++
    std::thread t = std::thread( MyFunctor() );
    auto t2 = std::thread(MyFunctor());
```

3. Before C++11: add an extra pair of parentheses ()

```c++
    std::thread t((MyFunctor()));
```



### lambda

A lambda is an anonymous function (closure). 


```c++
#include <iostream>

using std::cout;
using std::endl;


struct AddFuncObj{
  // implements the function call operator
  int operator()(int a, int b) const { return a + b; }
};
    
int main() {

  // defines a lambda function sum   
  auto sum = [](int a, int b){ return a + b; };        

  int local=sum(1,2);

  // defines a lambda function addToLocalRef   
  auto addToLocalRef = [&local](int b){ return local + b; };

  cout << "sum: " << sum(1,2) << endl;
  cout << "add to local sum 2: " << addToLocalRef(2) << endl;

  AddFuncObj addFuncObj;
  cout << "add over function-object 3: " << addFuncObj(local, 3) << endl;

}
```

Output:
```
clang++ -std=c++11 -stdlib=libc++ -g func.cpp && ./a.out
sum: 3
add to local sum 2: 5
add over funcion-object 3: 65
```


`for_each` takes a lambda for the vector iteration 

```c++
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int main() {

  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  for_each(begin(v), end(v), [](int i) {
    cout << i << endl;
  });

}
```


### Lambda Syntax

Controlling Lambda Capture


|   1  | 2    |
|:----:|------|
| []  | capture nothing |
| [&] |   Capture everything by reference   |
| [=] |   Capture everything by value (may not cheap)   |
| [&ctr] |   Capture only ctr by reference   |
| [ctr] |   Capture only ctr by value   |
| [&,ctr] |   Capture ctr by value, everthing else by refernce   |
| [=,&v] |   Capture v by refernce and everthing else by value   |
| [&, ctr1, ctr2] |  Capture ctr1 and ctr2 by value and everthing else by refernce   |


[https://en.cppreference.com/w/cpp/language/lambda](lambda reference)


### Lambda rules

[C++ Core Guidelins of lambdas](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#SS-lambdas) 


