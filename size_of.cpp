/**
	Diego Alejandro Rodriguez Ayala - 20142020068
	Practica sobre la relación de 'N'(datos de entrada) y cantidad de memoria utilizada.
**/
#include <iostream>

using namespace std;

int mayorUno(int n,int &memoria);
int mayorDos(int n, int &memoria);

int main(){
	/**FILE *archivo;
	archivo = fopen("memoria.txt","a");**/

	int memoria=0 ,n;

	cout<<"Ingrese el valor de N: ";
	cin>>n;

	memoria+=sizeof(n); //sizeof() - Operador que proporciona la cantidad de almacenamiento, en bytes.

	/**for (int i = 5; i <= 50; i+=5) {
 		memoria=0;
		memoria+=sizeof(i);
		mayorUno(i,memoria);
		fprintf(archivo, "%i\n", memoria);
	}

	fclose(archivo);**/

	cout<<"\nMayor: "<<mayorDos(n, memoria)<<endl; //Dependiendo del analisis se utiliza mayorUno() ó mayorDos().
	cout<<"Memoria: "<<memoria<<" bytes"<<endl; //Muestra la cantidad de memoria utilizada al final de la compilacion.
	return 0;
}
//Determina el mayor numero de una cantidad N de numeros.
int mayorUno(int n, int &memoria){
	int may=0, dato=0 , k=0;

	memoria+=sizeof(may);
	memoria+=sizeof(dato);
	memoria+=sizeof(k);

	for(;k<n;k++){
		dato=k;
		if(dato>may){
			may=dato;
		}
	}
	return may;
}
//Determina el mayor numero de un arreglo de N numeros.
int mayorDos(int n, int &memoria){
	int may=0, k=0;
	int dato[n];

	memoria+=sizeof(may);
	memoria+=sizeof(k);

	for(;k<n;k++){
		dato[k]=k;
	}

	may=dato[0];
	memoria+=sizeof(dato[0]);

	for(k=1;k<n;k++){
		memoria+=sizeof(dato[k]);
		if(dato[k]>may){
			may=dato[k];
		}
	}
	return may;
}
