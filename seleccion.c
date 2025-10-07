/*
Autor: Arturo Covarrubias Sanchez
Nombre Alumno: Arturo Covarrubias Sanchez
Grupo: 2BM2
Fecha: 05 / Octubre / 2025
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  int i, j, k, temp, *A;

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
  for(i = 0; i < n - 1; i++){
    k = i;
    for(j = k + 1; j < n; j++){
      if(A[j] < A[k]){
        k = j;
      }
    }
    temp = A[k];
		A[k] = A[i];
		A[i] = temp;
  }

  //Imprimir arreglo ordenado
  for(i = 0; i < n; i++){
    printf("Numero %d: %d\n", i + 1, A[i]);
  }
  return 0;
}