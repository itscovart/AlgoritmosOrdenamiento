#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void QuickSort(int *A, int p,int r);
int Pivot(int *A, int p,int r);
void Intercambiar(int *A, int i, int j);

int main(int argc, char *argv[]){
  clock_t t_inicio, t_final;
  double t_intervalo;

  if(argc != 2){
    printf("Porfavor ingresa la cantidad de números a ordenar, por ejemplo [user@equipo], %s, 100", argv[0]);
    exit(1);
  }

  int n, *A;

  n = atoi(argv[1]);
  A = malloc(n * sizeof(int));

  if(A == NULL){
    printf("Error al intentar reserver memoria para %d elementos\n", n);
    exit(1);
  }
  
  for(int i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  t_inicio = clock();
  QuickSort(A, 0, n - 1);
  t_final = clock();

  t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;
  printf("\nTiempo medido: %.10f segundos.", t_intervalo);

  for(int i = 0; i < n; i++){
    printf("\nNumero[%d]: %d", i, A[i]);
  }

  exit(0);
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