---
layout: post
title: Async, Promises and Futures 
description: Mutlithreading with Promises and Futures, Async
tags: c++
---

## Passing Data


In a lambda or varidatic template thread, we pass data (via arguments or capture) from the parent thread (i.e. main) to the worker thread.   


```c++  
#include <iostream>
#include <thread>

void call_from_thread(int tid) {
  std::cout << "Thread #" << tid << ", id: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Hello concurrent world, main Thread id : " << std::this_thread::get_id() << std::endl;
  // async launch a thread

  int tid = 1;
  std::thread t1(call_from_thread, tid);

  tid = 2;
  std::thread t2([tid] {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "Thread #" << tid << ", id: " << std::this_thread::get_id() << std::endl;
  }); 

  // thread barrier 
  t1.join(); 
  t2.join();

  return 0;
}
```

Output:
```
➜  g++ -pthread -std=c++11 multi_threads-barrier\ copy.cpp 
➜ ./a.out                                                 
Hello concurrent world, main Thread id : 0x11c94fe00
Thread #1, id: 0x7000043e1000
Thread #2, id: 0x700004464000
```



### passing data from child to parent 

In the C++ standard, to pass data in the opposite direction, the threads must be syncronized (via a syncronization protocol).
Using a single-use channel between threads, we can pass data between the two, the sending end of the channel is called **Promise**, the receiving end **Future**. 


#### exception example

To pass data from a child thread to a parent thread (main), a thread function can store a value or an exception through a promise.

Example of storing a thrown error in the promise.


```c++
#include <thread>
#include <iostream>
#include <future>
 
int main()
{
    std::promise<int> prms;
    std::future<int> ftr = prms.get_future();
 
    std::thread t([&prms]{
        try {
            // code that may throw
            // p.set_value(42);           
            throw std::runtime_error("Example");
        } catch(...) {
            prms.set_exception(std::current_exception());
        }
    });
 
    try {
        std::cout << "Value: " << ftr.get();
    } catch(const std::exception& e) {
        std::cout << "Exception: " << e.what() << '\n';
    }
    t.join();

    return 0;
}
```




### Promise

A promise creates a Channel. 

- `std::promise::set_value()` to set the return value and makes the state ready.
- `std::promise::set_value_at_thread_exit(e)` all from above, but sets at the end of the thread.
- `std::promise::set_exception()` to set a exception and makes the state ready.
- `std::promise::set_exception_at_thread_exit(e)` all from above, but sets at the end of the thread.

[std::promise](https://en.cppreference.com/w/cpp/thread/promise) 


### Future



As in life, a promise is useless without Future.
Future is used to retrieve the promised value.
 
A `std::future` connects to the channel and waits to read and return the data once it is written. 
To pair a Promise with a Future `promise::get_future`.


if a `std::future::valid()` returns true: `std::future::wait()` to perform a blocking wait until the result becomes available (or `std::future::wait_for(timeout)`) and `std::future::get()` to return the provided result or an exception. 


> :warning: `std::future::get()` invalidates the state, so "get" can be called **only once**



[std::future](https://en.cppreference.com/w/cpp/thread/future) 


Syncronization: a future get call blocks (task) because thread join is waiting (thread).

> :information_source:  A `std::shared_future` is copyable or can refer to shared state (with other asycronous return obejcts). [std::shared_future](https://en.cppreference.com/w/cpp/thread/shared_future) 

## Async


Passing data from a worker to the parent thread involves some overhead and boilerplate code (rvalue reference and `std::move`). A simpler (or higher level) option is to use `std::async` instead of `std::thread`.

`std::async` returns a `std::future`. 


```c++
#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <memory>

unsigned int square(int num)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); 

    if (num < 0)
        throw std::runtime_error("Exception from thread: num must greater or equals than zero");

    return num * num;
}


int main()
{
    auto num = -42; 
    
    // num = 3; 

    std::future<unsigned int> ftr = std::async(square, num);

    try {
        auto result = ftr.get();
        std::cout << "Result = " << result << std::endl;
    }
    catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

```

A simple example where async takes a callable (lambda) and stores the result in a vector of futures.   

```c++ 
#include <iostream>
#include <vector>
#include <future>


int main()
{
    std::vector<std::future<int>> futures;
    
    for(int i = 0; i < 10; ++i) {
      futures.push_back (std::async([](int num) {return num * num;} , i));
    }

    // retrieve results 
    for(auto &e : futures) {
      std::cout << e.get() << std::endl;
    }

    return 0;
}
```

It is also possible to make "fire and forget" calls over `std::launch::async` policy, which enforces the OS to create a thread.


[C++ Async](https://www.cplusplus.com/reference/future/async/)


