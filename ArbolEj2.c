typedef struct guarda{
  int nivel;
  int ;
}num;





int * busqueda_num(char* arreglo,int* numeros,int peso,int consultas){
  int nivel,i,mayor_num,menor_niv,j;
  nivel=-1;
  while (i<consultas){
    i=0;
    if (numero[i]>peso){
      if (i==0){
        return 0;
      }
      if (menor_niv>nivel){
        menor_niv=nivel;
        mayor_num=i;
      }
    }
    if (strcmp(arreglo[j],"(")) == 0){
      nivel++;
      j++;
      i++;
    }
    else{
      nivel--;
      j++;
    }
  }
  return i;
}
