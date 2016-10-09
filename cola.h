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

tcola newCola(int);
tCoordenada * dequeue(tCola *);
int enqueue(tCola *,tCoordenada *);
void destroy(tCola *);
