#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE *archivo;

  archivo = fopen("Tiempos.csv", "w");
  if(!archivo){
    printf("No se pudo inicializar el archivo");
    exit(1);
  }

  fprintf(archivo, "n,500,1000,5000,10000,50000,100000,200000,500000,750000,1000000");
  fclose(archivo);

  printf("Columnas escritas exitosamente en el archivo");
  system("./seleccion numeros1M.txt 500 1000 5000 10000 50000 100000 200000 500000 750000 1000000");
  system("./insercion numeros1M.txt 500 1000 5000 10000 50000 100000 200000 500000 750000 1000000");
  system("./burbuja numeros1M.txt 500 1000 5000 10000 50000 100000 200000 500000 750000 1000000");
  system("./merge numeros1M.txt 500 1000 5000 10000 50000 100000 200000 500000 750000 1000000");
  system("./quick numeros1M.txt 500 1000 5000 10000 50000 100000 200000 500000 750000 1000000");
  system("./shell numeros1M.txt 500 1000 5000 10000 50000 100000 200000 500000 750000 1000000");
  exit(0);
}