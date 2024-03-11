#include <stdio.h>

#include "element.h"

void element_print(Element e) {
    printf("%d ", e);
}

int element_compare(Element e1, Element e2) {
    return e1 - e2;
}