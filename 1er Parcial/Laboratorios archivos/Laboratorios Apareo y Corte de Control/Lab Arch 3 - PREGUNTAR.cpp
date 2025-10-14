#include <iostream>
#include <stdio.h>
#include "principal.hpp"
using namespace std;

struct Producto
{
    int COD_PROD;
    char desc[10];
    int cantVendidos;
};

int main()
{
    FILE *PrimerT;
    FILE *SegundoT;
    FILE *TercerT;
    FILE *Resultado;
    PrimerT = fopen("1erTrimestre.dat", "rb");
    SegundoT = fopen("2doTrimestre.dat", "rb");
    TercerT = fopen("3erTrimestre.dat", "rb");
    Resultado = fopen("Resultado.dat", "wb");

    Producto prTr, seTr, teTr;
    fread(&prTr, sizeof(Producto), 1, PrimerT);
    fread(&seTr, sizeof(Producto), 1, SegundoT);
    fread(&teTr, sizeof(Producto), 1, TercerT);

    while (!feof(PrimerT) && !feof(SegundoT) && !feof(TercerT))
    {
        if (prTr.COD_PROD < seTr.COD_PROD)
        {
            if (prTr.COD_PROD < teTr.COD_PROD)
            {
                fwrite(&prTr, sizeof(Producto), 1, Resultado);
                fread(&prTr, sizeof(Producto), 1, PrimerT);
            }
            else
            {
                fwrite(&teTr, sizeof(Producto), 1, Resultado);
                fread(&teTr, sizeof(Producto), 1, TercerT);
            }
        }
        else if (seTr.COD_PROD < teTr.COD_PROD)
        {
            fwrite(&seTr, sizeof(Producto), 1, Resultado);
            fread(&seTr, sizeof(Producto), 1, SegundoT);
        }
        else
        {
            fwrite(&teTr, sizeof(Producto), 1, Resultado);
            fread(&teTr, sizeof(Producto), 1, TercerT);
        }
    }

    while (!feof(PrimerT))
    {
        fwrite(&prTr, sizeof(Producto), 1, Resultado);
        fread(&prTr, sizeof(Producto), 1, PrimerT);
    }

    while (!feof(SegundoT))
    {
        fwrite(&seTr, sizeof(Producto), 1, Resultado);
        fread(&seTr, sizeof(Producto), 1, SegundoT);
    }

    while (!feof(TercerT))
    {
        fwrite(&teTr, sizeof(Producto), 1, Resultado);
        fread(&teTr, sizeof(Producto), 1, TercerT);
    }

    fclose(PrimerT);
    fclose(SegundoT);
    fclose(TercerT);
    fclose(Resultado);

    return 0;
}
