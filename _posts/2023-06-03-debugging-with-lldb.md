---
Layout: Post
title: lldb - the llvm debugger
description: Debugging in C++ 
tags: debugging c++
---


# C++ debugging basics

A debugger allows to intervene in a program, to continue or to examine variables at a breakpoint or watchpoint. 
For example, to fix a seqfault of the program.
The program must be compiled with debug symbols.

Start `lldb program-name` or run `lldb` and create a `target create program-name`.

to start the program in lldb: 
- `process launch` or alias `run`, `r` 
- or connect it to a process by process id or process name.

When it is running: 

1. `s` step into  
2. `n` next 
3. `f` finish


- `help`
- `bt` backtrace 



## Interactive debugging

Example using [lldb](https://lldb.llvm.org/) for a program called `sdl-beatbox` with CMake.
CMake ensures that the program is built with `-g` for lldb or gdb.


1. `mkdir Debug && cd Debug`
2. `cmake -DCMAKE_BUILD_TYPE=Debug ..`
3. `make`
4. `lldb sdl-beatbox`
7. breakpoint example `b main` 
    - on symbol: `b Au<tab>`
    - or on line: `set breakpoint -f <filename> -l <line number>` or `b sequencer.cpp : 43`
8. `r` to launch.


[![lldb-run](/images/lldb-run.png)](/images/lldb-run.png)


## lldb gui

In the lldb session, `gui` leads to the graphical user interface.  
In the gui, a diamond shows the current line and allows navigation with arrow keys and checking the status. 


[![lldb-run](/images/lldb-gui.png)](/images/lldb-gui.png)


## Links

1. [lldb tutorial](https://lldb.llvm.org/use/tutorial.html)
2. [lldb for gdb users](https://github.com/llvm/llvm-project/blob/main/lldb/docs/lldb-for-gdb-users.txt)
