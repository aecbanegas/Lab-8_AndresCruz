#include "Pieza.h"
#ifndef REINA_H
#define REINA_H
class Reina:public Pieza{
    public:
        virtual bool validarMovimiento(string,Pieza***);
        Reina();
};
#endif