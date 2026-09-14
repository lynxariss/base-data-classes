#ifndef Funciones_H
#define Funciones_H

#include <string>

int  readIntInRange(std::string prompt, int min, int max);
void fillMatrix(int matrix[8][4], int playOP);
void playAgainstComputer(int matrix[8][4]);
void playAgainstUser(int matrix[8][4]);

#endif