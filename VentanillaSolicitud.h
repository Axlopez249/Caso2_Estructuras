#include <iostream>
#include <string>
#include "lista.h"
#include "restaurant.h"

using namespace std;

class ventanillaS{
    private:
        string nom_carro;
        string nom_orden;
    public:
        ventanillaS(){
        }

        void procesarOrden(string [] carro_orden, Restaurant prestaurant){
            //se procesa el elemento carro con su orden
            prestaurant.conocerOrden();
            prestaurant.cocinar();

        }
        

};