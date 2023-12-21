#include "InsertionSort.h"
#include "Utils.h"
#include <string.h>
// Function to perform the insertion sort algorithm
void insertionSort(int *A, size_t n_items) {
    for (size_t i = 1; i < n_items; i++) {
        size_t j;
        for (j = 0; j < i && less(A[j],A[i]); j++) {
        }
        int tmp;
        if (j != i) {
            copy(A+i,&tmp);
            copyRange(A+j, i-j, A+j+1);
            copy(&tmp,A+j);
        }
    }
}
