/**
  Diego Alejandro Rodriguez Ayala - 20142020068
  Practica para estudiar el algoritmo de ordenamiento Quick Sort y su comportamiento
  Ademas se calcula tiempo de ejecución del algoritmo para compararlo despues con el t(n) teorico.
**/
#include <stdio.h>
#include <time.h>
#include "sorting_algorithms.h"
//#include <windows.h>

using namespace std;

void quickSort(int *array, int left, int right);
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
  fillArray(array, n); // Llena el arreglo de forma descendente

  printf("\nArray:\n");
  printArray(array, n);

  // Mide tiempo de ejecución entre &t_ini y &t_fin
  //QueryPerformanceCounter(&t_ini);
  quickSort(array, 0, n-1); // Algoritmo de ordenamiento - Quick Sort
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
/*
  Algoritmo de ordenamiento Quick Sort
    - *array: Arreglo
    - left: Posicion del primer valor del arreglo (izquierda)
    - right: Posicion del ultimo valor del arreglo (derecha)
*/
void quickSort(int *array, int left, int right) {

  int i, j, v;

  if (right > left) {
    v = array[right];
    i = left-1;
    j = right;
    for (;;) {
      while (array[++i] < v);
      while (array[--j] > v);
      if (i >= j) {
        break;
      }
      exchange(array, i, j);
    }
    exchange(array, i, right);
    quickSort(array, left, i-1); // Llamado recursivo por la izquierda
    quickSort(array, i+1, right); // Llamado recursivo por la derecha
  }
}
/*
// Funcion para medir tiempo de ejecución (windows) - agregar include "windows.h"
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){

  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);

  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
*/
