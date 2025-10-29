/*
 1) Desarrolle los siguientes subprogramas:
    a) Una función que retorne una lista ORDENADA a partir de la UNIÓN de dos pilas y una cola.
    b) Un procedimiento que genere una lista SIN ORDEN a partir de la INTERSECCION de una pila y una lista.
 2) Se tiene un vector de Matriculas para una escuela de la ciudad, para el 2024, que contiene un resumen de
 matrículas abonadas, con los siguientes campos:
    - Código del curso
    - Cantidad de alumnos
    - Monto facturado
 Además, se cuenta con una lista ordenada que contiene las últimas reservas de matrículas, cada nodo de la
 lista contiene:
    - Código del curso
    - Monto facturado
 Se pide, actualizar el vector Metrículas con el vector que hay en la lista. Por cada reserva, debe actualizar
 la cantidad el monto facturado, como así incrementar en 1 la cantidad de alumnos. Se sabe que cómo máximo hay
 30 cursos.
 3) Se tiene un archivo de productos STOCK.dat (sin orden)
    - Código de producto
    - Peso
    - Tipo: 'P' o 'N'
    - Cantidad en stock
 Se pide:
    a) Ordenar el archivo STOCK.dat por código de producto.
    b) Generar dos listas y mostrarlas por pantalla:
        I. La primera con los productos que no tienen unidades en Stock.
        II. La segunda con los productos PESADOS (Peso > 100kg.) y No perecederos.
*/

#include <iostream>
#include <stdio.h>
#include "principal.hpp"
using namespace std;

struct Matriculas
{
    int COD_CURSO;
    int CANT_ALUM;
    int MONTO_FAC;
};

struct NodoMatricula
{
    int COD_CURSO;
    int MONTO_FAC;
    NodoMatricula *sgte;
};

struct Producto
{
    int COD_PROD;
    int PESO;
    char TYPE;
    int CANT_STOCK;
};

struct NodoProducto
{
    Producto info;
    NodoProducto *sgte;
};

int main()
{
    /* EJERCICIO 2) */
    Matriculas vec[30];
    int len;
    NodoMatricula *Lista;

    NodoMatricula *aux = Lista;
    int pos = -1;

    while (aux != NULL)
    {
        pos = buscar(vec, len, aux->COD_CURSO);
        if (pos != -1)
        {
            vec[pos].CANT_ALUM++;
            vec[pos].MONTO_FAC += aux->MONTO_FAC;
        }
    }
    liberar(Lista);

    /* EJERCICIO 3) */
    FILE *Stock;
    Stock = fopen("STOCK.dat", "rb");

    NodoProducto *ListaAOrdenar = NULL;
    NodoProducto *ListaSinStock = NULL;
    NodoProducto *ListaPesado = NULL;
    Producto raux;
    fread(&raux, sizeof(Producto), 1, Stock);

    while (!feof(Stock))
    {
        insertarOrdenado(ListaAOrdenar, raux);
        if (raux.CANT_STOCK == 0)
        {
            insertarOrdenado(ListaSinStock, raux);
        }
        if (raux.PESO > 100 && raux.TYPE == 'N')
        {
            insertarOrdenado(ListaPesado, raux);
        }
        fread(&raux, sizeof(Producto), 1, Stock);
    }

    fclose(Stock);
    mostrar(ListaPesado);
    mostrar(ListaSinStock);
    liberar(ListaPesado);
    liberar(ListaSinStock);

    Stock = fopen("STOCK.dat", "wb");
    NodoProducto *auxProd = ListaAOrdenar;

    while (auxProd != NULL)
    {
        fwrite(&auxProd->info, sizeof(Producto), 1, Stock);
        auxProd = auxProd->sgte;
    }

    fclose(Stock);
    liberar(ListaAOrdenar);
    return 0;
}

/* EJERCICIO 1)a) */
Nodo *generarListaOrdenada(Nodo *cfte, Nodo *cfin, Nodo *pila1, Nodo *pila2)
{
    int rdo = 0;
    Nodo *ListaOrdenada = NULL;

    while (cfte != NULL && pila1 != NULL && pila2 != NULL)
    {
        rdo = pop(pila1);
        insertarOrdenado(ListaOrdenada, rdo);
        rdo = pop(pila2);
        insertarOrdenado(ListaOrdenada, rdo);
        rdo = suprimir(cfte, cfin);
        insertarOrdenado(ListaOrdenada, rdo);
    }
    while (cfte != NULL)
    {
        rdo = suprimir(cfte, cfin);
        insertarOrdenado(ListaOrdenada, rdo);
    }
    while (pila1 != NULL)
    {
        rdo = pop(pila1);
        insertarOrdenado(ListaOrdenada, rdo);
    }
    while (pila2 != NULL)
    {
        rdo = pop(pila2);
        insertarOrdenado(ListaOrdenada, rdo);
    }

    return ListaOrdenada;
}

/* EJERCICIO 1)b) */
void generarLista(Nodo *Lista, Nodo *pila)
{
    Nodo *ListaSinOrden = NULL;
    int rdo = 0;

    while (pila != NULL)
    {
        rdo = pop(pila);
        if (buscar(Lista, rdo) != NULL)
        {
            agregarNodo(ListaSinOrden, rdo);
        }
    }
    mostrar(ListaSinOrden);
    liberar(ListaSinOrden);
}