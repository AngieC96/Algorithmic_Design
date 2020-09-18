#include "select.h"


unsigned int select_index(void *A, const int l, const int r, 
                          const unsigned int i,
                          const size_t elem_size, 
                          total_order leq)
{
    if((l - r) <= 10) {
        quick_sort_aux(A, l, r, elem_size, leq);
        return i;
    }

    int j = select_pivot(A, l, r, elem_size, leq);
    int* k = select_partition(A, l, r, j, elem_size, leq);

    if (i >= k[0] && i <= k[1]) return k[0];

    if (i < k[0]) {
        return select_index(A, l, k[0] - 1, i, elem_size, leq);
    }
    
    return select_index(A, k[1] + 1, r, i, elem_size, leq);
}

unsigned int select_pivot(void *A, const int l, const int r,
                          const size_t elem_size, 
                          total_order leq)
{
    if((r - l) <= 10){
        quick_sort_aux(A, l, r, elem_size, leq);
        return (l+r)/2;
    }
    
    int chunks = (r - l) / 5;
    for(size_t c = 0; c < chunks - 1; ++c){
        int cl = c * 5;
        int cr = 5 + c * 5;
        quick_sort_aux(A, cl, cr, elem_size, leq);
        swap(A + (cl + 2) * elem_size, A + (l + c) * elem_size, elem_size);
    }

    return select_index(A, l, l + chunks - 1, chunks/2, elem_size, leq);
}

int* select_partition(void *A, const int l, const int r, const int p, 
                const size_t elem_size, total_order leq)
{   
    // Switch the pivot p and the first element in A:
    swap(A + l * elem_size, A + p * elem_size, elem_size);
    unsigned int i = l + 1, j = r, p1 = l;
    while (i <= j){
        if (!leq(A + i * elem_size, A + p1 * elem_size)){
            swap(A + i * elem_size, A + j * elem_size, elem_size);
            --j;
        } else if (!leq(A + p1 * elem_size, A + i * elem_size)) {
            ++i;
        } else {
            ++p1;
            swap(A + i * elem_size, A + p1 * elem_size, elem_size);
            ++i;
        }
    }
    for (size_t h = l; h <= p1; ++h) {
        swap(A + h * elem_size, A + j * elem_size, elem_size);
        --j;
    }

    int *pivots=(int *)malloc(sizeof(int)*2);
    pivots[0] = j + 1;
    pivots[1] = i - 1;
    
    return pivots;
}

void quick_sort_select(void *A, const unsigned int n, 
                       const size_t elem_size, 
                       total_order leq)
{
   // This function must be implemented
   quick_sort_select_aux(A, 0, n - 1, elem_size, leq);
}

void quick_sort_select_aux(void *A, const int l, const int r, 
                const size_t elem_size, total_order leq)
{
    int p; int* k;

    if (l < r){
        p = select_index(A, l, r, (l+r)/2, elem_size, leq);
        k = select_partition(A, l, r, p, elem_size, leq);
        quick_sort_select_aux(A, l, k[0] - 1, elem_size, leq);
        quick_sort_select_aux(A, k[1] + 1, r, elem_size, leq);
        free(k);
    }
}
