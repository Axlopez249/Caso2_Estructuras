#include "lista.h" // Asegúrate de incluir el archivo de encabezado correcto que define tu clase List
#include <iostream>
#include <string>
#include <vector>

#include <iostream>
#include <string>
#include "lista.h"
#include "restaurant.h"



#include <thread>
#include <chrono>

using namespace std;



int main() {

    Queue<orden>* listaEntrante = new List<orden>();
    listaEntrante->enqueue(new string("Coca"));
    listaEntrante->enqueue(new string("Hamburguesa"));
    listaEntrante->enqueue(new string("Taco"));
    Restaurant *resta = new Restaurant(listaEntrante);

    // Agregar otros elementos de orden predefinida aquí

    
    // Agregar otros elementos de la lista de entrada aquí

    // Acomodar la lista de entrada según la lista de orden predefinida
    acomodarLista(listaEntrante);

    // Imprimir la lista acomodada
    cout << "Lista Acomodada:" << endl;
    listaEntrante->printValues();

    return 0;
}
