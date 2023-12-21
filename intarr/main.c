// Look at the instructions and fill the following functions
#include <stdio.h>

void swap(int A[], int i, int j) {
    // To fill
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

int sorted(int A[], int length) {
    // To fill
    for (int i = 0; i < length - 1; i++) {
        if (A[i + 1] < A[i])
            return 0;
    }
    return 1;
}

int maxVal(int A[], int i, int j) {
    // To fill
    int max = A[i];
    for (int k = i + 1; k <= j; k++) {
        if (A[k] > max)
            max = A[k];
    }
    return max;
}

int maxPos(int A[], int i, int j) {
    // To fill
    int max = A[i];
    int maxpos = i;
    for (int k = i + 1; k <= j; k++) {
        if (A[k] > max) {
            maxpos = k;
            max = A[k];
        }
    }
    return maxpos;
}

void reversedCopy(int A[], int B[], int length) {
    for (int i = 0; i < length; i++) {
        B[length - 1 - i] = A[i];
    }
}

void reverse(int A[], int length) {
    for (int i = 0; i < length / 2; i++) {
        swap(A, i, length - 1 - i);
    }
}

int mostFrequentElement(const int *A, size_t length) {
    int maxelement = A[0];
    int maxcnt = 0;
    int cnt = 0;
    for (size_t i = 0; i < length - 1; i++) {
        if (A[i] == maxelement)
            continue; // if by any chance the next element is equal to the one tested
        // before, skip it
        for (size_t j = i + 1; j < length; j++) {
            if (A[j] == A[i])
                cnt++;
        }
        if (cnt > maxcnt) {
            maxelement = A[i];
            maxcnt = cnt;
        }
        cnt = 0;
    }
    return maxelement;
}

// Function to print an array
void print_array(int A[], int length) {
    printf("[");
    for (int i = 0; i < length; i++) {
        printf("%d", A[i]);
        if (i < length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    int A[] = {1, 1, 2, 1, 2};
    int length_A = sizeof(A) / sizeof(A[0]);
    int B[length_A];

    print_array(A, length_A);
    printf("Sorted: %d\n", sorted(A, length_A));
    swap(A, 0, 2);
    print_array(A, length_A);
    printf("Sorted: %d\n", sorted(A, length_A));
    printf("Max val: %d\n", maxVal(A, 0, length_A - 1));
    printf("Max pos: %d\n", maxPos(A, 0, length_A - 1));
    reversedCopy(A, B, length_A);
    print_array(B, length_A);
    reverse(A, length_A);
    print_array(A, length_A);
    printf("Most frequent: %d\n", mostFrequentElement(A, length_A));
    return 0;
}
