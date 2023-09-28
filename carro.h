#ifndef carro 
#define carro
#include <string>
#include <iostream>

using namespace std;

class Carro {
    private:
        int id_carro;
        int id_orden;
        vector<string> orden;

    public:
        Carro(int pid){
            //Se le asigna el id al vehiculo
        }

        int get_id(){
            // return id_carro

        vector<string> getOrden(){
            //return orden;
        }

        int get_idorden(){
            //return id_orden
        }

        void setIdOrden(int porden){
            //id_orden = porden;
        }

        void setOrden(int porden){
            //orden = porden;
        }
    
};

#endif