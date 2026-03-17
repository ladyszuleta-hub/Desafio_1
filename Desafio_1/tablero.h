#ifndef TABLERO_H
#define TABLERO_H


int pedirAncho();
int pedirAlto();
unsigned char** crearTablero(int ancho,int alto);
void imprimirTablero(unsigned char** tablero, int alto, int ancho);


#endif // TABLERO_H

