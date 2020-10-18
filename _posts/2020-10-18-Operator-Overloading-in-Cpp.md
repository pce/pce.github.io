---
layout: post
title: operator overloading in c++
description: operator overloading in c++ 
tags: c++
---



### overloading operators 

Overloading operators in a language, allows to provide the custom implementation of operators for operands of user-defined types. 


One usage Example is to compare instances of a user-defined type, for example a comparision of custom  `Date`-objects, 
 with overloaded `+` and comparsion `<=` operators:  

```cpp
auto today = Date(); 
auto fooday = Date(); 

// instead of fooday.AddDays(2),
// handle Date like a primitive type
fooday = fooday + 2; 

if (today <= fooday) {
  // true
  std::cout << "remember fooday is in {foo} days"; 
}

```

Comparison of Objects, Operator overloading also enables sort, to return a List of objects in a sorted order.  

```cpp
// timestamp is a private member of Date 
bool Date::operator<= (const Date &d) const {
  return(timestamp<=d.timestamp);
}

// and operators in symetric fashion `>`, and for `+`: `-`     
```

A std Example is [string concation](http://www.cplusplus.com/reference/string/string/operator+/).  
`+` to concat strings and  [`+=` modifies the string-object itself](http://www.cplusplus.com/reference/string/string/operator+=/).


```cpp
std::string toplevel{"com"};
std::string hostname; 
// the rvalue references modify the moved string:
hostname = "www." + "example." + toplevel;
```

[C++ Core Guidelines: Rules for Overloading and Overload Operators](https://www.modernescpp.com/index.php/c-core-guidelines-rules-for-overloading-and-overload-operators) 


### User-defined operators 

User-defined operators in a language would support missing operators.

For example instead of `pow(a,b)`:  `a pow b` or  `a ** b`.  
Algol68 showed one way to support user-defined operators.  
It can be done, but Readability, Complexity of Syntax (are operators restricted to a set of characters or prefixed), and Precedence are the reasons why C++ does not support user-defined operators.
