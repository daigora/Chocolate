/**
 * Diego Alejandro Rodriguez Ayala - 20142020068
 * Practica para estudiar problemas intratables (Algoritmos NP y NP Completos).
 * Ademas se calcula tiempo de ejecución del algoritmo .__.
 */

#include <cstdlib>
#include <iostream>
//#include <windows.h>

using namespace std;

int DIMENSION =8;

bool colocarReina (int **t, int fila);
void imprimir(int **lab);
bool amenazada(int **t, int fila, int columna);
//double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);

int main(int argc, char *argv[]) {

  int **t;
  /*
  double secs = 0;
  LARGE_INTEGER t_ini, t_fin;

  FILE *archivo;
  archivo = fopen("tiempo.txt", "a");
  */
  t = new int*[DIMENSION];

  for (int i = 0; i < DIMENSION; i++){
    t[i] = new int[DIMENSION];
  }

  //QueryPerformanceCounter(&t_ini);
  colocarReina(t,0);
  //QueryPerformanceCounter(&t_fin);

  /*
  secs = performancecounter_diff(&t_fin, &t_ini);
  printf("\nTime: %.16g milliseconds\n", secs*1000.0);

  fprintf(archivo, "%.16g\n", secs*1000.0);
  fclose (archivo);
  */
  return 0;
}

bool colocarReina (int **t, int fila) {

  bool tmp;

  if (fila == DIMENSION) {
    cout << "Solución encontrada\n\n";
    imprimir(t);
    return true;
  }

  for (int columna = 0; columna < DIMENSION; columna++) {
    if (!amenazada(t, fila, columna)) {
      t[fila][columna] = fila + 1; // reina i-esima
      tmp = colocarReina(t, fila+1);
      if (tmp == true) {
        return true;
      }
      // borra solución invalida
      t[fila][columna] = 0;
    }
  }
  return false;
}

void imprimir(int **lab) {

  for (int i = 0; i < DIMENSION; i++) {
    for (int j = 0; j < DIMENSION; j++) {
      cout << lab[i][j];
    }
    cout << endl;
  }
}

bool amenazada(int **t, int fila, int columna) {

  int i, f, c;

  // revisa fila y columna
  for (i = 0; i < DIMENSION; i++) {
    if ((t[fila][i] != 0) || (t[i][columna] != 0)) {
      return true;
    }
  }

  // arriba a la izquierda
  for (f = fila, c = columna; (f >= 0) && (c >= 0); f--, c--) {
    if (t[f][c] != 0 ) {
      return true;
    }
  }

  // arriba a la derecha
  for (f = fila, c = columna; (f >= 0) && (c < DIMENSION); f--, c++) {
    if (t[f][c] != 0) {
      return true;
    }
  }

  // abajo a la izquierda
  for (f = fila, c = columna; (f < DIMENSION) && (c >= 0); f++, c--) {
    if (t[f][c] != 0) {
      return true;
    }
  }

  // abajo derecha
  for (f = fila, c = columna; (f < DIMENSION) && (c < DIMENSION); f++, c++) {
    if(t[f][c] != 0) {
      return true;
    }
  }
  return false;
}
/*
// Funcion para medir tiempo de ejecución (windows) - agregar include "windows.h"
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){

  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);

  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
*/
