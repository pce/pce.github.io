---
layout: post
title: Sum of odd is square
description: auto vector 
tags: c++ art-of-code
---


## Art of Code 01

Today, i write a simple program that prints squares in numbers, to prove that the sum of odd numbers are square.  

If we have one item and add a odd number of items to it, the items forms a square.

- 2 Square = 4 = 1 + 3 
- 4 Square = 16 = 1+3+5+7
- n Square = 1 + odd numbers

The Output of `aoc_01-sumofofodd.cpp` 

    1
    4
    9
    16
    25
    36
    49
    64
    81


A geometrical Prove of the sum of Odd is square:

![](/images/sumofodd_is_square.png)



### appendix std::vector, auto and const

`std::vector` - Vectors 

~~~cpp
    vector<int> v = {1, 4, 2};
~~~

`auto`, explicit declared is so nineties ;-) 

In "modern" c++, the compiler can decide which type applies.
 
~~~cpp
    auto v = {1, 4, 2};
    for (auto i: v)
      cout << i << "\n";
~~~

We may also explicit tell the compiler we read only with `const`:

~~~cpp
    auto v = {1, 4, 2};
    for (const int &i: v)
      cout << i << "\n";
~~~



###  aoc_01-sumofofodd.cpp 


To compile and play  with the sum of odds in C++:  
`g++ aoc_01-sumofofodd.cpp && ./a.out`  
or   
`clang++ -std=c++11 -stdlib=libc++ -g aoc_01-sumofofodd.cpp && ./a.out`  

{% gist 067f37ac6ced9ddec1e538f8c6da56f9 %}


