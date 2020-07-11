/**
 * @file
 * Documentation for this file.
 */
 
 #include "matrix.h"

/**
 * @brief Subtracts two rectangular matrices.
 * @param C The matrix where to put the result.
 * @param A The first matrix of the sbutaction.
 * @param B The second matrix of the subtraction.
 * @param C_f_row The starting point on the rows of the sub-matrix of C.
 * @param C_f_col The starting point on the columns of the sub-matrix of C.
 * @param A_f_row The starting point on the rows of the sub-matrix of A.
 * @param A_f_col The starting point on the columns of the sub-matrix of A.
 * @param B_f_row The starting point on the rows of the sub-matrix of B.
 * @param B_f_col The starting point on the columns of the sub-matrix of B.
 * @param n The dimension of the matrices.
 * 
 * This function performs the element-wise subtraction of B from A and puts the
 * resulting sub-matrix in C.
 * The parameters *_f_row and *_f_col represents the first row and the first
 * column, respectively, of the sub-matrix we want to deal with.
 */
void sub_matrix_blocks(float **C, float const *const *const A,
                       float const *const *const B,
                       const size_t C_f_row, const size_t C_f_col,
                       const size_t A_f_row, const size_t A_f_col,
                       const size_t B_f_row, const size_t B_f_col,
                       const size_t n, const size_t m){
    for(size_t y = 0; y < n; ++y){
        for(size_t x = 0; x < m; ++x) {
            C[y + C_f_row][x + C_f_col] = A[y + A_f_row][x + A_f_col] - B[y + B_f_row][x + B_f_col];
        }
    }
}

/**
 * @brief Sums two rectangular matrices.
 * @param C The matrix where to put the result.
 * @param A The first matrix of the summation.
 * @param B The second matrix of the summation.
 * @param C_f_row The starting point on the rows of the sub-matrix of C.
 * @param C_f_col The starting point on the columns of the sub-matrix of C.
 * @param A_f_row The starting point on the rows of the sub-matrix of A.
 * @param A_f_col The starting point on the columns of the sub-matrix of A.
 * @param B_f_row The starting point on the rows of the sub-matrix of B.
 * @param B_f_col The starting point on the columns of the sub-matrix of B.
 * @param n The dimension of the matrices.
 * 
 * This function performs the element-wise sum ofA and B and puts the
 * resulting sub-matrix in C.
 * The parameters *_f_row and *_f_col represents the first row and the first
 * column, respectively, of the sub-matrix we want to deal with.
 */
void sum_matrix_blocks(float **C, float const *const *const A,
                       float const *const *const B,
                       const size_t C_f_row, const size_t C_f_col,
                       const size_t A_f_row, const size_t A_f_col,
                       const size_t B_f_row, const size_t B_f_col,
                       const size_t n, const size_t m){
    for(size_t y = 0; y < n; ++y){
        for(size_t x = 0; x < m; ++x) {
            C[y+C_f_row][x+C_f_col] = A[y + A_f_row][x + A_f_col] + B[y + B_f_row][x + B_f_col];
        }
    }
}

/**
 * @brief Naive algorithm for matrix multiplication.
 * @param C The matrix where to put the result.
 * @param A The first matrix of the multiplication.
 * @param B The second matrix of the multiplication.
 * @param C_f_row The starting point on the rows of the sub-matrix of C.
 * @param C_f_col The starting point on the columns of the sub-matrix of C.
 * @param A_f_row The starting point on the rows of the sub-matrix of A.
 * @param A_f_col The starting point on the columns of the sub-matrix of A.
 * @param B_f_row The starting point on the rows of the sub-matrix of B.
 * @param B_f_col The starting point on the columns of the sub-matrix of B.
 * @param n The dimension of the matrices.
 * 
 * This function implements the naive algorithm for matrix multiplication between
 * sub-matrixes. The result is placed in the sub-matrix C.
 * The parameters *_f_row and *_f_col represents the first row and the first
 * column, respectively, of the sub-matrix we want to deal with.
 */
