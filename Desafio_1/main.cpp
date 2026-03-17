#include <iostream>
#include "tablero.h"
#include "piezas.h"
using namespace std;

int main(){

    int ancho = pedirAncho();
    int alto = pedirAlto();
    char movi= leerMovimiento();

    unsigned char** tablero = crearTablero(ancho, alto);

    unsigned char pieza[4];


    generarPieza(pieza);

    moverDerecha(pieza);

    moverDerecha(pieza);

    do {

        char movi = leerMovimiento();

        procesarMovimiento(movi, pieza);

        copiarPieza(tablero,pieza,0,0);

        imprimirTablero(tablero, alto, ancho);

    } while(movi != 'q');


    return 0;
}
