#ifndef _COLA_H_INCLUDED_
#define _COLA_H_INCLUDED_

typedef struct Coordenada{
    int fila;
    int columna;
}tCoordenada;

typedef struct Cola{
        int maximoElementos;
        int size;
        int primero;
        int final;
        tCoordenada * contenido;
}tCola;

tCola* newCola(int);
int SCola(tCola *);
tCoordenada * dequeue(tCola *);
int enqueue(tCola *,tCoordenada *);
void destroy(tCola *);

#endif
