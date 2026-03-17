#include <iostream>
#include "juego.h"
#include "tablero.h"
#include "piezas.h"
using namespace std;

bool colision(unsigned char **tablero, unsigned char pieza[4], int posX, int posY, int alto, int ancho){
    for (int i=0; i<4;i++){
        int y =posY+i;
        if(y<0) continue;
        if (y>=alto)return true;
        for(int j=0;j<8; j++){
            if(pieza[i] & (1 << j))
            {
                int x=posX+j;
                if(x<0 || x>=ancho)return true;
                int Byte= x/8;
                int bit =x%8;
                if(tablero[y][Byte] & (1 << bit))
                    return true;
            }
        }

    }return false;
}
