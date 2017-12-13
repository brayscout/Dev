#include "Nodo.h"

Nodo::Nodo()
{
	
}

Nodo::Nodo(int a, Nodo *lista)
{
	datoEntero = a;
	sigDir = lista;
}

int Nodo::GetDato()
{
	return datoEntero;
}

Nodo* Nodo::GetNodo()
{
	return sigDir;
}

void Nodo::SetDato(int valor)
{
	datoEntero = valor;
}

void Nodo::SetNodo(Nodo *siguiente)
{
	sigDir = siguiente;
}

Nodo::~Nodo()
{
	
}
