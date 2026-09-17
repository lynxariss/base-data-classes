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
    int l = 10;
    int pila[l];
    int p =0;
    int dato = 0;
    int op = 0;

    do{
        cout<<"------menu--------\n"<<
        "1.- agregar pila\n"<<
        "2.- leer pila\n"<<
        "3.- buscar dato\n"<<
        "4.- Eliminar de la pila\n"
        "5.- Vaciar pila\n"<<
        "0.- Cerrar sistema\n"<<
        "Opcion: ";
        cin>>op;
        switch (op)
        {
        case 1:
            if(p < 1){
                cout<<"ingresa el dato para insertar en la pila"<<endl;
                cin>>dato;
                push(pila,dato,p);
            }else
                cout<<"pila ";
            break;
        case 2:
            if(!isEmpty(pila, p)){
            dato = peek(pila, p);
            }
            break;
        case 3:
            if(!isEmpty(pila, p)){
                cout<<"indica el numero a buscar"<<endl;
                cin>>dato;
                search(pila, dato, p);
            }
            break;
        case  4:
            if(!isEmpty(pila, p))
                dato = pop(pila, p);
            break;
        case 5:
            clear(pila, p);
            break;
        case 0:
            cout<<"cerrando todo.."<<endl;
            return true;
            break;
        default:
            cout<<"opcion invalida";
            break;
        }
    }while(true);
}