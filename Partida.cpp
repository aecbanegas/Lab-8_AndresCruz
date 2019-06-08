#include "Partida.h"
#include "WRFile.h"
Partida::Partida(){
}
Partida::Partida(string nom, string pie){
    nombre=nom;
    pie=pie;
}
void Partida::setMovimientos(vector<string> movs){
    movimientos=movs;    
}
void Partida::guardarPartida(){
    WRFile* cargar;
    cargar->escribirArchivo(nombre,pieza,movimientos);    
    delete cargar;
}
void Partida::setNombre(string nom){
    nombre=nom;
}
void Partida::setPieza(string pie){
    pieza=pie;
}
string Partida::getNombre(){
    return nombre;
}
vector<string> Partida::getMovimientos(){
    return movimientos;
}