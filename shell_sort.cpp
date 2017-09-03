/**
  Diego Alejandro Rodriguez Ayala - 20142020068
  Practica para estudiar el algoritmo de ordenamiento shell y su comportamiento
  Ademas se calcula tiempo de ejecución del algoritmo para compararlo despues con el t(n) teorico.
**/
#include <stdio.h>
#include <time.h>
#include "sorting_algorithms.h"
//#include <windows.h>

using namespace std;

void shellSort(int *array, int n);
//double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);

int main(int argc, char const *argv[]) {

  int *array, n;
  /*
  double secs = 0;
  LARGE_INTEGER t_ini, t_fin;

  FILE *archivo;
  archivo = fopen("tiempo.txt", "a");
  */
  srand(time(0));

  printf("Ingrese el valor de N (N>=20): ");
  scanf("%i", &n);

  array = new int[n];

  int randNum = rand()% 9999+1000; // Genera un numero aleatorio entre 1000 a 9999

  for (int i = 0; i < n; i++) {
    array[i] = randNum-i;
  }

  printf("\nArreglo:\n");
  printArray(array, n);

  // Mide tiempo de ejecución entre &t_ini y &t_fin
  //QueryPerformanceCounter(&t_ini);
  shellSort(array, n); // Algoritmo de ordenamiento - Shell
  //QueryPerformanceCounter(&t_fin);

  printf("\nArreglo Ordenado:\n");
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
// Algoritmo de ordenamiento Shell Sort (n>=20)
void shellSort(int *array, int n) {

  int i, j, h, v;

  for (h = 0; h < (n-1)/9 ; h = 3*h+1);
  for (; h > 0; h/=3) {
    for (i = h; i < n; i++) {
      v = array[i];
      j = i;
      while ((j >= h) && (array[j-h] > v)) {
        array[j] = array[j-h];
        j-=h;
      }
      array[j] = v;
    }
  }
}
/*
// Funcion para medir tiempo de ejecución (windows) - agregar include <windows.h>
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b) {

  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);

  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
*/
