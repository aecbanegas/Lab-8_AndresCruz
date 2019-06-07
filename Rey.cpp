#include "Rey.h"
Rey::Rey(){
    nombre="Rey";
}
Rey::Rey(string col){
    color=col;
}
void Rey::setColor(string col){
    color=col;
}
string Rey::getColor(){
    return color;
}
bool Rey::validarMovimiento(string coordenada,Pieza*** tablero){
    int x1,y1,x2,y2;
    bool valido=false;
    x1=coordenada[1]-97;
    y1=(int)coordenada[2]-49;
    y1=(y1*-1)+8;
    x2=coordenada[4]-97;
    y2=coordenada[5]-49;
    y2=(y2*-1)+8;
    if((tablero[x1][y1]->toString()=='K')){
        if((x2-1==x1)&&(y1==y2)){
            valido=true;
        }
        if((x2-1==x1)&&(y1==y2-1)){
            valido=true;
        }
        if((x2-1==x1)&&(y1==y2+1)){
            valido=true;
        }
        if((x2+1==x1)&&(y1==y2+1)){
            valido=true;
        }
        if((x2+1==x1)&&(y1==y2-1)){
            valido=true;
        }
        if((x2+1==x1)&&(y1==y2)){
            valido=true;
        }
        if((x2==x1)&&(y1==y2-1)){
            valido=true;
        }
        if((x2==x1)&&(y1==y2+1)){
            valido=true;
        }
    }
    return valido;
}
string Rey::toString(){
    return "K";
}