/*
Se tiene un vector de Reservas de hotel para el verano 2025, que contiene todas las habitaciones de un hotel con los siguientes campos:
     - Número de Habitación
     - Cantidad de camas
     - Cantidad de días disponibles en la temporada.

Además, se cuenta con una lista ordenada que contiene las últimas reservas realizadas, cada nodo de la lista contiene el Número de habitación,
cantidad de camas y la cantidad de días.

Se pide, actualizar el vector Reservas con la información que hay en la lista. Ej: Si en la lista la habitación 1 tiene 2 días reservados y 4 camas,
se deben restar en el campo correspondientes del vector. Se sabe que cómo Máximo hay 700 habitaciones.
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

struct Reserva
{
    int numHabitacion;
    int cantCamas;
    int cantDiasDisp;
};

struct Nodo
{
    Reserva info;
    Nodo *sgte;
};

void actualizarInfo(Reserva reserva[], int len, Nodo *LOReservas);

int main()
{
    Reserva reserva[700];
    int len;

    Nodo *LOReservas;

    actualizarInfo(reserva, len, LOReservas);

    return 0;
}

void actualizarInfo(Reserva reserva[], int len, Nodo *LOReservas)
{
    Nodo *aux;

    aux = LOReservas;
    while (aux != NULL)
    {
        int pos = buscar(reserva, len, aux->info.numHabitacion);
        if (pos != -1)
        {
            reserva[pos].cantDiasDisp = (reserva[pos].cantDiasDisp) - (aux->info.cantDiasDisp);
        }
        aux = aux->sgte;
    }
}