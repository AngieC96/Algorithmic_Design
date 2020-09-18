#include <stdio.h>

#include "insertion_sort.h"
#include "quick_sort.h"
#include "select.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "heap_sort.h"
#include "total_order.h"
#include "utilities.h"

#define MAX_SIZE_ALL (1<<18) //13
#define MAX_SIZE_NLOGN (1<<20)
#define ARRAY_SIZE (1<<23)

#define NUM_OF_REPETITIONS 5//15

void test_and_print(void (*sort)(void *A, const unsigned int n, 
                         const size_t elem_size, 
                         total_order leq), 
                    const void *A, const unsigned int n, 
                    const size_t elem_size, total_order leq, 
                    const unsigned int rep)
{
    int sorted;

    printf("\t%lf",test(sort,A,n,elem_size,leq,rep,&sorted));
    if (!sorted) {
        printf(" (KO)");
    }
    fflush(stdout);
}


int main(int argc, char *argv[])
{
    // int n = 24;
    // //int *A=get_random_int_array(n);
    // int *A=malloc(sizeof(int)*n);
    // A[0] = -2; A[1] = 2; A[2] = 5; A[3] = 7; A[4] = 13; A[5] = 0; A[6] = 2; A[7] = 4; A[8] = 6; A[9] = 13; A[10] = -2; A[11] = -1; A[12] = 8; A[13] = 10; A[14] = 15; A[15] = -9; A[16] = -5; A[17] = 4; A[18] = 12; A[19] = 14; A[20] = -6; A[21] = -2; A[22] = 8; A[23] = 16;
    // printf("BEFORE:");
    // for(size_t i = 0; i < n; ++i){
    //     printf("\n%d", A[i]);
    // }
    // //int* k = select_partition(A, 0, n-1, 12, sizeof(int), leq_int);
    // //printf("\n\nPivot: %d\n", A[k[0]]);
    // int m = select_index(A, 0, n-1, n/2, sizeof(int), leq_int);
    // printf("\nMedian: %d\n", A[m]);
    // printf("\nAFTER:");
    // for(size_t i = 0; i < n; ++i){
    //     printf("\n%d", A[i]);
    // }
    // printf("\n");


    int *A=get_random_int_array(ARRAY_SIZE);
    int *A_sorted=malloc(sizeof(int)*ARRAY_SIZE);
    int *A_rev_sorted=malloc(sizeof(int)*ARRAY_SIZE);

    for (unsigned int i=0; i<ARRAY_SIZE; i++) {
        A_sorted[i]=i;
        A_rev_sorted[i]=ARRAY_SIZE-i;
    }

    unsigned int i;
    printf("Size\tInsertion Sort\t          \t        \n");
    // printf("    \t(Random Case)\t(Best Case)\t(Worst Case)");
    // for (i=2; (1<<i)<=MAX_SIZE_ALL; i++) {
    //     const unsigned int A_size=1<<i;
    //     printf("\n2^%d",i);
    //     test_and_print(insertion_sort, A,
    //                    A_size, sizeof(int),
    //                    leq_int, NUM_OF_REPETITIONS);
    //     test_and_print(insertion_sort, A_sorted,
    //                    A_size, sizeof(int),
    //                    leq_int, NUM_OF_REPETITIONS);
    //     test_and_print(insertion_sort, A_rev_sorted,
    //                    A_size, sizeof(int),
    //                    leq_int, NUM_OF_REPETITIONS);
    // }
    // printf("\n\n\n");

    printf("Size\tQuick Sort\t           \tQuick Sort + Select\n");
    printf("    \t(Random Case)\t(Worst Case)\t(Random Case)\t(Worst Case)");
    for (i=2; (1<<i)<=MAX_SIZE_ALL; i++) {
        const unsigned int A_size=1<<i;
        printf("\n2^%d",i);
        test_and_print(quick_sort, A,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
        test_and_print(quick_sort, A_sorted,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
        test_and_print(quick_sort_select, A,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
        test_and_print(quick_sort_select, A_sorted,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
    }
    printf("\n\n\n");

    // printf("Size\tInsertion Sort\tQuick Sort\tBubble Sort\tSelection Sort\tHeap Sort\n");
    // printf("    \t(Random Case)\t(Random Case)\t\t\t");
    // for (i=2; (1<<i)<=MAX_SIZE_ALL; i++) {
    //     const unsigned int A_size=1<<i;
    //     printf("\n2^%d",i);
    //     test_and_print(insertion_sort, A,
    //                    A_size, sizeof(int),
    //                    leq_int, NUM_OF_REPETITIONS);
    //     test_and_print(quick_sort, A,
    //                    A_size, sizeof(int),
    //                    leq_int, NUM_OF_REPETITIONS);
    //     test_and_print(bubble_sort, A,
    //                    A_size, sizeof(int),
    //                    leq_int, NUM_OF_REPETITIONS);
    //     test_and_print(selection_sort, A,
    //                    A_size, sizeof(int),
    //                    leq_int, NUM_OF_REPETITIONS);
    //     test_and_print(heap_sort, A,
    //                    A_size, sizeof(int),
    //                    leq_int, NUM_OF_REPETITIONS);
    // }
    // printf("\n\n\n");
    // printf("Size\tQuick Sort\tQuick Sort +\tHeap Sort\n");
    // printf("    \t          \t  Select\n");
    // printf("    \t(Random Case)\t(Random Case)\t");
    // for (; (1<<i)<=MAX_SIZE_NLOGN; i++) {
    //     const unsigned int A_size=1<<i;
    //     printf("\n2^%d",i);
    //     test_and_print(quick_sort, A,
    //                    A_size, sizeof(int),
    //                    leq_int, NUM_OF_REPETITIONS);
    //     test_and_print(quick_sort_select, A,
    //                    A_size, sizeof(int),
    //                    leq_int, NUM_OF_REPETITIONS);
    //     test_and_print(heap_sort, A,
    //                    A_size, sizeof(int),
    //                    leq_int, NUM_OF_REPETITIONS);
    // }

    printf("\n");

    free(A);
    free(A_sorted);
    free(A_rev_sorted);

    return 0;
}