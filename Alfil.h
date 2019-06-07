#include "Pieza.h"
#ifndef ALFIL_H
#define ALFIL_H
class Alfil:public Pieza{
    public:
        virtual bool validarMovimiento(string,Pieza***);
        Alfil();
};
#endif
