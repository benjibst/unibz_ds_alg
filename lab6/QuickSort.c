#include "Utils.h"
#include "QuickSort.h"
#include "InsertionSort.h"
size_t partition(int *A, size_t n) {
    switch (n) {
        case 1:
            return 1;
        case 2:
            if (more(A[0], A[1])) swap(A, 0, 1);
            return 1;
        default: break;
    }
    size_t l = -1;
    size_t r = n;
    int pivot = A[n - 1];
    while (true) {
        while (less(A[++l], pivot)) {}
        while (more(A[--r], pivot)) {}
        if (l < r)
            swap(A, l, r);
        else return l;
    }
}

void quickSort(int* A, size_t n) {
    size_t szl = partition(A,n);
    size_t szr = n-szl;
    if(szl>1)quickSort(A,szl);
    if(szr>1)quickSort(A+szl,szr);
}
