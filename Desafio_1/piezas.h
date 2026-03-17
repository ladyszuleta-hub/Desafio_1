#ifndef PIEZAS_H
#define PIEZAS_H

bool bajarPieza(unsigned char **tablero, unsigned char pieza[4], int &posX, int &posY, int ancho, int alto);
void rotarPieza(unsigned char pieza[4]);
void moverDerecha(unsigned char pieza[4],int &posX,int posY,unsigned char **tablero,int alto,int ancho);
void moverIzquierda(unsigned char pieza[4],int &posX,int posY,unsigned char **tablero,int alto,int ancho);
void copiarPieza(unsigned char** tablero,unsigned char pieza[4],int x,int y);
void generarPieza(unsigned char pieza[4]);
char leerMovimiento();
void procesarMovimiento(char mov,unsigned char pieza[4],int &posX,int posY,unsigned char **tablero,int alto,int ancho);



#endif // PIEZAS_H
