/*
1) Invertir una lista usando una pila.
    a. Pasar los elementos de una lista a una pila y luego mostrarlos invertidos
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

void pasarAPila(Nodo *Lista);

int main()
{
    Nodo *Lista = NULL;
    int carga;

    cout << "Ingrese valores, termina con 0" << endl;
    cin >> carga;

    while (carga != 0)
    {
        agregarNodo(Lista, carga);
        cout << "Ingrese valores, termina con 0" << endl;
        cin >> carga;
    }

    pasarAPila(Lista);

    liberar(Lista);
    return 0;
}

void pasarAPila(Nodo *Lista)
{
    Nodo *pila = NULL;
    Nodo *aux = NULL;
    int rdo;

    aux = Lista;
    while (aux != NULL)
    {
        push(pila, aux->info);
        aux = aux->sgte;
    }

    while (pila != NULL)
    {
        rdo = pop(pila);
        cout << "Valor: " << rdo << endl;
    }

    liberar(pila);
}