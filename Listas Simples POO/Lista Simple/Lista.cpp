#include "Lista.h"
#include <iostream>

using namespace std;


Lista::Lista()
{
	lista = NULL;
}

Lista::~Lista()
{
	
}

void Lista::insertarDatoNodo(int dato)
{
	Nodo *nuevo = new Nodo(dato, lista);
	lista = nuevo;
	
}

int Lista::contarListaSimple()		// Esta funcion me permite determinar el numero de elementos
{
	Nodo *auxiliar;
	auxiliar = lista;

	int contador=0;

	while(auxiliar != NULL)
	{
		contador++;
		auxiliar = auxiliar->GetNodo();
	}
	
	return contador;
}

void Lista::imprimirListaSimple()
{
	Nodo *nodoAux;
	nodoAux = lista;
	
	printf("\n\n\tLISTA:\t");
	while(nodoAux != NULL)
	{
		printf("%d ->", nodoAux->GetDato());
		nodoAux = nodoAux->GetNodo();
	}
	printf("\n\n");
}


void Lista::eliminarUltimoNodo()
{
	/////////////////////////////////// Algoritmo para eliminar el primer elemento
	lista = lista->GetNodo();
	//imprimirListaSimple();
}

void Lista::modificarNodoLista(int buscador, int dato )
{
	Nodo *auxiliar;
	auxiliar = lista;
	
	while(auxiliar != NULL)
	{
		if(auxiliar->GetDato() == buscador)
		{
			auxiliar->SetDato(dato);
		}
		auxiliar = auxiliar->GetNodo();
	}
}

bool Lista::verificarLista()
{
	if(lista == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Lista::guardarArchivo()
{
	//"Historial.txt", ""
	char path[] = "Historial.txt";
	char texto[] = "ELIMINAR";
	
	Nodo *auxiliar;
	auxiliar = lista;
	
	FILE *archivo;
	
	archivo = fopen(path, "a");
	
	if (archivo!=NULL)
	{
		fprintf(archivo, "%s\n ", texto);
		while(auxiliar != NULL)
		{
			fprintf(archivo, "%d ", auxiliar->GetDato());
			fprintf(archivo, "-> ");
			auxiliar = auxiliar->GetNodo();
		}
		fprintf(archivo, " NULL \n\n");
	}
	fclose(archivo);
}

