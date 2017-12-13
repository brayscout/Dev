/*

UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Autor: Bryan Tualle
NRC: 2479
Fecha de creacion:13/11/2017
Profesor: Ing. Edgar Fernando Solis Acosta
Carrera: Ing. Sistemas e informatica


2.- Se dispone de una lista, con la información de los clientes que se acercan a pagar impuestos. 
De cada cliente se conoce: 
DNI, Apellido y Nombre, Código de impuesto a pagar (de A a K) y el monto a pagar. 
Se pide:
a.	   Simular la atención de los clientes hasta que se haya recaudado al menos $500.000 o se hayan procesado todos los clientes de la lista.
Al finalizar la atención de los clientes, se desea informar:
b.	El monto total recaudado por cada código de impuesto.
c.	   La cantidad de clientes que quedaron sin atender.

*/
#include "conio.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "ctype.h"

struct Nodo
{
	long int cedula;
	char nombre[10];
	char apellido[10];
	char codigo[1];
	float valorDeuda;
	float valorCancelado;

	Nodo *siguiente;
};
typedef struct Nodo *Lista;


void insertarNodo(Lista &lista, Nodo nodo)
{
	Lista nuevoNodo = new Nodo();
	

	if(nuevoNodo != NULL)
	{
		nuevoNodo->cedula = (nodo.cedula);
		strcpy(nuevoNodo->nombre, (nodo.nombre));
		strcpy(nuevoNodo->apellido, (nodo.apellido));
		strcpy(nuevoNodo->codigo, (nodo.codigo));
		nuevoNodo->valorDeuda = (nodo.valorDeuda);
		nuevoNodo->valorCancelado = 0;
		
		nuevoNodo->siguiente = lista;
		lista = nuevoNodo;
	}
}

void ingresarClientes(Lista &lista, int limite)
{
	//Lista nodoAuxliliar = new Nodo();
	Nodo nodoAuxliliar;
	int i=0;

	
	for(i=0; i<limite; i++)
	{
		printf("\n\nIngrese los datos de la persona[%d]:", i+1);
		
		printf("\nCedula:\t");
		scanf("%ld", &(nodoAuxliliar.cedula));
		//printf("\n\n%ld", nodoAuxliliar.cedula);
		fflush(stdin);
		
		printf("\nNombre:\t\t");
		gets(nodoAuxliliar.nombre);
		//puts(nodoAuxliliar.nombre);
		fflush(stdin);
		
		printf("\nApellido:\t");
		gets(nodoAuxliliar.apellido);
		//puts(nodoAuxliliar.apellido);
		fflush(stdin);
		do
		{
			printf("\nCodigo:\t\t");
			gets(nodoAuxliliar.codigo);
			nodoAuxliliar.codigo[0] = toupper(nodoAuxliliar.codigo[0]);
			//puts(nodoAuxliliar.codigo);
			fflush(stdin);
			if((nodoAuxliliar.codigo[0] <65) || (nodoAuxliliar.codigo[0] > 75))
				printf("\n\t\tError. El codigo debe estar entre A-k");
		}while((nodoAuxliliar.codigo[0] <65) || (nodoAuxliliar.codigo[0] > 75));
		
		
		printf("\nMonto Adeudado:\t");
		scanf("%f", &(nodoAuxliliar.valorDeuda));
		//printf("\n\n%f", nodoAuxliliar.valorDeuda);
		fflush(stdin);
		
		insertarNodo(lista, nodoAuxliliar);					// Me agrega el nodo a la lista
		
	}	
}



void imprimirListaSimple(Lista lista)
{
	Lista nodoAux;
	nodoAux = lista;
	
	
	printf("\n\n\t\t\tLISTA");
	while(nodoAux != NULL)
	{
		printf("\n  Cedula:%ld \tNombre:%s \tApellido:%s \tCodigo:%s \tDeuda:%0.2f \tCancelado:%0.2f", nodoAux->cedula, nodoAux->nombre, nodoAux->apellido, nodoAux->codigo, nodoAux->valorDeuda, nodoAux->valorCancelado);
		nodoAux = nodoAux->siguiente;
	}
	printf("\n\n");
}

void calcularValoresCancelador(Lista lista, float *cantidad)
{
	
	int i=0, validador=0;
	
	Lista auxiliar;
	auxiliar = lista;


	while(auxiliar != NULL)
	{
		if(auxiliar->valorCancelado > 0 )
		{
			*cantidad = *cantidad + auxiliar->valorCancelado;
		}

		auxiliar = auxiliar->siguiente;	
	}

}

int calcularClientesCancelados(Lista lista)
{
	
	int i=0, contador=0;
	
	Lista auxiliar;
	auxiliar = lista;


	while(auxiliar != NULL)
	{
		if(auxiliar->valorCancelado != 0 )
		{
			contador++;
		}

		auxiliar = auxiliar->siguiente;	
	}
	return contador;
}


