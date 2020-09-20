# Strassen's Algorithm rectangular matrices

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
Beginning
Allocated matrices
       dim	Naive Alg.	Strassen's Alg.	Str. Alg. best	Same result
   1x   1x   1	0.000002	0.000006	0.000003	1 1
   3x   5x   7	0.000002	0.000005	0.000018	1 1
   9x  25x  49	0.000033	0.000555	0.000544	1 1
  27x 125x 343	0.012168	0.137508	0.131498	1 1
  81x 625x2401	1.749203	47.157107	44.011950	1 1
```

Description output.

### Build the documentation

You can build the documentation by running

```bash
make doc
```

The documentation is built into the folder `$BLD/doc/`, where `$BLD` is your build folder.
