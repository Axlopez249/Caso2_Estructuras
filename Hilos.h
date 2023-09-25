#include <iostream>
#include <string>
#include <vector>
#include "lista.h"
#include "queue.h"
#include "stack.h"
#include "carro.h"
#include "reseta.h"
#include <fstream>
#include <nlohmann/json.hpp>
//son para generar los numeros aleatorios
#include <cstdlib> // Necesario para srand() y rand()
#include <ctime>   // Necesario para time()
//estos son para el hilo
#include <thread>
#include <chrono>

using namespace std;

void generar_carros(vector<Reseta>& presetas,vector<Carro>& carros){

    ifstream archivo_json("JSON.json");

    if (!archivo_json.is_open()) {
        cerr << "No se pudo abrir el archivo JSON." << endl;
        return;
    }

    json configuracion;
    archivo_json >> configuracion;
    
    json carros_json = configuracion["Configuracion"]["Carros"];
    json resetas_json = configuracion["Configuracion"]["Resetas"];

    //usa un vector para meter los objetos de tipo reseta
    for (auto& reseta_json : resetas_json) {
        string nombre = reseta_json["Nombre"];
        int precio = reseta_json["Precio"];
        vector<string> ingredientes = reseta_json["Ingredientes"];

        // Crear un objeto Reseta y agregarlo a la lista
        Reseta reseta = new Reseta(nombre, precio, ingredientes);
        presetas.push_back(reseta);

    } 

    //usa un vector para meter los objetos de tipo carro
    for (auto& carro_json : carros_json) {
        Carro carro = new Carro(carro_json["Nombre"], carro_json["Hora"]);
        carros.push_back(carro);
    }
    return;
}

void ingresar_cola(vector<Carro> &pcarro, vector<Reseta> &preseta, Queue<string[]> *pcola_carros){

    int contador=0;
    string[2] elemento_cola;

    while (contador<=5){
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        // Generar un número aleatorio entre 0 y 3
        int numeroAleatorio = std::rand() % 4;

        elemento_cola[0] = pcarro[contador];
        elemento_cola[1] = preseta[numeroAleatorio];
        pcola_carros->enqueue(&elemento_cola);
        contador++;

        // Pausa el hilo durante un segundo
        this_thread::sleep_for(chrono::seconds(5));
    }
    
    
}

    //Falta relacionar las resetas con los carros
    //Falta crear un tiempo
    //Falta ir sacando los carros y poniendolos en la cola con su reseta de alguna forma
    //Que llegue a la ventanilla con su cierto tiempo
    //Hay que agregar en el json el tiempo que se tarda en la realidad y en la simulacion
    //por ejemplo en realidad 10 segundos son 5 minutos y así para que tenga fluidez

    //Secuencia
    //saco datos carros y resetas
    //El carro tiene que llevar el nombre de la orden
