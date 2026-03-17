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
void generarPieza(unsigned char pieza[4]){

    int tipo = rand()%2;

    if(tipo==0){ // cuadrado

        pieza[0] = 0b00011000;
        pieza[1] = 0b00011000;
        pieza[2] = 0;
        pieza[3] = 0;

    }

    if(tipo==1){ // linea

        pieza[0] = 0b00010000;
        pieza[1] = 0b00010000;
        pieza[2] = 0b00010000;
        pieza[3] = 0b00010000;

    }

}

void copiarPieza(unsigned char** tablero,unsigned char pieza[4],int x,int y){

    for(int i=0;i<4;i++){

        int fila = y+i;

        if(pieza[i]!=0){

            int byte = x/8;
            int bit = x%8;

            tablero[fila][byte] |= (pieza[i] >> bit);

        }
    }
}
void moverIzquierda(
    unsigned char pieza[4],
    int &posX,
    int posY,
    unsigned char **tablero,
    int alto,
    int ancho
    ){
    if(!colision(tablero, pieza, posX - 1, posY, alto, ancho))
        posX--;
}
void moverDerecha(unsigned char pieza[4],
    int &posX,
    int posY,
    unsigned char **tablero,
    int alto,
    int ancho
    ){
    if(!colision(tablero, pieza, posX + 1, posY, alto, ancho))
        posX++;
}
char leerMovimiento() {

    char mov;

    cout << "Movimiento (a=izq, d=der, q=salir): ";
    cin >> mov;

    return mov;
}
void procesarMovimiento(
    char mov,
    unsigned char pieza[4],
    int &posX,
    int posY,
    unsigned char **tablero,
    int alto,
    int ancho
    ){
    if(mov == 'a'){
        moverIzquierda(pieza, posX, posY, tablero, alto, ancho);
    }
    else if(mov == 'd'){
        moverDerecha(pieza, posX, posY, tablero, alto, ancho);
    }
    else if(mov == 'r'){
        rotarPieza(pieza);
    }
}

