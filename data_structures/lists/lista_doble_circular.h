/**
 * Diego Alejandro Rodriguez Ayala - 20142020068
 * Libreria de lista circular doblemente encadenada para cualquier tipo de dato.
 */

#ifndef LISTA_DOBLE_CIRCULAR_H
#define  LISTA_DOBLE_CIRCULAR_H

#include <iostream>

template <typename T>
struct nodo{

  T info;
  nodo<T> *sig = NULL;
  nodo<T> *ant = NULL;
};

template <typename T>
class lista{

  nodo<T> *cab;
  nodo<T> *z;
  int tam;
  bool init;

  public:
    lista(){
      z = new nodo<T>;
      tam = 0;
      init = false;
    };
    void insertar_inicio(T dato);
    void insertar_pos(int pos, T dato);
    void insertar_final(T dato);
    T eliminar_inicio();
    T eliminar_pos(int pos);
    T eliminar_final();
    T consultar(int pos);
    int tamano_lista();
    bool lista_vacia();

};

template <typename T>
void lista<T>::insertar_inicio(T dato) {

  nodo<T> *nuevo = new nodo<T>;
  nuevo->info = dato;

  if (tam == 0) {
    init = false;
  }

  if (init == false) {
    cab = nuevo;
    cab->sig = z;
    z->sig = cab;
    cab->ant = z;
    z->ant = cab;

    init = true;
  } else {
    nuevo->sig = cab;
    cab->ant = nuevo;
    nuevo->ant = cab->ant;
    z->sig = nuevo;
    cab = nuevo;
  }
  tam++;
}

template <typename T>
void lista<T>::insertar_pos(int pos, T dato) {

  if (pos > tam) {
    insertar_final(dato);
  } else if (pos == 1) {
    insertar_inicio(dato);
  } else if ((pos > 1) && (pos <= tam)) {
    nodo<T> *nuevo, *aux;
    nuevo = new nodo<T>;
    nuevo->info = dato;
    aux = cab;

    int p = 1;
    while ((p < pos-1) && (aux != NULL)) {
      aux = aux->sig;
      p++;
    }

    nuevo->sig = aux->sig;
    nuevo->sig->ant = nuevo;
    aux->sig = nuevo;
    nuevo->ant = aux;

    tam++;
  }
}

template <typename T>
void lista<T>::insertar_final(T dato){

  if (tam != 0) {
    nodo<T> *nuevo = new nodo<T>;
    nuevo->info = dato;

    z->ant->sig = nuevo;
    nuevo->ant = z->ant;
    nuevo->sig = z;
    z->ant = nuevo;

    tam ++;
  } else {
    insertar_inicio(dato);
  }
}

template <typename T>
T lista<T>::consultar(int pos) {

  nodo<T> *aux = cab;

  if ((pos <= tam) && (pos >= 0)) {
    int p = 1;
    while ((p < pos) && (aux != NULL)) {
      aux = aux->sig;
      p++;
    }
    return aux->info;
  }
  return aux->info;
}

template <typename T>
T lista<T>::eliminar_inicio() {

  if (tam != 0) {
    nodo<T> *aux = cab;

    z->sig = aux->sig;
    aux->sig->ant = z;
    T val = aux->info;
    cab = aux->sig;

    delete aux;
    tam--;

    return val;
  }
}

template <typename T>
T lista<T>::eliminar_pos(int pos) {

  if (tam != 0) {
    if (pos == tam) {
      return eliminar_final();
    } else if (pos == 1) {
      return eliminar_inicio();
    } else if ((pos > 1) && (pos < tam)) {
      nodo <T> *temp = cab;

      int p = 1;
      while ((p < pos) && (temp != NULL)) {
        temp = temp->sig;
        p++;
      }

      nodo <T> *aux = temp->sig;
      temp->sig = aux->sig;
      aux->sig->ant = temp;
      T val = aux->info;

      delete aux;
      tam--;

      return val;
    }
  }
}

template <typename T>
T lista<T>::eliminar_final(){

  if (tam != 0) {
    nodo<T> *aux = z->ant;

    aux->ant->sig = z;
    z->ant = aux->ant;
    T val = aux->info;

    delete aux;
    tam --;

    return val;
  }
}

template <typename T>
int lista<T>::tamano_lista() {
  return tam;
}

template <typename T>
bool lista<T>::lista_vacia() {
  return (tam==0);
}
#endif
