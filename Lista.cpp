#include "Lista.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Lista::Lista()
{
	Punta = nullptr; 
    Fin = nullptr;
}

void Lista::Insertar_inicio(int d)                          // x es el nuevo Nodo
{
    Nodo* x = new Nodo();
    x->Setdato(d);

    if (Punta == nullptr)
    {
        Punta = x;              // pongo la punta en la primera direccion en memoria

        Fin = x;                // para poder hacer una lista circular  doblde el  fin lo necesitamos para unir el ultimo con la punta
        x->Setld(Punta);
        x->Setli(Punta);
    }
    else
    {
        x->Setld(Punta);                        //aqui inserto a inicio el nodo
        Punta->Setli(x);
        Punta = x;

        Fin->Setld(Punta);                //liga el inicio con el fin
        Punta->Setli(Fin);
    }
}

void Lista::MOSTRAR()
{
    Nodo* p = Punta;

    do
    {
        cout << "\t|" << p->Getdato() <<"|" ;              //mostrar el dato y la liga que es la posicion en meoria
        p = p->Getld();                                                         // avanzar el p
    } while (p != Punta);
    system("pause");
}

void Lista::MOSTRARIzq()                // mostrar liga por la izquierda
{
    Nodo* p = Punta;

    do
    {
        cout << "\t|" << p->Getdato() << "|" ;              //mostrar el dato y la liga que es la posicion en memoria
        p = p->Getli();                                                         // avanzar el p
    } while (p != Punta);
    system("pause");
}

void Lista::Insertar_final(int d)
{
    Nodo* x = new Nodo();
   // Nodo* p;
    //int d;
    // p = Punta;
    x->Setdato(d);
    if (Punta == nullptr)
    {
        Punta = x;
        Fin = x;                // para poder hacer una lista circular el  fin lo necesitamos para unir el ultimo con la punta
        x->Setli(Punta);
        x->Setld(Punta);
    }
    else
    {
       /* while (p->Getliga() != nullptr)           // p se necesita para insertar una lista simple
        {
            p = p->Getliga();
        }*/

        Fin->Setld(x);                    //insertar al final una lista cricular , p ya no se necesita , se utiliza es el fin en vez del p
        x->Setli(Fin);
        Fin = x;
        Fin->Setld(Punta);
        Punta->Setli(Fin);
    }
}

void Lista::ORDENAR()
{
    int aux = 0;
    Nodo* p = Punta , * x;
    x = p->Getld();

    do
    {
        if (p->Getdato() > x->Getdato())
        {
            aux = p->Getdato();                     //utilizo el aux para remplazra el valor q voy a ordenar
            p->Setdato(x->Getdato());
            x->Setdato(aux);
        }

        if (x == Fin)
        {
            p = p->Getld();
            x = p->Getld();
        }
        else
        {
            x = x->Getld();
        }
    } while (p->Getld() != Punta);
}

void Lista::INSERTAR_ORDENADO(int d)
{
    Nodo* x = new Nodo(), * a = nullptr , * p;
    ORDENAR();                     //  pregunto el dato a insertar
    x->Setdato(d);
    if (Punta == nullptr)
    {
        Punta = x;
        Fin = x;                // para poder hacer una lista circular el  fin lo necesitamos para unir el ultimo con la punta
        x->Setli(Punta);
        x->Setld(Punta);
    }
    else
    {
        p = Punta;
        do
        {
            a = p;
            p = p->Getld();
        }while (p != Punta && x->Getdato() > p->Getdato());

        if (p == Punta)
        {
            x->Setld(Punta);
            Punta->Setli(x);
            Punta = x;
            Punta->Setli(Fin);
            Fin->Setld(Punta);
        }
        else
        {
            a->Setld(x);
            x->Setli(a);

            x->Setld(p);
            p->Setli(x);
        }

    }  
}

void Lista::BUSCAR(int d_buscar)
{
    Nodo* p = Punta;
    do
    {
        if (p->Getdato() == d_buscar)
        {
            cout << "\n\tEl dato se encontro :D ";
        }
        else
        {
            p = p->Getld();
        }

    } while (p != Punta  &&  p->Getdato() != d_buscar);

    if (p->Getdato() == d_buscar)
    {
        cout << "\n\tEl dato se encontro :D ";
    }
    else
    {
        cout << "\n\tEl dato NO se encontro  ";
    }
    system("pause");
}

void Lista::REMPLAZAR(int d , int d_reemplazar)
{
    Nodo* p = Punta;
    bool sw = 1;
    
    do
    {
        if (d_reemplazar == p->Getdato())
        {
            p->Setdato(d);
            cout << "\n\tEl dato se reemplazo con exito :D " << endl;
            sw = 0;
            system("pause");
        }
          
        p = p->Getld();
    } while (p != Punta && d != p->Getdato());
    
    if (sw != 0)
    {
        cout << "\n\tEl dato no se encontro" << endl;
    }

    system("pause");
}

void Lista::ELIMINAR(int d)
{
    Nodo* L = Punta, * a = L->Getli(), * c = L->Getld()  ;
    bool sw = 1, SWF = 1;

    do
    {
        if (L == Fin && sw==1)
        {
            SWF = 0;
        }              
        if (d == L->Getdato())
        {
            if (L == Punta)
            {
                Punta = c;
                c->Setli(a);
                a->Setld(c);
            }
            else
            {
                a->Setld(c);
                c->Setli(a);
            }
            delete L;
            sw = 0;
        }
        else
        {
            L = L->Getld();
            a = L->Getli();
            c = L->Getld();
        }

    }while (sw != 0 && SWF != 0);

    if (sw == 1)
    {
        cout << "\n\tEl dato No se encontro por lo tanto no se borro " << endl;
    }
    else
    {
        cout << "\n\tEl dato se encontro por lo tanto se borro " << endl;
    }

    system("pause");
}

void Lista::SUMAR2LISTAS(Lista *L1)
{
    Nodo* p = L1->Punta , * q = Punta ;
    int D = 0;
    bool sw = 1; 
    Lista* L3 = new Lista();
    do
    {
        if (sw == 1 || (p != L1->Punta && q != Punta))
        {
            D = p->Getdato() + q->Getdato();
            q = q->Getld();
            p = p->Getld();
            sw = 0;
        }
        else
        {
            if (p != L1->Punta && q == Punta)
            {
                D = p->Getdato();
                p = p->Getld();
            }
            if (q != L1->Punta && p == Punta)
            {
                D = q->Getdato();
                q = q->Getld();
            }
        }
        L3->Insertar_final(D);
        
    } while (p != L1->Punta || q != Punta);
    L1->MOSTRAR();
    MOSTRAR();
    cout << "\n\tLista 3 :" << endl;
    L3->MOSTRAR();

    delete L3;


        system("pause");
}
