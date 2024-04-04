#ifndef AVL_TEST_H
#define AVL_TEST_H

#include "element.h"

typedef struct Node {
    Element key;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(Element key);
void updateHeight(Node *node);
void nodePrint(Node *node);
//void updateAllHeights(Node *root);

#endif