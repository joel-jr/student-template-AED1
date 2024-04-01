#include <stdio.h>
#include <stdlib.h>

int *getArray() {
    int arr[5] = {1, 2, 3, 4, 5};
    printf("Endereço array (getArray): %p\n", arr);
    return arr; // locação estática: antes de retornar a memória é desalocada, retornando 'nil'
}

int *create_array(int n) {
    int *v = malloc(sizeof(int) * n); // retornará bloco alocado: quem chamou a funç. é responsável por liberá-lo!
    for (int i=0; i < n; i++)
        v[i] = i;
    return v;
}

int main() {
    // Alocação Estática + Memory Leak:
    /*int *p = malloc(sizeof(int));
    *p = 10;
    printf("*p: %d\n", *p);
    //free(p); // descomentar! */

    // Alocação Dinâmica Arrays:
    /*int n;
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &n);

    int *v = malloc(sizeof(int) * n);
    for (int i=0; i < n; i++)
        v[i] = i;
    
    for (int i=0; i < n; i++)
        printf("v[%d]: %d\n", i, v[i]);

    free(v);*/

    // Alocação para structs:
    /*typedef struct {
        int x;
        int y;
    } Point;

    Point *point_struct = malloc(sizeof(Point));
    point_struct->x = 10;
    point_struct->y = 20;
    printf("p->x: %d | p->y: %d\n", point_struct->x, point_struct->y);
    free(point_struct);*/
    
    // Array alocado estaticamente:
    int *arr = getArray();
    printf("Endereço array (main): %p\n\n", arr);

    // Array alocado dinamicamente:
    int n;
    printf("Digite tamanho do vetor: \n");
    scanf("%d", &n);
    int *v = create_array(n);
    for (int i=0; i < n; i++)
        printf("v[%d]: %d\n", i, v[i]);
    free(v);

    return 0;
}