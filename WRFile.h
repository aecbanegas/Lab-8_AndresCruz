#include "Partida.h"
#ifndef WRFILE_H
#define WRFILE_H
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class WRFile{
    private:
        fstream file;
    public:
        WRFile();
        void escribirArchivo(string,string,vector<string>);
        void leerArchivo(vector<Partida*>);
};
#endif