void calcularCodigosCancelados(Lista lista, float valorCancelado)
{
	
	int i=0;
	
	Lista auxiliar;
	auxiliar = lista;
	
	float contA=0, contB=0, contC=0, contD=0, contE=0, contF=0, contG=0, contH=0, contI=0, contJ=0, contK=0;


	while(auxiliar != NULL)
	{
		switch(auxiliar->codigo[0])
		{
			case 'A':
			{
				contA= contA + auxiliar->valorCancelado;
				break;
			}
			
			case 'B':
			{
				contB= contB + auxiliar->valorCancelado;
				break;
			}
			
			case 'C':
			{
				contC= contC + auxiliar->valorCancelado;
				break;
			}
			
			case 'D':
			{
				contD= contD + auxiliar->valorCancelado;
				break;
			}
			
			case 'E':
			{
				contE= contE + auxiliar->valorCancelado;
				break;
			}
			
			case 'F':
			{
				contF= contF + auxiliar->valorCancelado;
				break;
			}
			
			case 'G':
			{
				contG= contG + auxiliar->valorCancelado;
				break;
			}
			
			case 'H':
			{
				contH= contH + auxiliar->valorCancelado;
				break;
			}
			
			case 'I':
			{
				contI= contI + auxiliar->valorCancelado;
				break;
			}
			
			case 'J':
			{
				contJ= contJ + auxiliar->valorCancelado;
				break;
			}
			
			case 'K':
			{
				contK= contK + auxiliar->valorCancelado;
				break;
			}
			
		}

		auxiliar = auxiliar->siguiente;	
	}
	
	printf("\nb) Monto total recaudado por Codigos:");
	printf("\n\tA: %0.2f \tB: %0.2f \tC: %0.2f \tD: %0.2f", contA, contB, contC, contD);
	printf("\n\tE: %0.2f \tF: %0.2f \tG: %0.2f \tH: %0.2f", contE, contF, contG, contH);
	printf("\n\tI: %0.2f \tJ: %0.2f \tK: %0.2f ", contI, contJ, contK);
	printf("\n\tTOTAL RECAUDADO: \t%0.f", valorCancelado);

}



void cobrarClientes(Lista &lista, int limite)
{
	int i=0, validador=0, opcion=1;
	float cantidad=0;
	Nodo nodoAuxliliar;
	Lista auxiliar, apuntador;
	auxiliar = lista;
	apuntador = lista;

	
	do
	{
		auxiliar = apuntador;
		validador=0;
		printf("\n\nIngrese el numero de Cedula de la persona");
		
		printf("\nCedula:\t");
		scanf("%ld", &(nodoAuxliliar.cedula));
		//printf("\n\n%ld", nodoAuxliliar.cedula);
		fflush(stdin);
	

		while(auxiliar != NULL)
		{
			if(auxiliar->cedula == nodoAuxliliar.cedula )
			{
				
				printf("\nCodigo:\t%s", auxiliar->codigo);
				printf("\nNombre:%s %s \tDeuda:%0.2f \tCancelado:%0.2f", auxiliar->nombre, auxiliar->apellido, auxiliar->valorDeuda, auxiliar->valorCancelado);
				do
				{
					printf("\nIngrese el monto a pagar:\t");
					scanf("%f", &(nodoAuxliliar.valorCancelado));
					if( ( (nodoAuxliliar.valorCancelado) > (auxiliar->valorDeuda - auxiliar->valorCancelado)) || (nodoAuxliliar.valorCancelado <= 0) )
						printf("\n\t\tError en el ingreso de la cantidad");
						
				}while( ( (nodoAuxliliar.valorCancelado) > (auxiliar->valorDeuda - auxiliar->valorCancelado)) || (nodoAuxliliar.valorCancelado <= 0));
				
				
				auxiliar->valorCancelado = nodoAuxliliar.valorCancelado;
				//lista = auxiliar;
				validador++;
			}

			auxiliar = auxiliar->siguiente;	
		}
		
		if(validador==0)
			printf("\n\t\tCedula no registrada");
	
		calcularValoresCancelador(lista,&cantidad);
		
		if((cantidad >= 500000) || (calcularClientesCancelados(lista)==limite))
		{
			printf("\n\na) ¿Desea seguir ingresando pagos?\n Pulse 0 para salir");
			scanf("%d", &opcion);
		}
		
	}while(opcion!=0);	
}


////////////////////////////////////////////////////////////////////////////////////////////
main()
{
	Lista lista = new Nodo();
	lista = NULL;
	
	int numeroClientes;
	int i;
	float valorCancelado=0;
	
	printf("\nIngrese el numero de clientes:\t");
	scanf("%d", &numeroClientes);
	ingresarClientes(lista, numeroClientes);
	imprimirListaSimple(lista);

	cobrarClientes(lista, numeroClientes );
	imprimirListaSimple(lista);
	calcularValoresCancelador(lista, &valorCancelado);
	//printf("\nb) Monto total recaudado:\t%0.2f", valorCancelado);
	calcularCodigosCancelados(lista, valorCancelado);
	printf("\nc) Personas sin atender:\t%d", calcularClientesCancelados(lista)-numeroClientes);
	
}
