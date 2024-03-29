#include "WRFile.h"
#include <sstream>
#include <vector>
using std::stringstream;
using std::vector;
WRFile::WRFile(){
}
vector<Partida*> WRFile::leerArchivo(){
    string linea;    
    int cont=0;
    vector<Partida*> partidas;
    string hola="bitacoraPartidas.txt";
    file.open(hola,fstream::in | fstream::out);
    while(getline(file,linea)){
        if(cont==0){
            partidas.push_back(new Partida());
            partidas[partidas.size()-1]->setNombre(linea);
            cont++;
        }else if(cont==1){
            partidas[partidas.size()-1]->setPieza(linea);
            cont++;
        }else if(cont==2){
            vector<string>movimientos;
            stringstream mov;
            for (int i = 0; i < linea.size(); i++){
                if(linea[i]!=';'){
                    mov<<linea[i];
                }else{
                    movimientos.push_back(mov.str());
                    mov.str("");
                }
            }
            partidas[partidas.size()-1]->setMovimientos(movimientos);
            cont++;
        }else if(cont==3){
            cont=0;
        }
    }
    file.close();
    return partidas;
}
void WRFile::escribirArchivo(string nombres,string piezas,vector<string> movimientos){
    string hola="bitacoraPartidas.txt";
    file.open(hola,ios::app);
    file<<nombres<<"\n"<<piezas<<"\n";
    for (int i = 0; i < movimientos.size(); i++){
        file<<movimientos[i]<<";";
    }
    file<<"\n";
    for (int i = 0; i < 20; i++){
        file<<"-";
    }
    file<<"\n";
    
    file.close();
}