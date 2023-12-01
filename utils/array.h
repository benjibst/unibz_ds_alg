#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void print_array(int A[], int length) {
    if (!length)
    {
        printf("[ ]\n");
        return;
    }
    printf("[%d", A[0]);
    for (int i = 1; i < length; i++) {
        printf(",%d", A[i]);
    }
    printf("]\n");
}

int* rand_ints(size_t sz){
    srand(time(NULL));
    int* arr = malloc(sz*sizeof(int));
    if(!arr) return NULL;
    for (int i = 0; i < sz; ++i) {
        arr[i] = rand();
    }
    return arr;
}
double get_time_diff_seconds(struct timespec t1, struct timespec t2) {
    return (double)(t2.tv_sec - t1.tv_sec +
                    (t2.tv_nsec - t1.tv_nsec) / 1000000000.0);
}
#define arr_sz(x)(sizeof(x)/sizeof(x[0]))
