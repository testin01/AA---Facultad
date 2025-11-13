#include <iostream>
#include <stdio.h>
#include "principal.hpp"
using namespace std;

int main()
{

    return 0;
}

/* Dados 2 vectores de enteros (A[10], B[10]) genere la UNION de ambos en C[20] */
void unirVectores(int A[], int lenA, int B[], int lenB)
{
    int C[20];
    int lenC = 0;

    inicializarVector(C, 20, 0);

    for (int i = 0; i < lenA; i++)
    {
        insertar(C, lenC, A[i], i);
    }
    mostrarVector(C, lenC);
    for (int i = 0; i < lenB; i++)
    {
        insertar(C, lenC, B[i], i + lenA);
    }
    cout << "Vector terminado: " << endl;
    mostrarVector(C, lenC);
}

/* Dadas 2 Colas de enteros (Cola A y Cola B) genere la UNION de ambas en Cola C. */
void unirColas(Nodo *cfteA, Nodo *cfteB, Nodo *cfinA, Nodo *cfinB)
{
    Nodo *cfteC = NULL;
    Nodo *cfinC = NULL;

    int rdo = 0;
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
}

/* Dadas 2 Pilas de enteros (Pila A y Pila B) genere la UNION de ambas en Pila C. */
void unirPilas(Nodo *pilaA, Nodo *pilaB)
{
    Nodo *pilaC = NULL;

    int rdo = 0;

    while (pilaA != NULL && pilaB != NULL)
    {
        rdo = pop(pilaA);
        push(pilaC, rdo);
        rdo = pop(pilaB);
        push(pilaC, rdo);
    }
    while (pilaA != NULL)
    {
        rdo = pop(pilaA);
        push(pilaC, rdo);
    }
    while (pilaB != NULL)
    {
        rdo = pop(pilaB);
        push(pilaB, rdo);
    }
}

/* Dadas 2 Listas de enteros (Lista A y Lista B) genere la UNION de ambas en Lista C. */
void unirListas(Nodo *ListaA, Nodo *ListaB)
{
    Nodo *auxA = ListaA;
    Nodo *auxB = ListaB;
    Nodo *ListaC = NULL;

    int rdo = 0;
    while (auxA != NULL && auxB != NULL)
    {
        insertarOrdenado(ListaC, auxA->info);
        auxA = auxA->sgte;
        insertarOrdenado(ListaC, auxB->info);
        auxB = auxB->sgte;
    }
    while (auxA != NULL)
    {
        insertarOrdenado(ListaC, auxA->info);
        auxA = auxA->sgte;
    }
    while (auxB != NULL)
    {
        insertarOrdenado(ListaC, auxB->info);
        auxB = auxB->sgte;
    }
}

/* Desarrolle una función que retorne una lista ordenada a partir la INTERSECCION de 2 Listas. */
Nodo *generarListaOrdenada(Nodo *ListaA, Nodo *ListaB)
{
    Nodo *auxA = ListaA;
    Nodo *auxB = ListaB;
    Nodo *ListaOrdenada = NULL;

    Nodo *nAux = NULL;
    while (auxA != NULL)
    {
        nAux = buscar(ListaB, auxA->info);
        if (nAux != NULL)
        {
            insertarOrdenado(ListaOrdenada, nAux->info);
        }
        auxA = auxA->sgte;
    }

    return ListaOrdenada;
}

/* Desarrolle una función que retorne una lista ordenada a partir la INTERSECCION de una Lista y una Pila */
Nodo *generarListaOrdenadaB(Nodo *Lista, Nodo *Pila)
{
    Nodo *ListaOrdenada = NULL;

    int rdo = 0;
    while (Pila != NULL)
    {
        rdo = pop(Pila);
        if (buscar(Lista, rdo) != NULL)
        {
            insertarOrdenado(ListaOrdenada, rdo);
        }
    }

    return ListaOrdenada;
}