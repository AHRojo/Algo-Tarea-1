#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cola.h"

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

void recorridoAncho(char **M, int k, int l){
    return;
}

void calcularArea(char **M){
    int i, j;
    char linea[10];
    while (1){
        fgets(linea, sizeof(linea), stdin);
        if(linea[0] == '\n'){
            break;
        }
        sscanf(linea, "%i %i", &i, &j);
        recorridoAncho(M, i, j);
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
    calcularArea(M);
    return 0;
}
