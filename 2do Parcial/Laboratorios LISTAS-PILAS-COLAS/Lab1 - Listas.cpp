/*
1)Crear una lista de 5 números enteros ingresados por el usuario.
    a. Mostrar la lista completa.
    b. Mostrar el primer y último elemento.
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
    Nodo *Lista = NULL;
    Nodo *primero = NULL;
    Nodo *ultimo = NULL;
    int carga;

    for (int i = 0; i < 5; i++)
    {
        cout << "Ingrese 5 valores" << endl;
        cin >> carga;
        agregarPrimero(Lista, carga);
    }

    mostrar(Lista);
    ultimo = Lista;
    cout << "Primer nodo: " << Lista->info << endl;

    // Mostrar último elemento
    Nodo *aux = Lista;
    while (aux->sgte != NULL)
    {
        aux = aux->sgte; // Recorrido de la lista
    }
    cout << "Ultimo nodo: " << aux->info << endl;

    liberar(Lista);
    return 0;
}