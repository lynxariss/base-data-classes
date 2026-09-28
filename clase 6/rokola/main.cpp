#include "funtions.h"
#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>
#include <vector>
#include <iomanip>

//made by lyria and adrian

using namespace std;


int main(){
    int op = 0, op_sub=0, pos = 0;
    Jukebox jukebox;
    int artistIndex;
    int  songIndex;
    system("clear");
    cout<<"Cargando canciones, por favor espere..."<<endl;
    initializeJukebox(jukebox);
    system("clear");
    do{
        system("clear");
        do{
        if (jukebox.playlist.empty()){
            showShortMenu();
            cin>>op;
            if(op >= 3||op <= 0){
                cout<<"opcion invalida, intenta de nuevo";
                cin>>op;
                cout<<endl;
            }
            else{
                
                if (op == 2){
                    op = 6;
                }
            break;
            
            }
        }
        else if(jukebox.playlist.size() >= 1){
            showLongMenu(jukebox);
            cin>>op;
            if(op > 6|| op < 1){
                cout<<"opcion invalida, intenta de nuevo"<<endl;
                cin>>op;
                cout<<endl;
            }
            else{
                break;
            }
            
        }
        }while (true);
        
        
        switch (op)
        {
        case 1:
            showArtists(jukebox);
            cin>>artistIndex;
            artistIndex--;
            showSongs(jukebox, artistIndex);
            cin>>songIndex;
            songIndex--;
            while(true){
            system("clear");
            if(!addSong(jukebox, artistIndex, songIndex)){
                showArtists(jukebox);
                cin>>artistIndex;
                artistIndex--;
                showSongs(jukebox, artistIndex);
                cin>>songIndex;
                songIndex--;
            }
            else{
                    cout<<"cancion agregada con exito"<<endl; 
                    break;
            }
            }
            break;
        case 2:
            if(pauseSong(jukebox)==false){
                cout<<"la cola esta vacia"<<endl;
            }
            cout<<"pulsa enter..."<<endl;
            cin.get();
            cin.get();
            break;
        case 3:
            if(nextSong(jukebox) == false){
                cout<<"no hay mas canciones"<<endl;
            } cout<<"pulsa enter..."<<endl;
            cin.get();
            cin.get();
            break;
        case 4:
            //menu of 3 op delete a song, delete all and cancel
            showDeleteMenu();
            cin>>op_sub;
                switch (op_sub)
                {
                case 1:
                    showPlaylist(jukebox);
                    cin>>pos;
                    pos --;
                    removeSong(jukebox, pos);
                    break;
                case 2:
                    clearPlaylist(jukebox);
                    break;
                case 3:
                    break;
                }
            break;
        case 5: 
            if(previousSong(jukebox) == false){
                cout<<"llegaste al inicio"<<endl;
            }
            cout<<"pulsa enter..."<<endl;
            cin.get();
            cin.get();
            break;
        case 6: 
            cout<<"pulsa enter..."<<endl;
            cin.get();
            cin.get();
            return 0;
            break;
        default:
            break;
        }
    }while(true);
}