/*
1)      Crear una cola con los valores ingresados por el usuario que terminan con un 0.
a.      Mostrar por pantalla la cola, pero agregando la posición de cada elemento que muestra.
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
    Nodo *colafte = NULL;
    Nodo *colafin = NULL;

    int carga;
    cout << "Ingrese un valor, finalice con 0" << endl;
    cin >> carga;

    while (carga != 0)
    {
        agregar(colafte, colafin, carga);
        cout << "Ingrese un valor, finalice con 0" << endl;
        cin >> carga;
    }

    int aux, acum = 1;
    while (colafte != NULL)
    {
        aux = suprimir(colafte, colafin);
        cout << "El valor de la posición [" << acum << "] es " << aux << endl;
        acum++;
    }
    return 0;
}