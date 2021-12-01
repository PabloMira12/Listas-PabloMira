#pragma once
#include "Nodo.h"

class Lista
{
//atributo
public: Nodo *Punta , *Fin;

//metodos
public:
	Lista();

	void Insertar_inicio(int);
	void MOSTRAR();
	void MOSTRARIzq();
	void Insertar_final(int);
	void ORDENAR();
	void INSERTAR_ORDENADO(int);
	void BUSCAR(int);
	void REMPLAZAR(int , int);
	void ELIMINAR(int);
	void SUMAR2LISTAS(Lista* L1);

};

