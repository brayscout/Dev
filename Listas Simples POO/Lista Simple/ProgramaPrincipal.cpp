
#include "Lista.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void Menu();
void menu(int n);

void main()
{
	Lista L1;
	int dato;
	int opc;
	
	do {
		cout << "1.- Ingreso de Datos" << endl;
		cout << "2.- Imprmir datos" << endl;
		cout << "3.- Eliminar Datos" << endl;
		cout << "4.- Buscar Datos" << endl;
		cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "Ingrese un dato: ";
			cin >> dato;
			L1.LeerDatos(dato);
			break;
		case 2:
			cout << "LISTA" << endl;
			L1.ImprimirDatos();
			break;
		case 3:
			int elim;
			cout << "Metodo eliminar dato." << endl;
			cout << "Ingresar dato a eliminar: ";
			cin >> elim;
			L1.Eliminar(elim);
			L1.ImprimirDatos();
			break;
		case 4:
			int busc;
			cout << "Ingresar dato a buscar: ";
			cin >> busc;
			L1.Buscar(busc);
			break;
		}
	} while (opc<5);
	

}


void Menu()
{
	

}

void menu(int n)
{
	Lista L1;
	int dato;
	
}
