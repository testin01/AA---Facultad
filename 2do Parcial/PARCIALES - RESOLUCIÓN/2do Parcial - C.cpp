/*
 1) Desarrolle una función que retone una lista ordenada a partir de la INTERSECCION de una Lista y una Cola.
 Nota: Defina la estructura que le resulte conveniente e indique.
 2) Desarrolle un procedimiento que dado 1 pila y 1 cola, genere una lista sin orden con la union de ambas.
 Definir la estructura del nodo e indicar.
 3) Se tiene un vector de Resumen de las carpas alquilada en MDP para el verano 2023, que contiene código del
 balneario, cantidad de días de la temporada reservados y cantidad de confirmaciones.
 Además, se cuenta con una lista ordenada que contiene los últmos pedidos realizados, cada nodo de la lista
 contiene:
    - Código del balneario.
    - Cantidad de días reservados.
 Se pide, actualizar el vector Carpas con la info que hay en la lista. Se sabe que cómo máximo hay 23 balnearios.
 4) Se tiene un archivo de resultados de la fase de grupo de la Copa UEFA Champions League, sumarizado llamado
 UEFA.dat (sin Orden).
    - ID del equipo
    - Cantidad de puntos obtenidos
    - Cantidad de partidos ganados
    - Cantidad de goles
 Se pide:
    a) Ordenar el archivo UEFA.dat por ID del equipo
    b) Armar una lista ordenada por Cantidad de Goles, si un equipo realizó mas de 10 e imprimir la lista por
    pantalla
 Nota: Solo puede leer una 1 vez el archivo.
*/

#include <iostream>
#include <stdio.h>
#include "principal.hpp"
using namespace std;

/* struct Nodo{
    int info;
    Nodo *sgte;
}; */

struct Carpa
{
    int COD_BALNEARIO;
    int CANT_DRESERVADOS;
    int CANT_RESERVAS;
};

struct Reserva
{
    int COD_BALNEARIO;
    int CANT_RESERVADOS;
};

struct NodoReservas
{
    Reserva info;
    NodoReservas *sgte;
};

struct Equipo
{
    int ID_EQUIPO;
    int CANT_PTOS;
    int CANT_PGANADOS;
    int CANT_GOLES;
};

struct NodoEquipos
{
    Equipo info;
    NodoEquipos *sgte;
};

int main()
{
    /* EJERCICIO 3) */
    Carpa carpas[23];
    int lenCarpas;
    NodoReservas *Lista;

    NodoReservas *aux = Lista;
    int pos = -1;
    while (aux != NULL)
    {
        pos = buscar(carpas, lenCarpas, aux->info.COD_BALNEARIO);
        if (pos != -1)
        {
            carpas[pos].CANT_DRESERVADOS += aux->info.CANT_RESERVADOS;
            carpas[pos].CANT_RESERVAS++;
        }
        aux = aux->sgte;
    }

    liberar(Lista);

    /* EJERCICIO 4) */
    FILE *UEFA;
    UEFA = fopen("UEFA.dat", "rb");
    NodoEquipos *ListaEquipos = NULL;
    NodoEquipos *ListaEquiposXGoles = NULL;

    Equipo raux;
    fread(&raux, sizeof(Equipo), 1, UEFA);

    while (!feof(UEFA))
    {
        insertarOrdenado(ListaEquipos, raux.ID_EQUIPO);
        if (raux.CANT_GOLES > 10)
        {
            insertarOrdenado(ListaEquiposXGoles, raux.CANT_GOLES);
        }
        fread(&raux, sizeof(Equipo), 1, UEFA);
    }

    fclose(UEFA);

    UEFA = fopen("UEFA.dat", "wb");
    NodoEquipos *auxEquipo = ListaEquipos;

    while (aux != NULL)
    {
        fwrite(&auxEquipo->info, sizeof(Equipo), 1, UEFA);
        aux = aux->sgte;
    }

    fclose(UEFA);
    liberar(ListaEquipos);
    mostrar(ListaEquiposXGoles);
    liberar(ListaEquiposXGoles);
    return 0;
}

/* EJERCICIO 1) */
Nodo *generarListaOrdenada(Nodo *Lista, Nodo *cfte, Nodo *cfin)
{
    Nodo *ListaOrdenada = NULL;
    int elementoABuscar = 0;
    while (cfte != NULL)
    {
        elementoABuscar = suprimir(cfte, cfin);
        if (buscar(Lista, elementoABuscar) != NULL)
        {
            insertarOrdenado(ListaOrdenada, elementoABuscar);
        }
    }
    return ListaOrdenada;
}

/* EJERCICIO 2) */
void generarListaSinOrden(Nodo *pila, Nodo *cfte, Nodo *cfin)
{
    Nodo *ListaSinOrden = NULL;
    int rdo = 0;

    while (pila != NULL && cfte != NULL)
    {
        rdo = pop(pila);
        agregarNodo(ListaSinOrden, rdo);
        rdo = suprimir(cfte, cfin);
        agregarNodo(ListaSinOrden, rdo);
    }
    while (pila != NULL)
    {
        rdo = pop(pila);
        agregarNodo(ListaSinOrden, rdo);
    }
    while (cfte != NULL)
    {
        rdo = suprimir(cfte, cfin);
        agregarNodo(ListaSinOrden, rdo);
    }

    mostrar(ListaSinOrden);
    liberar(ListaSinOrden);
}