/**
 * Diego Alejandro Rodriguez Ayala - 20142020068
 */

#include "pila.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

  string palindromo;
  Pila<char> aux;

  cout << "Ingrese una cadena: ";

  getline(cin, palindromo, '\n');

  for (int i = 0; i < palindromo.length(); i++) {
    if (palindromo[i] != ' ') {
      aux.push(palindromo[i]);
    }
  }

  for (int i = 0; !aux.pila_vacia(); i++) {
    if (palindromo[i] != ' ') {
      if (aux.pop() != palindromo[i]) {
        cout << "\nNo es palíndromo" << endl;
        return 0;
      }
    }
  }

  cout << "\nEs palíndromo" << endl;

  return 0;
}
