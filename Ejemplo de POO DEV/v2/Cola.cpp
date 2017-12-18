#include "Cola.h"

int Cola :: colaVacia()
{
	if(frente == NULL)
    return true;
}

void Cola :: insertar(int elemento)
{
    NodoCola* nuevo;
    nuevo = new NodoCola (elemento);
    
    if (colaVacia())
    {
        frente = nuevo;
    }
    else
    {
        final->siguiente = nuevo;
    }
    final = nuevo;
}

int Cola :: quitar()
{
    if (colaVacia())
    {
    	printf("\n\n\tCola vac�a, no se puede extraer");
	}
        
    int aux = frente -> numero;
    NodoCola* a = frente;
    frente = frente -> siguiente;
    delete a;
    return aux;
}

int Cola :: frenteCola()
{
    if (colaVacia())
    {
    	printf("\n\n\tCola vac�a");
	}
	
    return frente->numero;
}

/*
void Cola :: borrarCola()
{
    for (; frente != NULL;)
    {
        NodoCola* a;
        a = frente;
        frente = frente -> siguiente;
        delete a;
    }
    final = NULL;
}

*/
