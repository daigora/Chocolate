/**
 * Diego Alejandro Rodriguez Ayala - 20142020068
 * Practica para estudiar 3 funciones resursivas y su comportamiento
 * Ademas se calcula tiempo de ejecución de las funciones para compararlo despues con el t(n) teorico.
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
//#include <windows.h>

using namespace std;

int F(const char *const prts);
int mayor(int num[], int pos);
int calcular(int a, int b);
//double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);

int main(int argc, char const *argv[]) {

  int n = 0, select;
  /*
  double secs = 0;
  LARGE_INTEGER t_ini, t_fin;

  FILE *archivo;
  archivo = fopen("tiempo.txt", "a");
  */
  cout << "Función: \n\n1. F\n2. mayor\n3. calcular (aleatorio)\n\nSeleccione una opción: ";
  cin >> select;

  switch (select) {

    case 1: {

      char *array;

      cout << "\nIngrese la cantidad de caracteres: ";
      cin >> n;

      array = new char[n];

      for (int i = 0; i < n; i++) {
        array[i] = 33+i; // ASCII Code
      }

      cout << "\nCadena original:\n" << array << endl;
      cout << "Resultado: \n";

      //QueryPerformanceCounter(&t_ini);
      F(array);
      //QueryPerformanceCounter(&t_fin);

      cout << endl;
    }break;

    case 2: {

      int max;

      cout << "\nIngrese la cantidad de números: ";
      cin >> n;

      int num[n];

      for (int i = 0; i < n; i++) {
        num[i] = n-i;
      }

      cout << "\nArreglo: "<< endl;

      for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
      }

      //QueryPerformanceCounter(&t_ini);
      max = mayor(num, n-1);
      //QueryPerformanceCounter(&t_fin);

      cout << "\nMayor: " << max << endl;
    }break;

    case 3:{

      int a, b, MCD;

      srand(time(0));

      a = rand()%999+100;
      b = rand()%9999+1000;

      //QueryPerformanceCounter(&t_ini);
      MCD = calcular(a, b);
      //QueryPerformanceCounter(&t_fin);

      cout << "\nMCD (" << a << ", " << b << ") = " << MCD << endl;

    }break;
    default:
      cout << "\nError - Opción no valida" << endl;
      break;
  }
  /*
  secs = performancecounter_diff(&t_fin, &t_ini);
  printf("\nTime: %.16g milliseconds\n", secs*1000.0);

  fprintf(archivo, "\n%.16g", secs*1000.0);
  fclose (archivo);
  */
  return 0;
}

/**
 * Imprime de forma invertido un arreglo de caracteres.
 * @param  prts [arreglo de caracteres]
 * @return      [0 - si el arreglo es vacio]
 */
int F(const char *const prts) {

  if (prts[0] == '\0') {
    return 0;
  } else {
    F(&prts[1]);
    cout << prts[0];
  }
}

/**
 * Encuentra el número mayor en un arrelo de números enteros.
 * @param  num [arreglo de enteros]
 * @param  pos [tamaño del arreglo]
 * @return     [numero mayor]
 */
int mayor(int num[], int pos) {

  int aux;

  if (pos == 0) {
    return num[pos];
  } else {
    aux = mayor(num, pos-1);
    if (num[pos] > aux) {
      return num[pos];
    } else {
      return mayor(num, pos-1);
    }
  }
}

/**
 * Calcula el maximo común divisor entre dos numeros enteros.
 * @param  a [numero 1]
 * @param  b [numero 2]
 * @return   [MCD]
 */
int calcular(int a, int b) {

  if (b == 0) {
    return a;
  } else {
    return calcular(b, a%b);
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
