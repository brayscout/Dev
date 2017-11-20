#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

struct nodo
{
    int digito;
    struct nodo *siguienteDireccion;
    struct nodo *anterior;
};

typedef struct nodo *punteroNodo;

//Declaracion de prototipos
void MostrarEncabezado();

void MostrarMenu(int);

int ObtenerEnteroPositivo();

void IngresarPrimerDato(punteroNodo &);

void IngresarAlInicio(punteroNodo &);

void IngresarAlFinal(punteroNodo &);

void IngresarEntre(punteroNodo &);

void MostrarLista(punteroNodo);

void LiberarMemoria(punteroNodo &);

//Desarrollo de prototipos

void MostrarMenu(int opcion)
{
    HANDLE salida = GetStdHandle ( STD_OUTPUT_HANDLE );
    WORD coloresOriginales;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(salida, &csbiInfo);
    coloresOriginales = csbiInfo.wAttributes;
    switch(opcion){
        case 1:
            system("cls");
            printf("\t\t----------------------\n");
            printf("\t\t   LISTA DE NUMEROS\n");
            printf("\t\t----------------------\n\n");
            SetConsoleTextAttribute ( salida, FOREGROUND_GREEN | BACKGROUND_BLUE );
            printf("1.- Ingresar el primer elemento de la lista.                               \n");
            SetConsoleTextAttribute ( salida, coloresOriginales);
            printf("2.- Ingresar un numero entero positivo al inicio de la lista.              \n");
            printf("3.- Ingresar un numero entero positivo al final de la lista.               \n");
            printf("4.- Ingresar un numero entero positivo despues de una posicion de la lista.\n");
            printf("5.- Imprimir lista y Primos de la lista.                                   \n");
            printf("0.- Salir.                                                                 \n\n");
        break;
        case 2:
            system("cls");
            printf("\t\t----------------------\n");
            printf("\t\t   LISTA DE NUMEROS\n");
            printf("\t\t----------------------\n\n");
            printf("1.- Ingresar el primer elemento de la lista.                               \n");
            SetConsoleTextAttribute ( salida, FOREGROUND_GREEN | BACKGROUND_BLUE );
            printf("2.- Ingresar un numero entero positivo al inicio de la lista.              \n");
            SetConsoleTextAttribute ( salida, coloresOriginales);
            printf("3.- Ingresar un numero entero positivo al final de la lista.               \n");
            printf("4.- Ingresar un numero entero positivo despues de una posicion de la lista.\n");
            printf("5.- Imprimir lista y Primos de la lista.                                   \n");
            printf("0.- Salir.                                                                 \n\n");
        break;
        case 3:
            system("cls");
            printf("\t\t----------------------\n");
            printf("\t\t   LISTA DE NUMEROS\n");
            printf("\t\t----------------------\n\n");
            printf("1.- Ingresar el primer elemento de la lista.                               \n");
            printf("2.- Ingresar un numero entero positivo al inicio de la lista.              \n");
            SetConsoleTextAttribute ( salida, FOREGROUND_GREEN | BACKGROUND_BLUE );
            printf("3.- Ingresar un numero entero positivo al final de la lista.               \n");
            SetConsoleTextAttribute ( salida, coloresOriginales);
            printf("4.- Ingresar un numero entero positivo despues de una posicion de la lista.\n");
            printf("5.- Imprimir lista y Primos de la lista.                                   \n");
            printf("0.- Salir.                                                                 \n\n");
        break;
        case 4:
            system("cls");
            printf("\t\t----------------------\n");
            printf("\t\t   LISTA DE NUMEROS\n");
            printf("\t\t----------------------\n\n");
            printf("1.- Ingresar el primer elemento de la lista.                               \n");
            printf("2.- Ingresar un numero entero positivo al inicio de la lista.              \n");
            printf("3.- Ingresar un numero entero positivo al final de la lista.               \n");
            SetConsoleTextAttribute ( salida, FOREGROUND_GREEN | BACKGROUND_BLUE );
            printf("4.- Ingresar un numero entero positivo despues de una posicion de la lista.\n");
            SetConsoleTextAttribute ( salida, coloresOriginales);
            printf("5.- Imprimir lista y Primos de la lista.                                   \n");
            printf("0.- Salir.                                                                 \n\n");
        break;
        case 5:
            system("cls");
            printf("\t\t----------------------\n");
            printf("\t\t   LISTA DE NUMEROS\n");
            printf("\t\t----------------------\n\n");
            printf("1.- Ingresar el primer elemento de la lista.                               \n");
            printf("2.- Ingresar un numero entero positivo al inicio de la lista.              \n");
            printf("3.- Ingresar un numero entero positivo al final de la lista.               \n");
            printf("4.- Ingresar un numero entero positivo despues de una posicion de la lista.\n");
            SetConsoleTextAttribute ( salida, FOREGROUND_GREEN | BACKGROUND_BLUE );
            printf("5.- Imprimir lista y Primos de la lista.                                   \n");
            SetConsoleTextAttribute ( salida, coloresOriginales);
            printf("0.- Salir.                                                                 \n\n");
        break;
        case 6:
            system("cls");
            printf("\t\t----------------------\n");
            printf("\t\t   LISTA DE NUMEROS\n");
            printf("\t\t----------------------\n\n");
            printf("1.- Ingresar el primer elemento de la lista.                               \n");
            printf("2.- Ingresar un numero entero positivo al inicio de la lista.              \n");
            printf("3.- Ingresar un numero entero positivo al final de la lista.               \n");
            printf("4.- Ingresar un numero entero positivo despues de una posicion de la lista.\n");
            printf("5.- Imprimir lista y Primos de la lista.                                   \n");
            SetConsoleTextAttribute ( salida, FOREGROUND_GREEN | BACKGROUND_BLUE );
            printf("0.- Salir.                                                                 \n\n");
            SetConsoleTextAttribute ( salida, coloresOriginales);
        break;
        default:;
    }
}

