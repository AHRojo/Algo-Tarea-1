#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int  busqueda_num(char* arreglo,int* numeros,int peso,int consultas){
  	int nivel,i,mayor_num=0,menor_niv = 1000000,j;
  	nivel=-1;
  	i=0;
  	j=0;
  	while (i<=consultas){
    	if (numeros[i]>peso){
      		if (i==0){
        		return 0;
      		}
      		if (arreglo[j] == '('){
        		nivel++;
        		j++;
        		i++;
      		}
      		else{
        		nivel--;
        		j++;
      		}
			if (menor_niv>nivel){
				menor_niv=nivel;
				mayor_num=i;
				mayor_num--;
			}
    	}
    else{
    	if (arreglo[j] == '('){
      		nivel++;
      		j++;
      		i++;
    	}
    	else{
      		nivel--;
      		j++;
    		}
  		}
	}
  	return mayor_num;
}

/*
    Lo unico que realiza main, es guardar en un arreglo los parentesis del arbol, y en otro arreglo de ints
    guardar los pesos de cada nodo.
    Ademas determina la cantidad de consultas que se realizaran en el programa.
*/

int main(){
	int i = 0, nodos, n, consultas, peso, pos, numero, j = 0;
    int counter = 0;
	char linea[1000001];
	FILE *fp;
	fp = fopen("input.dat", "r");
	fscanf(fp, "%d", &nodos);
	char Parentesis[nodos*2];
	int valores[nodos];
    fscanf(fp, "%s\n", Parentesis);
    fgets(linea, sizeof(linea), fp);
    n = strlen(linea);
	for(i = 0; i < n; i++){
        if((linea[i] == ' ') || (linea[i] == '\n')){
            linea[i] = '\0';
            sscanf(linea+j, "%i", &pos);
            valores[counter] = pos;
            j = i + 1;
            counter += 1;
        }
    }
    fgets(linea, sizeof(linea), fp);
    sscanf(linea, "%i", &consultas);
    printf("%i\n", consultas);
	for(i = 0; i < consultas; i++){
		fgets(linea, sizeof(linea), fp);
		sscanf(linea, "%d %d", &pos, &peso);
		numero = busqueda_num(Parentesis, valores, peso, pos);
        printf("%i\n", numero);
	}
    fclose(fp);
	return 0;
}
