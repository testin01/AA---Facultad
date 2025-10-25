/*
 1) Desarrolle los siguientes SUBPROGRAMAS:
    a) Un procedimiento que genere una lista ORDENADA a partir de la unión de 2 colas.
    b) Una función que retorne una lista ordenada a partir de la intersección de 2 listas.
 Defina usted las estructuras que considere más conveniente y detallar.

 2) Se tiene un K1151tor de los alumnos del curso K1151, que contiene todos los alumnos que se
 inscribieron en la materia con los siguientes campos: Numero de legajo, Nota del Primer Parcial
 y Nota del Segundo Parcial. Además, se cuenta con una lista ordenada que contiene las notas de
 los que rindieron recuperatorio del SEGUNDO PARCIAL; cada nodo de la lista contiene el Numero de
 legajo y la nota del recuperatorio.
 Se pide actualizar el K1151tor K1151 con la información que hay en la lista, SOLO para el campo
 'Nota Segundo Parcial' si es que aprobó el recuperatorio, sino no hacer nada.
 Se sabe que cómo máximo hay 50 alumnos.

 3) Se tiene un archivo de resultados electorales sumarizado llamado PASO.dat (Sin orden).
    - ID del partido político
    - Nro de lista
    - ID de la provincia
    - Votos obtenidos
 Se pide:
    a) Ordenar el archivo Elecciones.DAT por ID del Partido
    b) Armar una lista ordenada por Votos Obtenidos, si los votos obtenidos superaron los 150.000
    e imprimir la lista por pantalla.
*/

#include <iostream>
#include <stdio.h>
#include "principal.hpp"
using namespace std;

/*
struct Nodo
{
    int info;
    Nodo *sgte;
};
*/

/* EJERCICIO 2 */
struct Alumno
{
    int legajo;
    int nota1parcial;
    int nota2parcial;
};

struct RAlumno
{
    int legajo;
    int nota2parcial;
};

struct NodoAlumno
{
    RAlumno info;
    NodoAlumno *sgte;
};

struct PartidoPolitico
{
    int idPartido;
    int nroLista;
    int idProvincia;
    int votosObtenidos;
};

int main()
{
    /* EJERCICIO 2) */
    Alumno K1151[50];
    int len;
    NodoAlumno *ListaAlumnos;
    NodoAlumno *auxAlumnos = ListaAlumnos;

    int pos;

    while (auxAlumnos != NULL)
    {
        if (auxAlumnos->info.nota2parcial >= 6)
        {
            pos = buscar(K1151, len, auxAlumnos->info.legajo);
            K1151[pos].nota2parcial = auxAlumnos->info.nota2parcial;
        }
        auxAlumnos = auxAlumnos->sgte;
    }

    mostrarVector(K1151, len);
    liberar(ListaAlumnos);

    /* EJERCICIO 3) */
    FILE *PASO;
    PASO = fopen("PASO.dat", "rb");

    Nodo *ListaParaOrdenar = NULL;
    Nodo *ListaOrdenada = NULL;

    PartidoPolitico raux;
    fread(&raux, sizeof(PartidoPolitico), 1, PASO);

    while (!feof(PASO))
    {
        insertarOrdenado(ListaParaOrdenar, raux);

        if (raux.votosObtenidos > 150000)
        {
            insertarOrdenado(ListaOrdenada, raux);
        }
        fread(&raux, sizeof(PartidoPolitico), 1, PASO);
    }
    fclose(PASO);

    FILE *Elecciones = fopen("Elecciones.dat", "wb");

    Nodo *aux = ListaParaOrdenar;

    while (aux != NULL)
    {
        fwrite(&aux->info, sizeof(PartidoPolitico), 1, Elecciones);
        aux = aux->sgte;
    }

    mostrar(ListaOrdenada);
    liberar(ListaOrdenada);
    liberar(ListaParaOrdenar);
    return 0;
}

/* EJERCICIO 1)a) */
void generarListaOrdenada(Nodo *cfteA, Nodo *cfinA, Nodo *cfteB, Nodo *cfinB)
{
    Nodo *ListaOrdenada = NULL;
    int rdo;

    while (cfteA != NULL && cfteB != NULL)
    {
        rdo = suprimir(cfteA, cfinA);
        insertarOrdenado(ListaOrdenada, rdo);
        rdo = suprimir(cfteB, cfinB);
        insertarOrdenado(ListaOrdenada, rdo);
    }
    while (cfteA != NULL)
    {
        rdo = suprimir(cfteA, cfinA);
        insertarOrdenado(ListaOrdenada, rdo);
    }
    while (cfteB != NULL)
    {
        rdo = suprimir(cfteB, cfinB);
        insertarOrdenado(ListaOrdenada, rdo);
    }

    mostrar(ListaOrdenada);
    liberar(ListaOrdenada);
}

/* EJERCICIO 1)b) */
Nodo *generarListaOrdenadaB(Nodo *ListaA, Nodo *ListaB)
{
    Nodo *ret = NULL;
    Nodo *auxAlumnosA = ListaA;
    Nodo *aBuscar = NULL;

    while (auxAlumnosA != NULL)
    {
        aBuscar = buscar(ListaB, auxAlumnosA->info);
        if (aBuscar != NULL)
        {
            insertarOrdenado(ret, auxAlumnosA->info);
        }
        auxAlumnosA = auxAlumnosA->sgte;
    }
    return ret;
}