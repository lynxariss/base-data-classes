#include <iostream>
#include "funtions.h"
using namespace std;
//mtw = move to where
//wtm = where to move

int movement(int size[7][3], int layer1, int layer2, int layer3, int turns){
    // Variables para guardar las torres elegidas y el disco
    int mtw, wtm;
    int disco;

    //while until the movenemt becomes valid
    do {    
    // Mostrar las opciones de las torres
    cout << "\n===== TORRES DE HANOI =====\n";
    cout << "Torre de origen (1-3): ";
    cin >> wtm;

    cout << "Torre de destino (1-3): ";
    cin >> mtw;

    // Contar el intento, aunque el movimiento sea invalido
    turns++;
    // check what pice its at the top
    int i = 0;
    do
    {
        if(i == 0){
            if(size[0][wtm] < size[1][wtm]){
                
            }
        }
        i++;
    }while(true);
    
    }while(true);
}
bool check_movement(int size[7][3], int layer1, int layer2, int layer3, int turns, int mtw, int wtm){
    /*
    here u will check if the movement its valid, soo u will 
    */
}
void display(){}

void win(){}