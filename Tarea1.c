#include <stdio.h>
#include <string.h>

int construirMatriz(){
    int i;
    char fila[999], Matriz[999][999];
    for(i = 0; i < 999; i++){
        fgets(fila, sizeof(fila), stdin);
        strcpy(Matriz[i], fila);
        if (strcmp(fila, "\n") == 0){
            break;
        }
    }
    return 0;
}

int main(){
    return 0;
}
