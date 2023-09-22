#include <iostream>
#include <string>
#include "lista.h"

using namespace std;

class ventanillaS{
    private:
        Queue<string> *colaCarros;
    public:
        ventanillaS(Queue<string> *cola){
            colaCarros = cola;
        }
        

};