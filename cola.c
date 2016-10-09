#include <stdio.h>
#include <stdlib.h>
#include "cola.h"


tCola * newCola (int capacidad){
    tCola *cola;
    cola = (tCola *)malloc(sizeof(tCola));
    cola ->contenido = (tCoordenada *)malloc(sizeof(tCoordenada) * capacidad);
    cola ->size = 0;
    cola ->maximoElementos = capacidad;
    cola ->primero = 0;
    cola ->final = -1;
    return cola;
}

tCoordenada * dequeue(tCola * cola){
    tCoordenada * elemento;
    if(cola ->size == 0){
        printf("La cola está vacia men\n");
    }
    else{
        elemento = &cola->contenido[cola->primero];
        cola->size--;
        cola->primero++;
        if(cola->primero ==cola->maximoElementos){
            cola->primero = 0;
        }
    }
    return elemento;
}

int enqueue(tCola * cola, tCoordenada * elemento){
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
        cola->contenido[cola->final] = *elemento;
    }
    return 1;
}

void destroy(tCola * cola){
    for(int i = 0; i < cola->maximoElementos;i++){
        free(cola->contenido[i]);
    }
    free(cola->contenido);
    free(cola);
    return;
}
