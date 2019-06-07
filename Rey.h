#include "Pieza.h"
#ifndef REY_H
#define REY_H
class Rey:public Pieza{
    public:
        virtual bool validarMovimiento(string,Pieza***);
        virtual string toString();
        void setColor(string);
        virtual string getColor();
        virtual string getNombre();
        Rey();
        Rey(string);
};
#endif
