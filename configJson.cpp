#ifndef CONFIGJSON
#define CONFIGJSON 1




#include <fstream>

#include <iostream>

#include <string>
#include "lista.h"
#include "json.hpp"

#include "ConfigGeneradorCarros.h"

#include "configTiempo.h"
#include "ConfigSimulacion.h"
#include "Alimento.h"



using json = nlohmann::json;
using namespace std;

class ConfigJson
{
private:

    ConfigSimulacion currentConfigSimulacion;
    ConfigGeneradorCarros currentConfigGeneradorCarros;
    
    List<string> *bebidas;
    List<string> *comidasPesadas;
    List<string> *postres;
    List<string> *extras;
    List<string> *acomodo;

    List<configTiempo> *tiempos = new List<configTiempo>();

    

public:
    ConfigJson()
    {
     
        // cargar el json al objecto
        // inicializo las listas
        bebidas = new List<string>();
        postres = new List<string>();
        extras = new List<string>();
        comidasPesadas = new List<string>(); 
        acomodo = new List<string>();

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
                    postres->add(new string(postre));
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
                for (const auto& ordenAcomodo : jsonData["Acomodo"]) {
                    acomodo->add(new string(ordenAcomodo));
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
                    configTiempo* tiempo = new configTiempo(); //aqui pase esto a puntero y se soluciono el problema
                
                    tiempo->tipo = pTiempo["Tipo"].get<string>();
                    tiempo->min = pTiempo["Duracion_min"].get<int>();
                    tiempo->max = pTiempo["Duracion_max"].get<int>();
                    
                    tiempos->add(tiempo);
                    
   
                }
                
                //sacar para generarcarros
                
                currentConfigGeneradorCarros.cantidad = jsonData["GeneradorCarros"]["Cantidad"].get<int>();
                currentConfigGeneradorCarros.intervalo = jsonData["GeneradorCarros"]["interval"].get<int>();
                currentConfigGeneradorCarros.tiempoMax = jsonData["GeneradorCarros"]["TiempoMax"].get<int>();
                currentConfigGeneradorCarros.tiempoMin = jsonData["GeneradorCarros"]["TiempoMin"].get<int>();
                
                //Para sacar el configsimulacion
                
                currentConfigSimulacion.Unidad = jsonData["Simulacion"]["Unidad"].get<string>();
                currentConfigSimulacion.relacionReal = jsonData["Simulacion"]["RelacionReal"].get<float>();
                currentConfigSimulacion.ventanillas = jsonData["Simulacion"]["ventanillas"].get<int>();

            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }

            file.close(); // Cierra el archivo después de usarlo
        } else {
            std::cerr << "No se pudo abrir el archivo." << std::endl;
        }
        
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

    List<string> *getacomodo()
    {
        return acomodo;
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