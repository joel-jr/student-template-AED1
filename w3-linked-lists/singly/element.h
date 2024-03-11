#ifndef ELEMENT_H
#define ELEMENT_H

#include <limits.h>

typedef int Element;

#define ELEMENT_NULL INT_MIN; // 'queimar' menor nº int possível: critério achar/não elemento buscado

void element_print(Element e);
int element_compare(Element e1, Element e2);

#endif