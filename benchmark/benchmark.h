#ifndef BENCHMARK_H_
#define BENCHMARK_H_

#include <time.h>
#include <stddef.h>

#define arr_sz(x)(sizeof(x)/sizeof(x[0]))
void print_array(int *A, size_t length);
double measure_exec_time_intarr(void (*alg)(int*, size_t), int* arr, size_t n);
int* rand_ints(size_t sz);
double time_diff_secs(struct timespec *start, struct timespec *stop);

#endif
