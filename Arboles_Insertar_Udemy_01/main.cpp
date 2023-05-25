#include <iostream>
#include <conio.h>
#include <math.h>
#include <functional>
using namespace std;
using namespace System;
struct Nodo {
	int dato;
	Nodo* Der;
	Nodo* Izq;
};
Nodo* arbol = NULL;
Nodo* CrearNodo(int n) {  //Funcion para crear un nuevo nodo
	Nodo* nuevo_nodo = new Nodo; //Reservamos memoria
	nuevo_nodo->dato = n;
	nuevo_nodo->Izq = NULL;
	nuevo_nodo->Der = NULL;
	return nuevo_nodo;
}
void Insertar(Nodo*& arbol, int n) { //Funcion para insertar para elemento
	if (arbol == NULL) { //Si el arbol está vacio 
		Nodo* nuevo_Nodo = CrearNodo(n);
		arbol = nuevo_Nodo;
	}
	else { // Si el arbol tiene un nodo o mas de un nodo
		int valorRaiz = arbol->dato; //Obtenemos el valor de la raiz
		if (n < valorRaiz) {
			Insertar(arbol->Izq, n);
		}
		else {
			Insertar(arbol->Der, n);
		}
	}
}

void Menu() {
	cout << "\t-------------Menu---------------" << endl;
	int dato, opc;
	do {
		cout << "\t  1. Insertar un nuevo nodo" << endl;
		cout << "\t  2. Salir" << endl;
		cout << "\t  Ingrese la opcion: "; cin >> opc;
		switch (opc) {
		case 1:cout << "Ingrese un numero: ", cin >> dato;
			Insertar(arbol, dato); //Insertamos un nuevo nodo
			cout << endl << endl;
			system("pause"); system("cls");
			break;
		case 2: 
			break;
		}
	} while (opc != 2);
}
int main() {
	Menu();
	_getch(); return 0;
}