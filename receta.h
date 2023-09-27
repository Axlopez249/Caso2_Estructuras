#ifndef reseta 
#define cant 3
#include <string>
#include <iostream>

using namespace std;

class Reseta {
    private:
        vector<string> refrescos;
        vector<string> platosFuerte;
        vector<string> platosSuave;
        vector<strign> postres;
        vector<string> ingredientes;
    public:
        Reseta(){
            //Se crea la receta
            //Aquí se  extrae  la info del json
            //Se guarda en los vectores para luego ser usados en ventanilla y asiginar orden al vehiculo
        }
        vector<string> getIngredientes(){
            //return ingredientes
        }


        vector<string> getplatosFuerte(){
            //return platosFuerte
        }

        vector<string> getplatosSuave(){
            //return platosSuave
        }

        vector<string> getpostres(){
            //return postres
        }

        vector<string> getrefrescos(){
            //return refrescos
        }





    
};

#endif