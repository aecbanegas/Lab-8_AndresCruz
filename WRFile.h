#ifndef WRFILE_H
#define WRFILE_H
#include <fstream>
#include <string>
#include <vector>
#include "Partida.h"
using std::vector;
using std::string;
using std::fstream;
using std::ios;
class WRFile{
    private:
        fstream file;
    public:
        WRFile();
        void leerArchivo(vector<Partida*>&);
        void escribirArchivo(string,string,vector<string>);
};
#endif