#include <iostream>
using namespace std;

void push(int pila[], int dato, int p);
int peek(int pila[], int p);
bool search(int pila[], int dato, int p);
bool isEmpty(int pila[], int p);
void clear(int pila[], int p);
int pop(int pila[], int p);

void push(int pila[], int dato, int p){
    pila[p++] = dato;
    cout<<"Elemento guardado en pila con exito"<<endl;
}

int peek(int pila[], int p){
    int d = 0;
    d = pila[p - 1];
    cout<<"El dato en la pila es: "<< d << endl;
    return d;
}

bool search(int pila[], int dato, int p){
    for (int i = 0; i < p; i++)
    {
        int d = 0;
        d = pila[i];
        if(d == dato){
            cout<<"El dato "<< dato<<" si existe en la pila."<<endl;
            return true;
        }
    }
    cout<<"El dato "<<dato << " no existe en la pila"<<endl;
    return false;
}

bool isEmpty(int pila[], int p){
    if(p == 0){
        cout<<"La pila esta vacia."<<endl;
        return true;
    }else{
        cout<<"La pila contiene datos."<<endl;
        return false;
    }

}

void clear(int pila[], int p){
    p = 0;
    cout<<"La pila se ha vaciado."<<endl;
}

int pop(int pila[], int p){
    int dato = 0;
    dato = pila[--p];
    cout<<"El dato eliminado de la pila es: "<<dato<< endl;
    return dato;
}

int main(){
    
}