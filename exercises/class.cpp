/**
  Diego Alejandro Rodriguez Ayala - 20142020068
  Segunda practica sobre la relación de 'N'(datos de entrada) y cantidad de memoria utilizada.
**/
#include <iostream>

using namespace std;

struct nodo{
  int x, y;
  nodo *sig;
};

void firstFunction(int n, int &memory);
void secondFunction(int n, int &memory);
void thirdFunction(int n, int &memory);

int main(int argc, char const *argv[]) {

  /**
  FILE *archivo;
	archivo = fopen("memoria.txt","a");
  **/
  int memory=0, n;

  cout<<"Ingrese el valor de N: ";
  cin>>n; // 1

  memory+=sizeof(n);

  /**
  for (int i = 5; i <= 50; i+=5) {
 		memory=0;
		memory+=sizeof(i);
		thirdFunction(i,memory);
		fprintf(archivo, "%i\n", memory);
	}

	fclose(archivo);
  **/
  cout<<""<<endl;
  //firstFunction(n,memory);
  //secondFunction(n, memory);
  thirdFunction(n, memory);

  cout<<"\nMemoria "<<memory<<" bytes"<<endl;
  return 0;
}
// Construye una arreglo n enteros por ciclo - Comportamiento: F(N)=N+4
void firstFunction(int n, int &memory) {

  int *A, i, j; // 3

  memory+=sizeof(i);
  memory+=sizeof(j);
  memory+=sizeof(A);

  for (i=0; i < n; i++) {
      A = new int[n]; // N
      memory+=sizeof(A[i]);
      for (j=0; j < n; j++) {
        A[j]=i*j;
        cout<<A[j]<<" ";
      }
      cout<<endl;
      delete A;
  }
}
// Construye una matriz de enteros nxn - Comportamiento: F(N)=N²+N+4
void secondFunction(int n, int &memory) {

  int **A, i , j; // 3

  memory+=sizeof(i);
  memory+=sizeof(j);
  memory+=sizeof(A);

  A = new int *[n]; // N

  for (i=0; i < n; i++) {
    A[i] = new int [n]; // N²
    memory+=sizeof(A[i]);
    for (j=0; j < n; j++) {
      memory+=sizeof(A[i][j]);
      A[i][j]=i*j;
    }
  }

  for (i=0; i < n; i++) {
    for (j=0; j < n; j++) {
      cout<<A[i][j]<<" ";
    }
    cout<<endl;
    delete A[i];
  }
}
// Comportamiento: 3*N+4
void thirdFunction(int n, int &memory) {

  int i;// 1
  nodo *cab=NULL, *aux; // 2

  memory+=sizeof(i);
  memory+=sizeof(aux);
  memory+=sizeof(cab);

  for (i=0; i < n; i++) {
    aux = new nodo; //3*N

    memory+=sizeof(aux->x);
    memory+=sizeof(aux->y);
    memory+=sizeof(aux->sig);

    aux->x=i;
    aux->y=n-i;
    aux->sig=cab;
    cab=aux;
  }

  aux=cab;

  while (aux != NULL) {
    cout<<aux->x<<" "<<aux->y<<endl;
    aux=aux->sig;
  }

  for (aux=cab->sig; aux != NULL; aux=aux->sig) {
    delete cab;
    cab=aux;
  }
  delete cab;
}
