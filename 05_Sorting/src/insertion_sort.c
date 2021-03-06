#include "insertion_sort.h"
#include "swap.h"

void insertion_sort(void *A, const unsigned int n, 
                    const size_t elem_size, 
                    total_order leq)
{
    // Implement insertion sort here
    size_t j;
    for (size_t i = 1; i < n; ++i){
        j = i;
        while((j > 0) && leq(A + j * elem_size, A + (j - 1) * elem_size)){
            swap(A + (j - 1) * elem_size, A + j * elem_size, elem_size);
            j -= 1;
        }
    }
}