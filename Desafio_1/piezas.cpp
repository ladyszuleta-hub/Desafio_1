#include <iostream>
#include "piezas.h"
#include "juego.h"
using namespace std;
//Aquí crearemos las piezas y su funcionamiento.
bool bajarPieza(unsigned char **tablero, unsigned char pieza[4], int &posX, int &posY, int alto, int ancho)
{
    if(!colision(tablero, pieza, posX, (posY + 1), alto, ancho))
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
void rotarSiSePuede(unsigned char pieza[4],unsigned char **tablero,int &posX,int &posY,int alto,int ancho)
{
    unsigned char copia[4];

    // copiar pieza original
    for(int i = 0; i < 4; i++)
        copia[i] = pieza[i];

    // rotar la copia
    rotarPieza(copia);

    // verificar colisión
    if(!colision(tablero, copia, posX, posY, alto, ancho))
    {
        // aplicar rotación a la original
        for(int i = 0; i < 4; i++)
            pieza[i] = copia[i];
    }
}
void generarPieza(unsigned char pieza[4]){

    int tipo = rand()%2;

    if(tipo==0){ // cuadrado

        pieza[0] = 0;
        pieza[1] = 0;
        pieza[2] = 0b00000011;
        pieza[3] = 0b00000011;

    }

    if(tipo==1){ // linea

        pieza[0] = 0b00000001;
        pieza[1] = 0b00000001;
        pieza[2] = 0b00000001;
        pieza[3] = 0b00000001;

    }
    if(tipo==2){ // T
        pieza[0] = 0;
        pieza[1] = 0b00000011;
        pieza[2] = 0b00000010;
        pieza[3] = 0;
    }

    if(tipo==3){ // L
        pieza[0] = 0b00000001;
        pieza[1] = 0b00000001;
        pieza[2] = 0b00000011;
        pieza[3] = 0;
    }
    if(tipo==4){ // L invertida
        pieza[0] = 0b00000010;
        pieza[1] = 0b00000010;
        pieza[2] = 0b00000011;
        pieza[3] = 0;
    }

}

void copiarPiezaParcial(unsigned char** tablero,unsigned char pieza[4],int posX,int posY,int lineasVisibles, int ancho){
    for(int i = 0; i < lineasVisibles; i++){
        int y = posY + i;


        if(y < 0) continue;

        for(int j = 0; j < 8; j++){
            if(pieza[i] & (1 << j)){
                int x = posX + j;

                int byte = x / 8;
                int bit  = x % 8;

                tablero[y][byte] |= (1 << bit);
            }
        }
    }
}
void moverIzquierda(
    unsigned char pieza[4],
    int &posX,
    int &posY,
    unsigned char **tablero,
    int alto,
    int ancho
    ){
    if(!colision(tablero, pieza, posX - 1, posY, alto, ancho))
        posX--;
}
void moverDerecha(unsigned char pieza[4],
    int &posX,
    int &posY,
    unsigned char **tablero,
    int alto,
    int ancho
    ){
    if(!colision(tablero, pieza, posX + 1, posY, alto, ancho))
        posX++;
}