int ObtenerEnteroPositivo(){
    char digito,cadenaDelEntero[5];
    int entero,iterador=0;
    while((digito=getch())!=13||iterador==0)
	{
        if(digito>='0'&&digito<='9'&&iterador<5){
            printf("%c",digito);
            cadenaDelEntero[iterador++]=digito;
        }
        if(iterador==5)
            break;
    }
    cadenaDelEntero[iterador]='\0';
    return entero=atoi(cadenaDelEntero);
}

void IngresarDatoPrimo(punteroNodo &lista, int dato)
{
    if(lista==NULL)
	{
        punteroNodo punteroAuxiliar=new(struct nodo);
        punteroAuxiliar->digito=dato;
        punteroAuxiliar->siguienteDireccion=punteroAuxiliar->anterior=NULL;
        lista=punteroAuxiliar;
    }
	else
	{
		punteroNodo punteroAuxiliar1,punteroAuxiliar2;
        punteroAuxiliar1=new(struct nodo);
        
        punteroAuxiliar1->digito = dato;
        punteroAuxiliar2=lista;
        punteroAuxiliar1->siguienteDireccion=punteroAuxiliar2;
        punteroAuxiliar1->anterior=punteroAuxiliar2->anterior;
        punteroAuxiliar2->anterior=punteroAuxiliar1;
        
		lista=punteroAuxiliar1;
    }
}

void IngresarPrimerDato(punteroNodo &lista){
    system("cls");
    printf("\t----------------------------\n");
    printf("\t   INGRESAR PRIMER NUMERO\n");
    printf("\t----------------------------\n\n");
    if(lista==NULL)
	{
        punteroNodo punteroAuxiliar=new(struct nodo);
        printf("Ingrese el primer numero:\n\n");
        punteroAuxiliar->digito=ObtenerEnteroPositivo();
        punteroAuxiliar->siguienteDireccion=punteroAuxiliar->anterior=NULL;
        lista=punteroAuxiliar;
        printf("\n\nPrimer numero ingresado!\n\n");
    }else{
        printf("Ya ingreso el primer elemento!\n\n");
    }
}

