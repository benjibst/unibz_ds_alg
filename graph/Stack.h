#include <stdbool.h>

#define SIZE 10000

typedef struct {
    int count;
    int stack[SIZE];
} Stack;

void initStack(Stack *s);
bool isEmptyStack(Stack *s);
void pushStack(Stack *s, int x);
int popStack(Stack *s);
void printStack(Stack *s);
void revPrintStack(Stack *s);
