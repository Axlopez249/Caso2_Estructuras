#include <iostream>
#include <string>
#include "lista.h"
#include "reseta.h"

using namespace std;

class Restaurant{
    private:
        string nom_orden;
        int precio;
        vector<string> ingredientes_orden;
        vector<string> orden_orden: //este es el orden de las ordenes
        vector<Reseta> resetas;
    public:
        Restaurant(vector<Reseta> &presetas, vector<string> &porden_orden){
            resetas = presetas;
            orden_orden = porden_orden;
        }

        void conocerOrden(string porden){
            nom_orden = porden;

            for (Reseta elemento_reseta : resetas){
                if (elemento_reseta.get_nom() == nom_orden){
                    precio = elemento_reseta.getPrecio();
                    ingredientes_orden = elemento_reseta.getIngredientes();
                    cocinar();
                }
                ;
            }
            
        }

        void cocinar(){
            //va apilando la comida en una pila segun los ingredientes
            //segun el orden que se tiene, se apila en la pila
            Stack <string> *comida_apilada = new List<string>();
            
            //Esto es para ir metiendo en la pila de comida de entrega los ingredientes solicitados
            for (string orden : orden_orden){
                int contador = 0;
                for (string ingrediente : ingredientes_orden){
                    if (orden == ingrediente){
                        comida_apilada->push(&orden);
                        ingredientes_orden[contador] = "";
                        break;
                    }
                    contador++;
                }
                    
            }
            
        }

        

};