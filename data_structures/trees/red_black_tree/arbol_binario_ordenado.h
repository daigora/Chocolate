/**
 * Diego Alejandro Rodriguez Ayala - 20142020068
 * Libreria de arbol binario ordenado (BST) adaptada para arbol rojo negro
 */

#include <iostream>

#ifndef ARBOL_BINARIO_ORDENADO_H
#define ARBOL_BINARIO_ORDENADO_H

using namespace std;

struct nodo {
  int info;
  bool color;
  nodo *padre, *izq, *der;
};

class arbol_bst {
private:
  nodo *raiz;

public:
  arbol_bst() { raiz = NULL; }
  nodo *raiz_arbol() { return raiz; }
  void ins_raiz_arbol(nodo *p) { raiz = p; }
  nodo *insertar_arbol(int);
  nodo *buscar_arbol(int, nodo *p, nodo *q);
  void borrar_nodo(nodo *p, nodo *q);
  nodo *buscar(int, nodo **p, nodo *q);
  nodo *retira_arbol(int);
  void inorden(nodo *p);
  void preorden(nodo *p);
  void posorden(nodo *p);
  void destruir(nodo *p);
  ~arbol_bst();
};

nodo *arbol_bst::buscar_arbol(int n, nodo *p, nodo *q) {
  if (p == NULL)
    return q;
  if (n < p->info) {
    q = p;
    q = buscar_arbol(n, p->izq, q);
    return q;
  } else if (n > p->info) {
    q = p;
    q = buscar_arbol(n, p->der, q);
    return q;
  } else
    return NULL;
}

nodo *arbol_bst::insertar_arbol(int n) {
  nodo *q;
  if (raiz == NULL) {
    raiz = new nodo;
    raiz->info = n;
    raiz->izq = raiz->der = NULL;
    raiz->color = true;
    raiz->padre = NULL;
    return raiz;
  }
  q = buscar_arbol(n, raiz, NULL);
  if (q == NULL)
    return NULL;
  nodo *nuevo;
  nuevo = new nodo;
  nuevo->info = n;
  nuevo->izq = nuevo->der = NULL;
  nuevo->color = true;
  if (n < q->info)
    q->izq = nuevo;
  else
    q->der = nuevo;
  nuevo->padre = q;
  return nuevo;
}

void arbol_bst::borrar_nodo(nodo *q, nodo *p) {
  nodo *r, *s, *t;
  if (p->izq == NULL)
    r = p->der;
  else if (p->der == NULL)
    r = p->izq;
  else {
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
  if (q == NULL)
    raiz = r;
  else if (p == q->izq)
    q->izq = r;
  else
    q->der = r;
  delete p;
}

nodo *arbol_bst::buscar(int n, nodo **p, nodo *q) {
  if (*p = NULL)
    return NULL;
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
  } else
    return q;
}

nodo *arbol_bst::retira_arbol(int n) {
  nodo *q, *p = raiz;
  q = buscar(n, &p, NULL);
  if (p == NULL)
    return NULL;
  borrar_nodo(q, p);
  return q;
}

void arbol_bst::inorden(nodo *p) {
  if (p != NULL) {
    inorden(p->izq);
    if (p->color == false) {
      cout << p->info << " N" << endl;
    } else {
      cout << p->info << " R" << endl;
    }
    inorden(p->der);
  }
}

void arbol_bst::preorden(nodo *p) {
  if (p != NULL) {
    if (p->color == false) {
      cout << p->info << " N" << endl;
    } else {
      cout << p->info << " R" << endl;
    }
    preorden(p->izq);
    preorden(p->der);
  }
}

void arbol_bst::posorden(nodo *p) {
  if (p != NULL) {
    posorden(p->izq);
    posorden(p->der);
    if (p->color == false) {
      cout << p->info << " N" << endl;
    } else {
      cout << p->info << " R" << endl;
    }
  }
}

void arbol_bst::destruir(nodo *p) {
  if (p != NULL) {
    destruir(p->izq);
    destruir(p->der);
    delete p;
  }
}

arbol_bst::~arbol_bst() { destruir(raiz); }

#endif
