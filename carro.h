#ifndef carro 
#define carro
#include <string>
#include <iostream>
#include "configJson.h"

using namespace std;

class Carro {
    private:
        int id;

    public:
        Carro(int pId): id(pId){}

        int get_id(){
            return id;
        }
    
};

#endif