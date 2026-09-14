#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Funciones.h"

using namespace std;

int main() {
    int playOP = -1;
    int matrix[8][4];
    srand((unsigned)time(NULL));

    do {
        system("clear");
        cout << "Play options\n"
             << "1.- Play against the computer\n"
             << "2.- Play against another player\n"
             << "0.- Back to main menu\n" << endl;
        playOP = readIntInRange("Select an option: ", 0, 2);

        switch (playOP) {
            case 1:
            case 2:
                fillMatrix(matrix, playOP);
                break;
            case 0:
                cout << "Closing system..." << endl;
                break;
        }
    } while (playOP != 0);   // <-- ANTES: while (option != 0), option nunca cambiaba

    return 0;
}