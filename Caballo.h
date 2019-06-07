#include "Pieza.h"
#ifndef CABALLO_H
#define CABALLO_H
class Caballo:public Pieza{
    public:
        virtual bool validarMovimiento(string,Pieza***);
        Caballo();
};
#endif
