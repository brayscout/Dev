#include "conio.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "windows.h"
#include "colores.h"
#include "Lista.h"

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
 /*
const char ingreso(char *msg)
{
	char dato[10];
	printf("%s", msg);
	gets (dato);
	
	return *dato;
}
*/
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

//---------- Metodos


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

void menuPrincipal()
 {
 	Lista lista;
 	
	bool repite=true;
	char menu[]="MENU PRINCIPAL";
	const char *opciones[]={"   Insertar   ","   Eliminar   ","   Modificar  ","   Imprimir   ","   Salir      "};
	int numeroOpciones=5, opcion=0;
	int i, valor, buscador;
	char valorString[10];
	
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
					printf("\nIngrese el valor:");
					gets(valorString);
					valor = atoi(valorString);
					//printf("\n%d", valor);
					lista.insertarDatoNodo(valor);
				//}
				printf("\nNumero de elementos: \t%d", lista.contarListaSimple());
				lista.imprimirListaSimple();
				lista.guardarArchivo();
				getch();
				break;
			 }
			case 2:		////////////// ELIMINAR
			{
				system("cls");
				printf("\n\t\t\tELIMINAR\n\n");
				if(lista.verificarLista() == false)
				{
					printf("Lista Vacia");
				}
				else
				{
					lista.imprimirListaSimple();
					lista.eliminarUltimoNodo();
					lista.imprimirListaSimple();
					lista.guardarArchivo();
				}
				
				getch();
				break;
			}
			case 3:		///////////// MODIFICAR
			{
				system("cls");
				printf("\n\t\t\tMODIFICARn\n");
				if(lista.verificarLista()==false)
				{
					printf("Lista Vacia");
				}
				else
				{
					lista.imprimirListaSimple();
					printf("\nIngrese el valor a buscar:");
					gets(valorString);
					buscador = atoi(valorString);
					//buscador = atoi(ingreso("d"));
					printf("\nIngrese el valor a reemplazar:");
					gets(valorString);
					valor = atoi(valorString);
					lista.modificarNodoLista(buscador, valor );
					lista.imprimirListaSimple();
					lista.guardarArchivo();
				}
				
				getch();
				break;
			}
			case 4:		//////////// IMPRIMIR
			{
				system("cls");
				printf("\n\t\t\tIMPRIMIR\n\n");
				
				if(lista.verificarLista()==false)
				{
					printf("Lista Vacia");
				}
				else
				{
					lista.imprimirListaSimple();
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
		
	color(15,0);
	menuPrincipal();
	
}




