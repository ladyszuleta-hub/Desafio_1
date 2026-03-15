#include <iostream>
#include "piezas.h"
#include "juego.h"
using namespace std;
//Aquí crearemos las piezas y su funcionamiento.
bool bajarPieza(unsigned char **tablero, unsigned char pieza[4], int &posX, int &posY, int ancho, int alto)
{
    if(!colision(tablero, pieza, posX, (posY + 1), ancho, alto))
    {
        posY++;
        return true;   // la pieza bajó
    }

    return false;      // no pudo bajar
}

void rotarPieza(unsigned char pieza[4]){
    unsigned char nueva[4] = {0,0,0,0};

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(pieza[i] & (1 << j))
            {
                nueva[j] |= (1 << (3 - i));
            }
        }
    }

    for(int i=0;i<4;i++)
        pieza[i] = nueva[i];
}
