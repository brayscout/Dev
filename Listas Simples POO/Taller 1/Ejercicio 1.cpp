/*
1.- Escriba un programa que lea una secuencia de números enteros hasta que llegue el número 999, el cual no debe procesarse, 
y genere una estructura lista simple almacenando cada número. Una vez generado la estructura lista, informe:
a.	Dos máximos entre los números leídos.
b.	La cantidad de números pares y la cantidad de números impares.
c.	La cantidad de dígitos que tiene el número que tiene más cifras.
*/

#include "stdlib.h"
#include "stdio.h"

struct Nodo
{
	int valor;
	Nodo *siguiente;
	
};
typedef struct Nodo *Lista;



char *ingreso(char *msg)
{
	char dato[10];
	printf("%s", msg);
	gets (dato);
	
	return dato;
}


void insertarNodo( Lista &lista, int valor)
{
	Lista nuevoNodo = new Nodo();
	
	if(nuevoNodo != NULL)
	{
		nuevoNodo->valor = valor;
		nuevoNodo->siguiente = lista;
		lista = nuevoNodo;
	}
}

void imprimirListaSimple(Lista lista)
{
	Lista nodoAux;
	nodoAux = lista;
	
	
	printf("\n\n\tLISTA:\t");
	while(nodoAux != NULL)
	{
		printf("%d ->", nodoAux->valor);
		nodoAux = nodoAux->siguiente;
	}
	printf("\n\n");
}

int contarListaSimple(Lista lista)		// Esta funcion me permite determinar el numero de elementos
{
	int contador=0;
	Lista auxiliar;
	
	auxiliar = lista;
	
	while(auxiliar != NULL)
	{
		contador++;
		auxiliar = auxiliar->siguiente;
	}
	
	return contador;
}

int encontrarNumeroMayor(Lista lista)
{
	Lista auxiliar;
	int mayor=0;
	
	auxiliar = lista;
	
	
	if(auxiliar != NULL)
	{
		if(auxiliar->siguiente != NULL)
		{
			mayor = auxiliar->valor;
			auxiliar = auxiliar->siguiente;
			
			while(auxiliar != NULL)
			{
				if(auxiliar->valor > mayor)
					mayor = auxiliar->valor;
					
				auxiliar = auxiliar->siguiente;
			}
			
			return mayor;
		}
		else
		{
			return auxiliar->valor;		// la lista tiene solo un elemento
		}
		
	}
	else
	{
		return -999;					// significa que la lista esta vacia
	}
	
}

void encontarNumerosMayores(Lista lista, int cantidad)
{
	Lista nodoAux1, nodoAux2, nodoAux3;
	nodoAux2 = lista;

	int i, limite=0, mayor=0, contador=0;
	
	limite=contarListaSimple(lista);
	

	if(limite>2)
	{
		nodoAux3 = nodoAux2;				//apunta al inicio de la lista principal
		//nodoAux1 = nodoAux2->siguiente;		
		for( i=0; i<cantidad; i++)
		{
			nodoAux1 = nodoAux2->siguiente;	// direccion siguiente
			mayor=encontrarNumeroMayor(nodoAux2);
			if(nodoAux2->valor== mayor)			// caso que el primer elemento de la lista sea el mayor
			{
				nodoAux2 = nodoAux2->siguiente;		//elimino para buscar otro mayor
				nodoAux3 = nodoAux2;
				//nodoAux2 = nodoAux3;
			}
			else
			{
				while(contador!=-999)
				{
					if(nodoAux1->valor == mayor)
					{
						contador = -999;
						nodoAux1 = nodoAux1->siguiente;
						nodoAux2->siguiente = nodoAux1;
					}
					else
					{
						nodoAux1 = nodoAux1->siguiente;
						nodoAux2 = nodoAux2->siguiente;
					}
				}
				
				nodoAux2 =  nodoAux3;
			}
			printf("\t%d", mayor);
		}
	}
	else
	{
		if(limite==0)
			printf("\nLista Vacia");
		else
		{
			//printf("\nLos %d Elementos Mayores:", cantidad);
			printf("\t%d", nodoAux2->valor);
			nodoAux2 = nodoAux2->siguiente;
			printf("\t%d", nodoAux2->valor);
		}
			
			
	}
	
	
}

void contarNumeroParesImpares(Lista lista)
{
	int contadorPar=0, contadorImpar=0;
	Lista auxiliar;
	auxiliar = lista;
	
	while(auxiliar != NULL)
	{
		if(( auxiliar->valor) != 0)
		{
			if(( auxiliar->valor) % 2 == 0 )
			{
				contadorPar++;
			}
			else
			{
				contadorImpar++;
			}
		}
		auxiliar = auxiliar->siguiente;
	}
	
	printf("\nb)\tCantidad de numeros Pares:\t%d", contadorPar);
	printf("\n\tCantidad de numeros Impares:\t%d", contadorImpar);
}

int cantidadDigitosNumeroEntero(int numero)
{
	int cociente=0;
	int contador=1;
	
	if(numero <0)
		numero = numero * -1;
		
	while(numero>9)
	{
		cociente = numero / 10;
		numero = cociente;
		contador++;
	}
	
	return contador;
}

main()
{
	Lista lista = new Nodo();
	int valor=0;
	
	lista = NULL;
	
	while(valor != 999)
	{
		valor = atoi(ingreso("\nIngrese el numero:\t"));
		if(valor != 999)
		{
			insertarNodo(lista, valor);
		}
		
	}
	imprimirListaSimple(lista);
	
	//printf("\nNumero Mayor:\t%d",encontrarNumeroMayor(lista));
	printf("\na)\tNumeros Mayores:\t");
	encontarNumerosMayores(lista, 2);
	contarNumeroParesImpares(lista);
	printf("\nc)\tEl mayor numero %d tiene %d digitos", encontrarNumeroMayor(lista), cantidadDigitosNumeroEntero(encontrarNumeroMayor(lista)));
}
