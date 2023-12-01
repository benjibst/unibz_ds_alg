#include <array.h>

void merge(int *arr1, int *arr2, size_t sz1, size_t sz2, int *dst) {
    size_t cnt1 = 0, cnt2 = 0, cnt = 0;
    while (cnt1 < sz1 && cnt2 < sz2) {
        if (arr1[cnt1] < arr2[cnt2])
            dst[cnt++] = arr1[cnt1++];
        else
            dst[cnt++] = arr2[cnt2++];
    }
    for (size_t i = cnt1; i < sz1; ++i) {
        dst[cnt++] = arr1[i];
    }
    for (size_t i = cnt2; i < sz2; ++i) {
        dst[cnt++] = arr2[i];
    }
}

void merge_sort(int *src, int *dst, size_t n) {
    switch (n) {
        case 1:
            *dst = *src;
            return;
        case 2:
            if(src[0]<=src[1]){
                dst[0]=src[0];
                dst[1]=src[1];
            }else{
                dst[1]=src[0];
                dst[0]=src[1];
            }
            return;
        default:
            break;
    }
    int *arr1 = src;
    int *arr2 = src + n / 2;
    merge_sort(arr1, dst, n / 2);
    merge_sort(arr2,dst+n/2,(n+1)/2);
    merge(dst,dst+n/2,n/2,(n+1)/2,arr1);
}

int main(void) {
    int A[] = {};
    int B[arr_sz(A)];
    merge_sort(A,B, arr_sz(A));
    print_array(A, arr_sz(A));
}
