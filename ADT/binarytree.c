#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binarytree.h"
#include <limits.h>
#include <string.h>
#include <math.h>

void InitTree(BinaryTree *tree, size_t data_sz)
{
    memset(tree, 0, sizeof(BinaryTree));
    tree->data_sz = data_sz;
}

#define DATA_AT_TREENODE(p_node)((char* )(p_node)+sizeof(TreeNode))

TreeNode *NewNode(void *data, size_t data_sz)
{
    //data will be stored after TreeNode in memory
    //layout for a TreeNode:
    // ... [left child *][right child *][{data_sz} bytes of memory for the data] ...
    //to avoid storing unnecessary pointers
    TreeNode *new = calloc(1, sizeof(TreeNode) + data_sz);
    if (!new) {
        fputs("Failed allocating node", stderr);
        return NULL;
    }
    memcpy(DATA_AT_TREENODE(new), data, data_sz);
    return new;
}

void print_int1(const void *val)
{
    printf("%d", *(int *) val);
}

TreeNode *ArrToTreeAux(void *data, size_t len, size_t data_sz, size_t *treeheight, size_t curr_height)
{
    if (len == 0) return NULL;
    size_t mid = len / 2;
    size_t sz_l = mid;
    size_t sz_r = len - mid - 1;
    if (curr_height == *treeheight) (*treeheight)++;
    TreeNode *new = NewNode((char *) data + mid * data_sz, data_sz);
    if (!new) exit(1);
    new->left = ArrToTreeAux(data, sz_l, data_sz, treeheight, curr_height + 1);
    new->right = ArrToTreeAux((char *) data + (mid + 1) * data_sz, sz_r, data_sz, treeheight, curr_height + 1);
    return new;
}

void ArrToTree(BinaryTree *tree, void *data, size_t len, size_t data_sz)
{
    InitTree(tree, data_sz);
    if (!(unsigned long) data * len) {
        return;
    }
    tree->node_cnt = len;
    tree->height = 0;
    tree->root = ArrToTreeAux(data, len, data_sz, &tree->height, tree->height);
}

void PrintTreeAux(TreeNode *curr, void (*print_fn)(const void *), unsigned int depth)
{
    if (!curr) {
        printf("\n");
        return;
    };
    PrintTreeAux(curr->right, print_fn, depth + 1);
    for (unsigned int i = 0; i < depth; ++i) {
        printf("    ");
    }
    print_fn(DATA_AT_TREENODE(curr));
    PrintTreeAux(curr->left, print_fn, depth + 1);
}

void PrintTree(BinaryTree *tree, void (*print_fn)(const void *))
{
    PrintTreeAux(tree->root, print_fn, 0);
}


