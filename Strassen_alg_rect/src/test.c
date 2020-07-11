#if defined(__STDC__) // standard compiler
#  if (__STDC_VERSION__ >= 199901L)
#     define _XOPEN_SOURCE 700
#  endif
#endif
#define _GNU_SOURCE

/**
 * @file
 * Documentation for this file.
 */
 
#include <time.h>

/**
 * @brief Takes the time of a function.
 * @param f The function to be tested.
 * @param C The matrix that stores the result.
 * @param A The first matrix.
 * @param B The second matrix.
 * @param n The rows of the A matrix.
 * @param m The columns of the A matrix.
 * @param p The columns of the B matrix.
 * 
 * This function takes the execution time of the function @ref f.
 */
double test(void (*f)(float **,
	                  float const *const *const,
	                  float const *const *const,
	                  size_t, size_t, size_t), 
	        float **C, float** A, float **B, size_t n, size_t m, size_t p)
{
  struct timespec requestStart, requestEnd;
  double accum;
  size_t rep = 1;

  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &requestStart);
  for (size_t i = 0; i < rep; i++) {
    f(C, (float const *const *const)A,
      (float const *const *const)B, n, m, p);
  }

  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &requestEnd);

  accum = (requestEnd.tv_sec - requestStart.tv_sec) +
          (requestEnd.tv_nsec - requestStart.tv_nsec) / 1E9;
  
  return accum / rep;
}

