#include <stdio.h>

// Function to print an array
void print_array(int A[], int length) {
  if (!length)
    return;
  printf("[%d", A[0]);
  for (int i = 1; i < length; i++) {
    printf(",%d", A[i]);
  }
  printf("]\n");
}

// swap function
void swap(int A[], int i, int j) {
  int tmp = A[i];
  A[i] = A[j];
  A[j] = tmp;
}

// split straightforward
void splitInEvenAndOdds(int *A,
                        int n) { // worst case: (number of even elements) swaps
  int maxidx = n;
  for (int i = 0; i < maxidx - 1; i++) {
    if (A[i] & 1) { // if odd
      for (int j = maxidx - 1; j > i;
           j--) // start from the back and look for the first even element
      {
        if (!(A[j] & 1)) { // if even
          swap(A, i, j);
          maxidx = j; // all elements behind j are odd
          break;
        }
      }
    }
  }
}

// strightforward approach
int sumOfProducts(const int *const A, int n) {
  int sum = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      sum += A[i] * A[j];
    }
  }
  return sum;
}
// 1 2 3 = 1*2 + 1*3 + 2*3
// diag = 1 4 9
//
//
//
//
//
//
//

int sumOfProducts_efficient(const int *const A, int n) {
  int sum = 0;
  int sum_of_coeff = 0;
  for (int i = 0; i < n - 1; i++) {
    sum_of_coeff += A[i];
    sum += sum_of_coeff * A[i + 1];
  }
  return sum;
}

int sumOfProducts_3(const int *const A, int n) {
  int sum_elem = 0;
  int sum_diag = 0;
  for (int i = 0; i < n; i++) {
    sum_diag += A[i] * A[i];
    sum_elem += A[i];
  }

  return (sum_elem * sum_elem - sum_diag) / 2;
}

int main() {
  int A[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  int n = sizeof(A) / sizeof(A[0]);

  printf("Original Array: ");
  print_array(A, n);

  splitInEvenAndOdds(A, n);
  printf("Split In Even And Odds: ");
  print_array(A, n);

  printf("Sum of products: %d\n", sumOfProducts(A, n));

  printf("Sum of products eff: %d\n", sumOfProducts_3(A, n));

  return 0;
}
