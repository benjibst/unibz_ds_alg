#include <stddef.h>
#include <stdio.h>

typedef struct listnode {
    struct listnode *next;
} ListNode;

typedef struct {
    ListNode *head;
    ListNode *tail;
    size_t data_sz;
    size_t node_cnt;
} LinkedList;

void InitList(LinkedList *list, size_t data_sz);

int Append(LinkedList *list, void *data);

int InsertAt(LinkedList *list, size_t index, void *data);

int Prepend(LinkedList *list, void *data);

int ReadAt(LinkedList *list, size_t index, void *out);

void *ViewAt(LinkedList *list, size_t index);

int RemoveAt(LinkedList *list, size_t index);

void FreeList(LinkedList *list);

void PrintList(LinkedList *list, void (*print_fn)(const void *));




