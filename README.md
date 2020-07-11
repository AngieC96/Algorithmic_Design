# DSSC - Algorithmic Design
This repository contains the codes developed in the course "Algorithmic Design" of the master course in Data Science and Scientific Computing at the University of Trieste.



## Homeworks

The folder [Homeworks](Homeworks) contains all the homeworks solved.



## Strassen's Algorithm

The folder [Strassen_alg](Strassen_alg) contains some code to simplify the implementation and the testing of the Strassen's algorithm for matrix multiplication.

In order to test the differences in term of execution-time between the naive algorithm and the Strassen's algorithm, both the algorithms are implemented. The former is implemented by the function `naive_matrix_multiplication` in the file [matrix.c](Strassen_alg/matrix.c) and the latter by the function `strassen_matrix_multiplication` in the file [strassen.c](Strassen_alg/strassen.c).

The folder [Strassen_alg_rect](Strassen_alg_rect) contains the implementation of the two functions adapted to work also with rectangular matrices.

### How to compile

A Makefile can be produced by using [cmake](https://cmake.org/) as follows:
```bash
cmake -G "Unix Makefiles" CMakeLists.txt
```
or 

```bash
cmake .
```

Afterwards you can compile the code by executing `make`. This produces an executable named `strassen_test.x` which can be executed in POSIX systems by using the command:

```bash
./strassen_test.x

    n	Naive Alg.	Strassen's Alg.	Str. Alg. best	Same result
    1	0.000001	0.000020	0.000001	1 1
    2	0.000000	0.000000	0.000000	1 1
    4	0.000001	0.000000	0.000000	1 1
    8	0.000009	0.000001	0.000001	1 1
   16	0.000005	0.000004	0.000004	1 1
   32	0.000032	0.000034	0.000028	1 1
   64	0.000250	0.000244	0.000234	1 1
  128	0.001934	0.001884	0.001853	1 1
  256	0.100109	0.013079	0.012471	1 1
  512	0.905262	0.089764	0.086891	1 1
 1024	8.541473	0.627640	0.612996	1 1
 2048	66.494477	4.420142	4.326053	1 1
 4096	185.323830	31.036216	30.434407	1 1
```

The first column in the output, `n`, report the number of the rows and columns in the tested matrices.

The second and third columns in the output, `Naive Alg.` and `Strassen's Alg.`, reports the execution-time in seconds of the implementations of the naive algorithm and of the Strassen's algorithm, respectively. The fourth column, `Str. Alg. best`, reports the execution-time of the Strassen's algorithm with reduced memory allocations.

Finally, the last column, `Same result`, which is exclusively meant to validate the implementations, contains the value 1 in the first column if and only if the result of the naive algorithm and that of the Strassen's algorithm are the same, and the value 1 in the second column if and only if the result of the naive algorithm and that of the Strassen's algorithm with reduced memory allocations are the same.

### Build the documentation

You can build the documentation by running

```bash
make doc
```

The documentation is built into the folder `$BLD/doc/`, where `$BLD` is your build folder.



## Binary heaps

### A simple binary heap library (and testing tools)

The folder [Binary_heaps](Binary_heaps) contains a template for a simple array-implementation of binary heaps in the C-programming language.

This template contains all the code needed to test your implementation of binary heaps in both correctness and efficiency terms. Your are exclusively required to code the type `binheap_type` in the file [binheap.h](Binary_heaps/include/binheap.h) and all the functions dealing it in the file [binheap.c](Binary_heaps/src/binheap.c). The meaning of the function parameters and the semantics of the functions themselves are detailed in [binheap.h](Binary_heaps/include/binheap.h). Once this has been done, a set of tests can be produced as described below.

You can generate the Makefile by using [cmake](https://cmake.org/) as follows:

```bash
cmake -G "Unix Makefiles" CMakeLists.txt
```

Afterwards you can compile the code by executing `make`. This produces a set of programs, named `test_delete_min`, `test_insert`, etc., which can be executed in POSIX systems simply by writing `./` and the name of the program in the terminal. For instance, in order to execute `test_delete_min`, use the following command:

```bash
./test_delete_min
Setting up test sets...done

Keep removing the minimum
n	On Heaps	On Arrays
0	0.000004	0.000005
409	0.000001	0.052824
818	0.000001	0.204115
1227	0.000002	0.470132
1636	0.000001	0.804782
2045	0.000001	1.270438
2454	0.000001	1.825179
2863	0.000001	2.499937
3272	0.000001	3.238163
3681	0.000001	4.117790
4090	0.000001	5.064005
```

## Installing the library

In order to install the library, you can set the install directory `<BINHEAP_INSTALL_DIR>` by executing:

```bash
cmake -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=<BINHEAP_INSTALL_DIR> CMakeLists.txt
```

If you don't do it, the library and its headers will be installed in `/usr/local/`. I've chosen the folder `'~/Documenti/Algorithmic Design/Algorithmic_Design/Binary_heaps'`.

After that simply write:

```bash
make install
```



## Sorting Algorithms

The folder [Sorting](Sorting) contains the implementation and testing of sorting algorithms. The algorithms implemented are: insertion sort, quick sort (with and without the select algorithm to identify the pivot), bubble sort, selection sort, and heap sort, but other algorithms can easily be added by editing the main function in the file [main.c](Sorting/src/main.c).

In order to test the differences in term of execution-time between the sorting algorithms, all of them are implemented. The insertion sort algorithm is implemented in the file [insertion_sort.c](Sorting/src/insertion_sort.c) according to the API defined in [insertion_sort.h](Sorting/src/insertion_sort.h); the quick sort algorithm is in the file [quick_sort.c](Sorting/src/quick_sort.c) and, so forward, for all the algorithms.


A Makefile can be produced by using [cmake](https://cmake.org/) as follows:

```bash
cmake -G "Unix Makefiles" CMakeLists.txt
```

You have to use the [`binheap` library](Binary_heaps) to compile heap sort, and you can do it by using the command:

```bash
cmake -G "Unix Makefiles" -DBINHEAP_PATH=<BINHEAP_INSTALL_DIR> CMakeLists.txt
```

See [here](## Installing the library) to have more details about `<BINHEAP_INSTALL_DIR>`.

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