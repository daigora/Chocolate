/**
 *  Diego Alejandro Rodriguez Ayala - 20142020068
 *  Liberia para una implementación de multilista estatica.
 */

#ifndef MULTILISTA_H
#define MULTILISTA_H

#include <iostream>

using namespace std;

struct estudiante {
  string nombre, carrera, hobby;
  int edad;
  int sigNombre = -1, sigCarrera = -1, sigHobby = -1, sigEdad = -1;
};

struct cabeza {
  string nombre;
  int pos = -1;
};

const int size = 15;  // Cantidad maxima de estudiantes que se podrán ingresar
const int heads = 10; // Cantidad de cabezas que se podrán ingresar;

class multilista {

private:
  int empty; // Posición vacia donde se ingresará el siguiente dato
  cabeza heads_list[heads];   // Lista de cabezas
  estudiante data_list[size]; // Lista de estudiantes (datos)
  string heads_names[heads] = {
      "Nombre",     "Edad",      "Sistemas", "Electronica",
      "Industrial", "Catastral", "Danza",    "Natacion",
      "Basket",     "Beisbol"}; // Arreglo con los nombre de las cabezas

  int buscar_cabeza(string nombre);
  void enlazar_ascendente();
  void enlazar_descendente();
  void enlazar_final(string val, string opt);

public:
  multilista();
  void insertar(string nombre, string carrera, string hobby, int edad);
  void imprimir_por_nombre();
  void imprimir_por_edad();
  void imprimir_por_carrera(string carrera);
  void imprimir_por_hobby(string hobby);
  bool lista_llena();
  bool lista_vacia();
};

multilista::multilista() {

  for (int i = 0; i < heads; i++) {
    heads_list[i].nombre = heads_names[i];
  }
  empty = 0;
}

/**
 * Inserta un estudiante y sus paramentros a listas enlazadas.
 * @param nombre  [nombre del estudiante]
 * @param carrera [carrera del estudiante]
 * @param hobby   [hobby del estudiante]
 * @param edad    [edad del estudiante]
 */
void multilista::insertar(string nombre, string carrera, string hobby,
                          int edad) {

  if (!lista_llena()) {
    data_list[empty].nombre = nombre;
    data_list[empty].carrera = carrera;
    data_list[empty].hobby = hobby;
    data_list[empty].edad = edad;
  }
  enlazar_ascendente();              // Para nombre
  enlazar_descendente();             // Para edad
  enlazar_final(carrera, "carrera"); // Para carrera
  enlazar_final(hobby, "hobby");     // Para hobby
  empty++;
}

/**
 * Función que encadena la lista de nombres de forma ascendente (menor a mayor).
 */
void multilista::enlazar_ascendente() {

  int cab = buscar_cabeza("Nombre");
  int index = heads_list[cab].pos;

  if (index != -1) {
    if ((data_list[empty].nombre) <= (data_list[index].nombre)) {
      heads_list[cab].pos = empty;
      data_list[empty].sigNombre = index;
    } else {

      int past;
      while ((data_list[empty].nombre) > (data_list[index].nombre) &&
             (data_list[index].sigNombre != -1)) {
        past = index;
        index = data_list[index].sigNombre;
      }

      if ((data_list[empty].nombre) <= (data_list[index].nombre)) {
        data_list[empty].sigNombre = data_list[past].sigNombre;
        data_list[past].sigNombre = empty;
      } else {
        data_list[empty].sigNombre = data_list[index].sigNombre;
        data_list[index].sigNombre = empty;
      }
    }
  } else {
    heads_list[cab].pos = empty;
  }
}

/**
 * Función que encadena la lista de edades de forma descendente (mayor a menor).
 */
