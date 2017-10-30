#ifndef COLA_PRIORIDAD_H
#define COLA_PRIORIDAD_H

#include <iostream>

using namespace std;

template <typename T> struct nodo {
  int priority = -1;
  T info;
};

template <typename T> class heap {

private:
  nodo<T> *data;
  int current;
  int MAX_SIZE;

  void agregar(int index);
  void eliminar(int index);
  int padre(int child);
  int izquierdo(int parent);
  int derecho(int parent);

public:
  heap(int size) {
    MAX_SIZE = size;
    current = 1;
    data = new nodo<T>[MAX_SIZE + 1];
  };
  int insertar(T info, int priority);
  T atender();
  int size();
  void imprimir();
  ~heap();
};

template <typename T> int heap<T>::padre(int child) {
  return (child > 0) ? (int)child / 2 : -1;
}

template <typename T> int heap<T>::izquierdo(int parent) {
  int left = parent * 2;
  return (left < current) ? left : -1;
}

template <typename T> int heap<T>::derecho(int parent) {
  int right = (parent * 2) + 1;
  return (right < current) ? right : -1;
}

template <typename T> int heap<T>::insertar(T info, int priority) {

  if (current > MAX_SIZE) {
    return -1;
  }

  nodo<T> node;
  node.info = info;
  node.priority = priority;

  data[current] = node;
  agregar(current++);

  return 0;
}

template <typename T> void heap<T>::agregar(int index) {

  int parent = padre(index);

  while ((data[parent].priority < data[index].priority) && (parent > 0)) {
    nodo<T> aux = data[index];
    data[index] = data[parent];
    data[parent] = aux;
    index = parent;
    parent = padre(index);
  }
}

template <typename T> T heap<T>::atender() {

  if (current < 2) {
    return -1;
  }

  int info = data[1].priority;

  data[1] = data[--current];
  eliminar(1);

  return info;
}

template <typename T> void heap<T>::eliminar(int index) {

  int left_child = izquierdo(index);
  int right_child = derecho(index);

  while (left_child != -1 || right_child != -1) {

    nodo<T> aux = data[index];

    if ((data[left_child].priority > aux.priority) &&
        (data[left_child].priority > data[right_child].priority) &&
        (left_child != -1)) {
      index = left_child;
    } else if ((data[right_child].priority > aux.priority) &&
               (data[right_child].priority > data[left_child].priority) &&
               (right_child != -1)) {
      index = right_child;
    } else {
      index = left_child;
    }

    data[padre(index)] = data[index];
    data[index] = aux;

    left_child = izquierdo(index);
    right_child = derecho(index);
  }
}

template <typename T> int heap<T>::size() { return MAX_SIZE; }

template <typename T> heap<T>::~heap() { delete[] data; }

template <typename T> void heap<T>::imprimir() {
  for (int i = 1; i < current; i++) {
    cout << data[i].priority << " ";
  }
  cout << endl;
}

#endif
