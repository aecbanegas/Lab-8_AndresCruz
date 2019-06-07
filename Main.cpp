#include "Partida.h"
#include "Rey.h"
#include "WRFile.h"
#include "Pieza.h"
#include "Reina.h"
#include "Torre.h"
#include "Alfil.h"
#include "Peon.h"
#include "Caballo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
void Jugar(vector<Partida*>&);
void Recrear(Partida*);
Pieza*** crearTablero();
void liberarTablero(Pieza***);
int main(){
    vector<Partida*>partidas;
    WRFile* archivo=new WRFile();
    archivo->leerArchivo(partidas);
    int opcm=0;
    while(opcm!=3){//menu
        cout<<"         Menu"<<endl
            <<"1. Jugar Partida"<<endl
            <<"2. Recrear Partida"<<endl
            <<"3. Salir"<<endl
            <<"Ingrese una opcion: "<<endl;
        cin>>opcm;
        if(opcm==1){
            Jugar(partidas);
        }
        if(opcm==2){
            if (!partidas.empty()){
                int pos;
                for (int i = 0; i < partidas.size(); i++){
                    cout<<"Posicion: "<<i<<" "<<partidas[i]->getNombre()<<"\n";
                }
                cout<<"Ingrese que partida desea recrear: "<<endl;
                cin>>pos;
                while(pos<0||pos>=partidas.size()){
                    cout<<"Ingrese que partida desea recrear: "<<endl;
                    cin>>pos;
                }
                Recrear(partidas[pos]);
            }else{
                cout<<"No hay partidas disponibles!"<<endl;
            }
            
        }
    }
    
    for (int i = 0; i < partidas.size(); i++){//liberar vector
        delete partidas[i];
    }
    partidas.clear();
    delete archivo;
    return 0;
}
void Jugar(vector<Partida*> &partidas){

}
Pieza*** crearTablero(){
    Pieza*** tablero=new Pieza**[8];
    for (int i = 0; i < 8; i++){
        tablero[i]=new Pieza*[8];
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tablero[i][j]=NULL;
        }
        
    }
    
    return tablero;
}
void liberarTablero(Pieza*** tablero){
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(tablero[i][j]!=NULL){
                delete tablero[i][j];
            }
        }
        delete[] tablero[i];
    }
    delete[] tablero;
}
void Recrear(Partida* partida){

}