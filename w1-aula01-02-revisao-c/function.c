#include <stdio.h>

int add(int *a, int *b) {
    *a = 10;
    *b = 20;
    return (*a + *b);
}

int main() {
    int x = 1;
    int y = 2;
    printf("%d + %d = %d\n", x, y, add(&x, &y));
    printf("x: %d\n", x);
    printf("y: %d\n", y);
	
    return 0;
}