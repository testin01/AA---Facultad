/*
Se tienen dos archivos de la materia prima necesaria para una cadena de comidas rápidas MCAgosto.dat y
MCSeptiembre.dat ordenado por código de producto.
    - Código de Producto: 999999
    - Cantidad de unidades vendidas: 99999
    - Tipo de producto: ‘H’, ‘C’ ó ‘P’ (Hamburguesas, Caja Feliz o Pollo)

Se pide:
    a) Obtener un archivo MC.dat que consolide ambos archivos.
    b) Generar un archivo sólo para Caja Feliz, CF.dat con la siguiente estructura:
        a. Código de Producto: 999999
        b. Cantidad de unidades en depósito: 99999

Nota: Sólo puede leer 1 vez el archivo.
*/

#include <iostream>
#include <stdio.h>
#include "principal.hpp"
using namespace std;

struct Producto
{
    int COD_PROD;
    int CANT_VENDIDAS;
    char TYPE_PROD;
};

struct RProducto
{
    int COD_PROD;
    int CANT_DEPO;
};

int main()
{
    FILE *MCAgosto;
    MCAgosto = fopen("MCAgosto.dat", "rb");
    FILE *MCSeptiembre;
    MCSeptiembre = fopen("MCSeptiembre.dat", "rb");
    FILE *MC;
    MC = fopen("MC.dat", "wb");
    FILE *CF;
    CF = fopen("CF.dat", "wb");

    Producto rauxAgosto;
    fread(&rauxAgosto, sizeof(Producto), 1, MCAgosto);
    Producto rauxSeptiembre;
    fread(&rauxSeptiembre, sizeof(Producto), 1, MCSeptiembre);

    while (!feof(MCAgosto))
    {
        if (rauxAgosto.COD_PROD < rauxSeptiembre.COD_PROD)
        {
            fwrite(&rauxAgosto, sizeof(Producto), 1, MC);

            if (rauxAgosto.TYPE_PROD == 'C')
            {
                RProducto rProd;
                rProd.CANT_DEPO = rauxAgosto.CANT_VENDIDAS;
                rProd.COD_PROD = rauxAgosto.COD_PROD;
                fwrite(&rProd, sizeof(RProducto), 1, CF);
            }

            fread(&rauxAgosto, sizeof(Producto), 1, MCAgosto);
        }
        else if (rauxSeptiembre.COD_PROD < rauxAgosto.COD_PROD)
        {
            fwrite(&rauxSeptiembre, sizeof(Producto), 1, MC);

            if (rauxSeptiembre.TYPE_PROD == 'C')
            {
                RProducto rProd;
                rProd.CANT_DEPO = rauxSeptiembre.CANT_VENDIDAS;
                rProd.COD_PROD = rauxSeptiembre.COD_PROD;
                fwrite(&rProd, sizeof(RProducto), 1, CF);
            }
            fread(&rauxSeptiembre, sizeof(Producto), 1, MCSeptiembre);
        }
        else
        {
            Producto prodConsolidado;
            prodConsolidado.COD_PROD = rauxAgosto.COD_PROD;
            prodConsolidado.TYPE_PROD = rauxAgosto.TYPE_PROD;
            prodConsolidado.CANT_VENDIDAS = rauxAgosto.CANT_VENDIDAS + rauxSeptiembre.CANT_VENDIDAS;

            fwrite(&prodConsolidado, sizeof(Producto), 1, MC);

            if (prodConsolidado.TYPE_PROD == 'C')
            {
                RProducto rProd;
                rProd.CANT_DEPO = prodConsolidado.CANT_VENDIDAS;
                rProd.COD_PROD = prodConsolidado.COD_PROD;
                fwrite(&rProd, sizeof(RProducto), 1, CF);
            }
            fread(&rauxAgosto, sizeof(Producto), 1, MCAgosto);
            fread(&rauxSeptiembre, sizeof(Producto), 1, MCSeptiembre);
        }
    }

    while (!feof(MCAgosto))
    {
        fwrite(&rauxAgosto, sizeof(Producto), 1, MC);

        if (rauxAgosto.TYPE_PROD == 'C')
        {
            RProducto rProd;
            rProd.CANT_DEPO = rauxAgosto.CANT_VENDIDAS;
            rProd.COD_PROD = rauxAgosto.COD_PROD;
            fwrite(&rProd, sizeof(RProducto), 1, CF);
        }

        fread(&rauxAgosto, sizeof(Producto), 1, MCAgosto);
    }

    while (!feof(MCSeptiembre))
    {
        fwrite(&rauxSeptiembre, sizeof(Producto), 1, MC);

        if (rauxSeptiembre.TYPE_PROD == 'C')
        {
            RProducto rProd;
            rProd.CANT_DEPO = rauxSeptiembre.CANT_VENDIDAS;
            rProd.COD_PROD = rauxSeptiembre.COD_PROD;
            fwrite(&rProd, sizeof(RProducto), 1, CF);
        }
        fread(&rauxSeptiembre, sizeof(Producto), 1, MCSeptiembre);
    }

    fclose(MCSeptiembre);
    fclose(MCAgosto);
    fclose(MC);
    fclose(CF);

    return 0;
}