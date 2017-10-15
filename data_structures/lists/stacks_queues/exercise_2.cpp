/**
 * Diego Alejandro Rodriguez Ayala - 20142020068
 */

#include "pila.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

  int tam1, tam2, tam3, x, y, dato;

  Pila<int> primero;
  Pila<int> segundo;
  Pila<int> resultado;

  cout << "Tamaño Pila 1: ";
  cin >> tam1;
  cout << "Tamaño Pila 2: ";
  cin >> tam2;

  tam3 = tam1 + tam2;

  cout << "\n\tPila 1" << endl;
  for (int i = 1; i <= tam1; i++) {
    cout << "Dato " << i << ": ";
    cin >> dato;
    primero.push(dato);
  }

  cout << "\n\tPila 2" << endl;
  for (int j = 1; j <= tam2; j++) {
    cout << "Dato " << j << ": ";
    cin >> dato;
    segundo.push(dato);
  }

  while (!primero.pila_vacia()) {
    resultado.push(primero.pop());
  }

  while (!segundo.pila_vacia()) {
    primero.push(segundo.pop());
  }

  while (!resultado.pila_vacia()) {
    segundo.push(resultado.pop());
  }

  while (!primero.pila_vacia()) {
    x = primero.pop();
    if (!segundo.pila_vacia()) {
      y = segundo.pop();
      if (x < y) {
        resultado.push(x);
        segundo.push(y);
      } else if (x == y) {
        resultado.push(x);
        resultado.push(y);
      } else {
        resultado.push(y);
        primero.push(x);
      }
    } else {
      resultado.push(x);
    }
  }
  while (!segundo.pila_vacia()) {
    y = segundo.pop();
    resultado.push(y);
    cout << "R: " << y << endl;
  }

  cout << "\n\t**Tercera**" << endl;
  for (int i = tam3; i >= 1; i--) {
    cout << "Dato " << i << ": " << resultado.pop() << endl;
  }
  return 0;
}
