/**
 * Diego Alejandro Rodriguez Ayala - 20142020068
 * Practica para estudiar el uso de plantillas (templates).
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

/**
 * Función que suma dos matrices mxn de cualquier tipo de dato (T).
 * @param  A [matriz]
 * @param  B [matriz]
 * @param  m [número de filas]
 * @param  n [número de columnas]
 * @return   [matriz resultado]
 */
template <typename T>
T **additionMatrices(T **A, T **B, int m, int n) {

  T **C = new T *[m];

  for (int i = 0; i < m; i++) {
    C[i] = new T[n];
    for (int j = 0; j < n; j++) {
      C[i][j] = A[i][j]+B[i][j]; // Suma
    }
  }
  return C;
}

/**
 * Función que imprime en pantalla una matriz mxn de cualquier tipo de dato (T).
 * @param A [matriz]
 * @param m [número de filas]
 * @param n [número de columnas]
 */
template <typename T>
void printMatrix(T **A, int m, int n) {

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
}

int main(int argc, char const *argv[]) {

  int m, n, select;

  cout << "Ingrese el numero de filas (m): ";
  cin >> m;
  cout << "Ingrese el numero de columnas (n): ";
  cin >> n;

  cout << "\n1. int\n2. char\n3. double\n4. float\n\nSeleccione el tipo de matriz: ";
  cin >> select;

  srand(time(0)); // Planta semilla para generar un random diferente

  switch (select) {
    case 1: {

      int **A, **B, **C;

      A = new int *[m];
      for (int i = 0; i < m; i++) {
        A[i] = new int[n];
        for (int j = 0; j < n; j++) {
          A[i][j] = rand()%99+10;
        }
      }

      B = new int *[m];
      for (int i = 0; i < m; i++) {
        B[i] = new int[n];
        for (int j = 0; j < n; j++) {
          B[i][j] = rand()%99 +10;
        }
      }

      C = additionMatrices(A, B, m, n); // Suma dos matrices (int)

      cout << "\nMatriz A: \n" << endl;
      printMatrix(A, m, n);
      cout << "\nMatriz B: \n" << endl;
      printMatrix(B, m, n);
      cout << "\nMatriz C = (A+B): \n" << endl;
      printMatrix(C, m, n);

    } break;

    case 2: {

      char **A, **B, **C;

      A = new char *[m];
      for (int i = 0; i < m; i++) {
        A[i] = new char[n];
        for (int j = 0; j < n; j++) {
          A[i][j] = rand()%126+33; // ASCII Code
        }
      }

      B = new char *[m];
      for (int i = 0; i < m; i++) {
        B[i] = new char[n];
        for (int j = 0; j < n; j++) {
          B[i][j] = rand()%126+33; // ASCII Code
        }
      }

      C = additionMatrices(A, B, m, n); // Suma dos matrices (char)

      cout << "\nMatriz A: \n" << endl;
      printMatrix(A, m, n);
      cout << "\nMatriz B: \n" << endl;
      printMatrix(B, m, n);
      cout << "\nMatriz C = (A+B): \n" << endl;
      printMatrix(C, m, n);
    } break;

    case 3: {

      double **A, **B, **C;

      A = new double *[m];
      for (int i = 0; i < m; i++) {
        A[i] = new double[n];
        for (int j = 0; j < n; j++) {
          A[i][j] = (double)(rand()%999)/100;
        }
      }

      B = new double *[m];
      for (int i = 0; i < m; i++) {
        B[i] = new double[n];
        for (int j = 0; j < n; j++) {
          B[i][j] = (double)(rand()%999)/100;
        }
      }

      C = additionMatrices(A, B, m, n); // Suma dos matrices (double)

      cout << "\nMatriz A: \n" << endl;
      printMatrix(A, m, n);
      cout << "\nMatriz B: \n" << endl;
      printMatrix(B, m, n);
      cout << "\nMatriz C = (A+B): \n" << endl;
      printMatrix(C, m, n);
    } break;

    case 4: {

      float **A, **B, **C;

      A = new float *[m];
      for (int i = 0; i < m; i++) {
        A[i] = new float[n];
        for (int j = 0; j < n; j++) {
          A[i][j] = (float)(rand()%999)/100;
        }
      }

      B = new float *[m];
      for (int i = 0; i < m; i++) {
        B[i] = new float[n];
        for (int j = 0; j < n; j++) {
          B[i][j] = (float)(rand()%999)/100;
        }
      }

      C = additionMatrices(A, B, m, n); // Suma dos matrices (float)

      cout << "\nMatriz A: \n" << endl;
      printMatrix(A, m, n);
      cout << "\nMatriz B: \n" << endl;
      printMatrix(B, m, n);
      cout << "\nMatriz C = (A+B): \n" << endl;
      printMatrix(C, m, n);
    } break;

    default:
      cout << "Error - Opcion no valida" << endl;
    break;
  }

  return 0;
}
