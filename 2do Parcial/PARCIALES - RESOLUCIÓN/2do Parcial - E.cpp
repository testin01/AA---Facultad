/*
 1) Desarrolle un procedimiento que dado 1 cola y 1 lista, genere una lista ordenada con la
 INTERSECCIÓN de ambas
 2) Desarrolle una función que retorne una lista ordenada a partir de la INTERSECCIÓN de una
 Lista y una Pila. Nota: defina la estructura que le resulte conveniente e indique.

 EJERCICIO 3 Y 4 REALIZADOS EN 2do Parcial - C.cpp y 2do Parcial - D.cpp
*/

#include <iostream>
#include <stdio.h>
#include "principal.hpp"
using namespace std;

int main()
{

    return 0;
}

/* EJERCICIO 1) */
void generarListaOrdenada(Nodo *cfte, Nodo *cfin, Nodo *Lista)
{
    Nodo *ListaOrdenada = NULL;

    int rdo = 0;

    while (cfte != NULL)
    {
        rdo = suprimir(cfte, cfin);
        if (buscar(Lista, rdo) != NULL)
        {
            insertarOrdenado(ListaOrdenada, rdo);
        }
    }
}

/* EJERCICIO 2) */
Nodo *generarListaOrdenadaV2(Nodo *Lista, Nodo *pila)
{
    Nodo *ListaOrdenada = NULL;
    int rdo = 0;

    while (pila != NULL)
    {
        rdo = pop(pila);
        if (buscar(Lista, rdo) != NULL)
        {
            insertarOrdenado(ListaOrdenada, rdo);
        }
    }
    return ListaOrdenada;
}