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

int counter = 0, indice = 0, pos = 0;
int values[999], prints[999];
char lectura[100];

int agregarVecinos(tCola * cola, tCoordenada * coordenada, char **M){
    int agregados = 0;
    tCoordenada * coordenadaVecino;
    int fila = coordenada->fila;
    int columna = coordenada->columna;
    if(fila == 0){
        if(columna == 0){
            if(M[fila][columna + 1] == 'W'){
                M[fila][columna + 1] = 'A'+counter;
                agregados += 1;
                coordenadaVecino = newCoordenada(fila, columna + 1);
                enqueue(cola, coordenadaVecino);
            }
            if(M[fila + 1][columna + 1] == 'W'){
                M[fila + 1][columna + 1] = 'A'+counter;
                agregados += 1;
                coordenadaVecino = newCoordenada(fila + 1, columna + 1);
                enqueue(cola, coordenadaVecino);
            }
            if(M[fila + 1][columna] == 'W'){
                M[fila + 1][columna] = 'A'+counter;
                agregados += 1;
                coordenadaVecino = newCoordenada(fila + 1, columna);
                enqueue(cola, coordenadaVecino);
            }
        }
        else if(columna == 999){
            if(M[fila][columna - 1]=='W'){
                M[fila][columna - 1] = 'A'+counter;
                agregados += 1;
                coordenadaVecino = newCoordenada(fila, columna - 1);
                enqueue(cola, coordenadaVecino);
            }
            if(M[fila + 1][columna - 1] == 'W'){
                M[fila + 1][columna - 1] = 'A'+counter;
                agregados += 1;
                coordenadaVecino = newCoordenada(fila + 1, columna - 1);
                enqueue(cola, coordenadaVecino);
            }
            if(M[fila + 1][columna] == 'W'){
                M[fila + 1][columna] = 'A'+counter;
                agregados += 1;
                coordenadaVecino = newCoordenada(fila + 1, columna);
                enqueue(cola, coordenadaVecino);
            }
        }
        else{
            if(M[fila][columna - 1] == 'W'){
                M[fila][columna - 1] = 'A'+counter;
                agregados += 1;
                coordenadaVecino = newCoordenada(fila, columna - 1);
                enqueue(cola, coordenadaVecino);
            }
            if(M[fila][columna + 1] == 'W'){
                M[fila][columna + 1] = 'A'+counter;
                agregados += 1;
                coordenadaVecino = newCoordenada(fila, columna + 1);
                enqueue(cola, coordenadaVecino);
            }
            if(M[fila +1][columna + 1] == 'W'){
                M[fila + 1][columna + 1] = 'A'+counter;
                agregados += 1;
                coordenadaVecino = newCoordenada(fila + 1, columna+1);
                enqueue(cola, coordenadaVecino);
            }
            if(M[fila + 1][columna] == 'W'){
                M[fila + 1][columna] = 'A'+counter;
                agregados += 1;
                coordenadaVecino = newCoordenada(fila + 1, columna);
                enqueue(cola, coordenadaVecino);
            }
            if(M[fila + 1][columna - 1] == 'W'){
                M[fila + 1][columna - 1] = 'A'+counter;
                agregados += 1;
                coordenadaVecino = newCoordenada(fila + 1, columna - 1);
                enqueue(cola, coordenadaVecino);
            }
        }
    }
    else if(fila == 999){
        if(columna == 0){
            if(M[fila - 1][columna] == 'W'){
                M[fila - 1][columna] = 'A'+counter;
                agregados += 1;
                coordenadaVecino = newCoordenada(fila - 1, columna);
                enqueue(cola, coordenadaVecino);
            }
            if(M[fila - 1][columna + 1] == 'W'){
                M[fila - 1][columna + 1] = 'A'+counter;
                agregados += 1;
                coordenadaVecino = newCoordenada(fila - 1, columna + 1);
                enqueue(cola, coordenadaVecino);
            }
            if(M[fila][columna + 1] == 'W'){
                M[fila][columna + 1] = 'A'+counter;
                agregados += 1;
                coordenadaVecino = newCoordenada(fila, columna + 1);
                enqueue(cola, coordenadaVecino);
            }
        }
        else if(columna == 999){
            if(M[fila][columna - 1] == 'W'){
                M[fila][columna - 1] = 'A'+counter;
                agregados += 1;
                coordenadaVecino = newCoordenada(fila, columna - 1);
                enqueue(cola, coordenadaVecino);
            }
            if(M[fila - 1][columna - 1] == 'W'){
                M[fila - 1][columna - 1] = 'A'+counter;
                agregados += 1;
                coordenadaVecino = newCoordenada(fila - 1, columna - 1);
                enqueue(cola, coordenadaVecino);
            }
            if(M[fila - 1][columna] == 'W'){
                M[fila - 1][columna] = 'A'+counter;
                agregados += 1;
                coordenadaVecino = newCoordenada(fila - 1, columna);
                enqueue(cola, coordenadaVecino);
            }
        }
        else{
            if(M[fila][columna - 1] == 'W'){
                M[fila][columna - 1] = 'A'+counter;
                agregados += 1;
                coordenadaVecino = newCoordenada(fila, columna - 1);
                enqueue(cola, coordenadaVecino);
            }
            if(M[fila - 1][columna - 1] == 'W'){
                M[fila - 1][columna - 1] = 'A'+counter;
                agregados += 1;
                coordenadaVecino = newCoordenada(fila - 1, columna - 1);
                enqueue(cola, coordenadaVecino);
            }
            if(M[fila - 1][columna] == 'W'){
                M[fila - 1][columna] = 'A'+counter;
                agregados += 1;
                coordenadaVecino = newCoordenada(fila - 1, columna);
                enqueue(cola, coordenadaVecino);
            }
            if(M[fila - 1][columna + 1] == 'W'){
                M[fila - 1][columna + 1] = 'A'+counter;
                agregados += 1;
                coordenadaVecino = newCoordenada(fila - 1, columna + 1);
                enqueue(cola, coordenadaVecino);
            }
            if(M[fila][columna + 1] == 'W'){
                M[fila][columna + 1] = 'A'+counter;
                agregados += 1;
                coordenadaVecino = newCoordenada(fila, columna + 1);
                enqueue(cola, coordenadaVecino);
            }
        }
    }
    else{
        if(M[fila - 1][columna - 1] == 'W'){
            M[fila - 1][columna - 1] = 'A'+counter;
            agregados += 1;
            coordenadaVecino = newCoordenada(fila - 1, columna - 1);
            enqueue(cola, coordenadaVecino);
            }
        if(M[fila - 1][columna] == 'W'){
            M[fila - 1][columna] = 'A'+counter;
            agregados += 1;
            coordenadaVecino = newCoordenada(fila - 1, columna);
            enqueue(cola, coordenadaVecino);
        }
        if(M[fila - 1][columna + 1] == 'W'){
            M[fila - 1][columna + 1] = 'A'+counter;
            agregados += 1;
            coordenadaVecino = newCoordenada(fila - 1, columna + 1);
            enqueue(cola, coordenadaVecino);
        }
        if(M[fila][columna + 1] == 'W'){
            M[fila][columna + 1] = 'A'+counter;
            agregados += 1;
            coordenadaVecino = newCoordenada(fila, columna + 1);
            enqueue(cola, coordenadaVecino);
        }
        if(M[fila + 1][columna + 1] == 'W'){
            M[fila + 1][columna + 1] = 'A'+counter;
            agregados += 1;
            coordenadaVecino = newCoordenada(fila + 1, columna + 1);
            enqueue(cola, coordenadaVecino);
        }
        if(M[fila + 1][columna] == 'W'){
            M[fila + 1][columna] = 'A'+counter;
            agregados += 1;
            coordenadaVecino = newCoordenada(fila + 1, columna);
            enqueue(cola, coordenadaVecino);
        }
        if(M[fila + 1][columna - 1] == 'W'){
            M[fila + 1][columna - 1] = 'A'+counter;
            agregados += 1;
            coordenadaVecino = newCoordenada(fila + 1, columna - 1);
            enqueue(cola, coordenadaVecino);
        }
        if(M[fila][columna - 1] == 'W'){
            M[fila][columna - 1] = 'A'+counter;
            agregados += 1;
            coordenadaVecino = newCoordenada(fila, columna - 1);
            enqueue(cola, coordenadaVecino);
        }
    }
    return agregados;
}

