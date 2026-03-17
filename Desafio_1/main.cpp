#include <iostream>
#include "tablero.h"
#include "piezas.h"
using namespace std;

int main(){

    int ancho = pedirAncho();
    int alto = pedirAlto();
    char movi;

    unsigned char** tablero = crearTablero(ancho, alto);

    unsigned char pieza[4];

    generarPieza(pieza);

    int posX = ancho / 2;
    int posY = 0;

    do {
        limpiarTablero(tablero, alto, ancho);

        copiarPieza(tablero,pieza,0,0);

        imprimirTablero(tablero, alto, ancho);

        movi = leerMovimiento();

        procesarMovimiento(movi, pieza, posX, posY,tablero, alto, ancho);

        if(!bajarPieza(tablero, pieza, posX, posY, alto, ancho)){

            copiarPieza(tablero, pieza, posX, posY); // fija la pieza

            generarPieza(pieza); // nueva pieza

            posX = ancho / 2;
            posY = 0;
        }

        copiarPieza(tablero, pieza, posX, posY);

        imprimirTablero(tablero, alto, ancho);


    } while(movi != 'q');


    return 0;
}
