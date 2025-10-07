/*
Autor: Arturo Covarrubias Sanchez
Nombre Alumno: Arturo Covarrubias Sanchez
Grupo: 2BM2
Fecha: 05 / Octubre / 2025
*/

#include <stdio.h>
#include <math.h>

void MergeSort(int *A, int p, int r);
void Merge(int *A, int p, int q, int r);
int main(){
  int arrNumeros[5] = {2, 1, 7, 10, 1};
  int *A = arrNumeros;
  int p = 0, r = 4;
  MergeSort(A, p, r);
  for(int i = 0; i < 5; i++){
    printf("Numero %d: %d\n", i, A[i]);
  }
  return 0;
}

void MergeSort(int *A, int p, int r){
  if(p < r){
    int q = floor((p + r) / 2);
    MergeSort(A, p, q);
    MergeSort(A, q + 1, r);
    Merge(A, p, q, r);
  }
}

void Merge(int *A, int p, int q, int r){
  int l = r - p + 1, i=p, j = q + 1, k;
  int numerosCombinados[l];
  int *C = numerosCombinados;
  for(k = 0; k < l; k++){
    if(i <= q && j <= r){
      if(A[i]<A[j]){
        C[k] = A[i];
        i++;
      } else {
        C[k] = A[j];
        j++;
      }
    } else if (i <= q){
      C[k] = A[i];
      i++;
    } else {
      C[k] = A[j];
      j++;
    }
  }
  k = p;
  for(i = 0; i < l; i++){
    A[k]=C[i];
    k++;
  }
}