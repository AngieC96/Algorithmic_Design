# Sorting Algorithms

This folder contains the implementation and testing of sorting algorithms. The algorithms implemented are: insertion sort, quick sort (with and without the select algorithm to identify the pivot), bubble sort, selection sort, and heap sort, but other algorithms can easily be added by editing the main function in the file [main.c](src/main.c).

In order to test the differences in term of execution-time between the sorting algorithms, all of them are implemented. The insertion sort algorithm is implemented in the file [insertion_sort.c](src/insertion_sort.c) according to the API defined in [insertion_sort.h](src/insertion_sort.h); the quick sort algorithm is in the file [quick_sort.c](src/quick_sort.c) and, so forward, for all the algorithms.


A Makefile can be produced by using [cmake](https://cmake.org/) as follows:

```bash
cmake -G "Unix Makefiles" CMakeLists.txt
```

You have to use the [`binheap` library](04_Binary_heaps) to compile heap sort, and you can do it by using the command:

```bash
cmake -G "Unix Makefiles" -DBINHEAP_PATH=<BINHEAP_INSTALL_DIR> CMakeLists.txt
```

I've chosen the folder `~/Documenti/'Algorithmic Design'/Algorithmic_Design/03_Binary_heaps` or the folder `~/Documenti/'Algorithmic Design/Algorithmic_Design/04_Binary_heaps_noswap'`, depending on what type of binary heap you want to use (see [here](../04_Binary_heaps_noswap/README.md) the difference). See [here](../03_Binary_heaps/README.md) to have more details about `<BINHEAP_INSTALL_DIR>`.

Afterwards you can compile the code by executing `make`. This produces an executable named `test_sorting` which can be executed in POSIX systems by using the command:

```bash
./test_sorting
Size	Insertion Sort	          	        
    	(Random Case)	(Best Case)	(Worst Case)
2^2 	0.000000 (KO)	0.000000	0.000000 (KO)
2^3	0.000000 (KO)	0.000000	0.000000 (KO)
2^4	0.000000 (KO)	0.000000	0.000000 (KO)
2^5	0.000000 (KO)	0.000000	0.000000 (KO)
2^6	0.000000 (KO)	0.000000	0.000000 (KO)
2^7	0.000000 (KO)	0.000000	0.000000 (KO)
2^8	0.000000 (KO)	0.000000	0.000000 (KO)
2^9	0.000000 (KO)	0.000000	0.000000 (KO)
2^10	0.000000 (KO)	0.000000	0.000000 (KO)
2^11	0.000000 (KO)	0.000000	0.000000 (KO)
2^12	0.000000 (KO)	0.000000	0.000000 (KO)
2^13	0.000000 (KO)	0.000000	0.000000 (KO)


Size	Quick Sort	          	Quick Sort + Select
    	(Random Case)	(Worst Case)	(Random Case)	(Worst Case)
2^2 	0.000000 (KO)	0.000000	0.000000 (KO)	0.000000
2^3	0.000000 (KO)	0.000000	0.000000 (KO)	0.000000
2^4	0.000000 (KO)	0.000000	0.000000 (KO)	0.000000
2^5	0.000000 (KO)	0.000000	0.000000 (KO)	0.000000
2^6	0.000000 (KO)	0.000000	0.000000 (KO)	0.000000
2^7	0.000000 (KO)	0.000000	0.000000 (KO)	0.000000
2^8	0.000000 (KO)	0.000000	0.000000 (KO)	0.000000
2^9	0.000000 (KO)	0.000000	0.000000 (KO)	0.000000
2^10	0.000000 (KO)	0.000000	0.000000 (KO)	0.000000
2^11	0.000000 (KO)	0.000000	0.000000 (KO)	0.000000
2^12	0.000000 (KO)	0.000000	0.000000 (KO)	0.000000
2^13	0.000000 (KO)	0.000000	0.000000 (KO)	0.000000


Size	Insertion Sort	Quick Sort	Bubble Sort	Selection Sort	Heap Sort
    	(Random Case)	(Random Case)			
2^2 	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)
2^3 	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)
2^4 	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)
2^5 	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)
2^6 	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)
2^7 	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)
2^8 	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)
2^9 	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)
2^10	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)
2^11	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)
2^12	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)
2^13	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)	0.000000 (KO)


Size	Quick Sort  	Quick Sort +	Heap Sort
			  Select
    	(Random Case)	(Random Case)
2^14	0.000001 (KO)	0.000001 (KO)	0.000000 (KO)
2^15	0.000005 (KO)	0.000005 (KO)	0.000002 (KO)
2^16	0.000004 (KO)	0.000004 (KO)	0.000000 (KO)
2^17	0.000011 (KO)	0.000011 (KO)	0.000011 (KO)
2^18	0.000030 (KO)	0.000030 (KO)	0.000013 (KO)
2^19	0.000105 (KO)	0.000105 (KO)	0.000041 (KO)
2^20	0.000110 (KO)	0.000110 (KO)	0.000075 (KO)
```

The first column in the output report the size of the tested array. The remaining columns in the output report the execution-time in seconds of the implementations of sorting algorithms. Whenever the resulting arrays are not sorted (e.g., due to a bug) the word "KO" follows the execution-time.

In order to better compare quick sort and heap sort on the random cases, a further set of tests on larger arrays are also performed.