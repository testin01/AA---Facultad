#include <iostream>
#include <stdio.h>
#include "principal.hpp"
using namespace std;

void unionVectores(int A[], int lenA, int B[], int lenB);

int main()
{
    int A[10];
    int lenA;
    int B[10];
    int lenB;

    unionVectores(A, lenA, B, lenB);

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

    for (int i = 0; i < lenA; i++)
    {
        insertar(C, lenC, A[i], lenC);
    }

    for (int i = 0; i < lenB; i++)
    {
        if (buscar(C, lenC, B[i]) != -1)
        {
            insertar(C, lenC, B[i], lenC);
        }
    }

    mostrarVector(C, lenC);
}