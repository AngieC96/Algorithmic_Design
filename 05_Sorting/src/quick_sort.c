#include "quick_sort.h"
#include "swap.h"

void quick_sort(void *A, const unsigned int n, 
                const size_t elem_size, 
                total_order leq)
{
    // Implement quick sort here
    quick_sort_aux(A, 0, n - 1, elem_size, leq);
}

void quick_sort_aux(void *A, const int l, const int r, 
                const size_t elem_size, total_order leq)
{
    int p; //, l1 = l, r1 = r;
    //while (l1 < r1){
    //    p = partition(A, l1, r1, l1, elem_size, leq);
    //    quick_sort_aux(A, l1, p - 1, elem_size, leq);
    //    l1 = p + 1;
    //}

    if (l < r){
        p = partition(A, l, r, l, elem_size, leq);
        quick_sort_aux(A, l, p - 1, elem_size, leq);
        quick_sort_aux(A, p + 1, r, elem_size, leq);
    }
}

int partition(void *A, const int l, const int r, const int p, 
                const size_t elem_size, total_order leq)
{   
    // Switch the pivot p and the first element in A:
    // swap(A + l * elem_size, A + p * elem_size, elem_size); // I already pass the first element
    unsigned int i = l + 1, j = r;
    while (i <= j){
        if (!leq(A + i * elem_size, A + p * elem_size)){
            swap(A + i * elem_size, A + j * elem_size, elem_size);
            --j;
        } else {
            ++i;
        }
    }
    swap(A + l * elem_size, A + j * elem_size, elem_size);
    return j;
}