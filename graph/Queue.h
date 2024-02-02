#include <stdbool.h>

#define SIZE 10000

typedef struct {
    int head;
    int tail;
    int queue[SIZE];
} Queue;

int next(int n);
void initQueue(Queue *q);
bool isEmptyQueue(Queue *q);
bool isFullQueue(Queue *q);
void enqueue(Queue *q, int x);
int dequeue(Queue *q);
int headQueue(Queue *q);
void printQueue(Queue *q);
