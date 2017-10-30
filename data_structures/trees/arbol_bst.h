/**
 * Diego Alejandro Rodriguez Ayala - 20142020068
 * Libreria estandar de arbol binario ordenado (BST)
 * Tomado: Ciencias de la Computación I - Deicy Alvarado
 */

#ifndef ARBOL_BST_H
#define ARBOL_BST_H

#include <iostream>

using namespace std;

template <typename T>
struct nodo {
  T info;
  nodo<T> *izq, *der;
};

template <typename T>
class arbol_bst {

  nodo<T> *raiz;

public:

  arbol_bst() { raiz = NULL; }
  nodo<T> *raiz_arbol() { return raiz; }
  int insertar_arbol(int n);
  nodo<T> *buscar_arbol(int n, nodo<T> *p, nodo<T> *q);
  void borrar_nodo(nodo<T> *q, nodo<T> *p);
  nodo<T> *buscar(int n, nodo<T> **p, nodo<T> *q);
  int retirar_arbol(int n);
  void inorden(nodo<T> *p);
  void preorden(nodo<T> *p);
  void posorden(nodo<T> *p);
  void destruir(nodo<T> *p);
  bool vacio();
  ~arbol_bst();
};

template <typename T>
nodo<T> *arbol_bst<T>::buscar_arbol(int n, nodo<T> *p, nodo<T> *q) {

  if (p == NULL) {
    return q;
  }

  if (n < p->info) {
    q = p;
    q = buscar_arbol(n, p->izq, q);
    return q;
  } else if (n > p->info) {
    q = p;
    q = buscar_arbol(n, p->der, q);
    return q;
  } else {
    return NULL;
  }
}

template <typename T> int arbol_bst<T>::insertar_arbol(int n) {

  nodo<T> *q;

  if (raiz == NULL) {
    raiz = new nodo<T>;
    raiz->info = n;
    raiz->izq = raiz->der = NULL;
    return 0;
  }

  q = buscar_arbol(n, raiz, NULL);
  if (q == NULL) {
    return -1;
  }

  nodo<T> *nuevo = new nodo<T>;
  nuevo->info = n;
  nuevo->izq = nuevo->der = NULL;

  if (n < q->info) {
    q->izq = nuevo;
  } else {
    q->der = nuevo;
  }

  return 0;
}

template <typename T>
void arbol_bst<T>::borrar_nodo(nodo<T> *q, nodo<T> *p) {

  nodo<T> *r, *s, *t;

  if (p->izq == NULL) {
    r = p->der;
  } else if (p->der == NULL) {
    r = p->izq;
  } else {
    s = p;
    r = p->der;
    t = r->izq;

    while (t != NULL) {
      s = r;
      r = t;
      t = t->izq;
    }

    if (p != s) {
      s->izq = r->der;
      r->der = p->der;
    }

    r->izq = p->izq;
  }

  if (q == NULL) {
    raiz = r;
  } else if (p == q->izq) {
    q->izq = r;
  } else {
    q->der = r;
  }

  delete p;
}

template <typename T>
nodo<T> *arbol_bst<T>::buscar(int n, nodo<T> **p, nodo<T> *q) {

  if (*p == NULL) {
    return NULL;
  }

  if (n < (*p)->info) {
    q = *p;
    *p = (*p)->izq;
    q = buscar(n, p, q);
    return q;
  } else if (n > (*p)->info) {
    q = *p;
    *p = (*p)->der;
    q = buscar(n, p, q);
    return q;
  } else {
    return q;
  }
}

template <typename T>
int arbol_bst<T>::retirar_arbol(int n) {

  nodo<T> *q, *p = raiz;

  q = buscar(n, &p, NULL);

  if (p == NULL) {
    return -1;
  }
  
  borrar_nodo(q, p);

  return 0;
}

template <typename T>
void arbol_bst<T>::inorden(nodo<T> *p) {

  if (p != NULL) {
    inorden(p->izq);
    cout << p->info << endl;
    inorden(p->der);
  }
}

template <typename T>
void arbol_bst<T>::preorden(nodo<T> *p) {

  if (p != NULL) {
    cout << p->info << endl;
    preorden(p->izq);
    preorden(p->der);
  }
}

template <typename T>
void arbol_bst<T>::posorden(nodo<T> *p) {

  if (p != NULL) {
    posorden(p->izq);
    posorden(p->der);
    cout << p->info << endl;
  }
}

template <typename T>
void arbol_bst<T>::destruir(nodo<T> *p) {

  if (p != NULL) {
    destruir(p->izq);
    destruir(p->der);
    delete p;
  }
}

template <typename T> bool arbol_bst<T>::vacio() { return (raiz == NULL); }

template <typename T> arbol_bst<T>::~arbol_bst() { destruir(raiz); }

#endif
