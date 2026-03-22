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
unsigned char** crearTablero(int alto,int ancho) {

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
    char cuadrado=219;

    for(int y = 0; y < alto; y++) {

        for(int x = 0; x < ancho; x++) {

            int byte = x / 8;
            int bit = x % 8;

            if(tablero[y][byte] & (1 << bit))
                cout << cuadrado;
            else
                cout << ".";

        }

        cout << endl;
    }
}

bool filaLlena(unsigned char *fila, int bytesPorFila)
{
    for(int i = 0; i < bytesPorFila; i++)
    {
        if(fila[i] != 0xFF) // 11111111
            return false;
    }
    return true;
}
void eliminarFilas(unsigned char **tablero, int alto, int ancho)
{
    int bytesPorFila = (ancho + 7) / 8;

    for(int y = 0; y < alto; y++)
    {
        if(filaLlena(tablero[y], bytesPorFila))
        {
            // bajar todas las filas de arriba
            for(int k = y; k > 0; k--)
            {
                for(int b = 0; b < bytesPorFila; b++)
                {
                    tablero[k][b] = tablero[k-1][b];
                }
            }

            // limpiar la fila superior
            for(int b = 0; b < bytesPorFila; b++)
            {
                tablero[0][b] = 0;
            }

            y--; // revisar la misma fila otra vez
        }
    }
}
void liberarTablero(unsigned char** tablero, int alto){

    for(int i = 0; i < alto; i++){
        delete[] tablero[i];
    }

    delete[] tablero;
}
