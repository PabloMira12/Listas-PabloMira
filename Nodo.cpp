#include "Nodo.h"

Nodo::Nodo()
{
	dato = 0;
	Li = nullptr;
	Ld = nullptr;
}

int Nodo::Getdato()
{
	return dato;
}

void Nodo::Setdato(int d)
{
	dato = d;
}

Nodo* Nodo::Getli()
{
	return Li;
}

void Nodo::Setli(Nodo*l)
{
	Li = l;
}

Nodo* Nodo::Getld()
{
	return Ld;
}

void Nodo::Setld(Nodo*l)
{
	Ld = l;
}