void IngresarAlInicio(punteroNodo &lista){
    system("cls");
    printf("\t-------------------------------\n");
    printf("\t   INGRESAR NUMERO AL INICIO\n");
    printf("\t-------------------------------\n\n");
    if(lista!=NULL){
        punteroNodo punteroAuxiliar1,punteroAuxiliar2;
        punteroAuxiliar1=new(struct nodo);
        printf("Ingrese el numero:\n\n");
        punteroAuxiliar1->digito=ObtenerEnteroPositivo();
        punteroAuxiliar2=lista;
        punteroAuxiliar1->siguienteDireccion=punteroAuxiliar2;
        punteroAuxiliar1->anterior=punteroAuxiliar2->anterior;
        punteroAuxiliar2->anterior=punteroAuxiliar1;
        lista=punteroAuxiliar1;
        printf("\n\nDato ingresado!\n\n");
    }else{
        printf("Debe ingresar el primer elemento!\n\n");
    }
}

void IngresarAlFinal(punteroNodo &lista){
    system("cls");
    printf("\t------------------------------\n");
    printf("\t   INGRESAR NUMERO AL FINAL\n");
    printf("\t------------------------------\n\n");
    if(lista!=NULL){
        punteroNodo punteroAuxiliar1,punteroAuxiliar2;
        punteroAuxiliar1=new(struct nodo);
        printf("Ingrese el numero:\n\n");
        punteroAuxiliar1->digito=ObtenerEnteroPositivo();
        punteroAuxiliar2=lista;
        while(punteroAuxiliar2->siguienteDireccion!=NULL){
            punteroAuxiliar2=punteroAuxiliar2->siguienteDireccion;
        }
        punteroAuxiliar1->siguienteDireccion=punteroAuxiliar2->siguienteDireccion;
        punteroAuxiliar2->siguienteDireccion=punteroAuxiliar1;
        punteroAuxiliar1->anterior=punteroAuxiliar2;
        printf("\n\nDato ingresado!\n\n");
    }else{
        printf("Debe ingresar el primer elemento!\n\n");
    }
}

void IngresarEntre(punteroNodo &lista){
    if(lista!=NULL){
        int iterador=1, bandera=0, posicion;
        do{
            system("cls");
            printf("\t---------------------------\n");
            printf("\t   INGRESAR NUMERO ENTRE\n");
            printf("\t---------------------------\n\n");
            printf("Ingrese la posicion:\n\n");
            posicion=ObtenerEnteroPositivo();
        }while(posicion==0);
        punteroNodo punteroAuxiliar2=lista;
        while(punteroAuxiliar2->siguienteDireccion!=NULL)
		{
            if(posicion==iterador)
			{
                punteroNodo punteroAuxiliar1=new(struct nodo);
                printf("\n\nDigite el numero a ingresar:\n\n");
                punteroAuxiliar1->digito=ObtenerEnteroPositivo();
                punteroAuxiliar1->siguienteDireccion=punteroAuxiliar2->siguienteDireccion;
                punteroAuxiliar2->siguienteDireccion=punteroAuxiliar1;
                punteroAuxiliar1->anterior=punteroAuxiliar2;
                punteroAuxiliar1->siguienteDireccion->anterior=punteroAuxiliar1;
                printf("\n\nDato ingresado!\n\n");
                while(punteroAuxiliar2->anterior!=NULL){
                    punteroAuxiliar2=punteroAuxiliar2->anterior;
                }
                lista=punteroAuxiliar2;
                bandera=1;
                break;
            }
            punteroAuxiliar2=punteroAuxiliar2->siguienteDireccion;
            iterador++;
        }
        if(posicion==iterador&&bandera==0){
            printf("\n\nUsted intenta ingresar un dato al final de la lista!\n\n");
            system("pause");
            IngresarAlFinal(lista);
        }else if(iterador<posicion&&bandera==0){
            printf("\n\nLa posicion ingresada es superior al numero de los elementos de la lista!\n\n");
        }
    }else{
        system("cls");
        printf("\t---------------------------\n");
        printf("\t   INGRESAR NUMERO ENTRE\n");
        printf("\t---------------------------\n\n");
        printf("Debe ingresar el primer elemento!\n\n");
    }
}

