#include <iostream>
#include <string>
#include <vector>
#include "VentanillaSolicitud.h"
#include "lista.h"
#include "queue.h"
#include "stack.h"
#include "carro.h"
#include "reseta.h"
#include <fstream>
#include "json.hpp"
//son para generar los numeros aleatorios
#include <cstdlib> // Necesario para srand() y rand()
#include <ctime>   // Necesario para time()
//estos son para el hilo
#include <thread>
#include <chrono>

using namespace std;
using json = nlohmann::json;  // Alias para la biblioteca JSON de nlohmann

// Declaración de las clases Reseta y Carro (asegúrate de que estén definidas en tu código)

void generar_carros(std::vector<Reseta>& presetas, std::vector<Carro>& carros) {
    std::ifstream archivo_json("JSON.json");

    if (!archivo_json.is_open()) {
        std::cerr << "No se pudo abrir el archivo JSON." << std::endl;
        return;
    }

    json configuracion;
    archivo_json >> configuracion;

    json carros_json = configuracion["Configuracion"]["Carros"];
    json resetas_json = configuracion["Configuracion"]["Resetas"];

    // Usa un vector para meter los objetos de tipo reseta
    for (auto& reseta_json : resetas_json) {
        std::string nombre = reseta_json["Nombre"];
        int precio = reseta_json["Precio"];
        std::vector<std::string> ingredientes = reseta_json["Ingredientes"];

        // Crear un objeto Reseta y agregarlo a la lista
        Reseta reseta(nombre, precio, ingredientes);  // Suponiendo que Reseta tiene un constructor adecuado
        presetas.push_back(reseta);
    }

    // Usa un vector para meter los objetos de tipo carro
    for (auto& carro_json : carros_json) {
        std::string nombre = carro_json["Nombre"];
        std::string hora = carro_json["Hora"];
        Carro carro(nombre, hora);  // Suponiendo que Carro tiene un constructor adecuado
        carros.push_back(carro);
    }
}


void ingresar_cola(vector<Carro> &pcarro, vector<Reseta> &preseta, Queue<string[]> *pcola_carros){

    int contador=0;
    

    while (contador<=5){
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        // Generar un número aleatorio entre 0 y 3
        int numeroAleatorio = std::rand() % 4;

        Carro carro_1 = pcarro[contador];
        Reseta reseta = preseta[numeroAleatorio];

        string elemento_cola[2];

        elemento_cola[0] = carro_1.getNom();
        elemento_cola[1] = reseta.getNom();
        
        pcola_carros->enqueue(&elemento_cola);
        cout << elemento_cola[0] << endl;
        cout << elemento_cola[1] << endl;
        contador++;

        // Pausa el hilo durante un segundo
        this_thread::sleep_for(chrono::seconds(5));
    }
    
    
}

void ingreso_ventanilla(Queue<string[]> *cola1, Queue<string[]> *cola2, Restaurant prestaurante){

    //se crean las 2 ventanillas de solicitud. Donde se recibe la comida
    ventanillaS ventanilla_1 = new ventanillaS();
    ventanillaS ventanilla_2 = new ventanillaS();

    //se crea el restaurante como un objeto que prepara y acomoda la comida

    //va a tomar la orden segun un tiempo random que se extrae igualmente del json que de hecho falta eso
    //extraer los tiempos para usar los random segun esas reglas
    while (!cola1->isEmpty())
    {
        string elemento_cola[] = cola1->dequeue();
        //se ingresa a ventanilla para que vaya a procesar la orden con respecto al restaurant
        ventanilla_1.procesarOrden(elemento_cola, prestaurante);

        
    }
    
}

    //Falta crear un tiempo
    //Que llegue a la ventanilla con su cierto tiempo
    //Hay que agregar en el json el tiempo que se tarda en la realidad y en la simulacion
    //por ejemplo en realidad 10 segundos son 5 minutos y así para que tenga fluidez

    //Secuencia
    //saco datos carros y resetas
    //El carro tiene que llevar el nombre de la orden
    //Llega a la ventanilla. Debe haber una funcion grande que cree 2 clases de tipo ventanilla_solicitud. 
