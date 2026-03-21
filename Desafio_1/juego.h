#ifndef JUEGO_H
#define JUEGO_H

bool colision(unsigned char **tablero, unsigned char pieza[4], int posX, int posY, int alto,int ancho);
void fijarPieza(unsigned char **tablero,unsigned char pieza[4],int &posX,int &posY,int alto,int ancho);
char leerMovimiento();
void procesarMovimiento(char mov, unsigned char pieza[4], int &posX, int &posY, unsigned char **tablero, int alto, int ancho);
bool gameOver(unsigned char **tablero,unsigned char pieza[4],int posX,int posY,int alto,int ancho);
void loopJuego(unsigned char **tablero, int alto, int ancho);
int ultimaFilaOcupada(unsigned char pieza[4]);
#endif // JUEGO_H
