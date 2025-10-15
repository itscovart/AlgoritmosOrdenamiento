#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void QuickSort(int *A, int p,int r);
int Pivot(int *A, int p,int r);
void Intercambiar(int *A, int i, int j);

int main(int argc, char *argv[]){
  
  FILE *archivo, *entrada;
  clock_t t_inicio, t_final;
  double t_intervalo;
  
  entrada = fopen(argv[1], "r");
  archivo = fopen("Tiempos.csv", "a");

  if(!entrada){
    printf("No se pudo abrir el archivo");
    exit(1);
  }

  if(!archivo){
    printf("No se pudo abrir el archivo");
    exit(1);
  }

  fprintf(archivo, "\nQuick,");

  if(argc < 3){
    printf("Porfavor ingresa el nombre del archivo de los numeros y la cantidad de números a ordenar, por ejemplo [user@equipo], %s numeros.txt 100", argv[0]);
    exit(1);
  }

  int n, *A;

  for(int i = 2; i < argc; i++){
    rewind(entrada);
    n = atoi(argv[i]);
    A = malloc(n * sizeof(int));
    
    if(A == NULL){
      printf("Error al intentar reserver memoria para %d elementos\n", n);
      exit(1);
    }
    
    for(int j = 0; j < n; j++){
      fscanf(entrada, "%d", &A[j]);
    }
    
    t_inicio = clock();
    QuickSort(A, 0, n - 1);
    t_final = clock();
    
    
    t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;
    fprintf(archivo, "%.10f,", t_intervalo);

    printf("Agregado exitosamente el tiempo del ordenamiento quick con %s\n", argv[i]);
    free(A);

  }

  fclose(archivo);

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