void naive_aux(float **C, float const *const *const A,
               float const *const *const B,
               const size_t C_f_row, const size_t C_f_col,
               const size_t A_f_row, const size_t A_f_col,
               const size_t B_f_row, const size_t B_f_col,
               const size_t n, const size_t m, const size_t p)
{
    for(size_t y = 0; y < n; ++y){
        for(size_t x = 0; x < p; ++x) {
            float value = 0.0;
            for(size_t z = 0; z < m; ++z){
                value += A[y + A_f_row][z + A_f_col] * B[z + B_f_row][x + B_f_col];
            }
            C[y + C_f_row][x + C_f_col] = value;
        }
    }
}

/**
 * @brief Strassen's algorithm for matrix multiplication.
 * @param C The matrix where to put the result.
 * @param A The first matrix of the multiplication.
 * @param B The second matrix of the multiplication.
 * @param C_f_row The starting point on the rows of the sub-matrix of C.
 * @param C_f_col The starting point on the columns of the sub-matrix of C.
 * @param A_f_row The starting point on the rows of the sub-matrix of A.
 * @param A_f_col The starting point on the columns of the sub-matrix of A.
 * @param B_f_row The starting point on the rows of the sub-matrix of B.
 * @param B_f_col The starting point on the columns of the sub-matrix of B.
 * @param n The dimension of the matrices.
 * 
 * This function implements the Strassen's algorithm for matrix multiplication
 * between sub-matrixes. The result is placed in the sub-matrix C.
 * The parameters *_f_row and *_f_col represents the first row and the first
 * column, respectively, of the sub-matrix we want to deal with.
 */
