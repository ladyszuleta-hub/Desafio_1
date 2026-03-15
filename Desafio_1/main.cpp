#include <iostream>
#include "tablero.h"
using namespace std;

int main(){

    int ancho = pedirAncho();
    int alto = pedirAlto();

    unsigned char** tablero = crearTablero(ancho, alto);

    imprimirTablero(tablero, alto, ancho);

    return 0;
}
