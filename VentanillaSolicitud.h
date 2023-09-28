#include <iostream>
#include <string>
#include "lista.h"
#include "restaurant.h"

using namespace std;

class ventanillaS{
    private:
        int id_carro;
        int id_orden; //Los nombres de las recetas son un string no un int
    public:
        ventanillaS(){
        }

        void procesarOrden(vector<string> &refrescos,vector<string> &fuerte,vector<string> &suave,vector<string> &postres,Restaurant pRestaurant, Queue<Carro> *pColaCarros){
            //Se extrae el carro de la cola y se le asigna una orden
            //se procesa el elemento carro con su orden
            //Luego se usa el .h restaurant para prepararla
        }

        int getCarro(){
            //return id_carro
        }

        int getOrden(){
            //return id_orden
        }
        

};