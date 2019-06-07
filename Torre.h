#include "Pieza.h"
#ifndef TORRE_H
#define TORRE_H
class Torre:public Pieza{
    public:
        virtual bool validarMovimiento(string,Pieza***);
        Torre();
};
#endif
