#include <string>
using std::string;
#ifndef PIEZA_H
#define PIEZA_H
class Pieza{
    protected:
        string nombre;
    public:
        virtual bool validarMovimiento(string,Pieza**)=0;
};
#endif