/*
Autor: Arturo Covarrubias Sanchez
Nombre Alumno: Arturo Covarrubias Sanchez
Grupo: 2BM2
Fecha: 05 / Octubre / 2025
*/

#include <stdio.h>

void QuickSort(int *A, int p,int r);
int Pivot(int *A, int p,int r);
void Intercambiar(int *A, int i, int j);
int main(){
  int arrNumeros[5] = {2, 1, 7, 10, 1};
  int *A = arrNumeros;
  int p = 0, r = 4;
  QuickSort(A, p, r);
  for(int i = 0; i < 5; i++){
    printf("Numero %d: %d\n", i, A[i]);
  }
  return 0;
}

void QuickSort(int *A, int p,int r){
  if(p < r){
    int j = Pivot(A, p, r);
    QuickSort(A, p, j - 1);
    QuickSort(A, j + 1, r);
  }
}
int Pivot(int *A, int p,int r){
  int piv = A[p], i = p + 1, j = r;
  while (i < j){
    while (A[i] <= piv && i < r){
      i++;
    }
    while (A[j] > piv){
      j--;
    }
    if ( i < j){
      Intercambiar(A, i, j);
    }
  }
  Intercambiar(A, p, j);
  return j;
}
void Intercambiar(int *A, int i, int j){
  int temp = A[j];
  A[j] = A[i];
  A[i] = temp;
}