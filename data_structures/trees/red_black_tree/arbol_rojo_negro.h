/**
 * Diego Alejandro Rodriguez Ayala - 20142020068
 * Libreria estandar de arbol rojo negro
 */

#include "arbol_binario_ordenado.h"

#ifndef ARBOL_ROJO_NEGRO_H
#define ARBOL_ROJO_NEGRO_H

class arbol_rojo_negro : public arbol_bst {

public:
  void rotacion_derecha(nodo *p);
  void rotacion_izquierda(nodo *p);
  void ajustar_insercion(nodo *p);
  void ajustar_eliminacion(nodo *p);
};

void arbol_rojo_negro::rotacion_derecha(nodo *p) {
  if (p->izq == NULL)
    return;
  else {
    nodo *y = p->izq;
    if (y->der != NULL) {
      p->izq = y->der;
      y->der->padre = p;
    } else
      p->izq = NULL;
    if (p->padre != NULL)
      y->padre = p->padre;
    if (p->padre == NULL)
      ins_raiz_arbol(y);
    else {
      if (p == p->padre->izq)
        p->padre->izq = y;
      else
        p->padre->der = y;
    }
    y->der = p;
    p->padre = y;
  }
}

void arbol_rojo_negro::rotacion_izquierda(nodo *p) {
  if (p->der == NULL)
    return;
  else {
    nodo *y = p->der;
    if (y->izq != NULL) {
      p->der = y->izq;
      y->izq->padre = p;
    } else
      p->der = NULL;
    if (p->padre != NULL)
      y->padre = p->padre;
    if (p->padre == NULL)
      ins_raiz_arbol(y);
    else {
      if (p == p->padre->izq)
        p->padre->izq = y;
      else
        p->padre->der = y;
    }
    y->izq = p;
    p->padre = y;
  }
}

void arbol_rojo_negro::ajustar_insercion(nodo *p) {
  nodo *u;
  if (raiz_arbol() == p) {
    p->color = false;
    return;
  }
  while (p->padre != NULL && p->padre->color == true) {
    nodo *g = p->padre->padre;
    if (g->izq == p->padre) {
      if (g->der != NULL) {
        u = g->der;
        if (u->color == true) {
          p->padre->color = false;
          u->color = false;
          g->color = true;
          p = g;
        }
      } else {
        if (p->padre->der == p) {
          p = p->padre;
          rotacion_izquierda(p);
        }
        p->padre->color = false;
        g->color = true;
        rotacion_derecha(g);
      }
    } else {
      if (g->izq != NULL) {
        u = g->izq;
        if (u->color == true) {
          p->padre->color = false;
          u->color = false;
          g->color = true;
          p = g;
        }
      } else {
        if (p->padre->izq == p) {
          p = p->padre;
          rotacion_derecha(p);
        }
        p->padre->color = false;
        g->color = true;
        rotacion_izquierda(g);
      }
    }
    raiz_arbol()->color = false;
  }
}

void arbol_rojo_negro::ajustar_eliminacion(nodo *p) {

  nodo *w;
  while (p != raiz_arbol() && p->color == false) {
    if (p->padre->izq == p) {
      w = p->padre->der;
      if (w->color == true) {
        w->color = false;
        p->padre->color = true;
        rotacion_izquierda(p->padre);
        w = p->padre->der;
      }
      if (w->der->color == false && w->izq->color == false) {
        w->color = true;
        p = p->padre;
      } else {
        if (w->der->color == false) {
          w->izq->color == false;
          w->color = true;
          rotacion_derecha(w);
          w = p->padre->der;
        }
        w->color = p->padre->color;
        p->padre->color = false;
        w->der->color = false;
        rotacion_izquierda(p->padre);
        p = raiz_arbol();
      }
    } else {
      w = p->padre->izq;
      if (w->color == true) {
        w->color = false;
        p->padre->color = true;
        rotacion_derecha(p->padre);
        w = p->padre->izq;
      }
      if (w->izq->color == false && w->der->color == false) {
        w->color = true;
        p = p->padre;
      } else {
        if (w->izq->color == false) {
          w->der->color = false;
          w->color = true;
          rotacion_izquierda(w);
          w = p->padre->izq;
        }
        w->color = p->padre->color;
        p->padre->color = true;
        w->izq->color = true;
        rotacion_derecha(p->padre);
        p = raiz_arbol();
      }
    }
    p->color = false;
    raiz_arbol()->color = false;
  }
}

#endif
