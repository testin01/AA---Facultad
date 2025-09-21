/*
1) Crear una lista con los valores ingresados por el usuario que finaliza con un valor negativo.
    a. Sumar todos los elementos de una lista.
    b. Buscar un número en la lista, dicho número será indicado por el usuario. Pedir al usuario un número y decir si está en la lista o no.
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

int sumarizar(Nodo *Lista);
void estaEnLista(Nodo *Lista);

int main()
{
    Nodo *Lista = NULL;
    int carga;

    cout << "Ingrese un valor, finaliza con negativos: " << endl;
    cin >> carga;

    while (carga >= 0)
    {
        agregarPrimero(Lista, carga);
        cout << "Ingrese un valor, finaliza con negativos: " << endl;
        cin >> carga;
    }

    int sumarizado = sumarizar(Lista); // Sumarizo los valores de la lista
    cout << "La lista sumarizada vale " << sumarizado << endl;

    estaEnLista(Lista); // Busco y comunico

    liberar(Lista);
    return 0;
}

int sumarizar(Nodo *Lista)
{
    int sum = 0;
    Nodo *aux = Lista;
    while (aux->sgte != NULL)
    {
        sum += aux->info;
        aux = aux->sgte;
    }

    liberar(aux);
    return sum;
}

void estaEnLista(Nodo *Lista)
{
    int valor = 0;
    cout << "Ingrese un valor a buscar en la lista" << endl;
    cin >> valor;
    if (buscar(Lista, valor) != NULL)
    {
        cout << "El valor " << valor << " se encuentra en la lista" << endl;
    }
    else
    {
        cout << "El valor " << valor << " no se encuentra en la lista" << endl;
    }
}