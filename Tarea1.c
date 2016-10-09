#include <stdio.h>
#include <string.h>

char** construirMatriz(){
    int i;
    char letra[999], **Matriz;
    Matriz = malloc(sizeof(char)*999);
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

int main(){
    return 0;
}
