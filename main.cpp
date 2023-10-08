

#include <iostream>
#include <string>
#include <vector>
#include "lista.h"
#include "queue.h"
#include "orden.h"
#include "configJson.cpp"
#include "restaurant.h"
#include "simulador.h"
#include <thread>
#include <chrono>

using namespace std;

int main() {

    //Creacion de la cola para las ordenes de los restaurantes
    Queue<orden> *listOrders = new List<orden>();
    Queue<Carro> *colaEsperaCarro = new List<Carro>();

    ConfigJson *config = new ConfigJson();
    Restaurant *resta = new Restaurant::Restaurant(listOrders);
    simulador *mainSim = new simulador::simulador(config, resta); //estas varas dan error tambien

    //Queue<string[]> *cola_carros1 = new List<string[]>();
    //Queue<string[]> *cola_carros2 = new List<string[]>();

    //lo siguiente es que vaya entrando a la ventanilla de solicitud
    //para eso se toman las colas de carro y con cada cierto tiempo se van pasando al restaurante



    return 0;

}
