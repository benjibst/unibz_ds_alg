#include "Utils.h"
#include <stdio.h>
#include <stdlib.h>
#include "benchmark.h"

uint64_t numComparisons = 0;
uint64_t numCopies = 0;

bool less(int x, int y) {
    numComparisons++;
    return x < y;
}

bool lessOrEqual(int x, int y) {
    numComparisons++;
    return x <= y;
}

bool more(int x, int y) {
    numComparisons++;
    return x > y;
}

bool moreOrEqual(int x, int y) {
    numComparisons++;
    return x >= y;
}

void copy(const int *src, int* dst){
    numCopies++;
    *dst=*src;
}

void swap(int A[], size_t i, size_t j) {
    numCopies += 2;
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void copyRange(const int *src, size_t n, int *dst) {
    numCopies += n;
    if(dst > src){
        for (size_t i = 0; i < n; i++) {
            dst[n - 1 - i] = src[n - 1 - i];
        }
    }else{
        for (size_t i = 0; i < n; ++i) {
            dst[i]=src[i];
        }
    }

}

bool isSorted(const int *A, size_t length) {
    for (size_t i = 0; i < length - 1; i++) {
        if (A[i] > A[i + 1]) {
            return false;
        }
    }
    return true;
}

void test(size_t length, void (*alg)(int[], size_t)) {
    numComparisons = 0;
    numCopies = 0;
    int *A = rand_ints(length);

    double elapsed = measure_exec_time_intarr(alg,A,length);
    uint64_t n_comp = numComparisons;
    uint64_t n_copy = numCopies;

    if (!isSorted(A, length)) {
        printf("ERROR - array is not sorted\n");
    } else {
        printf("Time: %fs", elapsed);
        printf(", %ld comparisons", n_comp);
        printf(", %ld copies\n", n_copy);
    }
    free(A);
}



