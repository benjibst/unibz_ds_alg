#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LEFT(x) (2 * (x) + 1)
#define RIGHT(x) (2 * (x) + 2)
#define PARENT(x) ((x - 1) / 2)

// priority que structure
struct PQ {
    int maxSize;
    int currentSize;
    int *queue;
};

// function to initialize a priority queue
struct PQ *createPQ(int maxSize) {
    struct PQ *pq = malloc(sizeof(struct PQ));
    if (!pq)
        return NULL;
    pq->maxSize = maxSize;
    pq->queue = (int *)malloc(maxSize * sizeof(int));
    pq->currentSize = 0;

    return pq;
}

// print a priority queue
void print(struct PQ *pq) {
    int curr_lvl_width = 1;
    int next_level_last_idx = 1;
    int cnt = 0;
    while (cnt < pq->currentSize) {
        if (cnt == next_level_last_idx) {
            curr_lvl_width *= 2;
            next_level_last_idx += curr_lvl_width;
            printf("\n");
            continue;
        }
        printf("%d ", pq->queue[cnt++]);
    }
    printf("\n\n");
}

// swap
void swap(int *A, int i, int j) {
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

// heapify
void heapify(struct PQ *pq, int i) {
    int l = LEFT(i);
    int r = RIGHT(i);
    int maxidx = i;
    if (l < pq->currentSize && pq->queue[l] > pq->queue[maxidx])
        maxidx = l;
    if (r < pq->currentSize && pq->queue[r] > pq->queue[maxidx])
        maxidx = r;
    if (maxidx != i) {
        swap(pq->queue, maxidx, i);
        heapify(pq, maxidx);
    }
}

// extendHeap
void extendHeap(struct PQ *pq, int i) {
    int parent = (i - 1) / 2;
    if (parent >= 0 && pq->queue[parent] < pq->queue[i]) {
        swap(pq->queue, parent, i);
        extendHeap(pq, parent);
    }
}

// check if queue is empty
bool isEmpty(struct PQ *pq) { return !pq->currentSize; }

// check if queue is full
bool isFull(struct PQ *pq) { return pq->currentSize == pq->maxSize; }

// extract maximum in the heap
int extractMax(struct PQ *pq) {
    if (isEmpty(pq)) {
        fputs("Extracting from empty heap", stderr);
        exit(-1);
    }
    if (pq->currentSize == 1) {
        pq->currentSize--;
        return pq->queue[0];
    }
    int max = pq->queue[0];
    pq->queue[0] = pq->queue[pq->currentSize - 1];
    pq->currentSize--;
    heapify(pq, 0);
    return max;
}

// insert new element in the heap, it stops when the heap is full
bool insert(struct PQ *pq, int n) {
    if (isFull(pq)) {
        int newsz = 2 * pq->maxSize + 1;
        int *new = realloc(pq->queue, sizeof(int) * newsz);
        if (new) {
            pq->maxSize = newsz;
            pq->queue = new;
        } else {
            fputs("Failed reallocating queue", stderr);
            exit(-1);
        }
    }
    pq->queue[pq->currentSize] = n;
    extendHeap(pq, pq->currentSize);
    pq->currentSize++;
    return true;
}

int main(void) {
    struct PQ *pq = createPQ(0);
    int prios[] = {3, 2, 1, 2, 3, 4, 5, 6, 2, 1, 7, 8, 1, 2, 4, 6, 3, 23, 1, 6};
    for (size_t i = 0; i < sizeof(prios) / sizeof(prios[0]); ++i) {
        insert(pq, prios[i]);
    }
    print(pq);
    for (size_t i = 0; i < sizeof(prios) / sizeof(prios[0]); ++i) {
        printf("Max element after extraction: %d\n", extractMax(pq));
        print(pq);
    }
    free(pq->queue);
    return 0;
}
