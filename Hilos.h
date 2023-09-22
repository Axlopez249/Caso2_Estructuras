#include <iostream>
#include <string>
#include <vector>
#include "lista.h"
#include "carro.h"
#include "reseta.h"
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;

void generar_carros(){

    ifstream archivo_json("JSON.json");

    if (!archivo_json.is_open()) {
        cerr << "No se pudo abrir el archivo JSON." << endl;
        return 1;
    }

    json configuracion;
    archivo_json >> configuracion;

    vector<Carro> carros;
    vector<Reseta> resetas;

    
    json carros_json = configuracion["Configuracion"]["Carros"];
    json resetas_json = configuracion["Configuracion"]["Resetas"];

    //usa un vector para meter los objetos de tipo reseta
    for (auto& reseta_json : resetas_json) {
        string nombre = reseta_json["Nombre"];
        int precio = reseta_json["Precio"];
        vector<string> ingredientes = reseta_json["Ingredientes"];

        // Crear un objeto Reseta y agregarlo a la lista
        Reseta reseta = new Reseta(nombre, precio, ingredientes);
        resetas.push_back(reseta);

    } 

    //usa un vector para meter los objetos de tipo carro
    for (auto& carro_json : carros_json) {
        Carro carro = new Carro(carro_json["Nombre"], carro_json["Hora"]);
        carros.push_back(carro);
    }

    //Falta relacionar las resetas con los carros
    //Falta crear un tiempo
    //Falta ir sacando los carros y poniendolos en la cola con su reseta de alguna forma
    //Que llegue a la ventanilla con su cierto tiempo
    //Hay que agregar en el json el tiempo que se tarda en la realidad y en la simulacion
    //por ejemplo en realidad 10 segundos son 5 minutos y así para que tenga fluidez
}