#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

tCola * newCola (int capacidad){
    tCola *cola;
    cola = (tCola *)malloc(sizeof(tCola));
    cola ->contenido = (char *)malloc(sizeof(capacidad));
    cola ->size = 0;
    cola ->maximoElementos = capacidad;
    cola ->primero = 0;
    cola ->final = -1;
    return cola;
}

char dequeue(tCola * cola){
    char elemento;
    if(cola ->size == 0){
        printf("La cola está vacia men\n");
        elemento = 'f';
    }
    else{
        elemento = cola->contenido[cola->primero];
        cola->size--;
        cola->primero++;
        if(cola->primero ==cola->maximoElementos){
            cola->primero = 0;
        }
    }
    return elemento;
}

int enqueue(tCola * cola, char elemento){
    if(cola->size == cola->maximoElementos){
        printf("Cola llena, no se puede encolar algo más :(\n");
        return 0;
    }
    else{
        cola->size++;
        cola->final = cola->final + 1;
        if(cola->final == cola->maximoElementos){
            cola->final = 0;
        }
        cola->contenido[cola->final] = elemento;
    }
    return 1;
}
