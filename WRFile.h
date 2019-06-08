#ifndef WRFILE_H
#define WRFILE_H
#include "Partida.h"
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
        vector<Partida*> leerArchivo();
};
#endif