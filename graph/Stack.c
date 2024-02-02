#include <stdio.h>
/* #include <stdbool.h> */
#include "Stack.h"

void initStack(Stack *s) {
    s->count = 0;
}

bool isEmptyStack(Stack *s) {
    return s->count == 0;
}

void pushStack(Stack *s, int x) {
    if (s->count < SIZE) {
        s->stack[s->count++] = x;
    } else {
        // Handle stack overflow
        printf("Stack overflow\n");
    }
}

int popStack(Stack *s) {
    if (!isEmptyStack(s)) {
        return s->stack[--s->count];
    } else {
        // Handle stack underflow
        printf("Stack underflow\n");
        return -1; // Indicate an error
    }
}

void printStack(Stack *s) {
    for (int i = 0; i < s->count; i++) {
        printf("%2d", s->stack[i]);
    }
    printf("\n");
}

void revPrintStack(Stack *s) {
    for (int i = s->count - 1; i >= 0; i--) {
        printf("%2d", s->stack[i]);
    }
    printf("\n");
}

