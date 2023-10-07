#ifndef CONFIGJSON
#define CONFIGJSON 1

#include "json.hpp"
#include <fstream>
#include <iostream>
#include "lista.h"
#include "ConfigSimulacion.h"
#include "ConfigGeneradorCarros.h"
#include "configTiempo.h"


using json = nlohmann::json;

class ConfigJson
{
private:
    ConfigSimulacion currentConfigSimulacion;
    ConfigGeneradorCarros currentConfigGeneradorCarros;

    List<string> *bebidas;
    List<string> *comidasPesadas;
    List<string> *postres;
    List<string> *extras;

    List<configTiempo> *tiempos;

    void parseAllJson()
    {
        // cargar todo en estructuras
        //tiempos = new List<string>(); //Esto da error porque crea dos listas de tipo diferente con el mismo nombre
        //y no creo que esta lista tipo string sea necesaria

        std::ifstream file("JSON.json"); // Abre el archivo JSON
        if (file.is_open()) {
            try {
                // Lee el contenido del archivo en un string
                std::string jsonStr((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

                // Parsea el string JSON
                json jsonData = json::parse(jsonStr);

                // Acceder a los elementos del JSON
                for (const auto& pTiempo: jsonData["Tiempos"])
                {
                    configTiempo tiempo;
                    tiempo.tipo = pTiempo["Tipo"];
                    tiempo.min = pTiempo["Duracion_min"];
                    tiempo.max = pTiempo["Duracion_max"];
                    tiempos->add(&tiempo);
                }

                //sacar para generarcarros
                for (const auto& generador : jsonData["GeneradorCarros"]) 
                {
                    currentConfigGeneradorCarros.cantidad = generador["Cantidad"];
                    currentConfigGeneradorCarros.intervalo = generador["interval"];
                    currentConfigGeneradorCarros.tiempoMax = generador["TiempoMax"];
                    currentConfigGeneradorCarros.tiempoMin = generador["TiempoMin"];
                }

                //Para sacar el configsimulacion
                for (const auto& simu : jsonData["Simulacion"]) 
                {
                    currentConfigSimulacion.Unidad = simu["Unidad"];
                    currentConfigSimulacion.RelacionReal = simu["RelacionReal"];
                    currentConfigSimulacion.ventanillas = simu["ventanillas"];

                }

            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }

            file.close(); // Cierra el archivo después de usarlo
        } else {
            std::cerr << "No se pudo abrir el archivo." << std::endl;
        }
        
    }

public:
    ConfigJson()
    {

        // cargar el json al objecto
        // inicializo las listas
        bebidas = new List<string>();
        comidasPesadas = new List<string>();
        postres = new List<string>();
        extras = new List<string>();

        //comienzo a extraer  la info del json
        std::ifstream file("JSON.json"); // Abre el archivo JSON
        if (file.is_open()) {
            try {
                // Lee el contenido del archivo en un string
                std::string jsonStr((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

                // Parsea el string JSON
                json jsonData = json::parse(jsonStr);
                //Para las comidas
                for (const auto& postre : jsonData["Postres"]) {
                    postres->add(new string (postre));
                }
                for (const auto& comida : jsonData["ComidaPesada"]) {
                    comidasPesadas->add(new string(comida));
                }
                for (const auto& extra : jsonData["Extra"]) {
                    extras->add(new string(extra));
                }
                for (const auto& bebida : jsonData["Bebida"]) {
                    bebidas->add(new string(bebida));
                }
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }

            file.close(); // Cierra el archivo después de usarlo
        } else {
            std::cerr << "No se pudo abrir el archivo." << std::endl;
        }

        parseAllJson();
    }

    ConfigSimulacion getConfigSimulacion()
    {
        return currentConfigSimulacion;
    }

    ConfigGeneradorCarros getConfigCarros(){
        return currentConfigGeneradorCarros;
    }

    List<configTiempo> *getConfigTiempo(){
        return tiempos;
    }

    List<string> *getBebidas()
    {
        return bebidas;
    }

    List<string> *getcomidasPesadas()
    {
        return comidasPesadas;
    }

    List<string> *getpostres()
    {
        return postres;
    }

    List<string> *getextras()
    {
        return extras;
    }

    int getMinTiempoFilaVentanilla()
    {
        return currentConfigGeneradorCarros.tiempoMin;
    }

    int getMaxTiempoFilaVentanilla()
    {
        return currentConfigGeneradorCarros.tiempoMax;
    }

    
};

#endif