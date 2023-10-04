#ifndef Order
#define Order 0
#include <string>
#include <iostream>
#include "carro.h"
#include <vector>

using namespace std;

class orden
{
private:
    Carro *carro;

    int number;
    string comida;
    string bebida;
    string postre;
    string extra;
    // estado de orden

public:
    List<string> order(Carro *pCarro, string comida, string bebida, string postre, string extra){
        //Se crea una orden
    }

    int getNumero(){
        //Para conseguir el numero de orden
    }

    Carro *getCarro(){
        //para conseguir el carro
    }
};

#endif