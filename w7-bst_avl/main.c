#include <stdio.h>

#include "bst.h"

void printTree(BST *bst) {
    printf("•In-Order: ");
    bst_printInOrder(bst);
    printf("\n•Pre-Order:\n");
    bst_print(bst);
    printf("\n•Post-Order: ");
    bst_printPostOrder(bst);
    printf("\n\n");
}

void testRoutePrints() {
    printf("<testRoutePrints()>\n\n");
    BST *bst = bst_create();
    int elements[] = {50, 61, 58, 43, 70, 48, 3};

    for (int i=0; i < 7; i++)
        bst_insert(bst, elements[i]);

    printTree(bst);
    
    bst_destroy(bst);
}

void testSearch() {
    printf("<testSearch()>\n\n");
    BST* bst = bst_create();
    Element validKeys[] = {50, 43, 3, 48, 61, 58, 70};
    Element invalidKeys[] = {0, 1, 2, 4, 5, 6, 7, 8, 9, 10, 90, 100};

    for (int i=0; i < 7; i++)
        bst_insert(bst, validKeys[i]);
    
    // Buscar elementos existentes:
    for (int i = 0; i < 7; i++)
        printf("%d: %sfound\n", validKeys[i], bst_search(bst, validKeys[i]) ? "" : "not ");
    printf("\n");

    // Buscas elementos NÃO existentes:
    for (int i = 0; i < 12; i++)
        printf("%d: %sfound\n", invalidKeys[i], bst_search(bst, invalidKeys[i]) ? "" : "not ");
    printf("\n");

    bst_destroy(bst);
}

void testInsert() {
    printf("<testInsert()>\n\n");
    // Árvore 1:
    BST *bst1 = bst_create();
    Element validKeys1[] = {50, 43, 3, 48, 45, 61, 58, 70};
    Element invalidKeys1[] = {1, 5, 10, 90, 100};

    for (int i=0; i < 8; i++)
        bst_insert(bst1, validKeys1[i]);

    // Buscar elementos inseridos:
    printf("•Árvore1:\n");
    for (int i=0; i < 8; i++)
        printf("%d: %s\n", validKeys1[i], bst_search(bst1, validKeys1[i]) ? "true" : "false");

    // Buscar elementos NÃO inseridos:
    for (int i=0; i < 5; i++)
        printf("%d: %s\n", invalidKeys1[i], bst_search(bst1, invalidKeys1[i]) ? "true" : "false");
    printf("\n");


    // Árvore 2:
    BST *bst2 = bst_create();
    Element validKeys2[] = {5, 3, 7, 2, 4, 6, 8};
    Element invalidKeys2[] = {0, 1, 9};

    for (int i=0; i < 7; i++)
        bst_insert(bst2, validKeys2[i]);

    // Buscar elementos inseridos:
    printf("•Árvore2:\n");
    for (int i=0; i < 7; i++)
        printf("%d: %s\n", validKeys2[i], bst_search(bst2, validKeys2[i]) ? "true" : "false");

    // Buscar elementos NÃO inseridos:
    for (int i=0; i < 3; i++)
        printf("%d: %s\n", invalidKeys2[i], bst_search(bst2, invalidKeys2[i]) ? "true" : "false");
    printf("\n");

    bst_destroy(bst1);
    bst_destroy(bst2);
}

void testRemove() {
    printf("<testRemove()>\n\n");
    BST *bst = bst_create();
    Element elements[] = {50, 43, 3, 48, 61, 58, 70};

    for (int i = 0; i < 7; i++)
        bst_insert(bst, elements[i]);
    
    printf("•Árvore original:\n");
    bst_print(bst);
    printf("\n");
    bst_remove(bst, 3); // nó folha
    printf("•bst_remove(3):\n");
    bst_print(bst);
    printf("\n");
    bst_remove(bst, 70);
    printf("•bst_remove(70):\n");
    bst_print(bst);
    printf("\n");
    bst_remove(bst, 43); // nó APENAS 1 filho ->
    printf("•bst_remove(43):\n");
    bst_print(bst);
    printf("\n");
    bst_remove(bst, 61); // nó APENAS 1 filho <-
    printf("•bst_remove(61):\n");
    bst_print(bst);
    printf("\n");
    bst_remove(bst, 50); // nó 2 filhos (raiz)
    printf("•bst_remove(50):\n");
    bst_print(bst);
    printf("\n");
    bst_remove(bst, 48);
    printf("•bst_remove(48):\n");
    bst_print(bst);
    printf("\n");
    bst_remove(bst, 58);
    printf("•bst_remove(58):\n(*)");
    bst_print(bst);
    printf("\n\n");

    bst_destroy(bst);
}

int main() {
    //testRoutePrints();
    //testSearch();
    //testInsert();
    testRemove();
    
    return 0;
}