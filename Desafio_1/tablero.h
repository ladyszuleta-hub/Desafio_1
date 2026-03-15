#ifndef TABLERO_H
#define TABLERO_H
extern unsigned char** tablero;
extern int ancho, alto;
extern int bytesPorFila;

void pedirDimensiones();
void crearTablero();
void imprimirTablero();

#endif // TABLERO_H

