#!/bin/bash

(
echo "--------"
./test

echo "--------"
./test --int 12

echo "--------"
./test --none -m --int2 32 --long2 111 --flt 0.1 -g 94.222 --size_t 123

echo "--------"
./test -m --int 11 -l 333 --flt 0.09 --dbl 43.4 --dbl2 90.88 --str "a string"

echo "--------"
./test --str "a string" --str2 string2

) >unittest.tmp

diff unittest.tmp unittest.out
exit $?
