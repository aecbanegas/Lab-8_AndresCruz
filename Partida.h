#ifndef PARTIDA_H
#define PARTIDA_H
#include <string>
#include "WRFile.h"
#include <vector>
using std::string;
using std::vector;
class Partida{
    private:
        string nombre;
        string pieza;
        vector<string> movimientos;
    public:
        void guardarPartida(WRFile*);
        Partida(string,string);
        void setMovimientos(vector<string>);
        void setNombre(string);
        void setPieza(string);
        string getNombre();
        Partida();
};
#endif