/**
 * Diego Alejandro Rodriguez Ayala - 20142020068
 */

#include "pila.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Pila<int> fact;

int factorial(int num) {

  if (fact.pila_vacia()) {
    fact.push(num);
    return factorial(num - 1);
  }

  if (num == 0) {
    return fact.pop();
  }

  fact.push((fact.pop() * num));

  return factorial(num - 1);
}

int main(int argc, char const *argv[]) {

  int i, x, num;

  cout << "Escriba el numero: ";
  cin >> num;

  x = factorial(num);

  cout << "\nEl factorial es: " << x << endl;

  return 0;
}
