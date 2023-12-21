#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct List {
    LinkedList l;
};

// add node as head
void addAsHead(struct List *list, int i)
{
    InsertAt(&list->l, 0, i);
}

void toList_aux(const int *A, int remaining, ListNode *node)
{
    node->val = *A;
    if (!remaining) {
        node->next = NULL;
        return;
    }
    node->next = malloc(sizeof(ListNode));
    toList_aux(++A, --remaining, node->next);
}

struct List toList_rec(const int A[], int size)
{
    LinkedList l = {0};
    l.head = malloc(sizeof(ListNode));
    toList_aux(A, size - 1, l.head);
    return (struct List) {l};
}

struct List toList(const int A[], int size)
{
    LinkedList l = {0};
    ListNode *nodes = malloc(sizeof(ListNode) * size);
    int i;
    for (i = 0; i < size; ++i) {
        nodes[i].val = A[i];
        nodes[i].next = nodes + i + 1;
    }
    nodes[i - 1].next = NULL;
    l.head = nodes;
    l.tail = nodes + size - 1;
    l.node_cnt = size;
    return (struct List) {l};
}

void print_int(const int *val)
{
    printf("%d", *val);
}

void print_aux(ListNode *node)
{
    printf("%d ", node->val);
    if (!node->next) {
        printf("\n");
        return;
    }
    print_aux(node->next);
}

// print list (recursive)
void print_rec(struct List *list)
{
    print_aux(list->l.head);
}

// print list (iterative)
void print(struct List *list)
{
    PrintList(&list->l, &print_int);
}

int firstPos_aux(ListNode *curr, int key, int cnt)
{
    if (!curr) return -1;
    if (curr->val == key) return cnt;
    return firstPos_aux(curr->next, key, ++cnt);
}

int firstPos_rec(struct List *list, int key)
{
    return firstPos_aux(list->l.head, key, 0);
}

// first position of the integer key (iterative)
int firstPos(struct List *list, int key)
{
    if (!list->l.node_cnt) return -1;
    int cnt = 0;
    ListNode *curr = list->l.head;
    while (curr) {
        if (curr->val == key) return cnt;
        cnt++;
        curr = curr->next;
    }
    return -1;
}

int lastPos_aux(ListNode* node, int key,int lastpos,int cnt){
    if(!node) return lastpos;
    if(node->val==key)return lastPos_aux(node->next,key,cnt,cnt+1);
    return lastPos_aux(node->next,key,lastpos,cnt+1);
}
// last position of the integer key (recursive)
int lastPos_rec(struct List *list, int key)
{
    return lastPos_aux(list->l.head,key,-1,0);
}

// last position of the integer key (iterative)
int lastPos(struct List *list, int key)
{
    if (!list->l.node_cnt) return -1;
    int cnt = 0;
    int last = -1;
    ListNode *curr = list->l.head;
    while (curr) {
        if (curr->val == key) last = cnt;
        cnt++;
        curr = curr->next;
    }
    return last;
}

int maxValFirstPos_aux(ListNode* node,int cnt,int curr_max,int curr_max_idx){
    if(!node) return curr_max_idx;
    if(node->val>curr_max) return maxValFirstPos_aux(node->next,cnt+1,node->val,cnt);
    return maxValFirstPos_aux(node->next,cnt+1,curr_max,curr_max_idx);
}
// first position of the maximal value (recursive)
int maxValFirstPos_rec(struct List *list)
{
    return maxValFirstPos_aux(list->l.head,0,list->l.head->val,-1);
}

// first position of the maximal value (iterative)
int maxValFirstPos(struct List *list)
{
    if (!list->l.node_cnt) return -1;
    int cnt = 0;
    ListNode *curr = list->l.head;
    int maxval = curr->val;
    int maxidx = -1;
    while (curr) {
        if (curr->val >= maxval) {
            maxval = curr->val;
            maxidx = cnt;
        }
        cnt++;
        curr = curr->next;
    }
    return maxidx;
}

void reversedCopy_aux(LinkedList *list, ListNode *curr)
{
    if (curr) {
        InsertAt(list, 0, curr->val);
        reversedCopy_aux(list, curr->next);
    }
}

struct List reversedCopy_rec(struct List *list)
{
    LinkedList l = {0};
    reversedCopy_aux(&l, list->l.head);
    return (struct List) {l};
}

// reversed copy (iterative)
struct List reversedCopy(struct List *list)
{
    LinkedList reversed = {0};
    ListNode *curr = list->l.head;
    while (curr) {
        InsertAt(&reversed, 0, curr->val);
        curr = curr->next;
    }
    return (struct List) {reversed};
}

void allPosAux(LinkedList *found, ListNode *curr, int cnt, int key)
{
    if (!curr)return;
    if (curr->val == key) Append(found, cnt);
    allPosAux(found, curr->next, ++cnt, key);
}

struct List allPos_rec(struct List *list, int key)
{
    LinkedList found = {0};
    allPosAux(&found, list->l.head, 0, key);
    return (struct List) {found};
}

// all positions (iterative)
struct List allPos(struct List *list, int key)
{
    LinkedList foundpos = {0};
    ListNode *f = list->l.head;
    int cnt = 0;
    while (f) {
        if (f->val == key)
            Append(&foundpos, cnt);
        cnt++;
        f = f->next;
    }
    return (struct List) {foundpos};
}

int main(void)
{
    printf("iterative\n");

    int A[] = {5, 4, -5, 6, 5, 7, 8, 5, -5, 5};
    int size = sizeof(A) / sizeof(A[0]);
    struct List list_A = toList(A, size);
    print(&list_A);
    printf("firstPos %d\n", firstPos(&list_A, 7));
    printf("lastPos %d\n", lastPos(&list_A, -5));
    printf("maxValFirstPos %d\n", maxValFirstPos(&list_A));
    struct List positions = allPos(&list_A, 5);
    print(&positions);
    struct List reversed = reversedCopy(&list_A);
    print(&reversed);

    printf("\nrecursive\n");

    int B[] = {4,2,3,1,1,1,1,7,2};
    int size_B = sizeof(B) / sizeof(B[0]);
    struct List list_b = toList_rec(B, size_B);
    print_rec(&list_b);
    printf("firstPos_rec %d\n", firstPos_rec(&list_b, 1));
    printf("lastPos_rec %d\n", lastPos_rec(&list_b, 1));
    printf("maxValFirstPos_rec %d\n", maxValFirstPos_rec(&list_b));
    struct List positions_rec = allPos_rec(&list_b, 5);
    print(&positions_rec);
    struct List reversed_rec = reversedCopy_rec(&list_b);
    print(&reversed_rec);

    return 0;
}
