#!/bin/sh
for ((i = 1; i <= 1000; i++))
do
    perl grid.pl 1000 1000 $i
    time ./bsq example_file
    echo Walls: $i
done