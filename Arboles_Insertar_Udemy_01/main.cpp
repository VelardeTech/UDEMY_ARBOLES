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
Nodo* CrearNodo(int);
void Insertar(Nodo*&, int);
void Menu();

void Mostrar_Arbol(Nodo*, int);

int main() {
	Menu();
	_getch(); return 0;
}

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
	int dato, opc, cont = 0;
	do {
		cout << "\t  1. Insertar un nuevo nodo" << endl;
		cout << "\t  2. Mostrar el arbol" << endl;
		cout << "\t  3. Salir" << endl;
		cout << "\t  Ingrese la opcion: "; cin >> opc;
		switch (opc) {
		case 1:cout << "Ingrese un numero: ", cin >> dato;
			Insertar(arbol, dato); //Insertamos un nuevo nodo
			cout << endl << endl;
			system("pause"); system("cls");
			break;
		case 2: cout << "Mostrando el arbol completo" << endl;
			Mostrar_Arbol(arbol, cont);
			cout << endl << endl << endl;
			system("pause"); system("cls");
			break;
		}
	} while (opc != 3);
}

void Mostrar_Arbol(Nodo* arbol, int cont) {
	if (arbol == NULL) { //Si el arbol esta vacio
		return;
	}
	else {
		Mostrar_Arbol(arbol->Der, cont + 1);
		for (int i = 0; i < cont; i++) {
			cout << "   ";
		}
		cout << arbol->dato << endl;
		Mostrar_Arbol(arbol->Izq, cont + 1);
	}
}