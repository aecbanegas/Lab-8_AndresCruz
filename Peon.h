#include "Pieza.h"
#ifndef PEON_H
#define PEON_H
class Peon:public Pieza{
    private: 
        int cont;
    public:
        virtual bool validarMovimiento(string,Pieza***);
        void setColor(string);
        virtual string getColor();
        virtual string toString();
        virtual string getNombre();
        Peon();
        Peon(string);
};
#endif
