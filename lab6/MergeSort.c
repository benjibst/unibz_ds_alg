#include <stdlib.h>
#include "MergeSort.h"
#include "Utils.h"

void merge(int *arr1, const int *arr2, size_t sz1, size_t sz2, int *tmp) {
    size_t cnt1 = 0, cnt2 = 0, cnt = 0;
    while (cnt1 < sz1 && cnt2 < sz2) {
        if (less(arr1[cnt1], arr2[cnt2]))
            copy(arr1+cnt1++,tmp+cnt++);
        else
            copy(arr2+cnt2++,tmp+cnt++);
    }
    for (size_t i = cnt1; i < sz1; ++i,++cnt) {
        copy(arr1+i,tmp+cnt);
    }
    for (size_t i = cnt2; i < sz2; ++i,++cnt) {
        copy(arr2+i,tmp+cnt);
    }
    copyRange(tmp,sz1+sz2,arr1);
}

void merge_sort(int *arr, size_t sz, int *tmp) {
    switch (sz) {
        case 1:
            return;
        case 2:
            if (more(arr[0], arr[1])) swap(arr, 0, 1);
            return;
        default:
            break;
    }
    size_t sz1 = sz / 2;
    size_t sz2 = sz - sz1;
    int *arr1 = arr;
    int *arr2 = arr + sz1;
    merge_sort(arr1, sz1, tmp);
    merge_sort(arr2, sz2, tmp);
    merge(arr1, arr2, sz1, sz2, tmp);
}

void mergeSort(int *src, size_t n) {
    int *tmp = malloc(n * sizeof(int));
    merge_sort(src, n, tmp);
    free(tmp);
}
