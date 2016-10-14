#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char Matriz[1000][1000];
int counter = 0, indice = 0, datos[1000];

int recursivo(int fila, int columna){
    Matriz[fila][columna] = 'A'+counter;
    int Area = 1;
    if(Matriz[fila - 1][columna - 1] == 'W'){
        Area += recursivo(fila - 1, columna - 1);
    }
    if(Matriz[fila][columna - 1] == 'W'){
        Area += recursivo(fila, columna - 1);
    }
    if(Matriz[fila + 1][columna - 1] == 'W'){
        Area += recursivo(fila + 1, columna - 1);
    }
    if(Matriz[fila + 1][columna] == 'W'){
        Area += recursivo(fila + 1, columna);
    }
    if(Matriz[fila + 1][columna + 1] == 'W'){
        Area += recursivo(fila + 1, columna + 1);
    }
    if(Matriz[fila][columna + 1] == 'W'){
        Area += recursivo(fila, columna + 1);
    }
    if(Matriz[fila - 1][columna + 1] == 'W'){
        Area += recursivo(fila - 1, columna + 1);
    }
    if(Matriz[fila - 1][columna] == 'W'){
        Area += recursivo(fila - 1, columna);
    }
    return Area;
}

void consultarArea(char *loc){
    int fila, columna, area;
    if(loc[0] == '\n') return;
    sscanf(loc, "%i %i", &fila, &columna);
    area = recursivo(fila - 1, columna - 1);
    datos[indice] = 'A'+counter;
    datos[indice + 1] = area;
    indice += 2;
    counter += 1;
    if (('A'+counter == 'W') || ('A'+counter == 'L')){
        counter += 1;
    }
    while(fgets(loc, sizeof(loc), stdin) != NULL && loc[0] != '\n'){
        sscanf(loc, "%i %i", &fila, &columna);
        if(Matriz[fila - 1][columna - 1] == 'W'){
            area = recursivo(fila - 1, columna - 1);
        }
        else{
            for(area = 0; area < indice; area += 2){
                if(datos[area] == Matriz[fila - 1][columna - 1]){
                    area = datos[area + 1];
                    break;
                }
            }
        }
        datos[indice] = counter;
        datos[indice + 1] = area;
        indice += 2;
        counter += 1;
        if (('A'+counter == 'W') || ('A'+counter == 'L')){
            counter += 1;
        }
    }
    datos[indice] = 0;
    indice += 2;
    return;
}

int main(){
    int i, n, j;
    char Palabra[1000];
    fgets(Palabra, sizeof(Palabra), stdin);
    sscanf(Palabra, "%i", &n);
    getchar();
    for(i = 0; i < n; i++){
        for(j = 0; j < 999; j++){
            fgets(Palabra, sizeof(Palabra), stdin);
            if ((Palabra[0] != 'W') && (Palabra[0] != 'L')){
                Matriz[i][0] = '\0';
                consultarArea(Palabra);
                break;
            }
            strcpy(Matriz[j], Palabra);
        }
    }
    i = 1;
    j = 0;
    while (1){
        if (datos[i] == 0){
            printf("\n");
            j++;
            i += 2;
            if(j == n) break;
        }
        else{
            printf("%i\n",datos[i]);
            i += 2;
        }
    }
    return 0;
}
