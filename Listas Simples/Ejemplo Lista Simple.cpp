#include "conio.h"
#include "stdlib.h"
#include "stdio.h"
#include "windows.h"
#include "colores.h"
//--------- Atributos
struct Nodo
{
	int datoEntero;
	Nodo *sigDir;
};
typedef struct Nodo ListaSimple;


//---------- Metodos
char *ingreso(char *msg)
{
	char dato[10];
	printf("%s", msg);
	gets (dato);
	return dato;
}


void insertarDatoNodo(ListaSimple *&lista, int dato)
{
	ListaSimple *nuevoNodo = new ListaSimple();
	
	if(nuevoNodo != NULL)
	{
		nuevoNodo->datoEntero = dato;
		nuevoNodo->sigDir = lista;
		lista = nuevoNodo;
	}

}


int contarListaSimple(ListaSimple *lista)		// Esta funcion me permite determinar el numero de elementos
{
	
	ListaSimple *auxiliar;
	int contador=0;
	
	auxiliar = lista;
	
	while(auxiliar != NULL)
	{
		contador++;
		auxiliar = auxiliar->sigDir;
	}
	
	return contador;
}

void imprimirListaSimple(ListaSimple *&lista)
{
	ListaSimple *nodoAux;
	nodoAux = lista;
	
	
	printf("\n\n\tLISTA:\t");
	while(nodoAux != NULL)
	{
		printf("%d ->", nodoAux->datoEntero);
		nodoAux = nodoAux->sigDir;
	}
	printf("\n\n");
}

void imprimirListaSimpleBuscador(ListaSimple *&lista, int buscador)
{
	ListaSimple *nodoAux;
	nodoAux = lista;
	int limite, contador;
	
	limite = contarListaSimple(lista);
	printf("\nLimite:\t\t\t %d", limite);
	printf("\nBuscador:\t\t %d", buscador);
	
	printf("\n\nEl nodo %d tiene:\t", buscador);
	for(int i=0; i <= (limite - buscador); i++)
	{
		if( i==(limite - buscador))
		{
			printf(" %d", nodoAux->datoEntero);
		}
		
		nodoAux = nodoAux->sigDir;
		contador++;
	}	
}

void eliminarUltimoNodo(ListaSimple *&lista, int limite)
{
	ListaSimple *auxiliar, *listaSecundaria;
	auxiliar = lista;
	listaSecundaria = auxiliar;


	if(auxiliar->sigDir != NULL)
	{
		for(int i=0; i<limite - 2; i++)
		{
			auxiliar=auxiliar->sigDir;
		}
		printf("\n\tNodo penultimo: %d", auxiliar->datoEntero);
		auxiliar->sigDir = NULL;
		lista = listaSecundaria;
	}
	else
	{
		lista = NULL;
	}
	
	/////////////////////////////////// Algoritmo para eliminar el primer elemento
	//imprimirListaSimple(auxiliar);
	/*
	lista = lista->sigDir;
	printf("\nA");
	imprimirListaSimple(auxiliar);*/
	
}

void modificarNodoLista(ListaSimple *&lista, int buscador, int dato )
{
	ListaSimple *auxiliar;
	
	auxiliar = lista;
	
	while(auxiliar != NULL)
	{
		if(auxiliar->datoEntero == buscador)
		{
			auxiliar->datoEntero = dato;
		}
		auxiliar = auxiliar->sigDir;
	}
}

void guardarArchivo(char path[], ListaSimple *lista, char texto[] )
{
	ListaSimple *auxiliar;
	auxiliar = lista;
	
	FILE *archivo;
	
	archivo = fopen(path, "a");
	
	if (archivo!=NULL)
	{
		fprintf(archivo, "%s\n ", texto);
		while(auxiliar != NULL)
		{
			fprintf(archivo, "%d ", auxiliar->datoEntero);
			fprintf(archivo, "-> ");
			auxiliar = auxiliar->sigDir;
		}
		fprintf(archivo, " NULL \n\n");
	}
	fclose(archivo);
}


