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
        Reseta(string pnombre, int pprecio, vector<string> &pingre){
            nom = pnombre;
            precio = pprecio;
            ingredientes = pingre;
        }

        string getNom(){
            return nom;
        }
        int getPrecio(){
            return precio;
        }
        vector<string> getIngredientes(){
            return ingredientes;
        }


    
};

#endif