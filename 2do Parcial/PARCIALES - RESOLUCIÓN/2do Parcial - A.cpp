/*
1) Desarrolle los siguientes subprogramas:
    a) Una función que retorne una lista ORDENADA a partir de la UNIÓN de dos pilas y una cola
    b) Un procedimiento que genere una lista SIN ORDEN a partir de la INTERSECCIÓN de una pila y una lista.

2) Se tiene un vector de Matrículas para una escuela de la ciudad, para el 2024, que contiene un resumen de
matrículas abonadas, con los siguientes campos:
    - Código de curso
    - Cantidad de alumnos
    - Monto facturado
Además se cuenta con una lista ordenada que contiene las últimas reservas de matrículas, cada nodo de la lista
contiene:
    - Código del curso
    - Monto facturado
Se pide, actualizar el vector Matrículas con la información que hay en la lista. Por cada reserva, debe
actualizar la cantidad del monto facturado, como así incrementar 1 la cantidad de alumnos. Se sabe que cómo
maximo hay 30 cursos.
*/

#include <iostream>
#include <stdio.h>
#include "principal.hpp"
using namespace std;

struct Matricula
{
    int COD_COURSE;
    int ALUMN_QUANT;
    int PRICE;
};

struct RMatricula
{
    int COD_COURSE;
    int PRICE;
};

struct Nodo2
{
    RMatricula info;
    Nodo2 *sgte;
};

void actualizarMatriculas(Matricula vec[], int len, Nodo2 *Lista);

int main()
{
    Matricula vec[30];
    int len;
    Nodo2 *Lista;

    actualizarMatriculas(vec, len, Lista);

    return 0;
}

/* EJERCICIO 1)A) */
Nodo *generarListaOrdenada(Nodo *pila1, Nodo *pila2, Nodo *cfte, Nodo *cfin)
{
    Nodo *listaOrdenada = NULL;
    int rdo;

    while (pila1 != NULL && pila2 != NULL && cfte != NULL)
    {
        rdo = pop(pila1);
        insertarOrdenado(listaOrdenada, rdo);
        rdo = pop(pila2);
        insertarOrdenado(listaOrdenada, rdo);
        rdo = suprimir(cfte, cfin);
        insertarOrdenado(listaOrdenada, rdo);
    }

    while (pila1 != NULL)
    {
        rdo = pop(pila1);
        insertarOrdenado(listaOrdenada, rdo);
    }

    while (pila2 != NULL)
    {
        rdo = pop(pila2);
        insertarOrdenado(listaOrdenada, rdo);
    }

    while (cfte != NULL)
    {
        rdo = suprimir(cfte, cfin);
        insertarOrdenado(listaOrdenada, rdo);
    }

    return listaOrdenada;
}

/* EJERCICIO 1)B) */
void generarLista(Nodo *Lista, Nodo *pila)
{
    Nodo *listaDesordenada = NULL;
    int rdo;

    while (pila != NULL)
    {
        rdo = pop(pila);
        if (buscar(Lista, rdo) != NULL)
        {
            agregarNodo(listaDesordenada, rdo);
        }
    }

    mostrar(listaDesordenada);
    liberar(listaDesordenada);
}

/* EJERCICIO 2) */
void actualizarMatriculas(Matricula vec[], int len, Nodo2 *Lista)
{
    Nodo2 *aux;
    aux = Lista;
    int pos = -1;
    while (aux != NULL)
    {
        pos = buscar(vec, len, aux->info.COD_COURSE);
        if (pos != -1)
        {
            vec[pos].ALUMN_QUANT++;
            vec[pos].PRICE += aux->info.PRICE;
        }
    }
}