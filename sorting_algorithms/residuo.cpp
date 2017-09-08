/**
  Diego Alejandro Rodriguez Ayala - 20142020068
  Practica para estudiar el algoritmo de ordenamiento por residuo y su comportamiento
  Ademas se calcula tiempo de ejecución del algoritmo para compararlo despues con el t(n) teorico.
**/
#include <stdio.h>
#include "sorting_algorithms.h"
#include <time.h>
//#include <windows.h>

inline unsigned bits(int k, int j, int x);
void residuo(int *array, int left, int right, int bit);
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

  srand(time(0));

  for (int i = 0; i < n; i++) {
    array[i] = rand()%7+8; // Para 4 bits
    //array[i] = rand()%128+128; // Para 8 bits
    //array[i] = rand()%32808+32727; // Para 16 bits
  }

  printf("\nArreglo:\n");
  printArray(array, n);

  // Mide tiempo de ejecución entre &t_ini y &t_fin
  //QueryPerformanceCounter(&t_ini);
  residuo(array, 0, n-1, 3); // Para 4 bits
  //residuo(array, 0, n-1, 7); // Para 8 bits
  //residuo(array, 0, n-1, 15); // Para 16 bits
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

// Algoritmo de ordenamiento por residuo (bit: cantidad de bits a bits a evaluar)
void residuo(int *array, int left, int right, int bit) {

  int i, j;

  if ((right > left) && (bit >= 0)) {
    i = left;
    j = right;
    while (j != i) {
      while ((!bits(bit, 1, array[i])) && (i < j)) {
        i++;
      }
      while ((bits(bit, 1, array[j])) && (j > i)) {
        j--;
      }
      exchange(array, i, j);
    }
    if (!bits(bit, 1, array[i])) {
      j++;
    }
    residuo(array, left, j-1, bit-1);
    residuo(array, j, right, bit-1);
  }
}

inline unsigned bits(int k, int j, int x) {
  
  return (x>>k) & ~(~0<<j);
}
/*
// Funcion para medir tiempo de ejecución (windows) - agregar include <windows.h>
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b) {

  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);

  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
*/
