
# Fibonacci Sequence

<!-- involving the growth of a population of rabbits based on idealized assumptions. -->

Each Number is the Sum of the preceeding two.
The numbers of the Sequence are denoted as _Fn_.

<!--  encodeURIComponent("F_0 = 0; F_1 = 1; F_{n+2} = F_{n+1} + F_n, n >= 0")  -->

![formula](https://render.githubusercontent.com/render/math?math=F_0%20%3D%200%3B%20F_1%20%3D%201%3B%20F_%7Bn%2B2%7D%20%3D%20F_%7Bn%2B1%7D%20%2B%20F_n%2C%20n%20%3E%3D%200)


Outside of India, the Fibonacci numbers first appear in the book "Liber Abaci" (Book of the Abacus, 1202) by Leonardo Pisano (Son of Bonaccio, called Fibonacci).
He was the greatest European mathematican of the Middle Ages and popularized the Hindu–Arabic numeral system in the Western World.
He also studied the work of al-Khwarizmi (latinized as Algorithmi, the word algorithm derived from the 9th-century persian polymathematican) and
contributed to arithmetic and geometry.
The fibbonaci numbers appear also in the nature, the golden ratio or in the Fermat's spiral (for example).

In "Liber Abaci" he published it as a execise:

> "How many pairs of rabbits can be produced from a single pair in a years time?"


Every Month a new pair and after one month a new pair becomes fertile. The rabbits never die.
There will be 2 pairs of rabbits after one month, 3 after 3 months and then a new pair (3 are already there) are 5 and so on.

I solved this great Exercise about addition in C++ as an Example for a recursive function, that saves a fibonaccio sequence in a vector.

{% gist 7c43c537a38f9af10a02f930f1e792a6 %}


Sources: ["Knuth" TAOCP Vol.1 - Fundamental Algorithms](https://www-cs-faculty.stanford.edu/~knuth/taocp.html)

## const and constexp


>    C++ supports two notions of immutability:
        const: meaning roughly " I promise not to change this value."...The compiler enforces the promise made by const....
        constexpr: meaning roughly "to be evaluated at compile time." This is used primarily to specify constants...


"A Tour of C++", Bjarne Stroustrup


`const` can be evaluated at runtime, `constexp` at compile-time.

- `const int = a + b` // const at run-time
- `constexpr int = 12;`// at compile time

- `const int = a; a++;` // error increment of read-only variable
- `constexpr int = a + b;`  // error


`const` can also be used to make sure that a reference will not accidentally get changed (see immutable pass by reference).


## Call by value or reference


In C++ you can pass values to functions as a copy or a reference to the passed variable itself.


### Pass by value

~~~cpp
#include <iostream>
#include <string>
using std::cout;
using std::string;


int Inc(int i) {
    i++;
    return i;
}

int num = 41;

cout << "num: " << num << "\n";
int ret = Inc(num)
cout << "ret: " << ret << "\n";
cout << "num: " << num << "\n";
~~~

### Pass by reference


To pass by Reference, add an ampersand to the variable `&i`
This `i` is the alternative name for the Variable passed to the function.
The passed variable `num` changes, if `i` changes.


~~~cpp
int Inc(int &i) {
    i++;
    return i;
}
~~~

### immutable pass by reference


read-only usage of a reference as function argument.


~~~cpp
int Inc(const int &i) {
    int j = i;
    j++;
    return j;
}

cout << "num: " << num << "\n";
int ret = Inc(num)
cout << "ret: " << ret << "\n";
cout << "num: " << num << "\n";
~~~

A vector of ints "guard"

~~~cpp
#include <iostream>
#include <vector>

// g++ -std=c++11 pass_by_ref_imu.cpp && ./a.out

int avg(const std::vector<int> &v)
{
  int avg = 0;
  int sum = 0;
  for(auto i : v) {
    sum += i;
  }
  return sum / v.size();
}

int main()
{
  std::vector<int> v  = {1, 2, 3};
  std::cout << avg(v) << "\n";
}
~~~









