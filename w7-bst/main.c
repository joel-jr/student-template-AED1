#include <stdio.h>

#include "bst.h"

void testPrints() {
    BST *bst = bst_create();
    Element keys[] = {5, 3, 7, 2, 4, 6, 8};

    for (int i=0; i < 7; i++)
        bst_insert(bst, keys[i]);

    printf("•inOrder (odem crescente elementos):\n");
    bst_printInOrder(bst);
    printf("\n");

    printf("•preOrder (ordem diagrama - cima/baixo):\n");
    bst_printPreOrder(bst);
    printf("\n");

    printf("•diagram (preOrder):\n");
    bst_print(bst);
    printf("\n");

    printf("•postOrder (ordem destroy - baixo/cima):\n");
    bst_printPostOrder(bst);
    printf("\n");

    bst_destroy(bst);
}

void testInsert() {
    BST *bst = bst_create();
    // Árvore 1:
    Element validKeys1[] = {50, 43, 3, 48, 45, 61, 58, 70};
    Element invalidKeys1[] = {1, 5, 10, 90, 100};

    for (int i=0; i < 8; i++)
        bst_insert(bst, validKeys1[i]);

    // Buscar elementos inseridos:
    printf("•Árvore1:\n");
    for (int i=0; i < 8; i++)
        printf("%d: %s\n", validKeys1[i], bst_search(bst, validKeys1[i]) ? "true" : "false");

    // Buscar elementos NÃO inseridos:
    for (int i=0; i < 5; i++)
        printf("%d: %s\n", invalidKeys1[i], bst_search(bst, invalidKeys1[i]) ? "true" : "false");
    printf("\n");


    // Árvore 2:
    Element validKeys2[] = {5, 3, 7, 2, 4, 6, 8};
    Element invalidKeys2[] = {0, 1, 9};

    for (int i=0; i < 7; i++)
        bst_insert(bst, validKeys2[i]);

    // Buscar elementos inseridos:
    printf("•Árvore2:\n");
    for (int i=0; i < 7; i++)
        printf("%d: %s\n", validKeys2[i], bst_search(bst, validKeys2[i]) ? "true" : "false");

    // Buscar elementos NÃO inseridos:
    for (int i=0; i < 3; i++)
        printf("%d: %s\n", invalidKeys2[i], bst_search(bst, invalidKeys2[i]) ? "true" : "false");

    bst_destroy(bst);
}

void printTree(BST *bst) {
    printf("•In-Order: ");
    bst_printInOrder(bst);
    printf("\n•Pre-Order:\n");
    bst_print(bst);
    printf("\n•Post-Order: ");
    bst_printPostOrder(bst);
    printf("\n");
}

void testRoute() {
    BST *bst = bst_create();
    int validKeys[] = {50, 61, 58, 43, 70, 48, 3};

    for (int i=0; i < 7; i++)
        bst_insert(bst, validKeys[i]);

    printTree(bst);

    bst_destroy(bst);
}

int main() {
    //testPrints();
    //testInsert();
    //testRoute();

    return 0;
}