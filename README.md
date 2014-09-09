Forecast.io-CPP
==============

A callback-based C++ wrapper for the Forecast IO API, using the C++11 standard. It is heavily modularised and object-oriented so that multiple listeners can easily be attached to different sections.

* **Version:** 2014-08-29
* **Author:** Todd Shore
* **Website:** https://github.com/errantlinguist/Forecast.io-CPP
* **Licensing:** Copyright 2014 Todd Shore. Licensed for distribution under the Apache License 2.0: See the file `LICENSE`.

Requirements
---------------------------
* Compiler: This was developed primarily using Clang 3.4.1 on an Ubuntu-derived Linux system; There was some minimal usage of GCC as well as MinGW under Windows 7, but I haven't tested these compilers on the newest version of the code.
* `json-c` 0.11: https://github.com/json-c/json-c/
* For the demo application, `cURL` 7.35 is also required

Demo
---------------------------
A makefile is included for building the included demo application `console-weather`: Use the target `debug` to build an executable with debugging symbols and `release` to build one without. As stated above, this makefile was tested largely only on an Ubuntu-based system, so it may need to be changed to work on your system.


To do
---------------------------
* Add callbacks for [forecast data blocks](https://developer.forecast.io/docs/v2#data-blocks)
* Improve build process: E.g. use CMake instead of writing makefile manually
* Add console-writing functionalities for as-yet-unimplemented callbacks
* Make demo program support printing out SI measurements as well
* Make demo writer classes wrap data at terminal edge
