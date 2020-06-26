#include "libro.h"
#include "catalogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define flecha_der 77
#define flecha_izq 75

CATALOGO *crear_catalogo(){
    CATALOGO *c = (CATALOGO*)malloc (sizeof(CATALOGO));
    c->head = NULL;
    c->tail = NULL;
    c->tam = 0;
    return c;
}

void imprimir_catalogo(CATALOGO *c){
    int i;
    LIBRO *t1 = c->head;
    for(t1= c->head, i=0; t1->next != c->head, i <= c->tam ; t1 = t1->next, i++){
        printf("%i. %s\t %s\t %s\t %s\t %ld\t %d\t %f\n",i+1, t1->INFO.titulo, t1->INFO.autor, t1->INFO.editorial, t1->INFO.formato, t1->INFO.ISBN, t1->INFO.existencia, t1->INFO.precio);
    }
}

void buscar_libro_ISBN(CATALOGO *c){
    long del;
    printf("Introduzca el ISBN\n");
    scanf("%ld", &del);
    LIBRO *l = c->head;
    int i = 0;
    for (i ; i < c->tam; i++){
        if (del == l->INFO.ISBN){
            printf("El titulo es %s\n", l->INFO.titulo);
            printf("Autor: %s\n", l->INFO.autor);
            printf("Editorial: %s\n", l->INFO.editorial);
            printf("Formato: %s\n", l->INFO.formato);
            printf("Existencias: %d\n", l->INFO.existencia);
            printf("Precio: %f\n", l->INFO.precio);
        }
        l = l->next;
    }
    i++;
    if( i == c->tam){
        printf("El libro no se encuentra");
    }
}

void buscar_libro_titulo(CATALOGO *c){
    printf("Introduzca el titulo\n");
    char titulo[50];
    scanf("%s", titulo);
    LIBRO *l = c->head;
    int i = 0;
    for (i ; i < c->tam; i++){
        if (strcmp(titulo, l->INFO.titulo)==0){
            printf("Autor: %s\n", l->INFO.autor);
            printf("Editorial: %s\n", l->INFO.editorial);
            printf("ISBN: %ld\n", l->INFO.ISBN);
            printf("Formato: %s\n", l->INFO.formato);
            printf("Existencias: %d\n", l->INFO.existencia);
            printf("Precio: %f\n", l->INFO.precio);
        }
        l = l->next;
    }
    i++;
    if( i == c->tam){
        printf("El libro no se encuentra");
    }
}


void buscar_libro_autor(CATALOGO *c){
    printf("Introduzca el autor\n");
    char autor[50];
    scanf("%s", autor);
    LIBRO *l = c->head;
    int i = 0;
    for (i ; i < c->tam; i++){
        if (strcmp(autor, l->INFO.autor)==0){
            printf("Titulo: %s\n", l->INFO.titulo);
            printf("Autor: %s\n", l->INFO.autor);
            printf("Editorial: %s\n", l->INFO.editorial);
            printf("ISBN: %ld\n", l->INFO.ISBN);
            printf("Formato: %s\n", l->INFO.formato);
            printf("Existencias: %d\n", l->INFO.existencia);
            printf("Precio: %f\n", l->INFO.precio);
        }
        l = l->next;
    }
    i++;
    if( i == c->tam){
        printf("El libro no se encuentra");
    }
}


CATALOGO *cargar_libros(CATALOGO *c){
    LIBRO *l;
    l = crear_libro();
    printf("Ingrese datos del libro\n\n");
    printf("Ingrese autor:\n");
    scanf("%s", l->INFO.autor);
    printf("Ingrese titulo:\n");
    scanf("%s",l->INFO.titulo);
    printf("Ingrese Formato:\n");
    scanf("%s",l->INFO.formato);
    printf("Ingrese editorial:\n");
    scanf("%s",l->INFO.editorial);
    printf("Ingrese ISBN: \n");
    scanf("%ld", &l->INFO.ISBN);
    printf("Ingrese existencia: \n");
    scanf("%d", &l->INFO.existencia);
    printf("Ingrese precio: \n");
    scanf("%f", &l->INFO.precio);
    c->tail->next = NULL;
    c->head->prev = NULL;
    c->tail->next=l;
    l->prev = c->tail;
    c->tail = l;
    l->next = c->head;
    c->head->prev = l;
    c->tam++;  
    return c;
}

void actualizar_catalogo(CATALOGO *c){
    int i;
    FILE *ap;
    ap = fopen("librosventaactualizado.txt", "w");
    if(ap == NULL){
        printf("No se pudo abrir el archivo");
    }else{
        LIBRO *temp = c->head;
        //imprimir_catalogo(c);
        printf("El tamano del catalogo es: %d\n", c->tam+1);
        for(temp= c->head, i = 0; temp->next != c->head, i <= c->tam ; temp = temp->next, i++){
            fprintf(ap, "%d\t", i+1);
            fprintf(ap, "%s\t", temp->INFO.titulo);
            fprintf(ap, "%s\t", temp->INFO.autor);
            fprintf(ap, "%s\t", temp->INFO.editorial);
            fprintf(ap, "%ld\t", temp->INFO.ISBN);
            fprintf(ap, "%s\t", temp->INFO.formato);
            fprintf(ap, "%d\t", temp->INFO.existencia);
            fprintf(ap, "%f\n", temp->INFO.precio);
        }
    }
    fclose(ap);
}
    

