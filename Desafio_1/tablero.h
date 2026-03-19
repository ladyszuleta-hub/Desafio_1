#ifndef TABLERO_H
#define TABLERO_H


int pedirAncho();
int pedirAlto();
unsigned char** crearTablero(int ancho,int alto);
void imprimirTablero(unsigned char** tablero, int alto, int ancho);
void limpiarTablero(unsigned char** tablero, int alto, int ancho);
void eliminarFilas(unsigned char **tablero, int alto, int ancho);
bool filaLlena(unsigned char *fila, int bytesPorFila);
#endif // TABLERO_H

