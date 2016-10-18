#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int  busqueda_num(char* arreglo,int* numeros,int peso,int consultas){
  	int nivel,i,mayor_num,menor_niv = 0,j;
  	nivel=0;
  	i=0;
  	j=0;
  	printf("%i\n", numeros[0]);
  	while (i<consultas){  
  		printf("HOLA\n");                       
    	if (numeros[i]>peso){
    		printf("onegai\n");
      		if (i==0){
        		return 0;
      		}
      		if (menor_niv>nivel){
      			printf("onegai\n");
        		menor_niv=nivel;
        		mayor_num=i;
      		}
      		if (arreglo[j] == '('){
      			printf("onegai\n");
        		nivel++;
        		j++;
        		i++;
      		}
      		else{
      			printf("onegai\n");
        		nivel--;
        		j++;
      		}
    	}
    else{
    	if (arreglo[j] == '('){
    		printf("onegai\n");
      		nivel++;
      		j++;
      		i++;
    	}
    	else{
    		printf("onegai\n");
      		nivel--;
      		j++;
    		}
  		}
	}
  	return mayor_num;
}

int main(){
	int i = 0, nodos, n, consultas, peso, pos, numero, total, j = 0, k = 0;
	char linea[1000001];
	FILE *fp;
	fp = fopen("input.dat", "r");
	fscanf(fp, "%d", &nodos);
	char Parentesis[nodos*2];
	int valores[nodos];
	fscanf(fp, "%s", &Parentesis);
	fgets(linea, sizeof(linea), fp);
	char num[10];
	while(linea[i] != '\0'){
		j = 0;
		num[j] = linea[i];
		j++;
		while((linea[i+1] != '0') && (linea[i+1] != '1') && (linea[i+1] != '2') && (linea[i+1] != '3') && (linea[i+1] != '4') && (linea[i+1] != '5') && (linea[i+1] != '6') && (linea[i+1] != '7') && (linea[i+1] != '8') && (linea[i+1] != '9')){
			num[j] = linea[i+1];
			i++;
			j++;
		}
		num[j+1] = ' ';
		valores[k] = atoi(num);
		k++;
		i++;
	}
	printf("%i %i %i", valores[0], valores[1], valores[2]);

	//
	fclose(fp);
	for(i = 0; i < consultas; i++){
		fgets(linea, sizeof(linea), stdin);
		sscanf(linea, "%d %d", &pos, &peso);
		numero = busqueda_num(Parentesis, valores, peso, pos);
		printf("%i\n", numero);
	}
	return 0;
}