void strassen_aux(float **C, float const *const *const A,
                  float const *const *const B,
                  const size_t C_f_row, const size_t C_f_col,
                  const size_t A_f_row, const size_t A_f_col,
                  const size_t B_f_row, const size_t B_f_col,
                  const size_t n, const size_t m, const size_t p)
{
    if(n <= 128) {  // To reduce the constant int he complexity! // if(n == 1) {
        naive_aux(C, A, B,
                     C_f_row, C_f_col, 
                     A_f_row, A_f_col,
                     B_f_row, B_f_col,
                     n, m, p);
        return;
    }

    size_t n2 = n/2; // This is the size of the row of the blocks of A
    size_t m2 = m/2; // This is the size of the columns of the blocks of A and of the rows of the blocks of B
    size_t p2 = p/2; // This is the size of the columns of the blocks of B

    float ***S = (float ***) malloc(sizeof(float **) * 10); // It's an array of matrices!
    S[0] = allocate_matrix(m2, p2); // We allocate the necessary matrix S
    S[1] = allocate_matrix(n2, m2);
    S[2] = allocate_matrix(n2, m2);
    S[3] = allocate_matrix(m2, p2);
    S[4] = allocate_matrix(n2, m2);
    S[5] = allocate_matrix(m2, p2);
    S[6] = allocate_matrix(n2, m2);
    S[7] = allocate_matrix(m2, p2);
    S[8] = allocate_matrix(n2, m2);
    S[9] = allocate_matrix(m2, p2);


    float ***P = (float ***) malloc(sizeof(float **) * 7);
    for(size_t i = 0; i < 7; ++i){
        P[i] = allocate_matrix(n2, p2);
    }

    // S1 = B12 - B22
    sub_matrix_blocks(S[0], B, B, 
                            0, 0,
                            B_f_row, B_f_col + p2,
                            B_f_row + m2, B_f_col + p2,
                            m2, p2);
    // P1 = A11 x S1
    strassen_aux(P[0], A, (const float *const *const) S[0],
                  0, 0,
                  A_f_row, A_f_col,
                  0, 0,
                  n2, m2, p2);
    // S2 = A11 + A12
    sum_matrix_blocks(S[1], A, A, 
                            0, 0,
                            A_f_row, A_f_col,
                            A_f_row, A_f_col + m2,
                            n2, m2);
    // P2 = S2 x B22
    strassen_aux(P[1], (const float *const *const) S[1], B,
                  0, 0,
                  0, 0,
                  B_f_row + m2, B_f_col + p2,
                  n2, m2, p2);
    // S3 = A21 + A22
    sum_matrix_blocks(S[2], A, A, 
                            0, 0,
                            A_f_row + n2, A_f_col,
                            A_f_row + n2, A_f_col + m2,
                            n2, m2);
    // P3 = S3 x B11
    strassen_aux(P[2], (const float* const* const) S[2], B,
                  0, 0,
                  0, 0,
                  B_f_row , B_f_col,
                  n2, m2, p2);
    // S4 = B21 - B11
    sub_matrix_blocks(S[3], B, B,
                            0, 0,
                            B_f_row + m2, B_f_col,
                            B_f_row, B_f_col,
                            m2, p2);
    // P4 = A22 x S4
    strassen_aux(P[3], A, (const float* const* const) S[3],
                           0, 0,
                           A_f_row + n2, A_f_col + m2,
                           0, 0,
                           n2, m2, p2);
    // S5 = A11 + A22
    sum_matrix_blocks(S[4], A, A, 
                            0, 0,
                            A_f_row, A_f_col,
                            A_f_row + n2, A_f_col + m2,
                            n2, m2);
    // S6 = B11 + B22
    sum_matrix_blocks(S[5], B, B,
                            0, 0,
                            B_f_row, B_f_col,
                            B_f_row + m2, B_f_col + p2,
                            m2, p2);
    // P5 = S5 × S6
    strassen_aux(P[4], (const float* const* const) S[4],
                       (const float* const* const) S[5],
                        0, 0,
                        0, 0,
                        0, 0,
                        n2, m2, p2);
    // S7 = A12 − A22
    sub_matrix_blocks(S[6], A, A, 
                            0, 0,
                            A_f_row, A_f_col + m2,
                            A_f_row + n2, A_f_col + m2,
                            n2, m2);
    // S8 = B21 + B22
    sum_matrix_blocks(S[7], B, B,
                            0, 0,
                            B_f_row + m2, B_f_col,
                            B_f_row + m2, B_f_col + p2,
                            m2, p2);
    // P6 = S7 x S8
    strassen_aux(P[5], (const float* const* const) S[6],
                       (const float* const* const) S[7],
                        0, 0,
                        0, 0,
                        0, 0,
                        n2, m2, p2);
    // S9 = A11 - A21
    sub_matrix_blocks(S[8], A, A,
                            0, 0,
                            A_f_row, A_f_col,
                            A_f_row + n2, A_f_col,
                            n2, m2);
    // S10 = B11 + B12
    sum_matrix_blocks(S[9], B, B,
                            0, 0,
                            B_f_row, B_f_col,
                            B_f_row, B_f_col + p2,
                            m2, p2);
    // P7 = S9 x S10
    strassen_aux(P[6], (const float* const* const) S[8],
                       (const float* const* const) S[9],
                        0, 0,
                        0, 0,
                        0, 0,
                        n2, m2, p2);
    // To be continued...

    //C11 = P5 + P4 - P2 + P6
    sum_matrix_blocks(C, (const float* const* const) P[4],
                         (const float* const* const) P[3],
                         C_f_row, C_f_col,
                         0, 0,
                         0, 0,
                         n2, p2);
    sub_matrix_blocks(C, (const float* const* const) C,
                         (const float* const* const) P[1],
                         C_f_row, C_f_col,
                         C_f_row, C_f_col,
                         0, 0,
                         n2, p2);
    sum_matrix_blocks(C, (const float* const* const) C,
                         (const float* const* const) P[5],
                         C_f_row, C_f_col,
                         C_f_row, C_f_col,
                         0, 0,
                         n2, p2);
    //C12 = P1 + P2
    sum_matrix_blocks(C, (const float* const* const) P[0],
                         (const float* const* const) P[1],
                         C_f_row, C_f_col + p2,
                         0, 0,
                         0, 0,
                         n2, p2);
    //C21 = P3 + P4
    sum_matrix_blocks(C, (const float* const* const) P[2],
                         (const float* const* const) P[3],
                         C_f_row + n2, C_f_col,
                         0, 0,
                         0, 0,
                         n2, p2);
    //C22 = P5 + P1 - P3 - P7
    sum_matrix_blocks(C, (const float *const *const) P[4],
                         (const float *const *const) P[0],
                         C_f_row + n2, C_f_col + p2,
                         0, 0,
                         0, 0,
                         n2, p2);
    sub_matrix_blocks(C, (const float *const *const) C,
                         (const float *const *const) P[2],
                         C_f_row + n2, C_f_col + p2,
                         C_f_row + n2, C_f_col + p2,
                         0, 0,
                         n2, p2);
    sub_matrix_blocks(C, (const float *const *const) C,
                         (const float *const *const) P[6],
                         C_f_row + n2, C_f_col + p2,
                         C_f_row + n2, C_f_col + p2,
                         0, 0,
                         n2, p2);

    
    deallocate_matrix(S[0], m2);
    deallocate_matrix(S[1], n2);
    deallocate_matrix(S[2], n2);
    deallocate_matrix(S[3], m2);
    deallocate_matrix(S[4], n2);
    deallocate_matrix(S[5], m2);
    deallocate_matrix(S[6], n2);
    deallocate_matrix(S[7], m2);
    deallocate_matrix(S[8], n2);
    deallocate_matrix(S[9], m2);
    free(S);
    
    for(size_t i = 0; i < 7; ++i){
        deallocate_matrix(P[i], n2);
    }
    free(P);

}

