#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void MergeSort(int *A, int p, int r);
void Merge(int *A, int p, int q, int r);

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
  MergeSort(A, 0, n - 1);
  t_final = clock();

  t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;
  printf("\nTiempo medido: %.10f segundos.", t_intervalo);

  for(int i = 0; i < n; i++){
    printf("\nNumero[%d]: %d", i, A[i]);
  }

  exit(0);
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