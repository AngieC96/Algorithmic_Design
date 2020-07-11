# Strassen's Algorithm

This folder contains some code to simplify the implementation and the testing of the Strassen's algorithm for rectangular matrix multiplication.

In order to test the differences in term of execution-time between the naive algorithm and the Strassen's algorithm, both the algorithms are implemented. The former is implemented by the function `naive_matrix_multiplication` in the file [matrix.c](matrix.c) and the latter by the function `strassen_matrix_multiplication` in the file [strassen.c](strassen.c).

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
