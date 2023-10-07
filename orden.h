#ifndef _ORDEN_
#define _ORDEN_ 1
#include <string>
#include <iostream>
#include "carro.h"

using namespace std;

class orden
{
private:
    Carro* carro;
    string comida;
    string bebida;
    string postre;
    string extra;
    
    // estado de orden

public:
    orden(Carro* pcarro, string pcomida, string pbebida, string ppostre, string pextra){
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

    string getBebida(){
        return bebida;
    }

    string getExtra(){
        return extra;
    }

    string getPostre(){
        return postre;
    }

    string getComida(){
        return comida;
    }



};

#endif