#ifndef estado 
#define estado
#include <string>
#include <iostream>



using namespace std;

class estado {
    private:
        string tipo;
        int min;
        int max;
        bool used = false;


    public:
        Estado(string pTipo, int pMin, int pMax, bool pUsed){
            //Se estructura el estado
        }

        int get_tipo(){
            // return tipo
        }

        int get_min(){
            // return min
        }

        int get_max(){
            // return max
        }

        int get_used(){
            //return used
        }
    
};

#endif