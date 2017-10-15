/**
 * Diego Alejandro Rodriguez Ayala - 20142020068
 */

#include "pila.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

  int tam, dato, x, nuevo, viejo;

  Pila<int> original;
  Pila<int> aux;

  cout << "Tamaño Pila: ";
  cin >> tam;

  cout << endl;
  for (int i = 1; i <= tam; i++) {
    cout << "Dato " << i << ": ";
    cin >> dato;
    original.push(dato);
  }

  cout << "\nNumero Viejo: ";
  cin >> viejo;
  cout << "Numero Nuevo:: ";
  cin >> nuevo;

  while (!original.pila_vacia()) {
    x = original.pop();
    if (x == viejo) {
      aux.push(nuevo);
    } else {
      aux.push(x);
    }
  }

  while (!aux.pila_vacia()) {
    original.push(aux.pop());
  }

  cout << "\n\t**Nueva Pila**" << endl;
  for (int i = tam; i >= 1; i--) {
    cout << "Dato " << i << ": " << original.pop() << endl;
  }

  original.~Pila();
  aux.~Pila();

  return 0;
}
