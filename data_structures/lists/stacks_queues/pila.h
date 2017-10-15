/**
 * Diego Alejandro Rodriguez Ayala - 20142020068
 * Libreria estandar de pila
 * Tomado: Ciencias de la Computación I - Deicy Alvarado
 */

#ifndef PILA_H
#define PILA_H

#include <cstdlib>
#include <iostream>

template <typename T>
struct nodo {
  T dato;
  nodo<T> *sig;
};

template <typename T>
class Pila {
  nodo<T> *cab;

public:
  Pila() {
    cab = new nodo<T>;
    cab->sig = NULL;
  }
  void push(T info);
  T pop();
  bool pila_vacia();
  ~Pila();
};

template <typename T>
void Pila<T>::push(T info) {

  nodo<T> *t = new nodo<T>;

  t->dato = info;
  t->sig = cab->sig;
  cab->sig = t;
}

template <typename T>
T Pila<T>::pop() {

  T x;
  nodo<T> *t = cab->sig;

  cab->sig = t->sig;
  x = t->dato;
  delete t;

  return x;
}

template <typename T>
bool Pila<T>::pila_vacia() { return cab->sig == NULL; }

template <typename T>
Pila<T>::~Pila() {

  nodo<T> *t = cab;

  while (t != NULL) {
    cab = t;
    t = t->sig;
    delete cab;
  }
}

#endif
