/*
1) Dadas 1 pila y una cola se pide la union de los elementos de las 2 estructuras en una lista ordenada.
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

void generarLista(Nodo *pila, Nodo *cfte, Nodo *cfin);

int main()
{
    Nodo *pila;
    Nodo *cfte;
    Nodo *cfin;

    generarLista(pila, cfte, cfin);

    return 0;
}

void generarLista(Nodo *pila, Nodo *cfte, Nodo *cfin)
{
    Nodo *Lista = NULL;
    int rdo = 0;

    while (pila != NULL && cfte != NULL)
    {
        rdo = pop(pila);
        insertarOrdenado(Lista, rdo);
        rdo = suprimir(cfte, cfin);
        insertarOrdenado(Lista, rdo);
    }
    while (pila != NULL)
    {
        rdo = pop(pila);
        insertarOrdenado(Lista, rdo);
    }
    while (cfte != NULL)
    {
        rdo = suprimir(cfte, cfin);
        insertarOrdenado(Lista, rdo);
    }

    mostrar(Lista);
    liberar(Lista);
}