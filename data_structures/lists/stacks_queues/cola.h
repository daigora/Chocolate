/**
 * Diego Alejandro Rodriguez Ayala - 20142020068
 * Libreria estandar de cola
 * Tomado: Ciencias de la Computación I - Deicy Alvarado
 */

#ifndef COLA_H
#define COLA_H

#include <cstdlib>
#include <iostream>

using namespace std;

template <typename T>
struct nodo {
  T dato;
  nodo<T> *sig;
};

template <typename T>
class Cola {
  nodo<T> *cab, *fin;

public:
  Cola() { cab = fin = NULL; }
  void insertar(T info);
  T atender();
  void imprimir();
  bool cola_vacia();
  ~Cola();
};

template <typename T>
void Cola<T>::insertar(T info) {

  nodo<T> *nuevo = new nodo<T>;
  nuevo->dato = info;
  nuevo->sig = NULL;

  if (cab == NULL) {
    cab = nuevo;
  } else {
    fin->sig = nuevo;
  }
  fin = nuevo;
}

template <typename T>
T Cola<T>::atender() {

  T x;
  nodo<T> *aux = cab;

  cab = aux->sig;
  x = aux->dato;
  delete aux;

  return x;
}

template <typename T>
void Cola<T>::imprimir() {

  nodo<T> *aux = cab;

  while (aux != NULL) {
    cout << aux->dato << " ";
    aux = aux->sig;
  }
}

template <typename T>
bool Cola<T>::cola_vacia() { return (cab == NULL); }

template <typename T>
Cola<T>::~Cola() {

  nodo<T> *aux;

  while (cab != NULL) {
    aux = cab;
    cab = aux->sig;
    delete aux;
  }
  delete cab;
}

#endif
