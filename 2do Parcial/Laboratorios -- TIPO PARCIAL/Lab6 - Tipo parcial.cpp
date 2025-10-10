/*
Desarrolle los siguientes Subprogramas:
a-       Una función que retorne una lista ordenada a partir de la Unión de una pila y una cola.
b-      Un procedimiento que genere una lista sin orden a partir de la INTERSECCION de 2 listas.
Defina usted las estructuras de los nodos de la manera que considere más conveniente y detallar.
*/

#include <iostream>
#include <stdio.h>
#include "principal.hpp"
using namespace std;

/* void agregarPrimero(Nodo *&Lista, int valor);
void agregarNodo(Nodo *&Lista, int valor); // Agregar al final
void mostrar(Nodo *Lista);
void liberar(Nodo *&Lista);
Nodo *buscar(Nodo *Lista, int valor);
int eliminarPrimerNodo(Nodo *&Lista);
void insertarOrdenado(Nodo *&Lista, int valor); */

int main()
{

    return 0;
}

/* struct Nodo
{
    int info;
    Nodo *sgte;
}; */

Nodo generarListaOrdenada(Nodo *pila, Nodo *cfte, Nodo *cfin)
{
    Nodo *ListaOrdenada = NULL;
    int rdo;

    while (pila != NULL && cfte != NULL)
    {
        rdo = pop(pila);
        insertarOrdenado(ListaOrdenada, rdo);
        rdo = suprimir(cfte, cfin);
        insertarOrdenado(ListaOrdenada, rdo);
    }

    while (pila != NULL)
    {
        rdo = pop(pila);
        insertarOrdenado(ListaOrdenada, rdo);
    }

    while (cfte != NULL)
    {
        rdo = suprimir(cfte, cfin);
        insertarOrdenado(ListaOrdenada, rdo);
    }

    return *ListaOrdenada;
}

void generarLista(Nodo *Lista1, Nodo *Lista2)
{
    Nodo *Lista = NULL;
    Nodo *aux1;
    Nodo *aux2;

    aux1 = Lista1;
    aux2 = Lista2;

    while (aux1 != NULL && aux2 != NULL)
    {
        if (buscar(Lista2, aux1->info) != NULL)
        {
            agregarNodo(Lista, aux1->info);
        }

        aux1 = aux1->sgte;
    }

    mostrar(Lista);
    liberar(Lista);
}