/**
 * @brief Wrapper function for the function @ref strassen_aux.
 * @param C The matrix where to put the result.
 * @param A The first matrix of the multiplication.
 * @param B The second matrix of the multiplication.
 * @param n The dimension of the matrices.
 * 
 * This functions is exclusively meant to provide an easy to use API.
 */
void strassen_matrix_multiplication(float **C, float const *const *const A,
                                    float const *const *const B, size_t n, size_t m, size_t p) 
{
 
    // IMPLEMENT THE STRASSEN'S ALGORITHM HERE
    strassen_aux(C, A, B,
                    0, 0,
                    0, 0,
                    0, 0,
                    n, m, p);

 
}

/**
 * @brief Strassen's algorithm for matrix multiplication with reduced memory allocation.
 * @param C The matrix where to put the result.
 * @param A The first matrix of the multiplication.
 * @param B The second matrix of the multiplication.
 * @param C_f_row The starting point on the rows of the sub-matrix of C.
 * @param C_f_col The starting point on the columns of the sub-matrix of C.
 * @param A_f_row The starting point on the rows of the sub-matrix of A.
 * @param A_f_col The starting point on the columns of the sub-matrix of A.
 * @param B_f_row The starting point on the rows of the sub-matrix of B.
 * @param B_f_col The starting point on the columns of the sub-matrix of B.
 * @param n The dimension of the matrices.
 * 
 * This function implements the Strassen's algorithm for matrix multiplication
 * between sub-matrixes. The result is placed in the sub-matrix C.
 * The parameters *_f_row and *_f_col represents the first row and the first
 * column, respectively, of the sub-matrix we want to deal with.
 * It is a better version of the function @see strassen_aux(), with a reduced
 * memory allocation to speed up the execution time.
 */
