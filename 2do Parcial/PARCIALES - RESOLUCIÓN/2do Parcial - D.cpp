/*
 1) Desarrolle un procedimiento que dado 2 pilas, genere una lista sin orden con la UNION de ambas. Definir la
 estructura del Nodo e indicar.
 2) Desarrolle una función que retorne una lista ordenada a partir de la UNION de 2 Listas.
 3) Se tiene un vector de Resumen de las reservas de pre-viaje para el verano 2023 en la costa Argentina, que
 contiene el código de la ciudad costera, cantidad de reservas hechas en todos los alojamientos y visitantes.
 Además, se cuenta con una lista ordenada que contiene las últimas cargas realizadas, cada nodo de la lista
 contiene (puede haber varios nodos por cada ciudad, ya que 1 nodo implica 1 reserva):
    - Código de la ciudad
    - Cantidad de visitantes
 Se pide, actualizar el vector Pre-viaje con la información que hay en la lista.
 Importante: Si en la lista hay una reserva para la ciudad '123', hay que actualizar el campo cantidad de
 visitantes e incrementar en 1 la reserva.
 Se sabe que cómo MAXIMO hay 20 ciudades.
 4) Se tiene un archivo de disponibilidad para las cabañas en la costa Verano023.dat (sin orden):
    - ID del complejo
    - Tipo: 'F','S' o 'M'
    - Habitaciones disponibles
    - Precio por día de la cabaña
 Se pide:
    a) Ordenar el archivo Verano2023.dat por número de habitación
    b) Armar una lista, ordenada por ID de la cabaña, y mostrarla por pantalla si el número de habitaciones
    disponibles es mayor a 50 y son 'F' o 'M'

*/

#include <iostream>
#include <stdio.h>
#include "principal.hpp"
using namespace std;

/* struct Nodo
{
    int info;
    Nodo *sgte;
}; */

/* EJERCICIO 3) */
struct Reserva
{
    int COD_CIUDAD;
    int CANT_RESERVAS;
    int CANT_VISITANTES;
};

struct NodoReserva
{
    int COD_CIUDAD;
    int CANT_VISITANTES;
    NodoReserva *sgte;
};

struct Cabana
{
    int ID_COMPLEJO;
    char TIPO;
    int HAB_DISPONIBLES;
    int PRECIO_NOCHE;
};

struct NodoCabana
{
    Cabana info;
    NodoCabana *sgte;
};

int main()
{
    /* EJERCICIO 3) */
    Reserva PreViaje[20];
    int len;
    NodoReserva *ListaOrdenada;

    NodoReserva *aux = ListaOrdenada;
    while (aux != NULL)
    {
        int pos = buscar(PreViaje, len, aux->COD_CIUDAD);
        if (pos != -1)
        {
            PreViaje[pos].CANT_VISITANTES += aux->CANT_VISITANTES;
            PreViaje[pos].CANT_RESERVAS++;
        }
        aux = aux->sgte;
    }
    mostrarVector(PreViaje, len);
    liberar(ListaOrdenada);

    /* EJERCICIO 4) */
    FILE *Reservas;
    Reservas = fopen("Verano2023.dat", "rb");
    NodoCabana *ListaParaOrdenar = NULL;
    NodoCabana *ListaOrdenadaXID = NULL;

    Cabana raux;
    fread(&raux, sizeof(Cabana), 1, Reservas);

    while (!feof(Reservas))
    {
        insertarOrdenado(ListaParaOrdenar, raux.ID_COMPLEJO);
        if (raux.HAB_DISPONIBLES > 50)
        {
            if (raux.TIPO == 'F' || raux.TIPO == 'M')
            {
                insertarOrdenado(ListaOrdenadaXID, raux.ID_COMPLEJO);
            }
        }
        fread(&raux, sizeof(Cabana), 1, Reservas);
    }

    fclose(Reservas);
    Reservas = fopen("Verano2023.dat", "wb");

    NodoCabana *auxCabana = ListaParaOrdenar;

    while (auxCabana != NULL)
    {
        fwrite(&auxCabana->info, sizeof(Cabana), 1, Reservas);
        auxCabana = auxCabana->sgte;
    }

    fclose(Reservas);
    liberar(ListaParaOrdenar);
    mostrar(ListaOrdenadaXID);
    liberar(ListaOrdenadaXID);

    return 0; 
}

void generarListaSinOrden(Nodo *pila1, Nodo *pila2)
{
    Nodo *ListaSinOrden = NULL;
    int rdo = 0;

    while (pila1 != NULL && pila2 != NULL)
    {
        rdo = pop(pila1);
        agregarNodo(ListaSinOrden, rdo);
        rdo = pop(pila2);
        agregarNodo(ListaSinOrden, rdo);
    }
    while (pila1 != NULL)
    {
        rdo = pop(pila1);
        agregarNodo(ListaSinOrden, rdo);
    }
    while (pila2 != NULL)
    {
        rdo = pop(pila2);
        agregarNodo(ListaSinOrden, rdo);
    }

    mostrar(ListaSinOrden);
    liberar(ListaSinOrden);
}

Nodo *generarListaOrdenada(Nodo *Lista1, Nodo *Lista2)
{
    Nodo *aux1 = Lista1;
    Nodo *aux2 = Lista2;
    Nodo *ListaOrdenada = NULL;

    while (aux1 != NULL && aux2 != NULL)
    {
        insertarOrdenado(ListaOrdenada, aux1->info);
        insertarOrdenado(ListaOrdenada, aux2->info);
        aux1 = aux1->sgte;
        aux2 = aux2->sgte;
    }
    while (aux1 != NULL)
    {
        insertarOrdenado(ListaOrdenada, aux1->info);
        aux1 = aux1->sgte;
    }
    while (aux2 != NULL)
    {
        insertarOrdenado(ListaOrdenada, aux2->info);
        aux2 = aux2->sgte;
    }

    return ListaOrdenada;
}