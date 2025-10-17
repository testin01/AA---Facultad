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

3) Se tiene un archivo de productos STOCK.dat (sin orden)
    - Codigo de producto: 99999
    - Peso: 9999 kg
    - Tipo: 'P' o 'N' (Perecedero o No perecedero)
    - Cantidad en stock: 9999999

Se pide:
    a) Ordenar el archivo STOCK.dat por código de producto
    b) Generar dos listas y mostrarlas por pantalla
        I. La primera con los productos que no tienen unidades en stock
        II. La segunda con los productos Pesados (mayor a 100 kg.) y No perecederos.
*/

#include <iostream>
#include <stdio.h>
#include "principal.hpp"
using namespace std;

/* EJERCICIO 2) */
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

/* EJERCICIO 3) */
struct Producto
{
    int COD_PROD;
    int WEIGHT;
    char TYPE_PROD; // 'P' o 'N'
    int STOCK;
};

void actualizarMatriculas(Matricula vec[], int len, Nodo2 *Lista);

int main()
{
    /* Ejercicio 2) */
    Matricula vec[30];
    int len;
    Nodo *Lista;

    actualizarMatriculas(vec, len, Lista);

    /* Ejercicio 3) */
    FILE *Productos;
    Productos = fopen("STOCK.dat", "rb");
    Nodo *Lista2 = NULL;
    Nodo *ListaSinStock = NULL;
    Nodo *ListaPesados = NULL;

    Producto raux;
    fread(&raux, sizeof(Producto), 1, Productos);

    while (!feof(Productos))
    {
        insertarOrdenado(Lista2, raux);
        if (raux.STOCK == 0)
        {
            agregarNodo(ListaSinStock, raux);
        }
        if (raux.WEIGHT > 100 && raux.TYPE_PROD == 'N')
        {
            agregarNodo(ListaPesados, raux);
        }
        fread(&raux, sizeof(Producto), 1, Productos);
    }
    fclose(Productos);

    Nodo *aux = Lista2;
    Productos = fopen("STOCK.dat", "wb");
    while (aux != NULL)
    {
        fwrite(&aux->info, sizeof(Producto), 1, Productos);
        aux = aux->sgte;
    }

    fclose(Productos);
    liberar(Lista2);
    liberar(ListaSinStock);
    liberar(ListaPesados);
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
