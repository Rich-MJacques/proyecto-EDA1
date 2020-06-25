#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "catalogo.h"
#include "libro.h"
#include "carrito.h"
#include <conio.h>

void main(){
    printf("Leyendo inventario\n");
    int i, op;
    int NUM =20;
    char opc='\0',opc1;
    bool bandera = false;
    bool bandera2 = false;
    long del;
    FILE *f;
    f = fopen ("librosventa.txt", "r");
    if(f == NULL){
        printf("Error de apertura\n");
    }else{
        LIBRO infor[NUM];
        for( i= 0; !feof(f) ; i++){
            fscanf(f, "%s\t", infor[i].INFO.titulo);           
            fscanf(f, "%s\t", infor[i].INFO.autor);
            fscanf(f, "%s\t", infor[i].INFO.editorial);
            fscanf(f, "%ld\t", &infor[i].INFO.ISBN);
            fscanf(f, "%s\t", infor[i].INFO.formato);
            fscanf(f, "%d\t", &infor[i].INFO.existencia);
            fscanf(f, "%f\n", &infor[i].INFO.precio);
        }
        fclose(f);
        printf("ya guarde %d libros del inventario\n",i);
        CATALOGO *c;
        c = crear_catalogo();
        if(c != NULL){
            c->head = &infor[0];
            c->tail = &infor[NUM-1];
            c->head->prev = c->tail;
            c->tail->next = c->head;
            LIBRO *t;
            int i;
            for(t = c->head, c->tam = 0 , i = 1; t->next == c->head, i <  NUM; t = t->next, i++){
                t->next = &infor[i];
                c->tam++;
            }
            for(t = c->tail, i = 20; t->prev != c->tail, i >= 0; t = t->prev, i--){
                t->prev = &infor[i];
            }
        }
        CARRITO *carrito = crear_carrito();
    while(opc!='3'){
        opc1= '0';
        printf("	 1:Administrador \n");
        printf("	 2:Cliente\n");
        printf("	 3:Salir \n");
        opc=getch();

    switch(opc){
        case '1':{
        while(opc1!='5'){
    	    printf("1) AGREGAR LIBROS PARA LA VENTA\n");
            printf("2) DAR DE BAJA A UN LIBRO\n");
            printf("3) AGREGAR EXISTENCIA DE UN LIBRO\n");
            printf("4) VISUALIZAR LOS LIBROS DE LA TIENDA\n ");
            printf("5:Salir \n");
    		opc1=getch();

    		switch(opc1)
            {
    			case '1':{
                    //Agregar libros a catalogo
                    printf("tam ahora es %d\n",c->tam);  
                    cargar_libros(c);             //si aumenta a tam
                    printf("tam ahora es %d\n",c->tam);
    			break;
                }
                case '2':{
                   	//Quitar un libro de catalogo
                    long del;
                    printf("Ingrese el ISBN del libro a eliminar:\n");
                    printf("El ISBN primero elemento de c es:%ld\n", c->head->INFO.ISBN);
                    printf("El ISBN Ultimo elemento de c es:%ld\n", c->tail->INFO.ISBN);
                    scanf("%ld", &del);
                    eliminar_libro_inicio(c, del);
                    eliminar_libro_enmedio(c, del);
                    eliminar_libro_final(c, del);
                    actualizar_catalogo(c);
                    
                break;
                }
                case '3':{
                   	//Agregar existencias
                    modificar_existencias(c);
                break;
                }
                case '4':{
                    //Imprimir catalogo
                    actualizar_catalogo(c);
                    imprimir_catalogo(c);
                break;
                }
                case '5':{//volver
                    int resultado=0;
                    printf("1: PARA SALIR \n");
                    printf("2: VOLVER AL MENU INICIAL\n");
                    scanf("%d",&resultado);
                    if(resultado==1){
                        opc='3';
                    }else
                        opc='0';
                break;
                }
                case '6':{
                    printf ("opcion 5");
                    getchar();
                    //   CAB=Ordenar(CAB);
                    getchar();
                break;
                }
            }
        }
    break;
    }

            case '2':{
                char opc2='\0', nombre[20];
                int respuesta=0;          
                printf("BIENVENIDO \n");
                printf("INDIQUE SU NOMBRE \n");
                scanf("%s",nombre);
                while(respuesta!=1){
                printf("¿Que quiere hacer?\n\n");
                printf("1. Mostrar catalogo\n");
                printf("2. Buscar por titulo\n");
                printf("3. Buscar por autor\n");
                printf("4. Buscar ISBN\n");
                printf("5. Agregar al carrito\n");//revisar
                printf("6. Eliminar libro del carrito\n");//revisar
                printf("7. Finalizar compra\n");//revisar :(
                printf("8. Cerrar sesion\n");

                opc2=getch();
                switch (opc2){
                    case '1':{
                        //Imprimir catalogo
                        imprimir_catalogo(c);
                        break;
                    }
                    case '2':{
                      	//buscar por titulo
                        buscar_libro_titulo(c);       
                        break;
                    }
                    case '3':{
                        //buscar por autor
                        buscar_libro_autor(c);
                        break;
                    }
                    case '4':{   
                        //Buscar por ISBN
                        buscar_libro_ISBN(c);
                        break;
                    }

                    case '5':{
                        anadir_libro_carrito(carrito,c); 
                        break;
                    }
                    case '6':{
                        //Eliminar libro
                        eliminar_libro_carrito(carrito);
                        break;
                    }
                    case '7':{
                        //Finalizar compra
                        agregar_libro_ticket(carrito); 
                        break;
                    }
                }
                    printf("SI DESEA SALIR DIGITE:1 \n");
                    printf("SI DESEA REGRESAR AL MENU CLIENTE DIGITE: 0\n");
                    scanf("%d",&respuesta);
                    getchar();
                    getchar();

                }
            break;
            }
        }

    }


    }
}

