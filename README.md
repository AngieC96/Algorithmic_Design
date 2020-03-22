# DSSC - Algorithmic Design
This repository contains the codes developed in the course "Algorithmic Design" of the master course in Data Science and Scientific Computing at the University of Trieste.



## Strassen's Algorithm

The folder [Strassen_alg](Strassen_alg) contains some code to simplify the implementation and the testing of the Strassen's algorithm for matrix multiplication.

In order to test the differences in term of execution-time between the naive algorithm and the Strassen's algorithm, both the algorithms are implemented. The former is implemented by the function `naive_matrix_multiplication` in the file [matrix.c](Strassen_alg/matrix.c) and the latter by the function `strassen_matrix_multiplication` in the file [strassen.c](Strassen_alg/strassen.c).

The branch `rectangular` contains the implementation of the two functions adapted to work also with rectangular matrices.

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

n	Naive Alg.	Strassen's Alg.	Same result
1	0.000000	0.000000	1
2	0.000000	0.000000	1
4	0.000000	0.000000	1
8	0.000000	0.000000	1
16	0.000000	0.000000	1
32	0.000000	0.000000	1
64	0.000000	0.000000	1
128	0.000000	0.000000	1
256	0.000000	0.000000	1
512	0.000000	0.000000	1
1024	0.000000	0.000000	1
2048	0.000000	0.000000	1
4096	0.000000	0.000000	1
```

The first column in the output, `n`, report the number of the rows and columns in the tested matrices. 

The second and third columns in the output, `Naive Alg.` and `Strassen's Alg.`, reports the execution-time in seconds of the implementations of the naive algorithm and of the Strassen's algorithm, respectively. 

Finally, the last column, `Same result`, which is exclusively meant to validate the implementations, contains the value 1 if and only if the result of the naive algorithm and that of the Strassen's algorithm are the same.

### Build the documentation

You can build the documentation by running

```bash
make doc
```

The documentation is built into the folder `$BLD/doc/`, where `$BLD` is your build folder.

### Testing

I compiled and run the code on Ulysses cluster in Sissa, for both square and rectangular matrices. After 12 hours, the output was

- for square matrices:

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

- for rectangular matrices:

  ```bash
  ./strassen_test.x
  
         dim	Naive Alg.	Strassen's Alg.	Str. Alg. best	Same result
     1x   3x   4	0.000001	0.000022	0.000001	1 1
     2x   6x   8	0.000001	0.000001	0.000000	1 1
     4x  12x  16	0.000002	0.000001	0.000001	1 1
     8x  24x  32	0.000007	0.000006	0.000006	1 1
    16x  48x  64	0.000061	0.000049	0.000049	1 1
    32x  96x 128	0.000390	0.000368	0.000364	1 1
    64x 192x 256	0.022256	0.022456	0.022060	1 1
   128x 384x 512	0.172694	0.174371	0.174951	1 1
   256x 768x1024	1.452749	0.465220	0.463335	1 1
   512x1536x2048	12.976235	1.766585	1.750519	1 1
  1024x3072x4096	69.019623	8.170306	8.084943	1 1
  ```

While on the new partition `frontend-beta` we have the following results:

- for square matrices:

  ```bash
  ./strassen_test.x
  
      n	Naive Alg.	Strassen's Alg.	Str. Alg. best	Same result
      1	0.000002	0.000006	0.000001	1 1
      2	0.000001	0.000001	0.000001	1 1
      4	0.000001	0.000001	0.000001	1 1
      8	0.000003	0.000002	0.000002	1 1
     16	0.000008	0.000006	0.000006	1 1
     32	0.000047	0.000041	0.000041	1 1
     64	0.000371	0.000347	0.000346	1 1
    128	0.003007	0.002964	0.002960	1 1
    256	0.025591	0.021378	0.020506	1 1
    512	0.211942	0.109676	0.100745	1 1
   1024	1.380608	0.741221	0.714642	1 1
   2048	19.931641	5.106519	5.021268	1 1
   4096	257.180293	35.810735	35.314176	1 1
  ```

- for rectangular matrices:

  ```bash
  ./strassen_test.x
  
         dim	Naive Alg.	Strassen's Alg.	Str. Alg. best	Same result
     1x   3x   4	0.000002	0.000006	0.000001	1 1
     2x   6x   8	0.000002	0.000001	0.000001	1 1
     4x  12x  16	0.000003	0.000002	0.000002	1 1
     8x  24x  32	0.000012	0.000009	0.000009	1 1
    16x  48x  64	0.000072	0.000066	0.000066	1 1
    32x  96x 128	0.000580	0.000552	0.000556	1 1
    64x 192x 256	0.004737	0.004684	0.004678	1 1
   128x 384x 512	0.039687	0.039087	0.039437	1 1
   256x 768x1024	0.294623	0.199306	0.196376	1 1
   512x1536x2048	2.336765	1.403819	1.380727	1 1
  1024x3072x4096	65.748678	9.800090	9.665999	1 1
  ```

We can see that the Strassen's algorithm is much better than the naive one, while the Strassen's algorithm with reduced memory allocations is only slightly better.

The graph shows that ...



## Binary heaps

### A simple binary heap library (and testing tools)

The folder [Binary_heaps](Binary_heaps) contains a template for a simple array-implementation of binary heaps in the C-programming language.

This template contains all the code needed to test your implementation of binary heaps in both correctness and efficiency terms. Your are exclusively required to code the type `binheap_type` in the file [binheap.h](include/binheap.h) and all the functions dealing it in the file [binheap.c](src/binheap.c). The meaning of the function parameters and the semantics of the functions themselves are detailed in [binheap.h](include/binheap.h). Once this has been done, a set of tests can be produced as described below.

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

