/**
 * @file
 * Documentation for this file.
 */
 
#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

/**
 * @brief Naive algorithm for matrix multiplication.
 * @param C The matrix where to put the result.
 * @param A The first matrix of the multiplication.
 * @param B The second matrix of the multiplication.
 * @param n The dimension of the matrices.
 * 
 * This function implements the naive algorithm for matrix multiplication between
 * rectangular matrixes. The result is placed in the sub-matrix C.
 */
void naive_matrix_multiplication(float **C, float const *const *const A,
                                float const *const *const B,
                                const size_t n, const size_t m, const size_t p) 
{
  // IMPLEMENT THE NAIVE ALGORITHM HERE
  for(size_t y = 0; y < n; ++y){
    for(size_t x = 0; x < p; ++x) {
      float value = 0.0;  // We don't need to derefrenece
      for(size_t z = 0;z < m; ++z){
        value += A[y][z] * B[z][x];
      }
      C[y][x] = value;
    }
  }
}

/**
 * @brief Checks if two matrices are equal.
 * @param A The first matrix.
 * @param B The second matrix.
 * @param rows The number of rows.
 * @param cols The number of columns.
 * 
 * This function checks if two matrices are equal. It returns 0 if they are
 * different, 1 if they are equal.
 */
int same_matrix(float const *const *const A, float const *const *const B,
                const size_t rows, const size_t cols) {
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      if (A[i][j] != B[i][j]) {
        return 0;
      }
    }
  }

  return 1;
}

/**
 * @brief Allocates a matrix.
 * @param rows The number of rows.
 * @param cols The number of columns.
 * 
 * This function allocates a matrix in the heap.
 */
float **allocate_matrix(const size_t rows, const size_t cols) {
  float **M = (float **)malloc(sizeof(float *) * rows);

  for (size_t i = 0; i < rows; i++) {
    M[i] = (float *)malloc(sizeof(float) * cols);
  }

  return M;
}

/**
 * @brief Deallocates a matrix.
 * @param rows The number of rows.
 * @param cols The number of columns.
 * 
 * This function deallocates a matrix from the heap.
 */
void deallocate_matrix(float **A, const size_t rows) {
  for (size_t i = 0; i < rows; i++) {
    free(A[i]);
  }

  free(A);
}

/**
 * @brief Allocates a random matrix.
 * @param rows The number of rows.
 * @param cols The number of columns.
 * 
 * This function allocates a matrix in the heap and fills it with **float** random numbers.
 */
float **allocate_random_matrix(const size_t rows, const size_t cols) {
  
  float **A = allocate_matrix(rows, cols);
  
  srand(10);
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      A[i][j] = (rand() - RAND_MAX / 2) % 5;
    }
  }

  return A;
}

