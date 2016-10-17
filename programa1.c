#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    La variable datos guarda en las posiciones pares, la marca de la variable y en los impares
    el area que tiene.
*/

char Matriz[1000][1000];
int counter = 0, indice = 0, datos[1500];

/*
    La funcion recursivo, toma la posición entregada por el terminal (dicha posición siempre debe ser W),
    corresponde a un recorrido profundo, cada vez que encuentre una posición que contenga una W, se volvera a invocar
    y sumara 1 al total del area calculada.
    Ademas la función "marca" la posicion con un valor de la tabla ascii, en caso de que se repitan los valores ya escogidos.
*/

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

/*
    consultarArea recibe como parametro la palabra que recibio un valor distinto a W o L
    y lo descompone de forma que queden 2 valores, fila y columna. Luego revisara la Matriz
    en caso de que dicha posicion posea una W, significa que la posicion aun no ha sido revisada
    asi que llamara a la funcion recursiva para calcular el area.

    En caso de que haya una letra distinta a W o L, quiere decir que la posicion ya fue revisada o
    es una direccion no valida respectivamente, si ya fue revisada entonces buscara dentro de un arreglo
    el valor del codigo ascii y guardara el valor siguiente del arreglo.
*/

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
            if(Matriz[fila -1][columna - 1] == 'L'){
                printf("Direccion invalida.\n");
            }
            else{
                for(area = 0; area < indice; area += 2){
                    if(datos[area] == Matriz[fila - 1][columna - 1]){
                        area = datos[area + 1];
                        break;
                    }
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

/*
    La funcion main se encarga principalmente de copiar los valores que se ingresan por terminal
    correspondientes a la información de la matriz y luego llama a la funcion consultarArea,
    cuando se termina de trabajar con dicha matriz se resetean sus valores con la funcion memset

    Finalmente printea los valores del area guardadas en la variable datos.
*/

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
                consultarArea(Palabra);
                memset(Matriz, 0, sizeof(Matriz[1000][1000])*1000*1000);
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
