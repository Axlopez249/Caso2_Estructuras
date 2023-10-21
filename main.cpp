

#include <iostream>
#include <string>
#include "lista.h"
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

    //Listas para las comidas


    ConfigJson *config = new ConfigJson();
    Restaurant *resta = new Restaurant(listOrders);
    simulador<int> *mainSimu = new simulador<int>(config, resta, colaEsperaCarro); 

    
    std::thread generarCarrosThread(&simulador<int>::generar_carros, mainSimu);
    std::thread ingresoVentanillaThread(&simulador<int>::ingreso_ventanilla, mainSimu);

    generarCarrosThread.join();
    ingresoVentanillaThread.join();
    
    

    /*
    List<string> *bebidas;
    List<string> *extras;
    List<string> *postres;
    List<string> *cp;

    bebidas = config->getBebidas();
    extras = config->getextras();
    postres = config->getpostres();
    cp = config->getcomidasPesadas();

    bebidas->printValues();
    extras->printValues();
    postres->printValues();
    cp->printValues();*/

    // Crear un hilo para la función generar_carros
    //td::thread hiloCarros(&simulador::generar_carros, mainSim);
    //hiloCarros.join();


    //Queue<string[]> *cola_carros1 = new List<string[]>();
    //Queue<string[]> *cola_carros2 = new List<string[]>();

    //lo siguiente es que vaya entrando a la ventanilla de solicitud
    //para eso se toman las colas de carro y con cada cierto tiempo se van pasando al restaurante



    return 0;

}