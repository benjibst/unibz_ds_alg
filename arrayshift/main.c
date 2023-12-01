#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// findShift auxiliary function
size_t findShift_aux(int *A, size_t l, size_t r) {
  size_t mid_idx = (l + r) / 2;
  if (r - l == 1) {
    return r;
  }
  if (A[mid_idx] > A[r]) {
    return findShift_aux(A, mid_idx, r);
  } else if (A[mid_idx] < A[l]) {
    return findShift_aux(A, l, mid_idx);
  }
  return 0xDEADBEEF;
}

// findShift
size_t findShift(int *A, size_t n) {
  if (A[0] < A[n - 1])
    return 0;
  return findShift_aux(A, 0, n - 1);
}

size_t findShift_naive(const int *const A, size_t n) {
  for (size_t i = 0; i < n - 1; ++i) {
    if (A[i] > A[i + 1])
      return i + 1;
  }
  return 0;
}

void print_array(int A[], int length) {
  if (!length)
    return;
  printf("[%d", A[0]);
  for (int i = 1; i < length; i++) {
    printf(",%d", A[i]);
  }
  printf("]\n");
}

void fill_array_shifted(int *A, size_t n) {
  srand(time(NULL));
  int start_nr = 0;
  size_t shift_idx = rand() % n;
  for (size_t i = shift_idx; i < n; ++i) {
    start_nr += rand() % 3 + 1;
    A[i] = start_nr;
  }
  for (int i = 0; i < shift_idx; ++i) {
    start_nr += rand() % 3 + 1;
    A[i] = start_nr;
  }
}

int maxPossibleGain(int A[], int n) {
  int maxgain = A[n - 1] - A[0];
  for (int i = n - 1; i > 0; --i) {
    if (A[i] > A[i - 1]) {
      for (int j = 0; j < i; ++j) {
        int gain = A[i] - A[j];
        if (gain > maxgain)
          maxgain = gain;
      }
    }
  }
  return maxgain;
}



void compare_algorithms() {
  const int retries = 50;
  printf("%15s%15s%15s\n", "n", "naive t[s]", "smart t[s]");
  size_t n_elements = 1000000000;
  int *arr = malloc(sizeof(int) * n_elements);
  struct timespec time_naive1;
  struct timespec time_naive2;
  struct timespec time1;
  struct timespec time2;
  for (size_t curr_elements = 10; curr_elements <= n_elements;
       curr_elements *= 10) {
    fill_array_shifted(arr, curr_elements);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_naive1);
    for (int i = 0; i < retries; ++i) {
      findShift_naive(arr, curr_elements);
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_naive2);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
    for (int i = 0; i < retries; ++i) {
      findShift(arr, curr_elements);
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
    double time_naive =
        get_time_diff_seconds(time_naive1, time_naive2) / retries;
    double time = get_time_diff_seconds(time1, time2) / retries;
    printf("%15zu%15.10f%15.10f\n", curr_elements, time_naive, time);
  }
  free(arr);
}

int main() {
  compare_algorithms();
  int A[] = {4, 5, 1, 2};
  size_t n = sizeof(A) / sizeof(A[0]);
  size_t shiftIndex_naive = findShift_naive(A, n);
  printf("Shift Index: %d\n", shiftIndex_naive);
  size_t shiftIndex = findShift(A, n);
  printf("Shift Index: %d\n", shiftIndex);

  int B[] = {8, 2, 3, 4, 5, 6, 7, 8};
  int m = sizeof(B) / sizeof(B[0]);
  printf("maxPossibleGain: %d\n", maxPossibleGain(B, m));

  return 0;
}
