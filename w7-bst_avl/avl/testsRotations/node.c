#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "rotations.h"

Node *createNode(Element key) {
    Node *newnode = malloc(sizeof(Node));
    newnode->key = key;
    newnode->height = 1;
    newnode->left = newnode->right = NULL;

    return newnode;
}

void fill_spaces(int size) {
    for (int i=0; i < size; i++)
        printf(" ");
}

int maximum (int a, int b) {
    return (a > b) ? a : b;
}

int height(Node *node) {
    // Árvore vazia / nó NULL
    if (node == NULL)
        return 0;

    return node->height;
}

void updateHeight(Node *node) {
    if (node != NULL)
        node->height = 1 + maximum(height(node->left), height(node->right));
}

void updateAllHeights(Node *root) {
    if (root != NULL) {
        updateAllHeights(root->left);
        updateAllHeights(root->right);
        updateHeight(root);
    }
}

int balanceFactor(Node *node) {
    // Árvore vazia / nó NULL
    if (node == NULL)
        return 0;
    
    // Fator balanceamento: (h_filho <-) - (h_filho ->)
    return height(node->left) - height(node->right);
}

void printDiagram(Node *node, int level) {
    // Caso base1: árvore vazia / nó NULL
    if (node == NULL)
        return;

    fill_spaces(level);
    element_print(node->key);
    printf(" %d %d \n", height(node), balanceFactor(node));
    // Chamadas Recursivas:
    printDiagram(node->left, level + 1);
    printDiagram(node->right, level + 1);
}
void nodePrint(Node *node) {
    printDiagram(node, 0);
}

void testRotateRight() {
    Node *root = createNode(10);
    root->left = createNode(7);
    root->right = createNode(20);

    root->left->left = createNode(5);
    root->left->right = createNode(9);

    root->left->left->left = createNode(3);

    updateAllHeights(root);

    printf("•Antes da Rotação (LL):\n");
    nodePrint(root);
    printf("\n");

    root = rotateRight(root);
    printf("Depois da Rotação (Right):\n");
    nodePrint(root);
    printf("\n");
}

void testRotateLeft() {
    Node *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);

    root->right->left = createNode(15);
    root->right->right = createNode(25);

    root->right->right->right = createNode(30);

    updateAllHeights(root);

    printf("•Antes da Rotação (RR):\n");
    nodePrint(root);
    printf("\n");
    
    root = rotateLeft(root);
    printf("Depois da Rotação (Left):\n");
    nodePrint(root);
    printf("\n");
}

void testRotateLeftRight() {
    Node *root = createNode(15);
    root->left = createNode(10);
    root->right = createNode(20);

    root->left->left = createNode(5);
    root->left->right = createNode(13);

    root->left->right->left = createNode(12);

    updateAllHeights(root);
    
    printf("•Antes da Rotação (LR):\n");
    nodePrint(root);
    printf("\n");

    root = rotateLeftRight(root);
    printf("Depois da Rotação (Left + Right):\n");
    nodePrint(root);
    printf("\n");
}

void testRotateRightLeft() {
    Node *root = createNode(15);
    root->left = createNode(10);
    root->right = createNode(30);

    root->right->left = createNode(25);
    root->right->right = createNode(40);

    root->right->left->right = createNode(29);

    updateAllHeights(root);
    
    printf("•Antes da Rotação (RL):\n");
    nodePrint(root);
    printf("\n");

    root = rotateRightLeft(root);
    printf("Depois da Rotação (Right + Left):\n");
    nodePrint(root);
    printf("\n");
}

int main() {
    testRotateRight();
    testRotateLeft();
    testRotateLeftRight();
    testRotateRightLeft();

    return 0;
}