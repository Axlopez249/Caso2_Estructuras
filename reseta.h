#ifndef reseta 
#define cant 3
#include <string>
#include <iostream>

using namespace std;

class Reseta {
    private:
        string nom;
        int precio;
        vector<string> ingredientes;
    public:
        Reseta(string pnombre, int pcant, int pprecio, vector<string> pingre){
            nom = pnombre;
            cantidad = pcant;
            precio = pprecio;
            ingredientes = pingre;
        }
    
};

#endif