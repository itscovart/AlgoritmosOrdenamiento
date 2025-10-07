/*
Autor: Arturo Covarrubias Sanchez
Nombre Alumno: Arturo Covarrubias Sanchez
Grupo: 2BM2
Fecha: 05 / Octubre / 2025
*/

#include <stdio.h>

int main(){
  int arrNumeros[5] = {2, 1, 7, 10, 1};
  int *A = arrNumeros;
  int i, j, aux, n = 5;
  for(i = 0; i < n; i++){
    for(j = 0; j < n - i - 1; j++){
      if(A[j] > A[j + 1]){
        aux = A[j];
        A[j] = A[j + 1];
        A[j + 1] = aux;
      }
    }
  }
  for(i = 0; i < n; i++){
    printf("Numero %d: %d\n", i, A[i]);
  }
  return 0;
}