void multilista::enlazar_descendente() {

  int cab = buscar_cabeza("Edad");
  int index = heads_list[cab].pos;

  if (index != -1) {
    if ((data_list[empty].edad) >= (data_list[index].edad)) {
      heads_list[cab].pos = empty;
      data_list[empty].sigEdad = index;
    } else {

      int past;
      while ((data_list[empty].edad) < (data_list[index].edad) &&
             (data_list[index].sigEdad != -1)) {
        past = index;
        index = data_list[index].sigEdad;
      }

      if ((data_list[empty].edad) >= (data_list[index].edad)) {
        data_list[empty].sigEdad = data_list[past].sigEdad;
        data_list[past].sigEdad = empty;
      } else {
        data_list[empty].sigEdad = data_list[index].sigEdad;
        data_list[index].sigEdad = empty;
      }
    }
  } else {
    heads_list[cab].pos = empty;
  }
}

/**
 * Función que encadena la lista por carrera o hobby al final.
 * @param val [nombre cabeza]
 * @param opt ["carrera" - encadenar lista carrera]
 *            ["hobby" - encadenar lista hobby]
 */
void multilista::enlazar_final(string val, string opt) {

  int cab = buscar_cabeza(val);
  int index = heads_list[cab].pos;

  if (index != -1) {
    if (opt == "carrera") {
      while (data_list[index].sigCarrera != -1) {
        index = data_list[index].sigCarrera;
      }
      data_list[index].sigCarrera = empty;
    } else if (opt == "hobby") {
      while (data_list[index].sigHobby != -1) {
        index = data_list[index].sigHobby;
      }
      data_list[index].sigHobby = empty;
    }
  } else {
    heads_list[cab].pos = empty;
  }
}

/**
 * Función que imprime la lista enlazada por nombre.
 */
void multilista::imprimir_por_nombre() {

  if (!lista_vacia()) {

    int cab = buscar_cabeza("Nombre");
    int index = heads_list[cab].pos;

    while (index != -1) {
      cout << index + 1 << " - " << data_list[index].nombre << endl;
      index = data_list[index].sigNombre;
    }
  } else {
    cout << "Error - La lista esta vacia" << endl;
  }
}

/**
 * Función que imprime la lista enlazada por carrera.
 * @param carrera [nombre de la carrera]
 */
void multilista::imprimir_por_carrera(string carrera) {

  if (!lista_vacia()) {

    int cab = buscar_cabeza(carrera);
    int index = heads_list[cab].pos;

    while (index != -1) {
      cout << index + 1 << " - " << data_list[index].carrera << endl;
      index = data_list[index].sigCarrera;
    }
  } else {
    cout << "Error - La lista esta vacia" << endl;
  }
}

/**
 * Función que imprime la lista enlazada por hobby.
 * @param hobby [nombre del hobby]
 */
void multilista::imprimir_por_hobby(string hobby) {

  if (!lista_vacia()) {

    int cab = buscar_cabeza(hobby);
    int index = heads_list[cab].pos;

    while (index != -1) {
      cout << index + 1 << " - " << data_list[index].hobby << endl;
      index = data_list[index].sigHobby;
    }
  } else {
    cout << "Error - La lista esta vacia" << endl;
  }
}

/**
 * Función que imprime la lista enlazada por edad.
 */
void multilista::imprimir_por_edad() {

  if (!lista_vacia()) {

    int cab = buscar_cabeza("Edad");
    int index = heads_list[cab].pos;

    while (index != -1) {
      cout << index + 1 << " - " << data_list[index].edad << endl;
      index = data_list[index].sigEdad;
    }
  } else {
    cout << "Error - La lista esta vacia" << endl;
  }
}

/**
 * Función que busca las posicion de una cabeza por su nombre.
 * @param  val [nombre de cabeza]
 * @return     [posición de la cabeza]
 */
int multilista::buscar_cabeza(string nombre) {

  int pos = 0;
  while (heads_list[pos].nombre != nombre)
    pos++;

  return pos;
}

/**
 * Función que verifica si el arreglo esta lleno.
 * @return [1 - Lleno]
 */
bool multilista::lista_llena() { return !(empty < size - 1); }

/**
 * Función que verifica si el arreglo de datos esta vacio.
 * @return [1 - Vacio]
 */
bool multilista::lista_vacia() { return (empty == 0); }

#endif
