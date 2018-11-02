#!/bin/bash
for fn in sampleInput/*.txt; do
  `./parser $fn > ./test.txt`
  diff=`diff ./test.txt expectedOutput/$(basename $fn).out --ignore-space-change --ignore-case --ignore-blank-lines`
  [ ! -z "$diff" ] && echo `basename "$fn"`
  [ ! -z "$diff" ] &&  echo "./parser $fn > ./test.txt && diff ./test.txt expectedOutput/$(basename $fn).out --side-by-side --ignore-space-change --ignore-case --ignore-blank-lines && rm ./test.txt"
  rm ./test.txt
done