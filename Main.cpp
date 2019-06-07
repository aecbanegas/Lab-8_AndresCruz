#include "Partida.h"
#include "Rey.h"
#include "WRFile.h"
#include "Pieza.h"
/*#include "Reina.h"
#include "Torre.h"
#include "Alfil.h"*/
#include "Peon.h"
//#include "Caballo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
void Jugar(vector<Partida*>&);
void Recrear(Partida*);
Pieza*** crearTablero();
void liberarTablero(Pieza***);
void imprimirTablero(Pieza***);
int main(){
    vector<Partida*>partidas;
    WRFile* archivo=new WRFile();
    partidas=archivo->leerArchivo();
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
            partidas[partidas.size()-1]->guardarPartida(archivo);
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
    cout<<"Bienvenido a APRENDE AJEDREZ"<<endl;
    string nom;
    cout<<"Ingrese el nombre de la partida: "<<endl;
    getline(cin,nom);
    int opcp=0;
    while(opcp!=1){
        cout<<"Menu Piezas"<<endl
            <<"1. Peon "<<endl
            <<"Ingrese que pieza usara: "<<endl;
        cin>>opcp;
    }
    Pieza*** tablero=crearTablero();
    switch (opcp)
    {
        case 1:{
            tablero[0][4]=new Rey("Negro");
            tablero[7][4]=new Rey("Blanco");
            tablero[1][4]=new Peon("Negro");
            tablero[6][4]=new Peon("Blanco");
        }       
        break;
    
        default:

        break;
    }
    imprimirTablero(tablero);
    bool color=false;
    while(true){
        string coordenada;
        int x,y,x2,y2;
        if(color){//negro
            cout<<"Ingrese las coordenadas en el formato [a6,b6] siendo las letras de la "<<endl
                <<"a a la h las columnas y del 1 al 8 las filas"<<endl
                <<"Ingrese las coordenadas: "<<endl;
            cin>>coordenada;
            x=coordenada[1]-97;
            y=(int)coordenada[2]-49;
            y=(y*-1)+8;
            x2=coordenada[4]-97;
            y2=coordenada[5]-49;
            y2=(y2*-1)+8;
            if(tablero[x][y]->validarMovimiento(coordenada,tablero)&&(tablero[x][y]->getColor()=="Negro")){
                tablero[x2][y2]=tablero[x][y];
                tablero[x][y]=NULL;
                imprimirTablero(tablero);
                color=!color;
            }else{
                cout<<"MOVIMIENTO INVALIDO INTENTE DE NUEVO!"<<endl;
            }
        }else{//Blanco
            cout<<"Ingrese las coordenadas en el formato [a6,b6] siendo las letras de la "<<endl
                <<"a a la h las columnas y del 1 al 8 las filas"<<endl
                <<"Ingrese las coordenadas: "<<endl;
            cin>>coordenada;
            x=coordenada[1]-97;
            y=(int)coordenada[2]-49;
            y=(y*-1)+8;
            x2=coordenada[4]-97;
            y2=coordenada[5]-49;
            y2=(y2*-1)+8;
            if(tablero[x][y]->validarMovimiento(coordenada,tablero)&&(tablero[x][y]->getColor()=="Blanco")){
                tablero[x2][y2]=tablero[x][y];
                tablero[x][y]=NULL;
                imprimirTablero(tablero);
                color=!color;
            }else{
                cout<<"MOVIMIENTO INVALIDO INTENTE DE NUEVO!"<<endl;
            }
        }
        string continua;
        cout<<"Desea continuar? yes/no"<<endl;
        cin>>continua;
        if(continua=="no"){
            break;
        }
    }
    if(opcp==1){
        partidas.push_back(new Partida(nom,"Peon"));
    }
    liberarTablero(tablero);
}
void imprimirTablero(Pieza*** tablero){
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(tablero[i][j]!=NULL){
                cout<<"["<<tablero[i][j]->toString()<<"] ";
            }else{
                cout<<"[ ] ";
            }
        }
        cout<<endl;
    }
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
    vector<string> mov=partida->getMovimientos();
    Pieza*** tablero=crearTablero();

    for (int i = 0; i < mov.size(); i++){
        cout<<"Movimiento Numero: "<<(i+1)<<endl;
        string temporal=mov[i];
        int x,y,x2,y2;
        x=temporal[1]-97;
        y=(int)temporal[2]-49;
        y=(y*-1)+8;
        x2=temporal[4]-97;
        y2=temporal[5]-49;
        y2=(y2*-1)+8;
        tablero[x2][y2]=tablero[x][y];
        tablero[x][y]=NULL;
        imprimirTablero(tablero);
    }
    
}