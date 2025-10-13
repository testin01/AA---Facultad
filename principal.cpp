#include <iostream>
#include <stdio.h>
#include "principal.hpp"
using namespace std;

int main()
{

    return 0;
}

/*
Desarrolle los siguientes PROCEDIMIENTOS:
    a- Dados 2 vectores de enteros (A[10], B[10]) genere la UNION de ambos en C[20]
 */

void unionVectores(int A[], int lenA, int B[], int lenB)
{
    int C[20];
    int lenC = 0;

    inicializarVector(C, 20, 0);

    int i = 0;

    while (i < lenA && i < lenB)
    {
        insertarOrdenado(C,lenC,A[i]);
        i++;
    }
    /*     for (int i = 0; i < lenA; i++)
        {
            insertar(C, lenC, A[i], i - 1);
        }
        for (int i = 10; i - 10 < lenB; i++)
        {
            insertar(C, lenC, B[i], i);
        } */
}