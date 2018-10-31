#!/bin/bash
for fn in sample_input/*.txt; do
  `./youngr_parser < $fn > ./test.txt`
  diff=`diff ./test.txt expected_output/$(basename $fn).out --ignore-space-change --ignore-case --ignore-blank-lines`
  [ ! -z "$diff" ] && echo `basename "$fn"`
  [ ! -z "$diff" ] &&  echo "./youngr_parser < $fn > ./test.txt && diff ./test.txt expected_output/$(basename $fn).out --side-by-side --ignore-space-change --ignore-case --ignore-blank-lines && rm ./test.txt"
  rm ./test.txt
done