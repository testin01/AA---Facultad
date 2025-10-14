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

    Producto rauxAgosto;
    fread(&rauxAgosto, sizeof(Producto), 1, MCAgosto);
    Producto rauxseptiembre;
    fread(&rauxseptiembre, sizeof(Producto), 1, MCSeptiembre);

    while (!feof(MCAgosto))
    {
        if (rauxAgosto.COD_PROD < rauxseptiembre.COD_PROD)
        {
            fwrite(&rauxAgosto, sizeof(Producto), 1, MC);
            fwrite(&rauxseptiembre, sizeof(Producto), 1, MC);
        }
        else
        {
            fwrite(&rauxseptiembre, sizeof(Producto), 1, MC);
            fwrite(&rauxAgosto, sizeof(Producto), 1, MC);
        }
        fread(&rauxAgosto, sizeof(Producto), 1, MCAgosto);
        fread(&rauxseptiembre, sizeof(Producto), 1, MCSeptiembre);
    }

    return 0;
}