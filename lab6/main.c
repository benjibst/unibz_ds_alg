#include "HeapSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "Utils.h"
#include <stdio.h>

void testAlgorithms(size_t size) {
    printf("\nTESTING ON A RANDOM ARRAY OF SIZE %lu \n", size);

    printf("heapSort:      ");
    test(size, heapSort);
    printf("insertionSort: ");
    test(size, insertionSort);
    printf("selectionSort: ");
    test(size, selectionSort);
    printf("mergeSort:     ");
    test(size, mergeSort);
    printf("quickSort:     ");
    test(size, quickSort);
    printf("\n");
}
int main(void) {
    size_t sz = 1;
    for (int i = 0; i <5; ++i) {
        testAlgorithms(sz);
        sz*=10;
    }
}
