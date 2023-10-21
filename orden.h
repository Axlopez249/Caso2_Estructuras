#ifndef _ORDEN_
#define _ORDEN_ 1
#include <string>
#include <iostream>
#include "carro.h"
#include <vector>

using namespace std;

class orden
{
private:
    Carro* carro;
    vector<string> comida;
    vector<string> bebida;
    vector<string> postre;
    vector<string> extra;
    
    // estado de orden

public:
    orden(Carro* pcarro, vector<string> pcomida, vector<string> pbebida, vector<string> ppostre, vector<string> pextra){
        
        
        //Se crea una orden
        carro = pcarro;
        comida = pcomida;
        bebida = pbebida;
        postre = ppostre;
        extra = pextra;
        
        
    }


    Carro* getCarro(){
        return carro;
    }

    vector<string> getBebida(){
        return bebida;
    }

    vector<string> getExtra(){
        return extra;
    }

    vector<string> getPostre(){
        return postre;
    }

    vector<string> getComida(){
        return comida;
    }



};

#endif