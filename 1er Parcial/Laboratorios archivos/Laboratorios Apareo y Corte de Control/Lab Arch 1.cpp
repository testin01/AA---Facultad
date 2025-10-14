#include <iostream>
#include <stdio.h>
#include "principal.hpp"
using namespace std;

struct Alumno
{
    int legajo;
    char materia[30];
    int nota;
};

int main()
{
    FILE *Alum;
    Alum = fopen("Primed.dat", "rb");
    Alumno raux;
    int anterior;
    int acum, cont, promedio;
    fread(&raux, sizeof(Alumno), 1, Alum);

    while (!feof(Alum))
    {
        anterior = raux.legajo;
        acum = 0;
        while (!feof(Alum) && anterior == raux.legajo)
        {
            acum += raux.nota;
            cont++;
            fread(&raux, sizeof(Alumno), 1, Alum);
        }
        promedio = acum / cont;
        cout << "El promedio del alumno " << raux.legajo << " es de " << promedio << endl;
    }
    fclose(Alum);
    return 0;
}