#include "rotations.h"
// Nó crítico / desbalanceado: fb FORA do intervalo [-1, 1]

// girar para "direita" é sentido HORÁRIO
Node *rotateRight(Node *node) {
    Node *pivot = node->left; // nó pivô: raiz subárvore <- nó crítico (node)
    node->left = pivot->right; // subárvore -> nó pivô torna-se subárvore <- nó crítico
    pivot->right = node; // nó crítico torna-se subárvore -> nó pivô

    updateHeight(node); // atualizar altura nó crítico (diminuir)
    updateHeight(pivot); // atualizar altura nó pivô (aumentar)

    return pivot; // pivô é nova raiz da subárvore
}

// girar para "esquerda" é sentido ANTI-HORÁRIO
Node *rotateLeft(Node *node) {
    Node *pivot = node->right; // nó pivô: raiz subárvore -> nó crítico (node)
    node->right = pivot->left; // subárvore <- nó pivô torna-se subárvore -> nó crítico
    pivot->left = node; // nó crítico torna-se subárvore <- nó pivô

    updateHeight(node); // atualizar altura nó crítico (diminuir)
    updateHeight(pivot); // atualizar altura nó pivô (aumentar)

    return pivot; // pivô é nova raiz da subárvore
}

Node *rotateLeftRight(Node *node) {
    node->left = rotateLeft(node->left); // pivô baixo: raiz subárvore -> nó crítico baixo
    return rotateRight(node); // pivô cima: raiz subárvore <- nó crítico cima
}

Node *rotateRightLeft(Node *node) {
    node->right = rotateRight(node->right); // pivô baixo: raiz subárvore <- nó crítico baixo
    return rotateLeft(node); // pivô cima: raiz subárvore -> nó crítico cima
}