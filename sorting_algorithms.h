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

// Algoritmo de ordenamiento (ordenamiento rapido) (Default left: 0, right: n-1)
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
    quickSort(array, left, i-1);
    quickSort(array, i+1, right);
  }
}

// Función para evaluar el valor del bit en una posicion (k) de un numero entero (x) (1: verdadero, 0: falso) (using: residuo)
inline unsigned bits(int k, int j, int x) {

  return (x>>k) & ~(~0<<j);
}

// Algoritmo de ordenamiento por residuo (Default left: 0, right: n-1, bits: cantidad de bits a evaluar)
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

// Función para encontrar el numero maximo de un arreglo (using: radixSort)
int max(int *array, int n) {

  int max = array[0];

  for (int i = 1; i < n; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }

  return max;
}

// Función para ordenar por base 10 y exponente (10, 10^2, 10^3,...) (using: radixSort)
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

// Algoritmo de ordenamiento (Base 10)
void radixSort(int *array, int n) {

  int m = max(array, n);

  for (int exp = 1; m/exp > 0; exp*=10) {
    sorting(array, n, exp);
  }
}

// Función para rellenar un arreglo de formar descendente (peor caso)
void fillArray(int *array, int n) {

  int randNum = rand()%9999+1000; // Genera un numero aleatorio entre 1000 a 9999

  for (int i = 0; i < n; i++) {
    array[i] = randNum-i;
  }
}

// Función que imprime un arreglo ingresado por parametro <a[]>.
void printArray(int *array, int n) {

  for (int i = 0; i < n; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

#endif
