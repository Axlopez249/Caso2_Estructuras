#include <iostream>
#include <string>
#include <vector>
#include "Colas.h"
#include "Pilas.h"

using namespace std;

int main(){
    cola *pruebacola = new cola("C1V1");
    pruebacola->enqueue("C1V2");
    cout << pruebacola->dequeue() << endl;
}