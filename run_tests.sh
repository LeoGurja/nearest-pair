#!/bin/bash

for i in {1..20}
do
  target/points >> output.log < points/$i.txt
done