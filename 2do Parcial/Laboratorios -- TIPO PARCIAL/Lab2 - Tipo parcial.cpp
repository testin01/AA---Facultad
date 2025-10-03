/*
2) Dadas una cola y una lista, generar una lista ordenada con la intersección de las 2 estructuras
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

void generarListaOrdenada(Nodo *Lista, Nodo *cfte, Nodo *cfin);

int main()
{
    Nodo *cfte;
    Nodo *cfin;
    Nodo *Lista;

    generarListaOrdenada(Lista, cfte, cfin);

    liberar(Lista);
    return 0;
}

void generarListaOrdenada(Nodo *Lista, Nodo *cfte, Nodo *cfin)
{
    Nodo *ListaOrdenada = NULL;
    int rdo;

    while (cfte != NULL)
    {
        rdo = suprimir(cfte, cfin);
        if (buscar(Lista, rdo) != NULL)
        {
            insertarOrdenado(ListaOrdenada, rdo);
        }
    }

    mostrar(ListaOrdenada);
    liberar(ListaOrdenada);
}