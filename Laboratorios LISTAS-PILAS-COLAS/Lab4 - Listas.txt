/*
1) Crear 2 listas con valores ingresados por el usuario y que finaliza con 0.
    a. Dadas esas dos listas de enteros, crear una nueva lista intercalando los elementos de ambas.
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

void generarTercerLista(Nodo *Lista1, Nodo *Lista2);

int main()
{
    Nodo *Lista1 = NULL;
    Nodo *Lista2 = NULL;
    int carga;

    cout << "Ingrese un valor, finalice con 0" << endl;
    cin >> carga;

    while (carga != 0)
    {
        agregarNodo(Lista1, carga);
        cout << "Ingrese un valor, finalice con 0" << endl;
        cin >> carga;
    }

    cout << "Ingrese un valor para la segunda lista, finalice con 0" << endl;
    cin >> carga;

    while (carga != 0)
    {
        agregarNodo(Lista2, carga);
        cout << "Ingrese un valor para la segunda lista, finalice con 0" << endl;
        cin >> carga;
    }

    generarTercerLista(Lista1, Lista2);

    liberar(Lista1);
    liberar(Lista2);
    return 0;
}

void generarTercerLista(Nodo *Lista1, Nodo *Lista2)
{
    Nodo *aux1 = NULL;
    Nodo *aux2 = NULL;
    Nodo *Lista3 = NULL;
    aux1 = Lista1;
    aux2 = Lista2;

    while (aux1 != NULL && aux2 != NULL)
    {
        agregarNodo(Lista3, aux1->info);
        agregarNodo(Lista3, aux2->info);
        aux1 = aux1->sgte;
        aux2 = aux2->sgte;
    }
    while (aux1 != NULL)
    {
        agregarNodo(Lista3, aux1->info);
        aux1 = aux1->sgte;
    }
    while (aux2 != NULL)
    {
        agregarNodo(Lista3, aux2->info);
        aux2 = aux2->sgte;
    }

    cout << "LISTA 3" << endl;
    mostrar(Lista3);

    liberar(Lista3);
}