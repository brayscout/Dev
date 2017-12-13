#pragma once
#include "Nodo.h"

class Lista
{
	private:
		Nodo *lista;
	
	public:
		Lista();
		~Lista();
		void insertarDatoNodo(int);
		int contarListaSimple();
		void imprimirListaSimple();
		void eliminarUltimoNodo();
		void modificarNodoLista(int , int );
		bool verificarLista();
		void guardarArchivo();
};

