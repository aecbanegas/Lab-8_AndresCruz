#include "WRFile.h"
#include <sstream>
using std::stringstream;
WRFile::WRFile(){
}
void WRFile::leerArchivo(vector<Partida*> &partidas){
    string linea;    
    int cont=0;
    file("bitacoraPartidas.txt");
    if(file.is_open()==false){
        file.open();
    }
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
}
void WRFile::escribirArchivo(string nombres,string piezas,vector<string> movimientos){
    file("bitacoraPartidas.txt",ios::app);
    if(file.is_open()==false){
        file.open();
    }
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