#include <iostream>
#include "tablero.h"
#include "piezas.h"
using namespace std;

unsigned char** tablero;
int ancho, alto;
int bytesPorFila;

void pedirDimensiones() {

    do {
        cout << "Ancho (multiplo de 8, minimo 8): ";
        cin >> ancho;
    } while(ancho < 8 || ancho % 8 != 0);

    do {
        cout << "Alto (minimo 8): ";
        cin >> alto;
    } while(alto < 8);

}

void crearTablero() {

    bytesPorFila = ancho / 8;

    tablero = new unsigned char*[alto];

    for(int i=0;i<alto;i++) {

        tablero[i] = new unsigned char[bytesPorFila];

        for(int j=0;j<bytesPorFila;j++)
            tablero[i][j] = 0;
    }
}
void imprimirTablero() {

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
