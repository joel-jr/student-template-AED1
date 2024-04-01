#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

typedef struct Node {
    Element key;
    struct Node *left;
    struct Node *right;
    
} Node;

struct BST {
    Node *root;
};

// Create / Destroy:
BST *bst_create() {
    BST *bst = malloc(sizeof(BST)); // alocar memória para a struct
    bst->root = NULL; // setar nó 'root': tirar possível 'lixo' guardado

    return bst;
}

void bst_destroyRecur(Node *node) {
    // Verificar se nó está vazio:
    if (node == NULL)
        return;
    
    bst_destroyRecur(node->left);
    bst_destroyRecur(node->right);
    free(node);
}
void bst_destroy(BST *bst) {
    bst_destroyRecur(bst->root); // liberar memória do nós
    free(bst); // libear memória da struct
}

// Insert:
Node *createNode(Element key) {
    Node *node = malloc(sizeof(Node)); // alocar memória para nó criado
    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node *bst_insertRecur(Node *node, Element key) {
    // Caso Base1: árvore vazia
    if (node == NULL)
       return createNode(key); // retorna nó alocado

    // Chamada Recursiva1: buscar subárvore <-
    if (key < node->key)
        node->left = bst_insertRecur(node->left, key);
    // Chamada Recursiva2: buscar subárvore ->
    else if (key > node->key)
        node->right = bst_insertRecur(node->right, key);

    // Caso Base2: chave JÁ existe na árvore
    return node; // retorna próprio nó recebido funç.
}
void bst_insertIter(BST *bst, Element key) {
    // Verificar se árvore está vazia:
    if (bst-> root == NULL) {
        bst-> root = createNode(key);
        return;
    }

    Node *parent = NULL;
    Node *cur = bst->root;

    while (cur != NULL) {
        if (key == cur->key) // elemento já existe na árvore
            return;

        if (key < cur->key) {
            parent = cur;
            cur = cur->left; // avançar para subárvore <-
        }
        else {
            parent = cur;
            cur = cur->right; // avançar para subárvore ->
        }
    }

    // Verificar qual lado do pai inserir nó criado:
    if (key < parent->key)
        parent->left = createNode(key);
    else
        parent->right = createNode(key);
}
void bst_insert(BST *bst, Element key) {
    bst->root = bst_insertRecur(bst->root, key);
    //bst_insertIter(bst, key);
}

// Remove:
Node *bst_successor(Node *node) {
    Node *cur = node->right; // acessar subárvore ->
    while (cur->left != NULL)
        cur = cur->left; // chegar nó folha <- dessa subárvore

    return cur;
}

Node *bst_removeRecur(Node *node, Element key) {
    // Caso Base1: árvore vazia ou chave NÃO encontrada
    if (node == NULL)
        return node;

    // Chamadas Recursivas:
    if (key < node->key)
        node->left = bst_removeRecur(node->left, key); // acessar subárvore <-
    else if (key > node->key)
        node->right = bst_removeRecur(node->right ,key); // acessar subárvore ->

    // Caso Base2: chave encontrada
    else { // (key == node->key)
        // Caso Base2.1 / 2.2: nó folha / NÃO possui filho <-
        if (node->left == NULL) {
            Node *trash = node; // copiar nó atual
            node = node->right; // puxar / subst. nó atual pelo seu filho ->
            free(trash); // liberar nó 'trash'
        }
        // Caso Base2.2: nó NÃO possui filho -> (puxar filho esq)
        else if (node->right == NULL) {
            Node *trash = node; // copiar nó atual
            node = node->left; // puxar / subst. nó atual pelo seu filho <-
            free(trash); // liberar nó 'trash'
        }
        // Caso Base2.3: nó possui 2 filhos
        else {
            Node *successor = bst_successor(node); // achar nó sucessor
            node->key = successor->key; // subst. chave nó atual pelo sucessor
            node->right = bst_removeRecur(node->right, successor->key); // eliminar nó sucessor
        }
    }

    return node;
}
void bst_remove(BST *bst, Element key) {
    bst->root = bst_removeRecur(bst->root, key);
    // bst_removeIter é MT mais complicado!!!
}

// Search:
bool bst_searchRecur(Node *node, Element key) { // busca RECURSIVAMENTE um elemento na ABB
    // Caso Base1: árvore vazia ou chave NÃO encontrada
    if (node == NULL) 
        return false;
    // Caso Base2: chave encontrada na árvore
    if (node->key == key)
        return true;

    // Chamadas Recursivas:
    if (key < node->key)
        return bst_searchRecur(node->left, key); // acessar subárvore <-
    // (key > cur->key)
    return bst_searchRecur(node->right, key); // acessar subárvore ->
}
bool bst_searchIter(Node *cur, Element key) { // busca ITERATIVAMENTE um elemento na ABB
    while (cur != NULL) {
        if (cur->key == key)
            return true;
        
        // Verificar lado da árvore percorrer:
        if (key < cur->key)
            cur = cur->left; // acessar subárvore <-
        else
            cur = cur->right; // acessar subárvore ->
    }
    
    return false; // árvore vazia ou chave NÃO encontrada
}
bool bst_search(BST *bst, Element key) {
    return bst_searchRecur(bst->root, key); // passar nó raíz da árvore
    //return bst_searchIter(bst->root, key); // passar nó raíz da árvore
}

// Prints:
void bst_printInOrderRecur(Node *node) { // left, nó, right
    // Verificar se é nó folha:
    if (node == NULL)
        return;
    
    bst_printInOrderRecur(node->left); // aprofundar filho <-
    element_print(node->key); // imprimir chave do nó ref.
    printf(" ");
    bst_printInOrderRecur(node->right); // aprofundar filho ->
}
void bst_printInOrder(BST *bst) { // ordem CRESCENTE elementos
    bst_printInOrderRecur(bst->root);
    printf("\n");
}

void bst_printPreOrderRecur(Node *node) { // nó, left, right
    // Verificar se é nó folha:
    if (node == NULL)
        return;
    
    element_print(node->key);
    printf(" ");
    bst_printPreOrderRecur(node->left);
    bst_printPreOrderRecur(node->right);  
} 
void bst_printPreOrder(BST *bst) { // ordem DIAGRAMA árvore
    bst_printPreOrderRecur(bst->root);
    printf("\n");
}

void bst_printPostOrderRecur(Node *node) { // left, right, nó
    // Verificar se é nó folha:
    if (node == NULL)
        return;
    
    bst_printPostOrderRecur(node->left);
    bst_printPostOrderRecur(node->right);
    element_print(node->key);
    printf(" ");
}
void bst_printPostOrder(BST *bst) { // ordem DESTROY elementos (v folha até raíz ^)
    bst_printPostOrderRecur(bst->root);
}

void bst_printDiagram(Node *node, int level) {
    // Verificar se é nó folha:
    if (node == NULL)
        return;

    for (int i=0; i < level; i++) // imprimir espaços " " na msmm linha
        printf("  ");
    
    element_print(node->key);
    printf("\n");
    bst_printDiagram(node->left, level+1);
    bst_printDiagram(node->right, level+1);
}
void bst_print(BST* bst) {
    bst_printDiagram(bst->root, 0);
}