/**
  Diego Alejandro Rodriguez Ayala - 20142020068
  Practica para estudiar el algoritmo de ordenamiento Merge Sort y su comportamiento
  Ademas se calcula tiempo de ejecución del algoritmo para compararlo despues con el t(n) teorico.
**/
#include <stdio.h>
#include <time.h>
#include "sorting_algorithms.h"
//#include <windows.h>

using namespace std;

void mergeSort(int *array, int first, int last);
void mergeList(int *array, int start1, int end1, int start2, int end2);
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
  mergeSort(array, 0, n-1); // Algoritmo de ordenamiento - Merge Sort
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

// Algoritmo de ordenamiento Merge Sort (Default first: 0, last: n-1)
void mergeSort(int *array, int first, int last) {

  int middle;

  if (first < last) {
      middle = (first+last)/2;
      mergeSort(array, first, middle);
      mergeSort(array, middle+1, last);
      mergeList(array, first, middle, middle+1, last);
  }
}

void mergeList(int *array, int start1, int end1, int start2, int end2) {

  int finalStart, finalEnd, indexC, *result;

  finalStart = start1;
  finalEnd = end2;
  indexC = 1;
  result = new int[end1+end2];

  while ((start1 <= end1) && (start2 <= end2)) {
    if (array[start1] < array[start2]) {
      result[indexC] = array[start1];
      start1++;
    } else {
      result[indexC] = array[start2];
      start2++;
    }
    indexC++;
  }

  if (start1 <= end1) {
    for (int i = start1; i <= end1; i++) {
      result[indexC] = array[i];
      indexC++;
    }
  } else {
    for (int i = start2; i <= end2; i++) {
      result[indexC] = array[i];
      indexC++;
    }
  }

  indexC = 1;

  for (int i = finalStart; i <= finalEnd; i++) {
    array[i] = result[indexC];
    indexC++;
  }

  delete []result;
}
/*
// Funcion para medir tiempo de ejecución (windows) - agregar include "windows.h"
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){

  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);

  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
*/