void strassen_aux_best(float **C, float const *const *const A,
                  float const *const *const B,
                  const size_t C_f_row, const size_t C_f_col,
                  const size_t A_f_row, const size_t A_f_col,
                  const size_t B_f_row, const size_t B_f_col,
                  const size_t n, const size_t m, const size_t p)
{
    if(n <= 128) {  // To reduce the constant int he complexity! // if(n == 1) {
        naive_aux(C, A, B,
                     C_f_row, C_f_col, 
                     A_f_row, A_f_col,
                     B_f_row, B_f_col,
                     n, m, p);
        return;
    }

    size_t n2 = n/2; // This is the size of the row of the blocks of A
    size_t m2 = m/2; // This is the size of the columns of the blocks of A and of the rows of the blocks of B
    size_t p2 = p/2; // This is the size of the columns of the blocks of B

    float **SA = allocate_matrix(n2, m2); // We allocate the necessary matrix S with the dimensions of A
    float **SB = allocate_matrix(m2, p2); // Matrix S with the dimensions of B


    float ***P = (float ***) malloc(sizeof(float **) * 7);
    for(size_t i = 0; i < 7; ++i){
        P[i] = allocate_matrix(n2, p2);
    }

    // S1 = B12 - B22
    sub_matrix_blocks(SB, B, B, 
                            0, 0,
                            B_f_row, B_f_col + p2,
                            B_f_row + m2, B_f_col + p2,
                            m2, p2);
    // P1 = A11 x S1
    strassen_aux_best(P[0], A, (const float *const *const) SB,
                  0, 0,
                  A_f_row, A_f_col,
                  0, 0,
                  n2, m2, p2);
    // S2 = A11 + A12
    sum_matrix_blocks(SA, A, A, 
                            0, 0,
                            A_f_row, A_f_col,
                            A_f_row, A_f_col + m2,
                            n2, m2);
    // P2 = S2 x B22
    strassen_aux_best(P[1], (const float *const *const) SA, B,
                  0, 0,
                  0, 0,
                  B_f_row + m2, B_f_col + p2,
                  n2, m2, p2);
    // S3 = A21 + A22
    sum_matrix_blocks(SA, A, A, 
                            0, 0,
                            A_f_row + n2, A_f_col,
                            A_f_row + n2, A_f_col + m2,
                            n2, m2);
    // P3 = S3 x B11
    strassen_aux_best(P[2], (const float* const* const) SA, B,
                  0, 0,
                  0, 0,
                  B_f_row , B_f_col,
                  n2, m2, p2);
    // S4 = B21 - B11
    sub_matrix_blocks(SB, B, B,
                            0, 0,
                            B_f_row + m2, B_f_col,
                            B_f_row, B_f_col,
                            m2, p2);
    // P4 = A22 x S4
    strassen_aux_best(P[3], A, (const float* const* const) SB,
                           0, 0,
                           A_f_row + n2, A_f_col + m2,
                           0, 0,
                           n2, m2, p2);
    // S5 = A11 + A22
    sum_matrix_blocks(SA, A, A, 
                            0, 0,
                            A_f_row, A_f_col,
                            A_f_row + n2, A_f_col + m2,
                            n2, m2);
    // S6 = B11 + B22
    sum_matrix_blocks(SB, B, B,
                            0, 0,
                            B_f_row, B_f_col,
                            B_f_row + m2, B_f_col + p2,
                            m2, p2);
    // P5 = S5 × S6
    strassen_aux_best(P[4], (const float* const* const) SA,
                       (const float* const* const) SB,
                        0, 0,
                        0, 0,
                        0, 0,
                        n2, m2, p2);
    // S7 = A12 − A22
    sub_matrix_blocks(SA, A, A, 
                            0, 0,
                            A_f_row, A_f_col + m2,
                            A_f_row + n2, A_f_col + m2,
                            n2, m2);
    // S8 = B21 + B22
    sum_matrix_blocks(SB, B, B,
                            0, 0,
                            B_f_row + m2, B_f_col,
                            B_f_row + m2, B_f_col + p2,
                            m2, p2);
    // P6 = S7 x S8
    strassen_aux_best(P[5], (const float* const* const) SA,
                       (const float* const* const) SB,
                        0, 0,
                        0, 0,
                        0, 0,
                        n2, m2, p2);
    // S9 = A11 - A21
    sub_matrix_blocks(SA, A, A,
                            0, 0,
                            A_f_row, A_f_col,
                            A_f_row + n2, A_f_col,
                            n2, m2);
    // S10 = B11 + B12
    sum_matrix_blocks(SB, B, B,
                            0, 0,
                            B_f_row, B_f_col,
                            B_f_row, B_f_col + p2,
                            m2, p2);
    // P7 = S9 x S10
    strassen_aux_best(P[6], (const float* const* const) SA,
                       (const float* const* const) SB,
                        0, 0,
                        0, 0,
                        0, 0,
                        n2, m2, p2);
    // To be continued...

    //C11 = P5 + P4 - P2 + P6
    sum_matrix_blocks(C, (const float* const* const) P[4],
                         (const float* const* const) P[3],
                         C_f_row, C_f_col,
                         0, 0,
                         0, 0,
                         n2, p2);
    sub_matrix_blocks(C, (const float* const* const) C,
                         (const float* const* const) P[1],
                         C_f_row, C_f_col,
                         C_f_row, C_f_col,
                         0, 0,
                         n2, p2);
    sum_matrix_blocks(C, (const float* const* const) C,
                         (const float* const* const) P[5],
                         C_f_row, C_f_col,
                         C_f_row, C_f_col,
                         0, 0,
                         n2, p2);
    //C12 = P1 + P2
    sum_matrix_blocks(C, (const float* const* const) P[0],
                         (const float* const* const) P[1],
                         C_f_row, C_f_col + p2,
                         0, 0,
                         0, 0,
                         n2, p2);
    //C21 = P3 + P4
    sum_matrix_blocks(C, (const float* const* const) P[2],
                         (const float* const* const) P[3],
                         C_f_row + n2, C_f_col,
                         0, 0,
                         0, 0,
                         n2, p2);
    //C22 = P5 + P1 - P3 - P7
    sum_matrix_blocks(C, (const float *const *const) P[4],
                         (const float *const *const) P[0],
                         C_f_row + n2, C_f_col + p2,
                         0, 0,
                         0, 0,
                         n2, p2);
    sub_matrix_blocks(C, (const float *const *const) C,
                         (const float *const *const) P[2],
                         C_f_row + n2, C_f_col + p2,
                         C_f_row + n2, C_f_col + p2,
                         0, 0,
                         n2, p2);
    sub_matrix_blocks(C, (const float *const *const) C,
                         (const float *const *const) P[6],
                         C_f_row + n2, C_f_col + p2,
                         C_f_row + n2, C_f_col + p2,
                         0, 0,
                         n2, p2);

    
    deallocate_matrix(SA, n2);
    deallocate_matrix(SB, m2);
    
    for(size_t i = 0; i < 7; ++i){
        deallocate_matrix(P[i], n2);
    }
    free(P);

}

/**
 * @brief Wrapper function for the function @ref strassen_aux.
 * @param C The matrix where to put the result.
 * @param A The first matrix of the multiplication.
 * @param B The second matrix of the multiplication.
 * @param n The dimension of the matrices.
 * 
 * This functions is exclusively meant to provide an easy to use API.
 */
void strassen_matrix_multiplication_best(float **C, float const *const *const A,
                                    float const *const *const B, size_t n, size_t m, size_t p) 
{
 
    // IMPLEMENT THE STRASSEN'S ALGORITHM HERE
    strassen_aux_best(C, A, B,
                    0, 0,
                    0, 0,
                    0, 0,
                    n, m, p);

 
}

