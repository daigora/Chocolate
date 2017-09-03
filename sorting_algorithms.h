/**
  Libreria para reunir algunos algoritmos de ordenamiento.
  #include "sorting_algorithms.h"
**/
#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <iostream>

using namespace std;

// Función que intercambia dos valores de un mismo arreglo.
void exchange(int *array, int min, int j) {

  int n = array[j];
  array[j] = array[min];
  array[min] = n;
}

// Algoritmo de ordenamiento (Selección).
void selectionSort(int *array, int n) {

  int min;

  for (int i = 0; i < n-1; i++) {
    min = i;
    for (int j = i+1; j < n; j++) {
      if (array[j] < array[min]) {
        min = j;
      }
    }
    exchange(array, min, i);
  }
}

// Algoritmo de ordenamiento (Inserción).
void insertionSort(int *array, int n) {

  int j, v;

  for (int i = 1; i < n; i++) {
    j = i;
    v = array[j];
    while (array[j-1] > v && j > 0) {
      array[j] = array[j-1];
      j--;
    }
    array[j] = v;
  }
}

// Algoritmo de ordenamiento (Burbuja).
void bubbleSort(int *array, int n) {

  for (int i = n; i >= 0; i--) {
      for (int j = 1; j < i; j++) {
        if (array[j-1] > array[j]) {
          exchange(array, j-1, j);
        }
      }
  }
}

// Algoritmo de ordenamiento (Shell) (n>=20)
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

// Función que imprime un arreglo ingresado por parametro <a[]>.
void printArray(int array[], int n){

  for (int i = 0; i < n; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

#endif
