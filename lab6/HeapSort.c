#include <stdio.h>
#include "HeapSort.h"
#include "Utils.h"

#define LEFT(x)(2*(x)+1)
#define RIGHT(x)(2*(x)+2)
#define PARENT(x)((x+1)/2-1)
void heapify(int* A,size_t i,size_t n){
    size_t l = LEFT(i);
    size_t r = RIGHT(i);
    size_t max_idx = i;
    if(l<n&&A[l]>A[max_idx]) max_idx = l;
    if(r<n&&A[r]>A[max_idx]) max_idx = r;
    if(max_idx!=i){
        swap(A,max_idx,i);
        heapify(A,max_idx,n);
    }
}
void buildHeap(int* A,size_t n)
{
    for (size_t i = PARENT(n-1); i != SIZE_MAX; --i) {
        heapify(A,i,n);
    }
}
void heapSort(int *A, size_t n) {
    buildHeap(A,n);
    for (size_t i = n-1; i>0; --i) {
        swap(A,0,i);
        heapify(A,0,i);
    }
}

