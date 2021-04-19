---
layout: post
title: Concurreny
description: concurrency support in C++ to or do many tasks at the "same" time
tags: c++
---


## proccess and threads

A process (also called a task) is controlled by the OS and manged by the Scheduler (A common "interrupting scheduler" switches between active proceses).
A Process passes through one of these defined states:

- 1. created or new (initial state in the process life cycle)
- 2. ready (process is loaded into main memory and waits in a queue to get assigned by the processor or scheduler)
- 3. running (is selected for execution)
- 4. block or wait (waits for an event, such as I/O) 
- 5. completion or termination (completed or explicit killed, may remain as a zombie till its lifetime ends)
- 6. suspend ready (swapped out of main memory from ready state)
- 7. suspend blocked or wait (a blocked process swapped out from main memory)


Operations are Creation, Scheduling, Execution and Deleting/Killing. 


## threads

The OS supports a more resource-friendly way of realizing concurrent operations: the threads.
Threads allow multiple functions to execute concurrently within a process.

Life Cycle of a thread

- new (created and not yet started)
- runnable (runs or is ready to run, it is the responsibility of the thread scheduler to assign CPU time to the thread)
- blocked (inactive in blocked or wating state)


<!-- // In C++ there are POSIX threads and since C++11 thread. -->

### concurrency 

A parallel path of execution, which runs concurrently with the main program is asynchronous.
Data Access from all the threads must be consistent.

A c++11 `thread` is launched and waits to finish by join.

Running a single thread 
```c++
#include <iostream>
#include <thread>

void call_from_thread(int tid) {
  std::cout << "Thread #" << tid << ", id: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Hello concurrent world, main Thread id : " << std::this_thread::get_id() << std::endl;
  // async launch a thread
  // std::thread t1(call_from_thread);
  std::thread t1(call_from_thread, 1);

  // wait to join the thread with the main thread
  t1.join(); 
  return 0;
}
```

Output:
```
clang++ -std=c++11 -stdlib=libc++ -g thread.cpp && ./a.out
Hello concurrent world, main Thread id : 0x10b45be00
Thread #1, id: 0x70000b067000
```


Creating multiple threads 
```c++ 

#include <iostream>
#include <thread>

void call_from_thread(int tid, bool is_main=true) {
  if (is_main) {
    std::cout << "-- Thread #" << tid << ", from main: " << std::this_thread::get_id() << std::endl;
  } else {
    std::cout << "Thread #" << tid << ", id: " << std::this_thread::get_id() << std::endl;
  }
}

int main() {

  std::cout << "Hello concurrent world, main Thread id : " << std::this_thread::get_id() << std::endl;

  // lambdas that calls a fuunction 
  std::thread threads([]{
  for(int i = 0; i < 10000; i++)
    call_from_thread(i, false);
  });

  for(int i = 0; i < 10000; i++)
    call_from_thread(i, true);
  
  // wait to join the thread with the main thread
  threads.join(); 
  return 0;
}

``` 


Output excerpt:
```
-- Thread #9332, from main: 0x1161f7e00
-- Thread #93339639, id: 0x700008b2b000
Thread #9640, id: 0x700008b2b000
Thread #9641, id: 0x700008b2b000
Thread #9642, id: 0x700008b2b000
Thread #9643, id: 0x700008b2b000
Thread #9644, id: 0x700008b2b000
Thread #9645, id: 0x700008b2b000
Thread #9646, id: 0x700008b2b000
Thread #9647, id: 0x700008b2b000
Thread #, from main: 0x1161f7e00
-- Thread #9648, id: 0x700008b2b000
9334, from main: 0x1161f7e00
-- Thread #Thread #9649, id: 0x700008b2b000
Thread #9650, id: 0x700008b2b000
Thread #9651, id: 0x700008b2b000
Thread #9652, id: 0x700008b2b000
Thread #96539335, from main: 0x1161f7e00
-- Thread #9336, from main: , id: 0x700008b2b000
Thread #9654, id: 0x700008b2b000
Thread #9655, id: 0x700008b2b000
``` 


A [powerful example of prallel programming](https://solarianprogrammer.com/2011/12/16/cpp-11-thread-tutorial/
) of complex image processing, may be to launch a number of threads (7 for a quad-core system), each one will process his chunk of the image. 



### Concurrency rules

[C++ Core Guidelins of Concurrency](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-concurrency
) 


- [CP.1: Assume that your code will run as part of a multi-threaded program](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rconc-multi)
- [CP.2: Avoid data races](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rconc-races)
- [CP.3: Minimize explicit sharing of writable data](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rconc-data)
- [CP.4: Think in terms of tasks, rather than threads](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rconc-task)
- [CP.8: Don’t try to use volatile for synchronization](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rconc-volatile)
- [CP.9: Whenever feasible use tools to validate your concurrent code](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rconc-tools)
