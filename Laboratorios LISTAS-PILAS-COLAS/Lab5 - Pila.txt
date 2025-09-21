/*
    1) Invertir el orden de los elementos ingresados por el usuario, mostrando ese orden invertido usando la estructura más apropiada para la operación.
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
    Nodo *Pila = NULL;
    int carga;
    int nodo;

    cout << "Ingrese valores" << endl;
    cin >> carga;

    while (carga != 0)
    {
        push(Pila, carga);
        cout << "Ingrese valores" << endl;
        cin >> carga;
    }

    while (Pila != NULL)
    {
        nodo = pop(Pila);
        cout << nodo << endl;
    }

    return 0;
}