//------- Menu
void portada()
{
	printf("\n\t\t\t\t\tUNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE");
	printf("\n\t\t\t\t\t\tESTRUCTURA DE DATOS 2479");
	printf("\n\t\tTema:\t\t Listas Simples");
	printf("\n\t\tAutor:\t\t Bryan Tualle");
	printf("\n\t\tFecha:\t\t 2017/11/05");
	printf("\n\t\tProfesor:\t Ing. Edgar Fernando Solis Acosta");
	printf("\n\t\tCarrera:\t Ing. Sistemas e informatica");

}
void gotoxy(int x,int y)
{  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  

/* LIBRERIA COLORES 
Colores :
BLACK			0 Negro
BLUE			1 Azul
GREEN			2 Verde
CYAN			3 Cían
RED				4 Rojo
MAGENTA			5 Magenta
BROWN			6 Marrón
LIGHTGRAY		7 Gris Claro
DARKGRAY		8 Gris Oscuro
LIGHTBLUE		9 Azul Claro
LIGHTGREEN		10 Verde Claro
LIGHTCYAN		11 Cían Claro
LIGHTRED		12 Rojo Claro
LIGHTMAGENTA	13 Magenta Claro
YELLOW			14 Amarillo
WHITE			15 Blanco
*/

int menuSeleccion(const char menu[], const char *opciones[], int numeroOpciones)
{
	int seleccion=1,tecla=0,i;
	bool repite=true;
	
	do
	{
		system("cls");
		color(15,3);
		portada();
		color(15,0);
		//gotoxy(6,3+seleccion);

		gotoxy(51,10);
		color(15,4);

		printf("%s",menu);
		color(15,0);
		for(i=0;i<numeroOpciones;i++)
		{
			gotoxy(50,12+i);
			if((4+i)==(3+seleccion))		//Rellena la opcion; Background
			{
				color(5,10);
				printf("%s",opciones[i]);	
				color(15,0);
			}
			else
			{
				printf("%s",opciones[i]);	
			}
			
		}
		
		do									//Valida para las flechas y ENTER
		{
			tecla=getch();
		}while((tecla!=72)&&(tecla!=80)&&(tecla!=13));
		
		switch(tecla)
		{
			case 72:		//Flecha Arriba
				{
					seleccion--;
					if(seleccion<1)
					{
						seleccion=numeroOpciones;
	
					}
					break;
				}
				
			case 80:		//Flecha Abajo
				{
					seleccion++;
					if(seleccion>numeroOpciones)
				 	{
						seleccion=1;
								
	
					}
					break;
				}
			case 13:		//ENTER
				{
					//color(4,15);
					repite=false;
					break;
				}
		}
	}while(repite);
	
	return seleccion;
}

void menuPrincipal(ListaSimple *&lista)
 {
	bool repite=true;
	char menu[]="MENU PRINCIPAL";
	const char *opciones[]={"   Insertar   ","   Eliminar   ","   Modificar  ","   Imprimir   ","   Salir      "};
	int numeroOpciones=5, opcion=0;
	int i, valor, buscador;
	
	do{
		//portada();
		opcion=menuSeleccion(menu,opciones,numeroOpciones); //retorno el valor de la opcion
		switch(opcion)
		{
			case 1:		/////////////// INSERTAR
			 {
				system("cls");
				printf("\n\t\t\tINSERTAR\n\n");
				//for(i=0; i<=4; i++)
				//{
					valor = atoi(ingreso("Ingrese el valor:\t"));
					//printf("\n%d", valor);
					insertarDatoNodo(lista,valor);
				//}
				printf("\nNumero de elementos: \t%d",contarListaSimple(lista));
				imprimirListaSimple(lista);
				guardarArchivo("Historial.txt", lista, "INSERTAR");
				getch();
				break;
			 }
			case 2:		////////////// ELIMINAR
			{
				system("cls");
				printf("\n\t\t\tELIMINAR\n\n");
				if(lista== NULL)
				{
					printf("Lista Vacia");
				}
				else
				{
					imprimirListaSimple(lista);
					eliminarUltimoNodo(lista, contarListaSimple(lista) );
					imprimirListaSimple(lista);
					guardarArchivo("Historial.txt", lista, "ELIMINAR");
				}
				
				getch();
				break;
			}
			case 3:		///////////// MODIFICAR
			{
				system("cls");
				printf("\n\t\t\tMODIFICARn\n");
				if(lista== NULL)
				{
					printf("Lista Vacia");
				}
				else
				{
					imprimirListaSimple(lista);
					buscador = atoi(ingreso("Ingrese el dato a modificar:\t"));
					valor = atoi(ingreso("Ingrese el nuevo valor:\t"));
					modificarNodoLista(lista, buscador, valor );
					imprimirListaSimple(lista);
					guardarArchivo("Historial.txt", lista, "MODIFICAR");
				}
				
				getch();
				break;
			}
			case 4:		//////////// IMPRIMIR
			{
				system("cls");
				printf("\n\t\t\tIMPRIMIR\n\n");
				
				if(lista== NULL)
				{
					printf("Lista Vacia");
				}
				else
				{
					imprimirListaSimple(lista);
				}
				
				getch();
				break;
			}
			case 5:		//////////// SALIR
			{
				repite =false;
				system("cls");
				printf("\n\t\t\tSALIR\n\n");
				printf("\n\n\t\t\tGracias\n\n");
				getch();
				break;
			}
			
		 }
		
	 }while(repite);
 }


//////////////////////////// VOID MAIN
main()
{
	ListaSimple *lista = new ListaSimple();
	lista = NULL;
	
	
	
	color(15,0);
	menuPrincipal(lista);
	/*
	for(int i=0; i<=4; i++)
	{
		valor = atoi(ingreso("Ingrese el valor:\t"));
		//printf("\n%d", valor);
		insertarDatoNodo(lista,valor);
	}
	printf("\nPosicion a buscar:\t");
	scanf("%d", &buscador);
	printf("\nNumero de elementos: \t%d",contarListaSimple(lista));
	imprimirListaSimple(lista);
	imprimirListaSimpleBuscador(lista, buscador);
	eliminarUltimoNodo(lista, contarListaSimple(lista) );
	imprimirListaSimple(lista);
	
	eliminarUltimoNodo(lista, contarListaSimple(lista) );
	imprimirListaSimple(lista);
	
	modificarNodoLista(lista, 2, 100 );
	imprimirListaSimple(lista);
	*/

	
}




