#ifndef carro 
#define carro 1
#include <string>
#include <iostream>

using namespace std;

class Carro {
    private:
        string nom;
        string tiempo_ingreso;
    public:
        Carro(string pnombre, string ptiempo){
            nom = pnombre;
            tiempo_ingreso = ptiempo;
        }
    
};

#endif