void MostrarLista(punteroNodo lista)
{
    if(lista==NULL){
        printf("No hay elementos en la lista!\n\n");
    }else
	{
		int numero=0;
		
        printf("\n\n\tLISTA:\t");
        while(lista!=NULL)
		{
			numero ++;

			printf("|#%d| %d ->", numero, lista->digito);

            lista=lista->siguienteDireccion;
        }
        printf("\n\n");
    }
}
bool verificarPrimo(int n)
{
	int i, a=0;
	
	for(i=1;i<(n+1);i++)
	{
		if(n%i==0)
		{
	    	a++;
		}
	}
	
    if(a!=2)
	{
          return false;
    }else
	{
    	return true;
    }
}

void encontrarNumeroPrimo(punteroNodo &lista, punteroNodo &listaPrimos)
{
	
	
	if(lista==NULL)
	{
        //printf("No hay elementos en la lista!\n\n");
    }else
	{
		punteroNodo punteroAuxiliar;
		punteroNodo punteroAuxiliar2=lista;
		punteroNodo punteroAuxiliar3=lista;
		
        while(punteroAuxiliar2!=NULL)
		{
			if(verificarPrimo(punteroAuxiliar2->digito) == true )
			{
				IngresarDatoPrimo(listaPrimos, punteroAuxiliar2->digito );
				printf("\n\nLista de Numeros Primos");
				//MostrarLista(listaPrimos);
				//printf("\nHasta aqui vale\n");
				//system("pause");
				/*
				punteroAuxiliar= punteroAuxiliar2->siguienteDireccion;
				punteroAuxiliar2 = punteroAuxiliar2->anterior;
				punteroAuxiliar2->siguienteDireccion = punteroAuxiliar;
				*/
			
				punteroAuxiliar3 = punteroAuxiliar2;
				punteroAuxiliar3 = punteroAuxiliar3->siguienteDireccion;
				
				punteroAuxiliar2 = punteroAuxiliar2->anterior;
				
				punteroAuxiliar2->siguienteDireccion = punteroAuxiliar3;
				punteroAuxiliar = punteroAuxiliar2;
				punteroAuxiliar2 = punteroAuxiliar2->siguienteDireccion;
			}
			else
			{
				punteroAuxiliar = punteroAuxiliar2;
				punteroAuxiliar2=punteroAuxiliar2->siguienteDireccion;	
			}
			
			//punteroAuxiliar2=punteroAuxiliar2->siguienteDireccion;	
            
        }
        printf("\n\n");
        
        while(punteroAuxiliar->anterior != NULL)
        {
        	punteroAuxiliar = punteroAuxiliar->anterior;
		}
		
        lista=punteroAuxiliar;
    }
	
    
}

void LiberarMemoria(punteroNodo &lista){
    if(lista!=NULL)
	{
        punteroNodo punteroAuxiliar;
        while(lista!=NULL){
            punteroAuxiliar=lista->siguienteDireccion;
            delete(lista);
            lista=punteroAuxiliar;
        }
        printf("Memoria liberada!\n\n");
    }
}

main()
{
    int iterador=1;
    char opcion;
    system("color 0c");
    punteroNodo lista, listaPrimos;
	lista = listaPrimos = NULL;
	
    do{
        MostrarMenu(iterador);
        while((opcion=getch())!=13)
		{
            if(opcion==72){
                if(iterador==1){
                    iterador=6;
                }else{
                    iterador--;
                }
            }
            if(opcion==80){
                if(iterador==6){
                    iterador=1;
                }else{
                    iterador++;
                }
            }
            MostrarMenu(iterador);
        }
        
		switch(iterador){
            case 1:
                IngresarPrimerDato(lista);
                system("pause");
            break;
            case 2:
                IngresarAlInicio(lista);
                system("pause");
            break;
            case 3:
                IngresarAlFinal(lista);
                system("pause");
            break;
            case 4:
                IngresarEntre(lista);
                system("pause");
            break;
            case 5:
            	encontrarNumeroPrimo(lista, listaPrimos);
            	//printf("\nHasta aqui vale");
                MostrarLista(lista);
                MostrarLista(listaPrimos);
                system("pause");
            break;
            case 6:
                LiberarMemoria(lista);
                LiberarMemoria(listaPrimos);
                printf("Gracias por usar este software!\n\n");
                system("pause");
            break;
            default:;
        }
    }while(iterador!=6);
    return 0;
}
