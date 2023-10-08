#ifndef _CARRO_  
#define _CARRO_ 5
#include <string>
#include <iostream>


using namespace std;

class Carro {
    private:
        int id;

    public:
        Carro(int pId){
            id = pId;
        }

        int get_id(){
            return id;
        }
    
};

#endif