#include <iostream>
#include "juego.h"
#include "tablero.h"
#include "piezas.h"
using namespace std;

bool colision(unsigned char **tablero, unsigned char pieza[4], int posX, int posY, int ancho, int alto){
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
void fijarPieza(unsigned char **tablero,unsigned char pieza[4],int &posX,int &posY,int ancho,int alto)
{
    for(int i = 0; i < 4; i++)
    {
        int y = posY + i;

        if(y < 0 || y >= alto)
            continue;

        for(int j = 0; j < 8; j++)
        {
            if(pieza[i] & (1 << j))
            {
                int x = posX + j;

                if(x < 0 || x >= ancho)
                    continue;

                int byte = x / 8;
                int bit  = x % 8;

                tablero[y][byte] |= (1 << bit);
            }
        }
    }
}
char leerMovimiento() {

    char mov;

    cout << "Movimiento (a=izq, d=der, s= bajar, r=rotar, q=salir): ";
    cin >> mov;

    return mov;
}
void procesarMovimiento(
    char mov,
    unsigned char pieza[4],
    int &posX,
    int &posY,
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

        rotarSiSePuede(pieza,tablero,posX,posY,ancho,alto);
    }
}



bool gameOver(unsigned char **tablero,unsigned char pieza[4],int posX,int posY,int ancho,int alto)
{
    return colision(tablero, pieza, posX, posY, ancho, alto);
}
void loopJuego(unsigned char **tablero, int ancho, int alto)
{    unsigned char pieza[4];
    generarPieza(pieza);

    int posX = ancho / 2;
    int posY = 0;

    char mov;
    int lineasVisibles = 1;

    do {
        //  Crear copia visual del tablero
        unsigned char** copia = crearTablero(ancho, alto);

        // copiar tablero real (piezas fijas)
        for(int i = 0; i < alto; i++){
            for(int j = 0; j < ancho/8; j++){
                copia[i][j] = tablero[i][j];
            }
        }

        copiarPiezaParcial(copia, pieza, posX, posY,lineasVisibles);
        imprimirTablero(copia, alto, ancho);
        mov = leerMovimiento();
        procesarMovimiento(mov, pieza, posX, posY, tablero, alto, ancho);

        // si presiona bajar
        if(mov == 's' && lineasVisibles==4){
            if(!bajarPieza(tablero, pieza, posX, posY, ancho, alto)){
                // fijar pieza
                fijarPieza(tablero,pieza,posX,posY,ancho,alto);
                eliminarFilas(tablero,alto,ancho);
                // nueva pieza
                generarPieza(pieza);
                posX = ancho / 2;
                posY = 0;
                if(gameOver(tablero, pieza, posX, posY, ancho, alto))
                {
                    cout << "GAME OVER\n";
                    break;
                }
                lineasVisibles=0;
            }
        }
        if(lineasVisibles < 4)
            lineasVisibles++;

        // liberar copia (IMPORTANTE)
        for(int i = 0; i < alto; i++){
            delete[] copia[i];
        }
        delete[] copia;

    } while(mov != 'q');
}
