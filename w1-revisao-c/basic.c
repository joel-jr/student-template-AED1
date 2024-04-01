#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    /*
    printf("Tamanho (bits) tipos dados:\n"); // sizeof() retorna tamnho em byte: 1 byte = 8 bits
    printf("char: %ld bits\n", sizeof(char) * 8);
    printf("int: %ld bits\n", sizeof(int) * 8);
    printf("short: %ld bits\n", sizeof(short) * 8);
    printf("long: %ld bits\n", sizeof(long) * 8);
    printf("long long: %ld bits\n", sizeof(long long) * 8);
    printf("float: %ld bits\n", sizeof(float) * 8);
    printf("double: %ld bits\n", sizeof(double) * 8);
    printf("long double: %ld bits\n", sizeof(long double) * 8);
    printf("bool: %ld bits\n", sizeof(bool) * 8);*/
    
    /*
    char nome[100];
    strcpy(nome, "Joel");
    printf("Nome: %s\n", nome); */

    /*
    typedef struct {
        unsigned short dia;
        unsigned short mes;
        unsigned short ano;
    } Data;

    typedef struct {
        char nome[20];
        int idade;
        char conceito;
        Data nascimento;
    } Aluno;

    Aluno a1 = {
        .nome = "Joel",
        .idade = 22,
        .conceito = 'A',
        .nascimento = {
            .dia = 22,
            .mes = 6,
            .ano = 2001
        }
    };
    printf("%s nasceu em %d/%d/%d, tem %d anos e tirou '%c' em AED1\n", a1.nome, a1.nascimento.dia, a1.nascimento.mes, a1.nascimento.ano, a1.idade, a1.conceito);*/

    /*
    char buffer[100];
    fgets(buffer, 100, stdin);
    printf("Saída:  %s", buffer);*/

    /*
    bool x = true;
    printf("Tipo booleano: %s\n", x ? "true":"false"); // expressão condicional */

    /*
    int x=0;
    while (x < 10) {
        printf("x: %d\n", x);
        x++;
    }*/

    /*
    int x=0;
    do {
        printf("x: %d\n", x);
        x++;
    } while (x < 10);*/
    
    /*
    for (int x=0; x < 10; x++)
        printf("x: %d\n", x);*/
    
    /*
    int x = 10, y = 20, z = 30;
    printf("x: %p\n", &x);
    printf("y: %p\n", &y);
    printf("z: %p\n", &z);*/

    /*
    int *p;
    float *q;
    char *r;
    printf("*p: %p\n", p);
    printf("*q: %p\n", q);
    printf("*r: %p\n", r);
    printf("&p: %p\n", &p);
    printf("&q: %p\n", &q);
    printf("&r: %p\n", &r);*/

    /*
    int x = 10;
    float y = 3.14;
    char z = 'a';
    int *p = &x;
    float *q = &y;
    char *r = &z;
    printf("x: %d | y: %.2f | z: '%c'\n", x,y,z);
    printf("&x: %p\n", &x);
    printf(" p: %p\n", p);
    printf("&y: %p\n", &y);
    printf(" q: %p\n", q);
    printf("&z: %p\n", &z);
    printf(" r: %p\n", r);
    printf("&p: %p\n", &p);
    printf("&q: %p\n", &q);
    printf("&r: %p\n", &r);*/
    
    /*
    int x = 10;
    float y = 3.14;
    char z = 'a';
    int *p = &x;
    float *q = &y;
    char *r = &z;
    printf("*p: %d | *q: %.2f | *r: '%c'\n", *p,*q,*r);*/

    /*
    int v[3] = {10, 20, 30};
    char s[] = "abc";
    int *p = v;
    char *q = s;
    printf("v: %p\n", v);
    printf("p: %p\n", p);
    printf("s: %p\n", s);
    printf("q: %p\n", q);
    printf("*p ou *(p+0): %d\n", *p);
    printf("*(p+1): %d\n", *(p+1));
    printf("*(p+2): %d\n", *(p+2));
    printf("*q ou *(q+0): '%c'\n", *q);
    printf("*(q+1): '%c'\n", *(q+1));
    printf("*(q+2): '%c'\n", *(q+2));*/

    
    typedef struct {
        int x;
        int y;
    } Point;

    Point struct_p = {10, 20};
    Point *point_struct = &struct_p;
    printf("- Acessar elementos a partir de struct_p:\n");
    printf("struct_p.x: %d | struct_p.y: %d\n", struct_p.x, struct_p.y);
    printf("- Acessar elementos a partir do ponteiro para struct_p:\n");
    printf("point_struct->x: %d | point_struct->y: %d\n", point_struct->x, point_struct->y);

    return 0;
}