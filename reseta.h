#ifndef reseta 
#define cant 3
#include <string>
#include <iostream>

using namespace std;

class reseta {
    private:
        vector<string> bebida;
        vector<string> comidaPesada;
        vector<string> extra;
        vector<strign> postre;
    public:
        Reseta(){
            //Se crea la receta
            //Aquí se  extrae  la info del json
            //Se guarda en los vectores para luego ser usados en ventanilla y asiginar orden al vehiculo
        }
        vector<string> getIngredientes(){
            //return ingredientes
        }


        vector<string> getComidaPesada(){
            //return platosFuerte
        }

        vector<string> getPostre(){
            //return platosSuave
        }

        vector<string> getExtra(){
            //return postres
        }

        vector<string> getBebida(){
            //return refrescos
        }

    
};

#endif