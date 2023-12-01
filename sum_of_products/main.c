#include <stdio.h>
#include <array.h>
#include <time.h>

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


// maximal partial sum of an array
int maximalPartialSum(int A[], size_t size) {
    // to fill
}

int sumOfProducts_efficient(const int *const A, size_t n) {
    int sum = 0;
    int sum_of_coeff = 0;
    for (size_t i = 0; i < n - 1; i++) {
        sum_of_coeff += A[i];
        sum += sum_of_coeff * A[i + 1];
    }
    return sum;
}

void compare_algorithms(void) {
    const int retries = 10;
    printf("%15s%15s%15s\n", "n", "old t[s]", "new t[s]");
    struct timespec time_old1;
    struct timespec time_old2;
    struct timespec time1;
    struct timespec time2;
    for (size_t curr_elements = 10; curr_elements <= 100000000; curr_elements *= 10) {
        int* arr = rand_ints(curr_elements);
        if (!arr) break;
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_old1);
        for (int i = 0; i < retries; ++i) {
            sumOfProducts_efficient(arr, curr_elements);
        }
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_old2);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
        for (int i = 0; i < retries; ++i) {
            sumOfProds(arr, curr_elements);
        }
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
        double time_old = get_time_diff_seconds(time_old1, time_old2) / retries;
        double time = get_time_diff_seconds(time1, time2) / retries;
        printf("%15zu%15.10f%15.10f\n", curr_elements, time_old, time);
        free(arr);
    }
}

int main(void) {

    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    size_t size_A = arr_sz(A);
    PairOfInts s_sp = sum_sp(A, 0, size_A);
    printf("Correct: %d\n", sumOfProducts_efficient(A, size_A));
    printf("%d %d\n", s_sp.first, s_sp.second);
    compare_algorithms();

//    int B[] = {4, -5, 6, 7, 8, -10, 5};
//    size_t size_B = arr_sz(B);
//    printf("%d\n", maximalPartialSum(B, size_B));

    return 0;

}
