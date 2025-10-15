#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int *A, int n);

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

  fprintf(archivo, "\nBurbuja,");

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
    BubbleSort(A, n);
    t_final = clock();
    
    
    t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;
    fprintf(archivo, "%.10f,", t_intervalo);

    printf("Agregado exitosamente el tiempo del ordenamiento burbuja con %s\n", argv[i]);
    free(A);

  }

  fclose(archivo);

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