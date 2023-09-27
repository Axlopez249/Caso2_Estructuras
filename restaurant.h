#include <iostream>
#include <string>
#include "lista.h"
#include "reseta.h"

using namespace std;

class Restaurant{
    private:
        string nom_orden; //Se usara dento de conocerOrden para saber que orden se va a cocinar
        int precio;//Se usara en conocerOrden tambien
        vector<string> ingredientes_orden;
        vector<string> orden_orden: //este es el orden de las ordenes
        vector<Reseta> resetas;
    public:
        Restaurant(vector<Reseta> &pResetas, vector<string> &pOrden_orden){
            //Se crean las ordenes del restaurante
        }

        void conocerOrden(string pOrden){
            //Para saber con que orden se trabaja
            //Se llama a coninar() para acomodar la comida
            
        }

        void cocinar(){
            //Preparacion de las ordenes
        };
}