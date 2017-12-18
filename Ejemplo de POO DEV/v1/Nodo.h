//#include "stdio.h"
#ifndef NODO_H_
#define NODO_H_

class Nodo
{
	private:
		int numero;
		Nodo *siguiente;
	
	public:
		
		Nodo();
		Nodo(int , Nodo *);
		
		int getNumero();
		void setNumero(int );
		
		Nodo *getNodo();
		void setNodo(Nodo *);
		
		void imprimirNodo();	
};




Nodo()
{
	
}

Nodo::Nodo(int _numero, Nodo *lista)
{
	numero =_numero;
	siguiente = lista;
}

Nodo::getNumero()
{
	return numero;
}

Nodo::setNumero(int _numero)
{
	numero = _numero;
}

Nodo::getNodo()
{
	return siguiente;	
}

Nodo::setNodo(Nodo *_siguiente)
{
	siguiente = _siguiente;
}

Nodo::imprimirNodo()
{
	printf("Hola mUNDO");
}

#endif
