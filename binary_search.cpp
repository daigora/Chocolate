/**
  Diego Alejandro Rodriguez Ayala - 20142020068
  Practica para estudiar el algoritmo de busqueda binaria y su comportamiento
  Ademas se calcula tiempo de ejecución del algoritmo para compararlo despues con el t(n) teorico.
**/
#include <stdio.h>
#include <time.h>
#include "sorting_algorithms.h"
//#include <windows.h>

using namespace std;

int binarySearch(int a[], int n, int wanted);
//double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);

int main(int argc, char const *argv[]) {

  int n, sought, pos;
  /**
  LARGE_INTEGER t_ini, t_fin;
  double secs = 0;

  FILE *archivo;
  archivo = fopen("tiempo.txt","a");
  **/
  printf("Ingrese el valor de N: ");
  scanf("%i", &n);

  srand(time(0)); // Planta semilla para generar un random diferente

  int array[n];

  int randNum = rand()%9999+1000; // Genera numeros de 1000 a 9999

  for(int i = 0; i < n; i++) {
    array[i] = randNum-i;
  }

  printf("\nArreglo:\n");
  printArray(array, n);

  selectionSort(array, n); // Algoritmo de ordenamiento - Seleccion

  printf("\nArreglo Ordenado:\n");
  printArray(array, n);

  printf("\nIngrese valor a buscar: ");
  scanf("%i", &sought);

  //sought = -1;

  pos = binarySearch(array, n, sought); // Busqueda binaria
  printf("\nValor [%i] encontrado en la posicion: %i\n", sought, pos);
  /**
  // Mide tiempo de ejecución entre &t_ini y &t_fin
  QueryPerformanceCounter(&t_ini);
  pos = busquedaBinaria(array, n, sought);
  QueryPerformanceCounter(&t_fin);

  secs = performancecounter_diff(&t_fin, &t_ini);
  fprintf(archivo,"\n%.16g",secs*1000.0);

  fclose (archivo);

  printf("\nTime: %.16g milliseconds\n", secs*1000.0);
  **/
  return 0;
}
/**
  Algoritmo de busqueda binaria - Peor caso: t(n) = log(n); Mejor caso: t(n) = 1
    - array[]: Arreglo
    - n: Tamaño del arreglo
    - sought: Valor buscado
**/
int binarySearch(int array[], int n, int sought){

  int middle;
  int left = 0;
  int right = n-1;

  while(left <= right) {
    middle = (left+right)/2;
    if(sought > array[middle]) {
      left = middle+1;
    }else if(sought < array[middle]) {
      right = middle-1;
    }else {
      return middle;
    }
  }

  return -1;
}
/**
// Funcion para medir tiempo de ejecución (windows) - agregar include "windows.h"
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){

  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);

  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
**/
