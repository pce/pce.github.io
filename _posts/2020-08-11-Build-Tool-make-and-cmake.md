---
layout: post
title: make
description: make and cmake
tags: c++ 
---

## Make

I use Makefiles a lot, i bet it's the most copied build-system, just because of the Tab-Separator.


A `Makefile` is a file of targets, which can be called with `make`, for example `make clean`.
Common targets are `all`, `install`, `clean`.

A simple Makefile without depencies and with Phony target:


    .PHONY: clean

    all:
      clang++ -std=c++11 -O3 -lboost_system -lboost_thread-mt main.cpp crow_all.h

    clean:
      rm a.out

One could make the Compiler and flags variable, set and read Envirmoment Variables, set Compiler Flags, build path and names.

    COMPILER=g++
    LIBS=...


Or a "phony" task for a Web-Project, in example: rails  with mod_passenger:

    PHONY=ssh_upload

    BASEDIR=$(CURDIR)

    SSH_HOST=10.10.4.2
    SSH_PORT=22
    SSH_USER=appname
    SSH_TARGET_DIR=/var/www/appname/api

    ssh_upload:
        @echo 'copy app directory...'
        scp -P $(SSH_PORT) -rp app/* $(SSH_USER)@$(SSH_HOST):$(SSH_TARGET_DIR)/app
        @echo 'copy routes...'
        scp -P $(SSH_PORT) -p config/routes.rb $(SSH_USER)@$(SSH_HOST):$(SSH_TARGET_DIR)/config/routes.rb
        @echo 'restart passenger...'
        ssh -p$(SSH_PORT) $(SSH_USER)@$(SSH_HOST) 'cd /var/www/appname/api/ && touch tmp/restart.txt'




## CMake

`CMakeLists.txt` is the build config file, which will be used by CMake to build a project. One can place multiple `CMakeLists.txt` files in project folders.

This example use a `src` and `build` folder.
In the projects-root a `CMakeLists.txt`:

- Set the required CMake Version `cmake_minimum_required(VERSION 3.5.1)`
- set the C++14 or 17 `set(CMAKE_CXX_STANDARD 14)`
- set the project `project(<project_name>)`
- set the resulting executable name and optional add src-files `add_executable(<executable_name>  <src_file_1>  <src_file_2>`


In the build dir, run `cmake ..`

If everything works (ie. compiler, feature checks) and the Makefile got generated `make` builds the <executable_name>.

Re-running `make` again, shows what steps or recompiling had to done.

The Makefile can be used till the build configuration changes, to rebuild the `Makefile` clean the build folder and run `cmake` again.

