/*
3) Se tiene un vector de los alumnos del curso K1151, que contiene todos los alumnos que se inscribieron al seminario de ingreso con los siguientes campos:
Numero de Legajo, Nota del Primer Parcial y Nota del Segundo Parcial.

Además, se cuenta con una lista ordenada que contiene las notas de los que rindieron recuperatorio del Segundo Parcial; cada nodo de la lista contiene el
Número de Legajo y la nota del recuperatorio.

Se pide, actualizar el vector K1151 con la información que hay en la lista, SOLO para el campo
Nota Segundo Parcial si es que aprobó el recuperatorio, sino no hacer nada.

Se sabe que cómo Máximo hay 50 alumnos
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

struct Alumno
{
    int legajo;
    int nota1P;
    int nota2P;
};

void buscarYActualizar(Nodo *Lista, Alumno vec[], int len);

int main()
{

    Nodo *Lista;
    Alumno vec[50];
    int len;

    buscarYActualizar(Lista, vec, len);

    liberar(Lista);
    return 0;
}

void buscarYActualizar(Nodo *Lista, Alumno vec[], int len)
{
    Nodo *aux = Lista;
    Alumno auxiliar;
    int legajoActualizar;
    while (aux != NULL)
    {
        if (aux->notaRecuperatorio >= 6)
        {
            legajoActualizar = aux->legajo;
            int pos = buscar(vec, len, legajoActualizar); // Buscamos legajo en vector
            if (pos != -1)
            {
                auxiliar.legajo = legajoActualizar;
                auxiliar.nota1P = vec[pos].nota1P;
                auxiliar.nota2P = aux->notaRecuperatorio; // cambio de nota

                eliminar(vec, len, pos);
                insertarOrdenado(vec, auxiliar);
            }
            aux = aux->sgte;
        }
    }
}