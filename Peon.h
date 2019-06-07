#include "Pieza.h"
#ifndef PEON_H
#define PEON_H
class Peon:public Pieza{
    public:
        virtual bool validarMovimiento(string,Pieza***);
        Peon();
};
#endif
