#include <string>
#include <sstream>
using std::stringstream;
using std::string;
#ifndef PIEZA_H
#define PIEZA_H
class Pieza{
    protected:
        string nombre;
        string color;
    public:
        virtual bool validarMovimiento(string,Pieza***)=0;
        virtual string getColor()=0;
        virtual string toString()=0;
        virtual string getNombre()=0;
};
#endif