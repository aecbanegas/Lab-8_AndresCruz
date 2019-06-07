#include "Pieza.h"
#ifndef REY_H
#define REY_H
class Rey:public Pieza{
    public:
        virtual bool validarMovimiento(string,Pieza***);
        Rey();
};
#endif
