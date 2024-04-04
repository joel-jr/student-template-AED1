#ifndef BST_H
#define BST_H

#include <stdbool.h>

#include "element.h"

typedef struct BST BST;

BST *bst_create(); // aloca memória para árvore
void bst_destroy(BST *bst); // libera memória para árvore

void bst_insert(BST *bst, Element key); // insere um elemento na ABB
void bst_remove(BST *bst, Element key); // remove um elemento na ABB
bool bst_search(BST *bst, Element key); // busca um elemento na ABB

void bst_print(BST* bst); // imprime árvore (preOrder)
void bst_printInOrder(BST *bst); // ordem CRESCENTE elementos da ABB
void bst_printPreOrder(BST *bst); // ordem DIAGRAMA (^ raíz até folha v) árvore da ABB
void bst_printPostOrder(BST *bst); // ordem DESTROY elementos (v folha até raíz ^) da ABB

int bst_height(BST *bst); // retorna altura da ABB
int bst_count(BST *bst); // retorna qtd elementos / nós nda ABB

#endif