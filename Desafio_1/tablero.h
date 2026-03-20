#ifndef TABLERO_H
#define TABLERO_H


int pedirAncho();
int pedirAlto();
unsigned char** crearTablero(int alto,int ancho);
void imprimirTablero(unsigned char** tablero, int alto, int ancho);
void eliminarFilas(unsigned char **tablero, int alto, int ancho);
bool filaLlena(unsigned char *fila, int bytesPorFila);
void liberarTablero(unsigned char** tablero, int alto);

#endif // TABLERO_H

