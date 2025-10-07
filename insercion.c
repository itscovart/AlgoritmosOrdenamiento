/*
Autor: Arturo Covarrubias Sanchez
Nombre Alumno: Arturo Covarrubias Sanchez
Grupo: 2BM2
Fecha: 05 / Octubre / 2025
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  int i, j, temp, *A;

  int n = atoi(argv[1]);
  A = malloc(n * sizeof(int));
  if(A == NULL){
    printf("Error al intentar reserver memoria para %d elementos\n", n);
    exit(1);
  }

  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  //Ordenamiento por seleccion
  for(i = 1; i < n - 1; i++){
    j = i;
    temp = A[i];
    while(j > 0 && temp < A[j - 1]){
			A[j] = A[j - 1];
			j--;
		}
		A[j] = temp;
  }

  //Imprimir arreglo ordenado
  for(i = 0; i < n; i++){
    printf("Numero %d: %d\n", i + 1, A[i]);
  }
  return 0;
}