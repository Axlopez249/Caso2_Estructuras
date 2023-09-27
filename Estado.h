#ifndef estado 
#define estado
#include <string>
#include <iostream>

using namespace std;

class Estado {
    private:
        string tipo;
        int min;
        int max;
        bool used = false;

    public:
        Estado(string tipo,int min,int max){
            //Se le asigna el id al veh
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