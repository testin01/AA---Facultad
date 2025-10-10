/* Se tiene un archivo de disponibilidad para las Reserva de un hotel en la costa Verano2025.dat (sin Orden):
-          Número de Habitación: 999999
-          Régimen de comida: ‘s’, ‘m’ o ‘c’ (Sin pensión, media pensión o pensión completa)
-          Días disponibles de la temporada: 999
-          Precio por día de la habitación: 999 (entero)
Se pide:
a)       Ordenar el archivo Verano2025.DAT por número de habitación
b)      Armar una lista, ordenada por Número de habitación, y mostrarla por pantalla si el número de días disponibles es mayor a 90 y son ‘c’ ó ‘m’.
Nota: Sólo puede leer 1 vez el archivo.
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
    char regimenComida;
    int diasDisponibles;
    int precioXDia;
};

struct Nodo
{
    Reserva info;
    Nodo *sgte;
};

int main()
{
    FILE *Habitacion;
    Nodo *Lista = NULL;
    Nodo *ListaMasDe90 = NULL;

    Habitacion = fopen("Verano2025.dat", "rb");

    Reserva raux;
    fread(&raux, sizeof(Reserva), 1, Habitacion);

    while (!feof(Habitacion))
    {
        insertarOrdenado(Lista, raux);
        if (raux.diasDisponibles > 90)
        {
            if (raux.regimenComida == 'c' || raux.regimenComida == 'm')
            {
                insertarOrdenado(ListaMasDe90, raux);
            }
        }
        fread(&raux, sizeof(Reserva), 1, Habitacion);
    }

    fclose(Habitacion);
    mostrar(ListaMasDe90);

    Habitacion = fopen("Verano2025.dat", "wb");
    Nodo *aux = Lista;
    while (aux != NULL)
    {
        fwrite(&aux->info, sizeof(Reserva), 1, Habitacion);
        aux = aux->sgte;
    }

    fclose(Habitacion);
    liberar(Lista);
    liberar(ListaMasDe90);

    return 0;
}