#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Node structure for the binary tree
typedef struct treenode {
    struct treenode *left;
    struct treenode *right;
} TreeNode;

// Tree structure
typedef struct binarytree {
    TreeNode *root;
    size_t data_sz;
    size_t node_cnt;
    size_t height;
} BinaryTree;

void InitTree(BinaryTree *tree, size_t data_sz);

void ArrToTree(BinaryTree *tree, void *data, size_t len, size_t data_sz);

void PrintTree(BinaryTree *tree, void (*print_fn)(const void *));
