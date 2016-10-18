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
	fclose(fp);
    fgets(linea, sizeof(linea), stdin);
    sscanf(linea, "%i", &consultas);
	for(i = 0; i < consultas; i++){
		fgets(linea, sizeof(linea), stdin);
		sscanf(linea, "%d %d", &pos, &peso);
		numero = busqueda_num(Parentesis, valores, peso, pos);
        printf("%i\n", numero);
	}
	return 0;
}
