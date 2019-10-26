# Qt4+/Qt5+ Port Knocking library

[![Build Status](https://travis-ci.org/QuentinCG/QPortKnocking.svg?branch=master)](https://travis-ci.org/QuentinCG/QPortKnocking) [![codecov](https://codecov.io/gh/QuentinCG/QPortKnocking/branch/master/graph/badge.svg)](https://codecov.io/gh/QuentinCG/QPortKnocking)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/d1075a52fb99494cb947dbd556425a81)](https://www.codacy.com/manual/QuentinCG/QPortKnocking?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=QuentinCG/QPortKnocking&amp;utm_campaign=Badge_Grade) [![License: MIT](https://img.shields.io/badge/License-MIT-brightgreen.svg)](https://github.com/QuentinCG/QPortKnocking/blob/master/LICENSE)

## What is it?

This library (with a basic example) is designed to send a port knocking sequence.

This class should work with any Qt4 and Qt5 version but was fully tested with <a href="https://download.qt.io/archive/qt/5.13/5.13.0/">Qt 5.13.0</a> and <a href="https://download.qt.io/archive/qt/4.8/4.8.7/">Qt 4.8.7</a> (only required libraries: QtNetwork and QtCore)

<img src="portknocking.jpg" width="300">

## How to build

1) Download <a target="_blank" href="https://github.com/QuentinCG/QPortKnocking/releases/download/2.0.0/QPortKnocking_v2_0_0.zip">latest release</a> (and launch executable if you just want to have a basic tool)

2) Add the QPortKnocking library into your project like done in <a href="https://github.com/QuentinCG/QPortKnocking/blob/master/example/example.pro">example.pro</a> project.

3) Include <a href="https://github.com/QuentinCG/QPortKnocking/blob/master/lib/include/QPortKnocking.h">QPortKnocking.h</a> in your project and use the library like this:
```cpp
#include <QPortKnocking.h>

...

QHostAddress addr("127.0.0.1");
QList<quint16> ports({1000, 1001, 1002, 1003});
QString error;

QPortKnocking::knock(addr, ports, error);
```

4) Build and launch your project.

## License

This project is under MIT license. This means you can use it as you want (just don't delete the library header).

## Contribute

If you want to add more examples or improve the library, just create a pull request with proper commit message and right wrapping.
