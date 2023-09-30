#include "json.hpp"
#include <fstream>
#include <iostream>
#include "lista.h"

using json = nlohmann::json;

struct ConfigSimulacion
{
    string Unidad;
    float RelacionReal;
    int ventanillas;
};

struct ConfigGeneradorCarros
{
    int cantidad;
    int intervalo;
    int tiempoMin;
    int tiempoMax;
};

struct configTiempo
{
    string tipo;
    int min;
    int max;
};


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
        tiempos = new List<string>();

        std::ifstream file("JSON.json"); // Abre el archivo JSON
        if (file.is_open()) {
            try {
                // Lee el contenido del archivo en un string
                std::string jsonStr((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

                // Parsea el string JSON
                json jsonData = json::parse(jsonStr);

                // Acceder a los elementos del JSON
                for (const auto& tiempo: jsonData["Tiempos"])
                {
                    configTiempo tiempo;
                    tiempo.tipo = tiempo["Tipo"];
                    tiempo.min = tiempo["Duracion_min"];
                    tiempo.max = tiempo["Duracion_max"];
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
                    currentConfigSimulacion.Unidad = simu["Unidad"]
                    currentConfigSimulacion.RelacionReal = simu["RelacionReal"]
                    currentConfigSimulacion.ventanillas = generador["ventanillas"];

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

    List<string> *getRefrescos()
    {
        return bebidas;
    }

    int getMinTiempoFilaVentanilla()
    {
        return currentConfigGeneradorCarros.tiempoMin;
    }

    int getMaxTiempoFilaVentanilla()
    {
        return currentConfigGeneradorCarros.tiempoMax;
    }

    //.. and so on
};