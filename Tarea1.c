#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cola.h"

/*
    Constructor de matriz de tierras, se crea un arreglo de arreglos a traves de memoria dinamica,
    cada arreglo interno corresponde a cada linea entregada por la linea de comando. como no se sabe cuantas filas tendra
    la matriz se utiliza el valor maximo posible, a diferencia de las columnas las cuales corresponderan al largo
    de la fila
*/

char** construirMatriz(){
    int i;
    char letra[999], **Matriz;
    Matriz = (char **)malloc(sizeof(char *)*999);
    for(i = 0; i < 999; i++){
        Matriz[i] = (char *)malloc(sizeof(char)*999);
    }
    fgets(letra, sizeof(letra), stdin);
    for(i = 0; i < 999; i++){
        fgets(letra, sizeof(letra), stdin);
        if(letra[0] == '\n') break;
        strcpy(Matriz[i], letra);
    }
    return Matriz;
}

int recorridoAncho(char **M, tCola *Q){
    tCoordenada *Cord;

    while(SCola(Q) != 0){
        Cord = dequeue(Q);
        //if(Cord->fila )
    }
    return 0;
}

int buscarArea(char **M, int i, int j){
    return 0;
}

void calcularArea(char **M){
    int i, j, tamano;
    tCola *Cola;
    char linea[10];
    while (1){
        fgets(linea, sizeof(linea), stdin);
        if(linea[0] == '\n'){
            break;
        }
        sscanf(linea, "%i %i", &i, &j);
        if(M[i][j] == 'V'){
            tamano = buscarArea(M, i, j);
        }
        else{
            M[i][j] = 'P';
            Cola = newCola(999);
            tCoordenada *Coordenada = (tCoordenada *)malloc(sizeof(tCoordenada));
            Coordenada->fila = i;
            Coordenada->columna = j;
            enqueue(Cola, Coordenada);
            tamano = 1;
            tamano += recorridoAncho(M, Cola);
        }
    }
    for(i = 0; i < 999; i++){
        free(M[i]);
    }
    free(M);
    return;
}

int main(){
    char **M;
    M = construirMatriz();
    //calcularArea(M);
    return 0;
}
