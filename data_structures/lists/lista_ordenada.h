/**
 * Diego Alejandro Rodriguez Ayala - 20142020068
 * Libreria de lista ordenada para enteros unicamente.
 */

#ifndef LISTA_ORDENADA_H
#define LISTA_ORDENADA_H

#include <iostream>

using namespace std;

struct nodo {
  nodo *sig;
  int info;
};

class lista_ordenada {

  nodo *cab;
  int tam;

public:

  lista_ordenada() {
    cab = NULL;
    tam = 0;
  }
  void insertar(int dato);
  int eliminar(int pos);
  int consultar(int pos);
  int tamano_lista();
  bool lista_vacia();
};

void lista_ordenada::insertar(int dato) {

  nodo *nuevo = new nodo;
  nuevo->info = dato;

  if (cab == NULL || cab->info > dato) {
    nuevo->sig = cab;
    cab = nuevo;
  } else {
    nodo *aux, *back;
    aux = cab;
    back = cab;

    while ((dato >= aux->info) && (aux->sig != NULL)) {
      back = aux;
      aux = aux->sig;
    }

    if (dato >= aux->info) {
      aux->sig = nuevo;
    } else {
      nuevo->sig = aux;
      back->sig = nuevo;
    }
  }
  tam++;
}

int lista_ordenada::eliminar(int dato) {

  int val = -1;

  if (cab != NULL) {
    nodo *aux, *back;
    aux = cab;
    back = cab;

    while ((dato > aux->info) && (aux->sig != NULL)) {
      back = aux;
      aux = aux->sig;
    }

    if(aux->info == dato) {
      if (aux != cab) {
        back->sig = aux->sig;
      } else {
        cab = aux->sig;
      }
      val = aux->info;
      delete aux;
      tam--;
    }
  }

  return val;
}

int lista_ordenada::consultar(int pos) {

  nodo *aux;
  aux = cab;

  int p = 1;
  while ((p < pos) && (aux != NULL)) {
    aux = aux->sig;
    p++;
  }

  if (aux != NULL) {
    return aux->info;
  }

  return aux->info;
}

int lista_ordenada::tamano_lista() {
  return tam;
}

bool lista_ordenada::lista_vacia() {
  return (tam == 0);
}

#endif
