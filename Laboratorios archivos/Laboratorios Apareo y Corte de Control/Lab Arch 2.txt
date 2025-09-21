#include <iostream>
#include <stdio.h>
#include "principal.hpp"
using namespace std;

struct Producto
{
    int COD_PROD;
    char desc[10];
    int stock;
};

int main()
{
    FILE *Este;
    FILE *Oeste;
    FILE *Completo;
    Este = fopen("Este.dat", "rb");
    Oeste = fopen("Oeste.dat", "rb");
    Completo = fopen("Completo.dat", "wb");

    Producto este, oeste;
    fread(&este, sizeof(Producto), 1, Este);
    fread(&oeste, sizeof(Producto), 1, Oeste);

    while (!feof(Este) && !feof(Oeste))
    {
        if (este.COD_PROD < oeste.COD_PROD)
        {
            fwrite(&este, sizeof(Producto), 1, Completo);
            fread(&este, sizeof(Producto), 1, Este);
        }
        else
        {
            fwrite(&oeste, sizeof(Producto), 1, Completo);
            fread(&oeste, sizeof(Producto), 1, Oeste);
        }
    }
    while (!feof(Este))
    {
        fwrite(&este, sizeof(Producto), 1, Completo);
        fread(&este, sizeof(Producto), 1, Este);
    }

    while (!feof(Oeste))
    {
        fwrite(&oeste, sizeof(Producto), 1, Completo);
        fread(&oeste, sizeof(Producto), 1, Oeste);
    }

    fclose(Este);
    fclose(Oeste);
    fclose(Completo);
    return 0;
}