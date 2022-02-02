#!/bin/bash

for i in {1..5}
do
  for j in {1..15}
  do
    target/points >> results/qs_$i.log < points/$i/$j.txt
  done
done