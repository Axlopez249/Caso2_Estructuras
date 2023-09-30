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
    List<string> *comidapesada;
    List<string> *bebida;
    List<string> *postre;
    List<string> *extra;
    // estado de orden

public:
    List<string> order(Carro *pCarro, int pNumero, List<string> *pPostre, List<string> *pBebida, List<string> *pExtra, List<string> *pComidaPesada ){
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