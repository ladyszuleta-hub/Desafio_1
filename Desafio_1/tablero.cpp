#include <iostream>
#include "tablero.h"
#include "piezas.h"
using namespace std;

int pedirAlto() {
    int alto;

    do {
        cout << "Alto (minimo 8): ";
        cin >> alto;
    } while(alto < 8);
    return alto;

}
int pedirAncho(){
    int ancho;
    do {
        cout << "Ancho (multiplo de 8, minimo 8): ";
        cin >> ancho;
    } while(ancho < 8 || ancho % 8 != 0);
    return ancho;
}
unsigned char** crearTablero(int ancho,int alto) {

    int bytesPorFila = ancho / 8;

    unsigned char** tablero = new unsigned char*[alto];

    for(int i=0;i<alto;i++) {

        tablero[i] = new unsigned char[bytesPorFila];

        for(int j=0;j<bytesPorFila;j++)
            tablero[i][j] = 0;
    }
    return tablero;
}
void imprimirTablero(unsigned char** tablero, int alto, int ancho) {

    for(int y = 0; y < alto; y++) {

        for(int x = 0; x < ancho; x++) {

            int byte = x / 8;
            int bit = x % 8;

            if(tablero[y][byte] & (1 << bit))
                cout << "#";
            else
                cout << ".";

        }

        cout << endl;
    }
}


