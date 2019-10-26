#!/bin/bash
for filename in `find . | egrep '\.cpp'`;
do
  sudo gcov -n -o . $filename > /dev/null;
done
