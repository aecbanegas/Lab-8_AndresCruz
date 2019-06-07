#include "Peon.h"
Peon::Peon(){
    nombre="Reina";
    cont=0;
}
Peon::Peon(string col){
    color=col;
}
void Peon::setColor(string col){
    color=col;
}
string Peon::getColor(){
    return color;
}
string Peon::toString(){
    return "P";
}
bool Peon::validarMovimiento(string coordenada,Pieza*** tablero){
    int x1,y1,x2,y2;
    bool valido=false;
    x1=coordenada[1]-97;
    y1=(int)coordenada[2]-48;
    y1=(y1*-1)+8;
    x2=coordenada[4]-97;
    y2=coordenada[5]-48;
    y2=(y2*-1)+8;
    if(cont==0){
        if((x1==x2)&&((y1==y2-1)||(y1==y2-2))){
            valido=true;
        }
        cont++;
    }else{
        if((x1==x2)&&(y1==y2-1)){
            valido=true;
        }
    }
    return valido;
}