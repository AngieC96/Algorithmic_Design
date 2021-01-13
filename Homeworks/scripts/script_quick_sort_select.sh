#!/usr/bin/env bash

ntrials=1000

# "Quick Sort\t           \tQuick Sort + Select"
# (Random Case)\t(Worst Case)\t(Random Case)\t(Worst Case)

for N in `seq 1 1 $ntrials`; do
	../../05_Sorting/test_sorting | grep "2^16" | awk '{print $2 ", " $3 ", " $4 ", " $5}' >> ./times_quicksortselect_histogram.csv
	echo 'Done' $N
done
