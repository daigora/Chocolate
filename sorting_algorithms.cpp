/**
  Diego Alejandro Rodriguez Ayala - 20142020068
  Practica para conocer los algoritmos de ordenamiento basicos y su funcionamiento.
  Ademas se calcula tiempo de ejecución en cada algoritmo para compararlo despues con el t(n) teorico.
**/
#include <iostream>
#include <stdio.h>
#include <time.h>
//#include <windows.h>


/**
// Funcion para medir tiempo de ejecución (windows) - agregar include "windows.h"
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);

  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
**/
void selectionSort(int a[], int n);
void insertionSort(int a[], int n);
void bubbleSort(int a[], int n);
void exchange(int a[], int min, int j);
void printArray(int a[], int n);

using namespace std;

int main(int argc, char const *argv[]) {

  int n, selec;

  /**
  LARGE_INTEGER t_ini, t_fin;
  double secs = 0;

  FILE *archivo;
  archivo = fopen("memoria.txt","a");
  **/
  cout << "Ingrese el tamaño del arreglo: ";
  cin >> n;

  srand(time(0)); // Planta semilla para generar un random diferente

  int array[n];

  int randNum = rand()%9999+1000; // Genera numeros de 1000 a 9999

  for (int i = 0; i < n; i++) {
    array[i] = randNum-i;
  }

  cout << "\nArreglo: " << endl;
  printArray(array, n);

  cout << "\nSeleccione el algoritmo de ordenamiento:" <<
  "\n 1. Seleccion" << "\n 2. Insercion" << "\n 3. Burbuja\n\n";
  cin >> selec;

  switch (selec) {
    case 1:
      selectionSort(array, n); // Selección
      break;
    case 2:
      insertionSort(array , n); // Inserción
      break;
    case 3:
      bubbleSort(array, n); // Burbuja
      break;
    default:
      cout << "Error - Opcion no valida" << endl;
      return 0;
      break;
  }

  cout << "\nArreglo Ordenado: " << endl;
  printArray(array, n);


  /**
  // Mide tiempo de ejecución entre &t_ini y &t_fin
  QueryPerformanceCounter(&t_ini);
  //bubbleSort(array, i);
  //insertionSort(array , i);
  //selectionSort(array, i);
  QueryPerformanceCounter(&t_fin);

  secs = performancecounter_diff(&t_fin, &t_ini);
	fprintf(archivo, "%.16g milliseconds\n", secs * 1000.0); // Guarda el tiempo de ejecución en un archivo .txt

	fclose(archivo);
  **/

  /**
  secs = performancecounter_diff(&t_fin, &t_ini);
  printf("\nTime: %.16g milliseconds\n", secs * 1000.0);
  **/
  return 0;
}
// Algoritmo de ordenamiento (Selección).
void selectionSort(int a[], int n) {

  int min;

  for (int i = 0; i < n-1; i++) {
    min = i;
    for (int j = i+1; j < n; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }
    exchange(a, min, i);
  }
}
// Algoritmo de ordenamiento (Inserción).
void insertionSort(int a[], int n) {

  int j, v;

  for (int i = 1; i < n; i++) {
    j = i;
    v = a[j];
    while (a[j-1] > v && j > 0) {
      a[j] = a[j-1];
      j--;
    }
    a[j] = v;
  }
}
// Algoritmo de ordenamiento (Burbuja).
void bubbleSort(int a[], int n) {

  for (int i = n; i >= 0; i--) {
      for (int j = 1; j < i; j++) {
        if (a[j-1] > a[j]) {
          exchange(a, j-1, j);
        }
      }
  }
}
// Función que intercambia dos valores de un mismo arreglo.
void exchange(int a[], int min, int j) {

  int n = a[j];
  a[j] = a[min];
  a[min] = n;
}
// Función que imprime un arreglo ingresado por parametro <a[]>.
void printArray(int a[], int n){

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
