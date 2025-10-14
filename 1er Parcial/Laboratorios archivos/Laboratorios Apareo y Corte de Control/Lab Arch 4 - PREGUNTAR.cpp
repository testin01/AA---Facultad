#include <iostream>
#include <stdio.h>
#include "principal.hpp"
using namespace std;

struct Ventas
{
    int COD_COMBO;
    int mesVenta;
    int unidVendidas;
};

int main()
{
    FILE *Vendidos;
    Vendidos = fopen("BurgerFast.dat", "rb");

    Ventas raux;
    int anterior, contador = 0;
    fread(&raux, sizeof(Ventas), 1, Vendidos);

    while (!feof(Vendidos))
    {
        anterior = raux.COD_COMBO;
        while (raux.COD_COMBO == anterior)
        {
            contador += raux.unidVendidas;
            fread(&raux, sizeof(Ventas), 1, Vendidos);
        }

        cout << "El total de unidades vendidas del combo " << anterior << " es de " << contador << endl;
        fread(&raux, sizeof(Ventas), 1, Vendidos);
    }

    return 0;
}