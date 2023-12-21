#include "benchmark.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void print_array(int *A, size_t length) {
    if (!length)
    {
        printf("[ ]\n");
        return;
    }
    printf("[%d", A[0]);
    for (size_t i = 1; i < length; i++) {
        printf(",%d", A[i]);
    }
    printf("]\n");
}
int* rand_ints(size_t sz){
    static bool rand_init = 0;
    if(!rand_init){
        srand(time(NULL));
        rand_init = true;
    }
    int* arr = malloc(sz*sizeof(int));
    if(!arr) return NULL;
    for (size_t i = 0; i < sz; ++i) {
        arr[i] = rand()%(2*sz);
    }
    return arr;
}
double time_diff_secs(struct timespec *start, struct timespec *stop) {
    long int second_diff = stop->tv_sec-start->tv_sec;
    long int nanos_diff = stop->tv_nsec-start->tv_nsec;
    if(nanos_diff<0){
        second_diff--;
        nanos_diff+=1000000000L;
    }
    return (double)(second_diff*1000000000L+nanos_diff)/1000000000.0;
}
double measure_exec_time_intarr(void (*alg)(int*, size_t), int* arr, size_t n){
    struct timespec t1;
    struct timespec t2;
    clock_gettime(CLOCK_THREAD_CPUTIME_ID,&t1);
    (*alg)(arr, n);
    clock_gettime(CLOCK_THREAD_CPUTIME_ID,&t2);
    return time_diff_secs(&t1,&t2);
}

