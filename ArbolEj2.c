#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
La idea del programa es que en mientras se encuentre dentro del rango de consultas posibles
se proceda a ver si el nodo visitado tiene mayor o igual peso al solicitado de ser asi,
se comprueba si ya se conocia uno mayor que este mas cerca de la raiz a traves del nivel arbol
para ir conociendo el valor del arbol se avanza en el arreglo de parentesis, mientras que 
para saber el valor del nodo se recorre el arreglo de enteros.

*/
int  busqueda_num(char* arreglo,int* numeros,int peso,int consultas){
  int nivel,i,mayor_num,menor_niv,j;
  nivel=-1;
  while (i<consultas){                           
    i=0;
    j=0;
    if (numeros[i]>peso){
      if (i==0){
        return 0;
      }
      if (menor_niv>nivel){
        menor_niv=nivel;
        mayor_num=i;
      }
      if ((strcmp(&arreglo[j],"(")) == 0){
        nivel++;
        j++;
        i++;
      }
      else{
        nivel--;
        j++;
      }
    }
    else{
    if ((strcmp(&arreglo[j],"(")) == 0){
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

int cantidad_nodos(char* archivo){
	FILE* arc;
	int nodos;
	arc=fopen(archivo,"r");
	fscanf(arc,"%d",&nodos);
	close(arc);
	return nodos;
	
	
	
}


/*
Y en el main se hacen Q iteraciones que como hemos visto cumplen con el tiempo total de ejecucion
ya que se ejecuta Q veces la funcion de arriba
*/int main(){
	FILE* archivo;
	int i,peso,pos;
	int nodos=cantidad_nodos("prueba.txt");
	int consultas;
	char parentesis[2*nodos];
	int valores[nodos];
	archivo=fopen("prueba.txt","r+");
	fscanf(archivo,"%d",&nodos);
	fget(parentesis, sizeof(parentesis), stdin);
	fget(valores, sizeof(valores), stdin);
	fscanf(archivo,"%d",&consultas);
	i=0;
	while (i<consultas){
		fscanf(archivo,"%d %d",&pos,&peso);
		printf("%d",busqueda_num(parentesis,valores,peso,pos));
	}
	return 0;
}
