# DSSC - Algorithmic Design
This repository contains the codes developed in the course "Algorithmic Design" of the master course in Data Science and Scientific Computing at the University of Trieste.



## Strassen's Algorithm

The folder [Strassen_alg](Strassen_alg) contains some code to simplify the implementation and the testing of the Strassen's algorithm for matrix multiplication.

In order to test the differences in term of execution-time between the naive algorithm and the Strassen's algorithm, you need to implement both the algorithms. The former must be implemented by the function `naive_matrix_multiplication` in the file [matrix.c](Strassen_alg/matrix.c) and the latter by the function `strassen_matrix_multiplication` in the file [strassen.c](Strassen_alg/strassen.c).

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



## Binary heaps

The folder [Binary_heaps](Binary_heaps) contains ...