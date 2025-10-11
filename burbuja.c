#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int *A, int n);

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
  BubbleSort(A, n);
  t_final = clock();

  t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;
  printf("\nTiempo medido: %.10f segundos.", t_intervalo);

  for(int i = 0; i < n; i++){
    printf("\nNumero[%d]: %d", i, A[i]);
  }
  
  exit(0);
}
void BubbleSort(int *A, int n){
  int aux;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n - i - 1; j++){
      if(A[j] > A[j + 1]){
        aux = A[j];
        A[j] = A[j + 1];
        A[j + 1] = aux;
      }
    }
  }
}