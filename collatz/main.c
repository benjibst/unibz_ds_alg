#include <stdio.h>
#include <string.h>

// collatz auxiliary function (optional)
int collatz_aux(int n, int steps_so_far) {
  if (n == 1)
    return steps_so_far;
  else if (n & 1)
    return collatz_aux(n * 3 + 1, ++steps_so_far);
  else
    return collatz_aux(n / 2, ++steps_so_far);
}

// collatz (recursive)
int collatz(int n) { return collatz_aux(n, 0); }

// collatz (iterative)
int collatz_iter(int n) {
  int cnt = 0;
  while (n != 1) {
    if (n & 1) {
      n = n * 3 + 1;
    } else {
      n = n / 2;
    }
    cnt++;
  }
  return cnt;
}

int cmp_lt(long long len1, long long len2) { return len1 < len2; }

int cmp_gt(long long len1, long long len2) { return len1 > len2; }

long long strlen_compat(void *d) {
  char *str = *(char **)d;
  return (long long)strlen(str);
}
long long int_compat(void *d) {
  int data = *(int *)d;
  return data;
}

void selection_sort(void *data, size_t n_items, size_t item_sz,
                    long long (*val_item)(void *),
                    int (*cmp)(long long, long long)) {
  long long item_vals[n_items];
  for (size_t i = 0; i < n_items; i++) {
    item_vals[i] = val_item(data + i * item_sz);
  }
  for (size_t i = 0; i < n_items - 1; i++) {
    size_t min_val_idx = i;
    long long min_val = item_vals[i];
    for (size_t j = i + 1; j < n_items; j++) {
      long long val_j = item_vals[j];
      if (cmp(val_j, min_val)) {
        min_val_idx = j;
        min_val = item_vals[j];
      }
    }
    // swap values
    long long val_tmp = item_vals[i];
    item_vals[i] = item_vals[min_val_idx];
    item_vals[min_val_idx] = val_tmp;
    // swap items with variable size
    void *i_ptr = data + i * item_sz;
    void *min_ptr = data + min_val_idx * item_sz;
    char tmp[item_sz];
    memcpy(tmp, i_ptr, item_sz);
    memcpy(i_ptr, min_ptr, item_sz);
    memcpy(min_ptr, tmp, item_sz);
  }
}

void insertion_sort(void *data, size_t n_items, size_t item_sz,
                    long long (*val_item)(void *),
                    int (*cmp)(long long, long long)) {
  long long item_vals[n_items];
  for (size_t i = 0; i < n_items; i++) {
    item_vals[i] = val_item(data + i * item_sz);
  }
  for (long long i = 1; i < n_items; i++) {
    long long val = item_vals[i];
    char tmp[item_sz];
    memcpy(tmp, data + i * item_sz, item_sz);
    long long j;
    for (j = 0; j < i && cmp(item_vals[j], val); j++) {
    }
    if (j != i) {
      memmove(data + (j + 1) * item_sz, data + j * item_sz, (i - j) * item_sz);
      memcpy(data + j * item_sz, tmp, item_sz);
      memmove(item_vals + j + 1, item_vals + j, (i - j) * sizeof(long long));
      item_vals[j] = val;
    }
  }
}

void selectionSort(char *A[], size_t n) {
  selection_sort(A, n, sizeof(A[0]), &strlen_compat, &cmp_lt);
}

void selectionSortInverse(char *A[], int n) {
  selection_sort(A, n, sizeof(A[0]), &strlen_compat, &cmp_gt);
}

// insertion sort algorithm (increasing strings)
void insertionSort(char *A[], int n) {
  insertion_sort(A, n, sizeof(A[0]), &strlen_compat, &cmp_lt);
}
void insertionSort_ints(int *A, int n) {
  insertion_sort(A, n, sizeof(A[0]), &int_compat, &cmp_lt);
}

// insertion sort algorithm (decreasing strings)
void insertionSortInverse(char *A[], int n) {
  insertion_sort(A, n, sizeof(A[0]), &strlen_compat, &cmp_gt);
}

// binary search

// binary search auxiliary function (optional)
int binSearch_aux(int A[], int q, int l, int r) {
  int mid = (l + r) >> 1;
  if (A[mid] == q)
    return mid;
  if (A[mid] < q) {
    l = mid + 1;
  } else {
    r = mid - 1;
  }
  if (l == r && A[l] != q)
    return -1;
  return binSearch_aux(A, q, l, r);
}

int binSearch(int A[], int q, int n) { return binSearch_aux(A, q, 0, n - 1); }
// binary search (iterative)
int binSearch_iter(int A[], int q, int n) {
  int l = 0;
  int r = n - 1;
  while (l != r) {
    int mid = (l + r) >> 1;
    if (A[mid] == q) {
      return mid;
    }
    if (A[mid] < q)
      l = mid + 1;
    else
      r = mid - 1;
  }
  if (A[l] == q)
    return l;
  return -1;
}

void print_int_array(int A[], int length) {
  printf("[");
  for (int i = 0; i < length; i++) {
    printf("%d", A[i]);
    if (i < length - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}
// function to print arrays
void print_array(char *A[], int n) {
  printf("[");
  for (int i = 0; i < n; i++) {
    printf("%s", A[i]);
    if (i < n - 1)
      printf(", ");
  }
  printf("]\n");
}

int main() {
  int a[] = {3, 1, 3, 2};
  insertionSort_ints(a, sizeof(a) / sizeof(a[0]));
  print_int_array(a, sizeof(a) / sizeof(a[0]));
  /*printf("%d\n", collatz(2));
  printf("%d\n", collatz(10));
  printf("%d\n", collatz_iter(3));
  printf("%d\n", collatz_iter(5));*/

  char *A[] = {"aaa", "bc", "cdefg", "t", "asdasdasd", "asd", "asaa"};
  size_t nA = sizeof(A) / sizeof(A[0]);
  printf("A = ");
  print_array(A, nA);
  selectionSort(A, nA);
  printf("Sel sort A = ");
  print_array(A, nA);
  char *C[] = {"aaa", "bc", "cdefg", "t", "asdasdasd", "asaa", "t"};
  int nC = sizeof(C) / sizeof(C[0]);
  printf("C = ");
  print_array(C, nC);
  selectionSortInverse(C, nC);
  printf("Sel sort Inverse C = ");
  print_array(C, nC);

  char *B[] = {"bc",         "cdefg", "t",
               "aaaaaaaaaa", "aaaaa", "asdasdasdasdsdasdasd",
               "aaa",        "aa"};
  int nB = sizeof(B) / sizeof(B[0]);
  printf("B = ");
  print_array(B, nB);
  insertionSort(B, nB);
  printf("Insert sort B = ");
  print_array(B, nB);

  char *D[] = {"a", "aaa", "aa", "aaaa", "aaaaa", "a", "aaaaaa", "aa"};
  int nD = sizeof(D) / sizeof(D[0]);
  printf("D = ");
  print_array(D, nD);
  insertionSortInverse(D, nD);
  printf("Insert sort inverse D = ");
  print_array(D, nD);

  int X[] = {1, 2, 8, 18, 22, 30};
  int nX = sizeof(X) / sizeof(X[0]);
  printf("%d\n", binSearch(X, 2, nX));
  printf("%d\n", binSearch(X, 22, nX));
  printf("%d\n", binSearch(X, 3, nX));
  printf("%d\n", binSearch_iter(X, 2, nX));
  printf("%d\n", binSearch_iter(X, 22, nX));
  printf("%d\n", binSearch_iter(X, 3, nX));
  return 0;
}
