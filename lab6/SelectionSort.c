#include "SelectionSort.h"
#include "Utils.h"

void selectionSort(int *A, size_t n) {
    for (size_t i = 0; i < n - 1; ++i) {
        int minval = A[i];
        size_t minidx = i;
        for (size_t j = i + 1; j < n; ++j) {
            if (less(A[j], minval)) {
                minval = A[j];
                minidx = j;
            }
        }
        swap(A, i, minidx);
    }
}

