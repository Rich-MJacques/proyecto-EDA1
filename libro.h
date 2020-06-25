#ifndef LIBRO_H
#define LIBRO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _info{
    char editorial[50];
    char formato[20];
    float precio;
    long ISBN;
    int existencia;
    char titulo[50];
    char autor[50];
}INFO;
// INFO2[NUM]->titulo=infor[NUM]->INFO.titulo

typedef struct _libro LIBRO;
struct _libro{
    INFO INFO;
    LIBRO *prev;
    LIBRO *next;
};

LIBRO *crear_libro();//Reserva espacio en la memoria para anadir un libro de tipo INFO
#endif
