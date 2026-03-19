#ifndef JUEGO_H
#define JUEGO_H

bool colision(unsigned char **tablero, unsigned char pieza[4], int posX, int posY, int ancho,int alto);
void fijarPieza(unsigned char **tablero,unsigned char pieza[4],int &posX,int &posY,int ancho,int alto);
char leerMovimiento();
void procesarMovimiento(char mov, unsigned char pieza[4], int &posX, int &posY, unsigned char **tablero, int alto, int ancho);
bool gameOver(unsigned char **tablero,unsigned char pieza[4],int posX,int posY,int ancho,int alto);
void loopJuego(unsigned char **tablero, int ancho, int alto);

#endif // JUEGO_H