LIBRO *actual(CATALOGO *c,int pos){
    LIBRO *t = c->head;
    int i = 0;
    while(t->next != c->head && i< pos){
        t=t->next;
    }
    return t;
}


LIBRO *ultimo(CATALOGO *c){
    LIBRO *t = c->head;
    while(t->next != c->head){
        t = t->next;
    }
    return t;
}

LIBRO *penultimo(CATALOGO *c){
    LIBRO *t = c->head;
    while(t->next->next = c->head){
        t = t->next;
    }
    return t;   
}

CATALOGO *modificar_existencias(CATALOGO *c){
    // bUSCAR libro por ISBN a modificar
    long del;
    printf("Introduzca el ISBN del libro a modificar\n");
    scanf("%ld", &del);
    LIBRO *l = c->head;
    int i = 0;
    for (i ; i < c->tam; i++){
        if (del == l->INFO.ISBN){
            int exi;
            printf("El titulo es %s\n", l->INFO.titulo);
            printf("Autor: %s\n", l->INFO.autor);
            printf("Existencias: %d\n", l->INFO.existencia);
            printf("Imgrese existencias a modificar\n");
            scanf("%d",&exi);
            l->INFO.existencia = exi;
            actualizar_catalogo(c);
        }
        l = l->next;
    }
    i++;
    if( i == c->tam){
        printf("El libro no se encuentra\n");
    }
    return c;

}

CATALOGO *eliminar_libro_inicio(CATALOGO *c, long del){
    if(c->head == NULL){
        printf("no hay catalogo\n");
    }
    if(del == c->head->INFO.ISBN){
        LIBRO *act, *prox;
        c->head->prev = NULL;
        c->tail->next = NULL;
        act = c->head;
        prox = act->next;
        act->next = NULL;
        prox->prev = NULL;
        c->head = prox;
        prox->prev = c->tail;
        c->tail->next = c->head;
        c->tam --;
        free(act);
        return c;
    }
}

CATALOGO *eliminar_libro_enmedio(CATALOGO *c, long del){
    if(c->head == NULL){
        printf("no hay catalogo\n");
    }else{
        LIBRO *b=c->head;
        int i;
        for(i=0, b; b->next != c->head, i < c->tam; b=b->next,i++ ){
            if(del == b->INFO.ISBN){
                LIBRO *prox,*ant;
                prox = b->next;
                ant = b->prev;
                b->next = NULL;
                b->prev = NULL;
                ant->next = prox;
                prox->prev = ant;
                free(b);
                b = NULL;
                c->tam--;
                return c;
            }
        }
    }
}
CATALOGO *eliminar_libro_final(CATALOGO *c, long del){
    if(c->head == NULL){
        printf("no hay catalogo\n");
    }
    if(del ==c->tail->INFO.ISBN){
        LIBRO *actual, *anterior;
        c->head->prev = NULL;
        c->tail->next = NULL;
        actual = c->tail;
        anterior = c->tail->prev;
        anterior->next = NULL;
        actual->prev = NULL;
        anterior = c->tail;
        c->head->prev = anterior;
        anterior->next = c->head;
        c->tam--;
        free(actual);
        return c;
    }
}

void recorrer_catalogo(CATALOGO *c){
    LIBRO *l = c->head;
    int flecha, salir;
    printf("presione enter\n");
    printf("Ahora puede ver el catalogo con las flechas derecha e izquierda\n");
	while( flecha != '1' ){
        printf("para salir presiona 1\n");
	    flecha = getch ();
	    if(flecha == flecha_der){
            printf("Titulo: %s\n", l->INFO.titulo);
            printf("Autor: %s\n", l->INFO.autor);
            printf("Editorial: %s\n", l->INFO.editorial);
            printf("ISBN: %ld\n", l->INFO.ISBN);
            printf("Formato: %s\n", l->INFO.formato);
            printf("Existencias: %d\n", l->INFO.existencia);
            printf("Precio: %f\n\n", l->INFO.precio);
            l = l->next;
        }
	    if(flecha == flecha_izq){
	        printf("Titulo: %s\n", l->INFO.titulo);
            printf("Autor: %s\n", l->INFO.autor);
            printf("Editorial: %s\n", l->INFO.editorial);
            printf("ISBN: %ld\n", l->INFO.ISBN);
            printf("Formato: %s\n", l->INFO.formato);
            printf("Existencias: %d\n", l->INFO.existencia);
            printf("Precio: %f\n\n", l->INFO.precio);
            l = l->prev;	
                                    
	    }       
    }
}
