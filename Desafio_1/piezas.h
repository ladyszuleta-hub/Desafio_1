#ifndef PIEZAS_H
#define PIEZAS_H

bool bajarPieza(unsigned char **tablero, unsigned char pieza[4], int &posX, int &posY, int alto, int ancho);
void rotarPieza(unsigned char pieza[4]);
void moverDerecha(unsigned char pieza[4],int &posX,int &posY,unsigned char **tablero,int alto,int ancho);
void moverIzquierda(unsigned char pieza[4],int &posX,int &posY,unsigned char **tablero,int alto,int ancho);
void copiarPiezaParcial(unsigned char** tablero,unsigned char pieza[4],int posX,int posY,int lineasVisibles, int ancho, int alto);
void generarPieza(unsigned char pieza[4]);

void rotarSiSePuede(unsigned char pieza[4],unsigned char **tablero,int &posX,int &posY,int alto,int ancho);


#endif // PIEZAS_H
