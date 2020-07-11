#!/usr/bin/env bash


for N in `seq 1 1 20`; do
	../Binary_heaps/test_delete_min_no_output >> ./times_delete_min.csv
	echo $'Done ' $N
done
