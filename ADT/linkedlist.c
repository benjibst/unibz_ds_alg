#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

LinkedList NewList(size_t data_sz)
{
    return (LinkedList) {.node_cnt = 0, .head = NULL, .tail = NULL, .elem_sz = data_sz};
}

#define DATA_AT_NODE(x)((x)+1)
ListNode *NewNode(void *data, size_t data_sz)
{
    //data will be stored after ListNode in memory
    //layout for a ListNode:
    // ... [pointer to next][{elem_sz} bytes of memory for the data] ...
    //to avoid storing unnecessary pointers
    ListNode *new = malloc(sizeof(ListNode) + data_sz);
    if (!new) {
        fputs("Failed allocating node", stderr);
        return NULL;
    }
    new->next = NULL;
    memcpy(DATA_AT_NODE(new), data, data_sz);
    return new;
}

int Append(LinkedList *list, void *data)
{
    return InsertAt(list, list->node_cnt, data);
}

int Prepend(LinkedList *list, void *data)
{
    return InsertAt(list, 0, data);
}

ListNode *GetNodeAt(LinkedList *list, size_t index)
{
    if (index >= list->node_cnt) {
        fputs("Read access out of bounds", stderr);
        return NULL;
    }
    ListNode *curr = list->head;
    for (size_t i = 0; i < index; ++i) curr = curr->next;
    return curr;
}

int InsertAt(LinkedList *list, size_t index, void *data)
{
    if (index > list->node_cnt) {
        fputs("Write access out of bounds", stderr);
        return 1;
    };
    ListNode *new = NewNode(data, list->elem_sz);
    if (!new) return -1;
    if(!list->node_cnt){
        list->head = new;
        list->tail = new;
    }
    else if(!index){
        new->next = list->head;
        list->head = new;
    }
    else if (index == list->node_cnt) {
        list->tail->next = new;
        list->tail = new;
    }  else {
        ListNode *l = GetNodeAt(list,index-1);
        ListNode *r = l->next;
        new->next = r;
        l->next = new;
    }
    list->node_cnt++;
    return 0;
}



void* ViewAt(LinkedList *list, size_t index)
{
    ListNode *node = GetNodeAt(list,index);
    if(!node) return NULL;
    return DATA_AT_NODE(node);
}

int ReadAt(LinkedList* list,size_t index,void* out){
    ListNode *node = GetNodeAt(list,index);
    if(!node) return 1;
    memcpy(DATA_AT_NODE(node),out,list->elem_sz);
    return 0;
}


int RemoveAt(LinkedList *list, size_t index)
{
    if(!list->node_cnt){
        fputs("Remove access out of bounds",stderr);
        return 1;
    }
    ListNode *removee;
    if (!index) {
        removee = list->head;
        list->head = removee->next;
        goto finally;
    }
    ListNode *left = GetNodeAt(list, index - 1);
    if(!left) return 1;
    if (index == list->node_cnt - 1) {
        removee = list->tail;
        left->next = NULL;
        list->tail = left;
    } else {
        removee = left->next;
        ListNode *right = removee->next;
        left->next = right;
    }
    finally:
    free(removee);
    list->node_cnt--;
    return 0;
}


void PrintList(LinkedList *list, void (*print_fn)(const void *))
{
    ListNode *curr = list->head;
    while (curr) {
        (*print_fn)(DATA_AT_NODE(curr));
        printf(" -> ");
        curr = curr->next;
    }
    printf("\n");
}

void FreeList(LinkedList* list){
    ListNode *curr = list->head;
    ListNode *next;
    while (curr){
        next = curr->next;
        free(curr);
        curr = next;
    }
    list->node_cnt = 0;
    list->head = NULL;
    list->tail = NULL;
}

