// Vamos a crear una lista y insertar un dato al inicio de la lista , mostrar la lista .
//
#include <iostream>
#include <stdlib.h>
#include "Lista.h"
using namespace std;

void Menu()
{
    cout << "\n\t (MENU)Lista Doblemente Ligada Circular" << endl;
    cout << "\n1. Insertar al inicio. " << endl;
    cout << "\n2. Insertar al final." << endl;
    cout << "\n3. Mostrar Lista por la Derecha" << endl;
    cout << "\n4. Mostrar Lista por la Izquierda" << endl;
    cout << "\n5. Insertar al ordenado" << endl;
    cout << "\n6. Ordenar" << endl;
    cout << "\n7. Buscar un dato" << endl;
    cout << "\n8. Reemplazar un dato por otro de la Lista" << endl;
    cout << "\n9. Eliminar un dato de la Lista (solo un Nodo) " << endl;
    cout << "\n10. Insertar en L2 " << endl;
    cout << "\n11. Sumar L1 y L2 = L3" << endl;
    cout << "\n12. Salir" << endl;
    cout << "\nIngrese una opcion:" << endl;
}

int main()                                      //funcion principal
{
    int opc = 0, dato1 = 0 , dato2 = 0;
    //instancia
    Lista *L1 = new Lista();
    Lista* L2 = new Lista();
    
    do
    {
        Menu(); cin >> opc;    
        system("cls");        
        switch (opc)
        {
            case 1: cout << "\nIngrese el numero : " << endl;
                    cin >> dato1;
                    L1->Insertar_inicio(dato1);                             // Insertar al INICIO
                break;
            case 2: cout << "\nIngrese el numero : " << endl;
                    cin >> dato1;
                    L1->Insertar_final(dato1);                                   // Insertar al FINAL
                break;
            case 3: if (L1->Punta == nullptr)                                   // si no se han ingresado datos la punta seria == a null por lo tanto no habria lista aun
                    {
                        cout << "La lista esta vacia : " << endl;
                        system("pause");
                    }
                          else
                    {
                        L1->MOSTRAR();                                          //MOSTRAR la lista derecha
                    }
                break;
            case 4: if (L1->Punta == nullptr)                                   // si no se han ingresado datos la punta seria == a null por lo tanto no habria lista aun
                    {
                        cout << "La lista esta vacia : " << endl;
                        system("pause");
                    }
                    else
                    {
                        L1->MOSTRARIzq();                               //MOSTRAR la lista izquierda
                    }                 
                break;
            case 5: cout << "\nIngrese el numero : " << endl;
                    cin >> dato1;
                    L1->INSERTAR_ORDENADO(dato1);                                // Insertar ORDENADO
                break;
            case 6: if (L1->Punta == nullptr)                                   // si no se han ingresado datos la punta seria == a null por lo tanto no habria lista aun
                    {
                        cout << "La lista esta vacia : " << endl;
                        system("pause");
                    }
                    else
                    {
                        L1->ORDENAR();                                          //Aqui ordena la lista
                    }                                                           
                break;
            case 7: if (L1->Punta == nullptr)                                   // si no se han ingresado datos la punta seria == a null por lo tanto no habria lista aun
                    {
                        cout << "La lista esta vacia : " << endl;
                        system("pause");
                     }
                     else
                     {
                        cout << "\nIngrese el numero : " << endl;
                        cin >> dato1;
                        L1->BUSCAR(dato1);                                      // aqui entra a buscar un dato en la lista             
                     }                
                break;
            case 8:if (L1->Punta == nullptr)                                   // si no se han ingresado datos la punta seria == a null por lo tanto no habria lista aun
                    {
                        cout << "La lista esta vacia : " << endl;
                        system("pause");
                    }
                    else
                    {
                        cout << "\nIngrese el dato que quiere ingresar : " << endl;
                        cin >> dato1;
                        cout << "\nIngrese el dato a reemplazar : " << endl;
                        cin >> dato2;
                        L1->REMPLAZAR(dato1, dato2);                                //Aqui se reemplaza un dato de la lista por otro.
                    }
                break;
            case 9:if (L1->Punta == nullptr)                                            // si no se han ingresado datos la punta seria == a null por lo tanto no habria lista aun
                    {
                       cout << "La lista esta vacia : " << endl;
                       system("pause");
                    }
                    else
                    {
                       cout << "\nIngrese el dato que quiere Eliminar : " << endl;
                       cin >> dato1;
                       L1->ELIMINAR(dato1);                                                      // Aqui se elimina un dato de la lista
                    }
                break;
            case 10:cout << "\nIngrese el numero : " << endl;
                    cin >> dato1;
                    L2->Insertar_final(dato1);                    
                break;

            case 11: if (L1->Punta == nullptr && L2->Punta == nullptr)                                   // si no se han ingresado datos la punta seria == a null por lo tanto no habria lista aun
                    {
                        cout << "Las dos listas estan vacias  " << endl;
                        system("pause");
                    }
                    else
                    {
                       L2->SUMAR2LISTAS(L1);                                         //Sumar l1 y l2 = l3
                    }            
                break;
            case 12: 
                break;
            default:cout << "\nOpcion incorrecta" << endl;
                    system("pause");
                break;
        }
        system("cls");
    } while (opc != 12);
    cout << "\tGracias por utilizar el programa" << endl<<endl;
    system("pause");
    return EXIT_SUCCESS;
}




