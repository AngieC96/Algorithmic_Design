/** @mainpage
 *
 * @section sec_description Description
 * Implementation of the Strassen's algorithm for matrix multiplication.
 *
 * @section sec_compile How to compile
 * @subsection sec_compilation Compilation
 * We include a standard `Makefile` for convenience, so you can run the usual
 * `make` commands; out-of-source build are not supported.
 *
 * It is also possible to generate the `Makefile` via `cmake` by opening a terminal
 * in the source code folder and running
 *
 *     cmake -G "Unix Makefiles" CMakeLists.txt
 *     make
 *
 * In both cases, if everything goes as it should, you now have an executable
 * `strassen_test.x` in your build folder `$BLD`. You can run it via
 *
 *     ./strassen_test.x
 *
 * @subsection sec_builddoc Build the documentation
 * You can build the documentation by running
 *
 *     make doc
 *
 * The documentation is built into the folder `$BLD/doc/`, where `$BLD` is
 * your build folder.
 */


/**
 * @file
 * Documentation for this file.
 */
 
#include <stdio.h>
#include "test.h"
#include "matrix.h"
#include "strassen.h"


int main(int argc, char *argv[]) {
  size_t n = 1 << 12;

  float **A = allocate_random_matrix(n, n);
  float **B = allocate_random_matrix(n, n);
  float **C0 = allocate_matrix(n, n);
  float **C1 = allocate_matrix(n, n);


  printf("n\tNaive Alg.\tStrassen's Alg.\tSame result\n");
  for (size_t j = 1; j <= n; j *= 2) {

    printf("%ld\t", j);
    fflush(stdout);
 
    printf("%lf\t", test(naive_matrix_multiplication, C0, A, B, j));
    fflush(stdout);
    printf("%lf\t", test(strassen_matrix_multiplication, C1, A, B, j));
    fflush(stdout);

    printf("%d\n", same_matrix((float const *const *const)C0,
                                 (float const *const *const)C1, j, j));
  }

  deallocate_matrix(A, n);
  deallocate_matrix(B, n);
  deallocate_matrix(C0, n);
  deallocate_matrix(C1, n);

  return 0;
}
