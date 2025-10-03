/*
4) Se tiene un vector de los Productos de un almacén, STOCK, que contiene todos los Productos que se tienen disponibles a la venta, con los siguientes campos:
ID del Producto, Tipo (‘S’ semilla, ‘E’ envasado y ‘A’ aceite) y Unidades en el almacén.
Además, se cuenta con una lista ordenada que contiene los últimos pedidos al almacén que deben ser entregados a los clientes finales.

Se pide, actualizar el vector STOCK con la información que hay en la lista, SOLO para el campo Unidades.

Se sabe que cómo Máximo hay 50 Productos
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

struct Producto
{
    int ID_info;
    char TYPE_info;
    int uAlmacen;
};

struct Nodo
{
    Producto info;
    Nodo *sgte;
};

int main()
{
    Producto STOCK[50];
    int len;
    Nodo *Lista;

    Nodo *aux = Lista;
    Producto aux2;

    while (aux != NULL)
    {
        int pos = buscar(STOCK, len, aux->info.ID_info);

        if (pos != -1)
        {
            /*  aux2.ID_info = aux->info.ID_info;
                aux2.TYPE_info = aux->info.TYPE_info;
                au2.uAlmacen = STOCK[pos].uAlmacen - aux->info.uAlmacen;

                eliminar(STOCK, len, pos);
                insertarOrdenado(STOCK, len, aux2); */
            STOCK[pos].uAlmacen = STOCK[pos].uAlmacen - aux->info.uAlmacen;
        }

        aux = aux->sgte;
    }

    liberar(Lista);
    return 0;
}