#include <stdio.h>

#include "avl.h"

void test_LL() {
    AVL *avl = avl_create();
    avl_insert(avl, 10);
    avl_insert(avl, 7);
    avl_insert(avl, 20);
    avl_insert(avl, 5);
    avl_insert(avl, 9);

    printf("•Árvore Original:\n");
    avl_print(avl);
    printf("\n");

    // Inserção Crítica:
    avl_insert(avl, 3);
    printf("•Após a Inserção do 3 (LL) + Rotação (Right):\n");
    avl_print(avl);
    printf("\n");

    avl_remove(avl, 9);
    avl_remove(avl, 10);
    printf("•Após as Remoções do 9 e 10:\n");
    avl_print(avl);
    printf("\n");

    // Remoção Crítica:
    avl_remove(avl, 20);
    printf("•Após a Remoção do 20 (LL) + Rotação (Right):\n");
    avl_print(avl);
    printf("\n");

    avl_destroy(avl);
}

void test_RR() {
    AVL *avl = avl_create();
    avl_insert(avl, 10);
    avl_insert(avl, 5);
    avl_insert(avl, 20);
    avl_insert(avl, 15);
    avl_insert(avl, 25);

    printf("•Árvore Original:\n");
    avl_print(avl);
    printf("\n");

    // Inserção Crítica:
    avl_insert(avl, 30);
    printf("•Após a Inserção do 30 (RR) + Rotação (Left):\n");
    avl_print(avl);
    printf("\n");

    avl_remove(avl, 10);
    avl_remove(avl, 15);
    printf("•Após as Remoções do 10 e 15:\n");
    avl_print(avl);
    printf("\n");

    // Remoção Crítica:
    avl_remove(avl, 5);
    printf("•Após a Remoção do 5 (RR) + Rotação (Left):\n");
    avl_print(avl);
    printf("\n");

    avl_destroy(avl);
}

void test_LR() {
    AVL *avl = avl_create();
    avl_insert(avl, 15);
    avl_insert(avl, 10);
    avl_insert(avl, 20);
    avl_insert(avl, 5);
    avl_insert(avl, 13);

    printf("•Árvore Original:\n");
    avl_print(avl);
    printf("\n");

    // Inserção Crítica:
    avl_insert(avl, 12);
    printf("•Após a Inserção do 12 (LR) + Rotação (Left + Right):\n");
    avl_print(avl);
    printf("\n");

    avl_remove(avl, 20);
    avl_remove(avl, 5);
    printf("•Após as Remoções do 20 e 5:\n");
    avl_print(avl);
    printf("\n");
    
    // Remoção Crítica:
    avl_remove(avl, 15);
    printf("•Após a Remoção do 15 (LR) + Rotação (Left + Right):\n");
    avl_print(avl);
    printf("\n");

    avl_destroy(avl);
}

void test_RL() {
    AVL *avl = avl_create();
    avl_insert(avl, 15);
    avl_insert(avl, 10);
    avl_insert(avl, 30);
    avl_insert(avl, 25);
    avl_insert(avl, 40);

    printf("•Árvore Original:\n");
    avl_print(avl);
    printf("\n");

    // Inserção Crítica:
    avl_insert(avl, 29);
    printf("•Após a Inserção do 29 (RL) + Rotação (Right + Left):\n");
    avl_print(avl);
    printf("\n");

    avl_remove(avl, 10);
    avl_remove(avl, 40);
    printf("•Após as Remoções do 10 e 40:\n");
    avl_print(avl);
    printf("\n");
    
    // Remoção Crítica:
    avl_remove(avl, 15);
    printf("•Após a Remoção do 15 (RL) + Rotação (Right + Left):\n");
    avl_print(avl);
    printf("\n");
    
    avl_destroy(avl);
}

void test_degenerete() {
    AVL *avl = avl_create();

    printf("•Inserções():\n");
    for (int i = 1; i < 11; i++) {
        avl_insert(avl, i);
        avl_print(avl);
        printf("\n");
    }
    printf("\n");

    printf("•Remoções():\n");
    for (int i = 1; i < 11; i++) {
        avl_remove(avl, i);
        avl_print(avl);
        printf("\n");
    }

    avl_destroy(avl);
}

int main() {
    //test_LL();
    //test_RR();
    //test_LR();
    //test_RL();
    test_degenerete();

    return 0;
}