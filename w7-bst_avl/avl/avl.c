// Binary Search Tree implementation with AVL balancing.

#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>

#include "avl.h"

typedef struct Node {
    Element key;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

struct AVL {
    Node *root;
};

AVL *avl_create() {
    AVL *bst = malloc(sizeof(AVL));
    bst->root = NULL;
    
    return bst;
}

void avl_destroyRecur(Node *node) {
    // Árvore vazia / nó NULL:
    if (node == NULL)
        return;

    avl_destroyRecur(node->left);
    avl_destroyRecur(node->right);
    free(node);
}
void avl_destroy(AVL *bst) {
    avl_destroyRecur(bst->root);
    free(bst);
}

int maximum(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node *node) {
    // Árvore vazia / nó NULL:
    if (node == NULL)
        return 0;
    
    return node->height;
}

void updateHeight(Node *node) {
    if (node != NULL)
        node->height = 1 + maximum(height(node->left), height(node->right));
}

int balanceFactor(Node *node) {
    // Árvore vazia / nó NULL:
    if (node == NULL)
        return 0;
    
    // Fator balanceamento: (h_filho <-) - (h_filho ->)
    return height(node->left) - height(node->right);
}

Node *rotateRight(Node *node) { // sentido HORÁRIO
    Node *pivot = node->left; // nó pivô: raiz subárvore <- nó crítico (node)
    node->left = pivot->right; // subárvore -> nó pivô torna-se subárvore <- nó crítico
    pivot->right = node; // nó crítico torna-se subárvore -> nó pivô

    updateHeight(node); // atualizar altura nó crítico (diminuir)
    updateHeight(pivot); // atualizar altura nó pivô (aumentar)

    return pivot; // pivô é nova raiz da subárvore
}

Node *rotateLeft(Node *node) { // sentido ANTI-HORÁRIO
    Node *pivot = node->right; // nó pivô: raiz subárvore -> nó crítico (node)
    node->right = pivot->left; // subárvore <- nó pivô torna-se subárvore -> nó crítico
    pivot->left = node; // nó crítico torna-se subárvore <- nó pivô

    updateHeight(node); // atualizar altura nó crítico (diminuir)
    updateHeight(pivot); // atualizar altura nó pivô (aumentar)

    return pivot; // pivô é nova raiz da subárvore
}

Node *rebalance(Node *node) {
    updateHeight(node); // atualizar altura do nó (aumentar / diminuir)

    // Desbalanceamento crítico à ESQUERDA:
    if (balanceFactor(node) > 1) {
        // LR:
        if (balanceFactor(node->left) < 0)
            node->left = rotateLeft(node->left);
        // LL / LR:
        return rotateRight(node);
    }
    
    // Desbalanceamento crítico à DIREITA:
    if (balanceFactor(node) < -1) {
        // RL:
        if (balanceFactor(node->right) > 0)
            node->right = rotateRight(node->right);
        // RR / RL:
        return rotateLeft(node);
    }

    return node; // desbalanceamento DENTRO da tolerância [-1, 1]
}

bool alv_searchRecur(Node *node, Element key) {
    // Caso Base1: árvore vazia ou chave NÃO encontrada
    if (node == NULL)
        return node;
    // Caso Base2: chave encontrada
    if (key == node->key)
        return true;

    // Chamadas Recursivas:
    if (key < node->key)
        return alv_searchRecur(node->left, key);  // acessar subárvore <-
    // (key > node->key)
    return alv_searchRecur(node->right, key);  // acessar subárvore ->
}
bool avl_search(AVL *bst, Element key) {
    return alv_searchRecur(bst->root, key);
}

// TESTAR TROCAR ORDEM ACIMA FUNÇÃO 'INSERT' [...........]
Node *createNode(Element key) {
    Node *newnode = malloc(sizeof(Node));
    newnode->key = key;
    newnode->height = 1;
    newnode->left = newnode->right = NULL;

    return newnode;
}

Node *avl_insertRecur(Node *node, Element key) {
    // Caso Base1: árvore vazia
	if (node == NULL)
		return createNode(key);
	
	// Chamada Recursiva1: buscar subárvore <-
	if (key < node->key)
		node->left = avl_insertRecur(node->left, key);
	// Chamada Recursiva2: buscar subárvore ->
	else if(key > node->key)
		node->right = avl_insertRecur(node->right, key);
	
	// Caso Base2: chave JÁ existe na árvore
	return rebalance(node);  // retorna próprio nó recebido REBALANCEADO
}
void avl_insert(AVL *bst, Element key) {
    bst->root = avl_insertRecur(bst->root, key);
}

Node *search_successor(Node *node) {
    Node *cur = node->right; // acessar subárvore ->
    while (cur->left != NULL)
        cur = cur->left; // chegar nó folha <- dessa subárvore

    return cur;
}

Node *avl_removeRecur(Node *node, Element key) {
    // Caso Base1: árvore vazia ou chave NÃO encontrada
	if (node == NULL)
		return node;
		
	// Chamadas Recursivas:
	if (key < node->key)
		node->left = avl_removeRecur(node->left, key); // acessar subárvore <-
	else if (key > node->key)
		node->right = avl_removeRecur(node->right, key); // acessar subárvore ->
	
	// Caso Base2: chave encontrada
	else { // (key == node->key)
		// Caso Base2.1 / 2.2: nó folha / NÃO possui filho <-
		if (node->left == NULL) {
			Node *trash = node;
            node = node->right; // puxar filho ->
            free(trash); // liberar nó 'trash'
		}
		// Caso Base2.2: nó NÃO possui filho ->
		else if (node ->right == NULL) {
			Node *trash = node;
			node = node->left; // puxar filho <-
			free(trash); // liberar nó 'trash'
		}		
		// Caso Base2.3: nó possui 2 filhos
		else {
			Node *successor = search_successor(node); // achar nó sucessor
			node->key = successor->key; // subst. chave nó atual pelo sucessor
			node->right = avl_removeRecur(node->right, successor->key); // eliminar nó sucessor
		}
	}
	
	return rebalance(node); // retorna próprio nó recebido REBALANCEADO
}
void avl_remove(AVL *bst, Element key) {
    bst->root = avl_removeRecur(bst->root, key);
}

void fill_spaces(int size) {
    for (int i=0; i < size; i++)
        printf(" ");
}

void printDiagram(Node *node, int level) {
    // Caso base: árvore vazia / nó NULL
    if (node == NULL)
        return;

    fill_spaces(level);
    element_print(node->key);
    printf(" %d %d \n", height(node), balanceFactor(node));
    // Chamadas Recursivas:
    printDiagram(node->left, level + 1);
    printDiagram(node->right, level + 1);
}
void avl_print(AVL *bst) {
    printDiagram(bst->root, 0);
}