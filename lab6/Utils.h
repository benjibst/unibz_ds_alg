#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "benchmark.h"
extern uint64_t numComparisons;
extern uint64_t numCopies;

bool less(int x, int y);

bool lessOrEqual(int x, int y);

bool more(int x, int y);

bool moreOrEqual(int x, int y);

void copy(const int *src, int* dst);

void swap(int A[], size_t i, size_t j);

void test(size_t length, void (*f)(int[], size_t));

//copy src[startA...startA+n] into dst
void copyRange(const int *src, size_t n, int *dst);

bool isSorted(const int A[], size_t length);
