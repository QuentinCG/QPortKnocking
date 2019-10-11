# Qt4+/Qt5+ Port Knocking library

[![Build Status](https://travis-ci.org/QuentinCG/QPortKnocking.svg?branch=master)](https://travis-ci.org/QuentinCG/QPortKnocking)

## What is it?

This library (with a basic example) is designed to send a port knocking sequence.

This class should work with any Qt4 and Qt5 version but was fully tested with <a href="https://download.qt.io/archive/qt/5.13/5.13.0/">Qt 5.13.0</a> and <a href="https://download.qt.io/archive/qt/4.8/4.8.7/">Qt 4.8.7</a> (only required libraries: QtNetwork and QtCore)


<img src="portknocking.jpg" width="300">


## How to build

1) Download <a target="_blank" href="https://github.com/QuentinCG/QPortKnocking/releases/download/2.0.0/QPortKnocking_v2_0_0.zip">latest release</a> (and launch executable if you don't want to build it yourself)

2) Open the <a href="https://github.com/QuentinCG/QPortKnocking/blob/master/QPortKnocking.pro">QPortKnocking.pro</a> project from <a href="https://download.qt.io/archive/qt/">QtCreator</a> (or add the <a href="https://github.com/QuentinCG/QPortKnocking/blob/master/include/QPortKnocking.h">QPortKnocking.h</a> and <a href="https://github.com/QuentinCG/QPortKnocking/blob/master/src/QPortKnocking.cpp">QPortKnocking.cpp</a> files into your project and add `QT += core` and `QT += network` in your pro file)

3) Build and launch the project to see the result in the command line


## License

This project is under MIT license. This means you can use it as you want (just don't delete the library header).


## Contribute

If you want to add more examples or improve the library, just create a pull request with proper commit message and right wrapping.
