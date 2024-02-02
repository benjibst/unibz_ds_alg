#include <stdio.h>
#include <stdbool.h>
#include "Queue.h"

int next(int n) {
    return (n == SIZE - 1) ? 0 : n + 1;
}

void initQueue(Queue *q) {
    q->head = q->tail = 0;
}

bool isEmptyQueue(Queue *q) {
    return (q->head == q->tail);
}

bool isFullQueue(Queue *q) {
    return (next(q->tail) == q->head);
}

void enqueue(Queue *q, int x) {
    if (!isFullQueue(q)) {
        q->queue[q->tail] = x;
        q->tail = next(q->tail);
    } else {
        printf("Queue is full\n");
    }
}

int dequeue(Queue *q) {
    if (!isEmptyQueue(q)) {
        int t = q->queue[q->head];
        q->head = next(q->head);
        return t;
    } else {
        printf("Queue is empty\n");
        return -1; // Indicate that the queue is empty
    }
}

int headQueue(Queue *q) {
    if (!isEmptyQueue(q)) {
        return q->queue[q->head];
    } else {
        printf("Queue is empty\n");
        return -1; // Indicate that the queue is empty
    }
}

void printQueue(Queue *q) {
    for (int i = q->head; i != q->tail; i = next(i)) {
        printf(" %d ", q->queue[i]);
    }
    printf("\n");
}
