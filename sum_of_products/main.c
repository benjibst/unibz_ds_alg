#include <stdio.h>
#include <benchmark.h>
#include <time.h>
#include <stdint.h>

// struct for pair of ints
typedef struct {
    int first;
    int second;
} PairOfInts;


// sum of products
int sumOfProds(const int A[], size_t size) {
    int sp = 0;
    int sum_left = 0;
    int sum_right = 0;
    switch (size) {
        case 1:
            return 0;
        case 2:
            return A[0] * A[1];
        default:
            break;
    }
    size_t i = size / 2;
    size_t szright = size - i;
    for (size_t j = 0; j < i; ++j) {
        sum_left += A[j];
    }
    for (size_t j = i; j < size; ++j) {
        sum_right += A[j];
    }
    sp += sum_left * sum_right;
    sp += sumOfProds(A, i);
    sp += sumOfProds(A + i, szright);
    return sp;
}

// given array and a range, returns pair of ints (sum and sp)
PairOfInts sum_sp(const int A[], size_t start, size_t end) {
    PairOfInts sum_sp = {0};
    for (size_t i = start; i < end; ++i) {
        sum_sp.first += A[i];
    }
    sum_sp.second = sumOfProds(A, end - start);
    return sum_sp;
}

int max_2(int l, int r) {
    return r > l ? r : l;
}

int max_3(int l, int m, int r) {
    return max_2(max_2(l, m), r);
}

int max_crossing_sum(int *A, size_t m, size_t sz) {
    int maxsum_l = INT32_MIN;
    int maxsum_r = INT32_MIN;
    int sum_l = 0;
    int sum_r = 0;
    for (size_t i = m; i < SIZE_MAX; --i) {
        sum_l += A[i];
        if (sum_l > maxsum_l)
            maxsum_l = sum_l;
    }
    for (size_t i = m; i < sz; ++i) {
        sum_r += A[i];
        if (sum_r > maxsum_r)
            maxsum_r = sum_r;
    }
    return max_3(maxsum_l, maxsum_r, maxsum_l + maxsum_r - A[m]);
}

int maximalPartialSum(int A[], size_t size) {
    if (size == 1) {
        return *A;
    }
    if (size == 2) {
        return max_3(A[0], A[1], A[0] + A[1]);
    }
    size_t m = size / 2;
    return max_3(maximalPartialSum(A,size/2), maximalPartialSum(A+m,size-m),max_crossing_sum(A,m,size));
}


int main(void) {

    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    size_t size_A = arr_sz(A);
    PairOfInts s_sp = sum_sp(A, 0, size_A);
    printf("%d %d\n", s_sp.first, s_sp.second);

    int B[] = {1,-2,3};
    size_t size_B = sizeof(B)/sizeof(*B);
    printf("%d\n", maximalPartialSum(B, size_B));

    return 0;

}
