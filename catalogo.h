#ifndef CATALOGO_H
#define CATALOGO_H
#include "libro.h"
#include <stdio.h>


typedef struct _catalogo{
    int tam;
    LIBRO *head;
    LIBRO *tail;
} CATALOGO;

CATALOGO *crear_catalogo(); // Almacena espacio en la memoria del tamaño de un catalogo
void add_libro_init(CATALOGO *c, LIBRO *l);//Añade nodos al principio del catalogo de tipo libro
void buscar_libro_ISBN(CATALOGO *c);//Busca un libro segun su ISBN
void imprimir_catalogo(CATALOGO *c);//Imprimer todos los libros actulizados en la terminal
CATALOGO *cargar_libros(CATALOGO *c);//solicita toda la informacion del libro y acomoda los apuntadores para actualizar el catalogo
void actualizar_catalogo(CATALOGO *C);//Genera un archivo txt del catalogo despues de modificar existencias, agregar o  eliminar libro
LIBRO *ultimo(CATALOGO *c);//A parirt de un apuntador auxiliar recorre catalogo hasta encontrar el ultimo nodo
LIBRO *penultimo(CATALOGO *c);//A partir de un apuntador auxiliar recorre el catalogo y encuentra penultimo libro del catalogo
void buscar_libro_autor(CATALOGO *c);//pide un isbn y por un for encuentra el libro para imprimir su informacion
void buscar_libro_titulo(CATALOGO *c);//pide un isbn y por un for encuentra el libro para imprimir su informacion
LIBRO *actual(CATALOGO *c,int pos);//por medio de un while recibe una posicion y retorna un libro
CATALOGO *modificar_existencias(CATALOGO *c);//Le da la opcion al vendedor de modificar las existencias del catalogo
CATALOGO *eliminar_libro_inicio(CATALOGO *c, long del);//recibe un ISBN para encontrar el libro a borrar, reacomoda los apuntadores
CATALOGO *eliminar_libro_enmedio(CATALOGO *c, long del);//por medio de un if entra a esta funcion y reacomoda los apuntadores para eliminar el libro
CATALOGO *eliminar_libro_final(CATALOGO *c, long del);//por medio de un if entra a esta funcion, reacomoda la lista
//doble ligada para eliminar sin perder informacion

#endif