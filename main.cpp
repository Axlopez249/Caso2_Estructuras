#include <iostream>
#include <string>
#include <vector>
#include "Colas.h"

using namespace std;

int main(){
    pruebas *pruebita = new pruebas(5,7);
    cout << pruebita->primerNum() << endl;
}