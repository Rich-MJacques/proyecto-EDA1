#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carrito.h"
#include "libro.h"
#include "catalogo.h"

CARRITO *crear_carrito(){
    CARRITO *carrito = (CARRITO*)malloc(sizeof(CARRITO));
    carrito->head= NULL;
    carrito->tam = 0;
    return carrito;
}


CARRITO *anadir_libro_carrito(CARRITO *carrito, CATALOGO *c){
    long ISBN;
    int i = 0;
    int cantidad;
    if (carrito == NULL){
        CARRITO *carrito = crear_carrito();
        printf("Ingrese el ISBN del libro a agregar al carrito:\n");
        scanf("%ld",&ISBN);
        LIBRO *t = c->head;
        LIBRO *act = crear_libro();
        while(t != NULL){
            if(t->INFO.ISBN == ISBN){
                break;
            }
            t = t->next;
            i++;
        }
        printf("Titulo :%s\n", t->INFO.titulo);
        printf("Acutalmete hay :%d existencias\n", t->INFO.existencia);
        printf("Cuantas libros desea comprar?\n");
        scanf("%d",&cantidad);
        if( cantidad <= t->INFO.existencia && cantidad > 0){
            act->INFO.existencia = cantidad;
            t->INFO.existencia = t->INFO.existencia-cantidad;
            strcpy(act->INFO.titulo, t->INFO.titulo);
            strcpy(act->INFO.autor, t->INFO.autor);
            strcpy(act->INFO.editorial,t->INFO.editorial);
            act->INFO.ISBN = t->INFO.ISBN;
            strcpy(act->INFO.formato,t->INFO.formato);
            act->INFO.precio = t->INFO.precio;
            carrito->head = act;
            carrito->tam ++;
            printf("Libro agregado %d\n",carrito->tam);
            imprimir_carrito(carrito);
            actualizar_catalogo(c);
            return carrito;
        }else{
            printf("No hay suficientes existencias\n");
        }
    }else{
        printf("Ingrese el ISBN del libro a agregar al carrito:\n");
        scanf("%ld",&ISBN);
        LIBRO *t = c->head;
        LIBRO *act = crear_libro();
        while(t != NULL){
            if(t->INFO.ISBN == ISBN){
                break;
            }
            t= t->next;
            i++;
        }
        printf("Titulo :%s\n", t->INFO.titulo);
        printf("Acutalmete hay :%d existencias\n", t->INFO.existencia);
        printf("Cuantas libros desea comprar?\n");
        scanf("%d",&cantidad);
        if( cantidad <= t->INFO.existencia && cantidad > 0){
            act->INFO.existencia = cantidad;
            t->INFO.existencia = t->INFO.existencia-cantidad;
            strcpy(act->INFO.titulo, t->INFO.titulo);
            strcpy(act->INFO.autor, t->INFO.autor);
            strcpy(act->INFO.editorial,t->INFO.editorial);
            act->INFO.ISBN = t->INFO.ISBN;
            strcpy(act->INFO.formato,t->INFO.formato);
            act->INFO.precio = t->INFO.precio;
            act->next = carrito->head;
            carrito->head = act;
            carrito->tam ++;
            printf("Libro agregado %d\n",carrito->tam);
            imprimir_carrito(carrito);
            actualizar_catalogo(c);
            return carrito;
        }else{
            printf("No hay suficientes existencias\n");
        }  
    }
}


bool eliminar_libro_carrito(CARRITO *carrito){
    if(carrito == NULL){
        printf("El carrito está vacio\n");
        return false;
    }else{
        LIBRO *act = carrito->head;
        act->next = carrito->head;
        act->next = NULL;
        free(act);
        carrito->tam--;
    }
    return true;
}


PAGADO *crear_pagado(){
    PAGADO *ticket = (PAGADO*)malloc(sizeof(PAGADO));
    ticket->head =NULL;
    ticket->tam = 0;
    return ticket;
}


PAGADO *agregar_libro_ticket(CARRITO *carrito){
    PAGADO *ticket = crear_pagado();
    ticket->head =carrito->head;
    ticket->tam = carrito->tam;
    mostrar_ticket(ticket);
    imprimir_carrito(carrito);
    for(int i = 0; i <= carrito->tam-1; i++){
        ticket->tam ++;
    }
    return ticket;
}

void mostrar_ticket(PAGADO *ticket){
    int i;
    float operacion = 0;
    FILE *ap2;
    ap2 = fopen("ticketlibros.txt", "w");
    if(ap2 == NULL){
        printf("No se pudo abrir el archivo\n");
    }else{
        LIBRO *temp = ticket->head;
        printf("El tamano del ticket es: %d\n", ticket->tam+1);
        for(i = 0; temp->next != NULL, i < ticket->tam ; temp= temp->next,i++){
            float total= 0;
            fprintf(ap2, "%d\t", i+1);
            fprintf(ap2, "%s\t", "Libro");
            fprintf(ap2, "%s\t", temp->INFO.titulo);
            fprintf(ap2, "%s\t", temp->INFO.autor);
            fprintf(ap2, "%d\t", temp->INFO.existencia);
            fprintf(ap2, "%f\n\n", temp->INFO.precio);
            total = temp->INFO.precio*temp->INFO.existencia;
            operacion = operacion + total;
        }
        fprintf(ap2, "El total de la compra es:\t $%f", operacion);
    }
    fclose(ap2);
}

void imprimir_carrito(CARRITO *carrito){
    LIBRO *temp = carrito->head;
    for(int i = 0; i <= carrito->tam-1; i++){
        printf("El titulo agregado es %s\n", temp->INFO.titulo);
        temp = temp->next;
    }
    return ;
}