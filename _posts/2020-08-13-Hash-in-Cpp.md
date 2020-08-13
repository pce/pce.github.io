## Hash

A `Hash Table` (or dictonary, associative array) is a datastructure that maps keys to values.

It's name derived from the fact that the keys or pointers to them are hashed (often with some collision resolution strategy) and stored in a table with the associated values (the hash indicates where the value is stored).

Useful for caches to speed up data-access, sets, indexing, uniqueness (dictonary, unique string lookups).
A hash-table is also used for Objects in dynamic languages, where one object is a hash-table with names of members and methods are the keys and the values are pointer to the methods and members. Or a Combination of an array and a hash for instance variables ([1] ruby)



### map and unordered map

If you have a reason to use a different container,  other than `std::array` or `std::vector` [2], use `std::unordered_map` [3] or if the keys have to be sorted: `std::map`.


Example a "string" to "string" map:

    std::unordered_map<std::string, std::string> colors = {
      {"red","#F00"},
      {"green","#0F0"},
      {"blue","#00F"}
    };


A gist of an unordered map with string as key and variable array (vector) of strings as value: `unordered_map <string, vector<string>> dict;`:

{% gist 8008e987a85215717b4a5332bc1eb9bc %}


1. [don't @ me](https://www.youtube.com/watch?v=HEFBDqly4ms)
2. [c++ guidelins on vector](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rsl-vector)
3. [cppreference/unordered_map](https://en.cppreference.com/w/cpp/container/unordered_map)