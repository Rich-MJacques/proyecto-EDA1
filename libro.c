#include "libro.h"

LIBRO *crear_libro(){
    LIBRO *l;
    l = (LIBRO*)malloc(sizeof(LIBRO));
    l->next = NULL;
    l->prev = NULL;
    return l;
}

