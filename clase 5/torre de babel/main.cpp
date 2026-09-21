#include <iostream>
#include "funtions.h"
using namespace std;

int main(){
    int size[7][3] = {{1,0,0},{2,0,0},{3,0,0},{4,0,0},{5,0,0},{6,0,0},{7,0,0}};
    int turns = 0;
    do{
        display(size);
        movement(size, turns);
        win(size);
        system("clear");
    }while (!win(size));
    display(size);
    cout<<"felicidades, acabaste en un total de "<<turns<<"turnos"<<endl;

}   