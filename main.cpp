#include <iostream>
#include <string>
#include <vector>
#include "lista.h"
#include "orden.cpp"
#include "configJson.cpp"
//#include "restaurant.h"
#include <thread>
#include <chrono>

using namespace std;

int main(){

    //Creacion de la cola para las ordenes de los restaurantes
    Queue<orden*> listOrders = new List<orden*>();

    ConfigJson *config = new ConfigJson();
    Restaurant *resta = new Restaurant(listOrders);
    Simulador *mainSim = new Simulador(config, resta);

    //Queue<string[]> *cola_carros1 = new List<string[]>();
    //Queue<string[]> *cola_carros2 = new List<string[]>();

    //lo siguiente es que vaya entrando a la ventanilla de solicitud
    //para eso se toman las colas de carro y con cada cierto tiempo se van pasando al restaurante



    return 0;

}