char** construirMatriz(){
    int i;
    char letra[999], **Matriz;
    Matriz = (char **)malloc(sizeof(char *)*999);
    for(i = 0; i < 999; i++){
        Matriz[i] = (char *)malloc(sizeof(char)*999);
    }
    //fgets(letra, sizeof(letra), stdin);
    for(i = 0; i < 999; i++){
        fgets(letra, sizeof(letra), stdin);
        if((letra[0] != 'W') && (letra[0] != 'L')){
        	strcpy(lectura, letra);
        	break;
        }
        strcpy(Matriz[i], letra);
    }
    return Matriz;
}

int recorridoAncho(char **M, tCola *Q){
    tCoordenada *Cord;
    int area = 0;
    while (SCola(Q) != 0){
        Cord = dequeue(Q);
        area += agregarVecinos(Q, Cord, M);
        }
    return area;
}


int buscarArea(char Letra){
    int area;
    for(area = 0; area < 999; area += 2){
        if(values[area] == Letra){
            return values[area + 1];
        }
    }
    printf("Variable no encontrada\n");
    return 0;
}

void calcularArea(char **M){
    int i, j, tamano;
    tCola *Cola;
    tCoordenada *Coordenada;
    while (1){
        if(lectura[0] == '\n'){
            break;
        }
        sscanf(lectura, "%i %i", &i, &j);
        if(M[i - 1][j - 1] != 'W'){
            tamano = buscarArea(M[i-1][j-1]);
            values[indice] = 'A'+counter;
            values[indice + 1] = tamano;
        }
        else{
            M[i - 1][j - 1] = 'A'+counter;
            Cola = newCola(999);
            Coordenada = newCoordenada(i - 1, j - 1);
            enqueue(Cola, Coordenada);
            tamano = 1;
            tamano += recorridoAncho(M, Cola);
            values[indice] = 'A'+counter;
            values[indice + 1] = tamano;
            }
        indice += 2;
        counter += 1;
        if(('A'+counter == 'W') || ('A'+counter == 'L')){
            counter += 1;
        }
        prints[pos] = tamano;
        pos += 1;
        //printf("%i\n", tamano);
        fgets(lectura, sizeof(lectura), stdin);
    }
   	prints[pos] = -1;
   	pos += 1;
    destroy(Cola);
    return;
}

void blackhole(char **M){
	int i;
	for(i = 0; i < 999; i++){
        free(M[i]);
    }
    free(M);
    return;
}

int main(){
    char **M, lec[100];
    int i, n, k;
    fgets(lec, sizeof(lec), stdin);
    sscanf(lec, "%i", &n);
    fgets(lec, sizeof(lec), stdin);
    for(i = 0; i < n; i++){
    	M = construirMatriz();
    	calcularArea(M);
    	blackhole(M);	
    }
    i = 0;
    while (1){
    	if(prints[i] == -1){
    		printf("\n");
    		i += 1;
    		k += 1;
    		if(k == n){
    			break;
    		}
    	}
    	else{
    		printf("%i\n", prints[i]);
    		i += 1;
    	}
    }
    return 0;
}
