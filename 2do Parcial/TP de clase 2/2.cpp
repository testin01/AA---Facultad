#include <iostream>
#include <stdio.h>
#include "principal.hpp"
using namespace std;

int main()
{

    return 0;
}

/*
Desarrolle los siguientes PROCEDIMIENTOS y defina los parámetros:
    a- Dadas 2 Colas de enteros (Cola A y Cola B) genere la UNION de ambas en Cola C.
    b- Dadas 2 Pilas de enteros (Pila A y Pila B) genere la UNION de ambas en Pila C.
    c- Dadas 2 Listas de enteros (Lista A y Lista B) genere la UNION de ambas en Lista C.
*/

/* EJERCICIO A */
void unionColas(Nodo *cfteA, Nodo *cfinA, Nodo *cfteB, Nodo *cfinB)
{
    Nodo *cfteC = NULL;
    Nodo *cfinC = NULL;
    int rdo;
    while (cfteA != NULL && cfteB != NULL)
    {
        rdo = suprimir(cfteA, cfinA);
        agregar(cfteC, cfinC, rdo);
        rdo = suprimir(cfteB, cfinB);
        agregar(cfteC, cfinC, rdo);
    }
    while (cfteA != NULL)
    {
        rdo = suprimir(cfteA, cfinA);
        agregar(cfteC, cfinC, rdo);
    }
    while (cfteB != NULL)
    {
        rdo = suprimir(cfteB, cfinB);
        agregar(cfteC, cfinC, rdo);
    }

    int aux = 0;
    int acum = 1;
    while (cfteC != NULL)
    {
        aux = suprimir(cfteC, cfinC);
        cout << "El valor de la posición [" << acum << "] es " << aux << endl;
        acum++;
    }
}

/* EJERCICIO B */
void unirPilas(Nodo *pilaA, Nodo *pilaB)
{
    Nodo *pilaC = NULL;
    int rdo;
    while (pilaA != NULL && pilaB != NULL)
    {
        rdo = pop(pilaA);
        push(pilaA, rdo);
        rdo = pop(pilaB);
        push(pilaB, rdo);
    }
    while (pilaA != NULL)
    {
        rdo = pop(pilaA);
        push(pilaA, rdo);
    }
    while (pilaB != NULL)
    {
        rdo = pop(pilaB);
        push(pilaB, rdo);
    }

    int aux;
    while (pilaC != NULL)
    {
        aux = pop(pilaC);
        cout << aux << endl;
    }
}

/* EJERCICIO C */
void unirListas(Nodo *ListaA, Nodo *ListaB)
{
    Nodo *ListaC = NULL;
    Nodo *auxA = ListaA;
    Nodo *auxB = ListaB;

    while (auxA != NULL & auxB != NULL)
    {
        agregarNodo(ListaC, auxA->info);
        agregarNodo(ListaC, auxB->info);
        auxA = auxA->sgte;
        auxB = auxB->sgte;
    }
    while (auxA != NULL & auxB != NULL)
    {
        agregarNodo(ListaC, auxA->info);
        auxA = auxA->sgte;
    }
    while (auxA != NULL & auxB != NULL)
    {
        agregarNodo(ListaC, auxB->info);
        auxB = auxB->sgte;
    }

    mostrar(ListaC);
    liberar(ListaC);
}