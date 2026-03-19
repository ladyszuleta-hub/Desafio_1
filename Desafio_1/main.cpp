#include <iostream>
#include "tablero.h"
#include "piezas.h"
#include "juego.h"
using namespace std;

int main(){

    int ancho = pedirAncho();
    int alto  = pedirAlto();

    unsigned char** tablero = crearTablero(ancho, alto);
    loopJuego(tablero,ancho,alto);


    return 0;
}
