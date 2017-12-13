#pragma once
class Nodo
{
	private:
		int datoEntero;
		Nodo *sigDir;
		
	public:
		// constructores
		Nodo();
		~Nodo();
		Nodo(int, Nodo *);
		
		//getters and setters
		int GetDato();
		void SetDato(int);
		Nodo* GetNodo();
		void SetNodo(Nodo *);
};

