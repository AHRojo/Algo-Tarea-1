#include <stdio.h>
#include <string.h>

int construirMatriz(){
    int i, j, Matriz[999][999];
    printf("hola\n");
    for(i = 0; i < 999; i++){
            Matriz[i][j] = fgets("%s", sizeof(char*999), stdin);
        }
    }
    for(i = 0; i < 999; i++){
        printf("%c", Matriz[i][0]);
    }
    return Matriz;
}

int main(){
    printf("hola\n");
    construirMatriz();

    return 0;
}
