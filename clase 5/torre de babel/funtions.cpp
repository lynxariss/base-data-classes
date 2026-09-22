#include <iostream>
#include "funtions.h"
#include <iomanip>
using namespace std;
//mtw = move to where
//wtm = where to move

int movement(int size[7][3], int turns){

    int mtw, wtm;
    int disco;
    int filaOrigen;
    int filaDestino;

    do
    {    
        cout << "\n===== TORRES DE BABEL =====\n";

        cout << "Torre de origen (1-3): ";
        cin >> wtm;

        cout << "Torre de destino (1-3): ";
        cin >> mtw;

        if(wtm < 1 || wtm > 3 || mtw < 1 || mtw > 3){
            cout<<"Error: selecciona torres del 1 al 3"<<endl;
        }
        else{
            // Pasar de 1-3 a índices 0-2
            wtm--;
            mtw--;

            // Buscar el disco superior
            disco = 0;

            for(int i = 0; i < 7; i++){
                if(size[i][wtm] != 0){
                    disco = size[i][wtm];
                    filaOrigen = i;
                    break;
                }
            }
            if(!check_movement(size, mtw, wtm)){
                cout<<"error, movimiento incorrecto"<<endl;
            }
        }
        turns++;
    }while (!check_movement(size, mtw, wtm));

    // Buscar dónde colocar el disco
    filaDestino = 6;

    for(int i = 0; i < 7; i++){
        if(size[i][mtw] != 0){
            filaDestino = i - 1;
            break;
        }
    }

    // Mover el disco
    size[filaOrigen][wtm] = 0;
    size[filaDestino][mtw] = disco;

    return turns;
}

bool check_movement(int size[7][3], int mtw, int wtm){

    int discoOrigen = 0;
    int discoDestino = 0;

    // Buscar disco superior de origen
    for(int i = 0; i < 7; i++){
        if(size[i][wtm] != 0){
            discoOrigen = size[i][wtm];
            break;
        }
    }

    // Buscar disco superior de destino
    for(int i = 0; i < 7; i++){
        if(size[i][mtw] != 0){
            discoDestino = size[i][mtw];
            break;
        }
    }

    // La torre de origen está vacía
    if(discoOrigen == 0){
        return false;
    }

    // La torre de destino está vacía
    if(discoDestino == 0){
        return true;
    }

    // El disco de origen debe ser menor que el de destino
    if(discoOrigen < discoDestino){
        return true;
    }

    return false;
}

void display(int size[7][3]){
    
    cout<<"\n"<<endl;
    
    for(int i=0; i<7; i++){
        
        for(int j=0; j<3; j++){
            
            if(size[i][j]!=0){
                //cuando si hay aro
                int disco= size[i][j];
                
                cout<<setw(9-disco)<<"";
                
                for(int m=0; m<disco; m++){
                    cout<<"=";
                }
                
                cout<<"|";
                for(int m=0; m<disco; m++){
                    cout<<"=";
                }
                cout<<setw(9-disco)<<"";
            
            } else{
                //esto es cuando no hay aro
                cout<<setw(9)<<"";
                cout<<"|";
                cout<<setw(9)<<"";
                //muestra torre sin nada
            }
        }
        cout<<endl;
    }
    
    cout<< "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n";
}

bool win(int size[7][3]){

    for(int i = 0; i < 7; i++){
        if(size[i][2] != i + 1){
            return false;
        }
    }

    return true;
}