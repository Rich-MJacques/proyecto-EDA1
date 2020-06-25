#ifndef CARRITO_H
#define CARRITO_H
#include "libro.h"
#include <stdbool.h>
#include "catalogo.h"

typedef struct _carrito{
    LIBRO *head;
    int tam;
} CARRITO;

typedef struct _pagado{
    LIBRO *tail;
    LIBRO *head;
    int tam;
}PAGADO;

CARRITO *crear_carrito();//Reserva espacio para 
CARRITO *anadir_libro_carrito(CARRITO *carrito, CATALOGO *c);//Añade un libro del catalogo al carrito
bool eliminar_libro_carrito(CARRITO *carrito);//Elimina un libro de carrito de compras
PAGADO *crear_pagado();//con la informacion del carrito hace un ticket
PAGADO *agregar_libro_ticket(CARRITO *carrito);//Agrega un nuevo libro al ticket y reacomoda los apuntadores
void mostrar_ticket(PAGADO *ticket);//crea un archivo ticket en caso de que no exista e imprime el precio con los libros comprados
void imprimir_carrito(CARRITO *carrito);//Imprime los libros que se encuentran en el carrito

#endif