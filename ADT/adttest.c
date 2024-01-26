#include "linkedlist.h"
#include "binarytree.h"
#include <math.h>

void print_int(const void *val)
{
    printf("%d", *(int *) val);
}

void print_double(const void *val)
{
    printf("%f", *(double *) val);
}

void test_tree(void)
{
    BinaryTree tree;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6};
    ArrToTree(&tree, arr, sizeof(arr) / sizeof(int), sizeof(int));
    printf("Tree height: %lu\nShould be: %d\n", tree.height, (int) ceil(log2(sizeof(arr) / sizeof(int))));
    PrintTree(&tree, print_int);
}

int main(void)
{
    test_tree();
    return 0;
}

