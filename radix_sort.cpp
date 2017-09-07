/**
  Diego Alejandro Rodriguez Ayala - 20142020068
  Practica para estudiar el algoritmo de ordenamiento Radix Sort y su comportamiento
  Ademas se calcula tiempo de ejecución del algoritmo para compararlo despues con el t(n) teorico.
**/

#include <stdio.h>
#include <time.h>
#include "sorting_algorithms.h"
//#include <windows.h>

using namespace std;

void radixSort(int *array, int n);
int max(int *array, int n);
void sorting(int *array, int n, int exp);
//double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);

int main(int argc, char const *argv[]) {

  int *array, n;
  /*
  double secs = 0;
  LARGE_INTEGER t_ini, t_fin;
  FILE *archivo;
  archivo = fopen("tiempo.txt", "a");
  */
  printf("Ingrese el valor de N: ");
  scanf("%i", &n);

  array = new int[n];

  srand(time(0)); // Planta semilla para generar un random diferente

  for (int i = 0; i < n; i++) {
    array[i] = 1000+rand()%(10000-1000); // Para 4 cifras
    //array[i] = 10000000+rand()%(100000000-10000000); // Para 8 cifras
  }

  printf("\nArray:\n");
  printArray(array, n);

  // Mide tiempo de ejecución entre &t_ini y &t_fin
  //QueryPerformanceCounter(&t_ini);
  radixSort(array, n); // Algoritmo de ordenamiento - Radix Sort
  //QueryPerformanceCounter(&t_fin);

  printf("\nArray Ordenado:\n");
  printArray(array, n);
  /*
  secs = performancecounter_diff(&t_fin, &t_ini);
  printf("\nTime: %.16g milliseconds\n", secs*1000.0);

  fprintf(archivo, "\n%.16g", secs*1000.0);
  fclose (archivo);
  */
  delete []array;

  return 0;
}

// Algoritmo de ordenamiento Radix Sort
void radixSort(int *array, int n) {

  int m = max(array, n);

  for (int exp = 1; m/exp > 0; exp*=10) {
    sorting(array, n, exp);
  }
}

// Función para encontrar el numero maximo de un arreglo
int max(int *array, int n) {

  int max = array[0];

  for (int i = 1; i < n; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }

  return max;
}

// Función para ordenar por base 10 y exponente (10, 10^2, 10^3,...)
void sorting(int *array, int n, int exp){

  int output[n];
  int i, count[10] = {0};

  for (i = 0; i < n; i++) {
    count[(array[i]/exp)%10]++;
  }

  for (i = 1; i < 10; i++) {
    count[i]+=count[i-1];
  }

  for (i = n-1; i >= 0; i--) {
    output[count[(array[i]/exp)%10]-1] = array[i];
    count[(array[i]/exp)%10]--;
  }

  for (i = 0; i < n; i++) {
    array[i] = output[i];
  }
}
