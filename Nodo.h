#pragma once
class Nodo
{
//atributos
	int dato;
	Nodo* Li , *Ld;


//M�todos
public:
	Nodo(); 		// constructor da valor inicial a los atributos

	int Getdato();			//obtener
	void Setdato(int);		//asignar , ir a guardar
	Nodo* Getli();
	void Setli(Nodo*);
	Nodo* Getld();
	void Setld(Nodo*);
};

