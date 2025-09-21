/*
1)      Crear una Pila y una cola con los valores ingresados por el usuario.
a.      Incluir todos los elementos de ambas estructuras en una lista.
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

void generarLista(Nodo *cfte, Nodo *cfin, Nodo *pila);

int main()
{
    Nodo *pila = NULL;
    Nodo *cfte = NULL;
    Nodo *cfin = NULL;

    // Carga de pila
    int cargaPila;
    cout << "Ingrese un valor para la pila (0 para terminar)" << endl;
    cin >> cargaPila;
    while (cargaPila != 0)
    {
        push(pila, cargaPila);
        cout << "Ingrese un valor para la pila (0 para terminar)" << endl;
        cin >> cargaPila;
    }

    // Carga de cola
    int cargaCola;
    cout << "Ingrese un valor para la cola (0 para terminar)" << endl;
    cin >> cargaCola;
    while (cargaCola != 0)
    {
        agregar(cfte, cfin, cargaCola);
        cout << "Ingrese un valor para la cola (0 para terminar)" << endl;
        cin >> cargaCola;
    }

    generarLista(cfte, cfin, pila);
    return 0;
}

void generarLista(Nodo *cfte, Nodo *cfin, Nodo *pila)
{
    Nodo *Lista = NULL;
    int rdo = 0;
    while (pila != NULL && cfte != NULL)
    {
        rdo = pop(pila);
        agregarNodo(Lista, rdo);
        rdo = suprimir(cfte, cfin);
        agregarNodo(Lista, rdo);
    }
    while (pila != NULL)
    {
        rdo = pop(pila);
        agregarNodo(Lista, rdo);
    }
    while (cfte != NULL)
    {
        rdo = suprimir(cfte, cfin);
        agregarNodo(Lista, rdo);
    }

    mostrar(Lista);
    liberar(Lista);
}