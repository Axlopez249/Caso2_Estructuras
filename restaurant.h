#include <iostream>
#include <string>
#include "lista.h"
#include "reseta.h"

using namespace std;

class Restaurant{
    private:
        string nom_orden;
        vector<Reseta> resetas;
    public:
        Restaurant(vector<Reseta> &presetas){
            resetas = presetas;
        }

        

};