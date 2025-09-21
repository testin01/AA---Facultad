/*
1) Crear una lista con los valores ingresados por el usuario que finaliza con un valor 0.
    a.Crear una nueva lista solo con los impares.
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

void crearImpares(Nodo *Lista);

int main()
{
    Nodo *Lista = NULL;
    int carga;

    cout << "Ingrese valores, finalice con 0 " << endl;
    cin >> carga;

    while (carga != 0)
    {
        agregarPrimero(Lista, carga);
        cout << "Ingrese valores, finalice con 0 " << endl;
        cin >> carga;
    }

    crearImpares(Lista);

    liberar(Lista);
    return 0;
}

void crearImpares(Nodo *Lista)
{
    Nodo *ListaImpar = NULL;
    Nodo *aux = NULL;

    aux = Lista;
    while (aux != NULL)
    {
        if (aux->info % 2 != 0)
        {
            agregarNodo(ListaImpar, aux->info);
        }
        aux = aux->sgte;
    }

    cout << "LISTA IMPAR" << endl;
    mostrar(ListaImpar);
    liberar(ListaImpar);
}