#ifndef _SIMULADOR_
#define _SIMULADOR_ 1

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Usados para el hilo
#include <thread>
#include <chrono>

// Usados para srand(), rand() y time()
#include <cstdlib>
#include <ctime>

#include "lista.h"
#include "queue.h"
#include "stack.h"
#include "configJson.cpp"
#include "ConfigGeneradorCarros.h"
#include "ConfigSimulacion.h"
#include "configTiempo.h"
#include "restaurant.h"
#include "json.hpp"
#include "carro.h"

#include "ventanillaSolicitud.h"

using namespace std;

class simulador
{
private:
    List<configTiempo> * lista_tiempos;
    List<ventanillaS > *ventanillas;
    ConfigSimulacion config;
    ConfigGeneradorCarros configCarros;
    int cantidadCarros;
    int carrosInvertalo;
    List<string> *bebidas;
    List<string> *comidasPesadas;
    List<string> *postres;
    List<string> *extras; 
    List<string> *stack = new List<string>;
    Stack<string> *pilaBolsa = stack;
    
public:
    simulador(ConfigJson *pConfig, Restaurant *currentRestaurant, List<Carro> colaEsperaCarro)
    {
        config = pConfig->getConfigSimulacion();
        configCarros = pConfig->getConfigCarros();
        ventanillas = new List<ventanillaS>();
        lista_tiempos = pConfig->getConfigTiempo();
        

        //LLamo esta funcion para saber cual es el tiempo que debo extraer para crear las ventanillas
        configTiempo *tiempoVentanilla = lista_tiempos->searchValue("Haciendo fila");

        //LLamo esta funcion para saber cual es el tiempo que debo extraer para cocinar en el restaurante
        configTiempo *tiempoRestaurant = lista_tiempos->searchValue("En espera");
        //Aqui incluyo los valores en el restaurante
        currentRestaurant->setMax(tiempoRestaurant->max);
        currentRestaurant->setMin(tiempoRestaurant->min);

        // aqui creo el hilo que va a generar los carros y le hago start
        for (int i = 0; i < config.ventanillas; i++)
        {
            ventanillaS *nueva_ventanilla = new ventanillaS(i,pConfig->getcomidasPesadas(), pConfig->getBebidas(), pConfig->getpostres(),
             pConfig->getextras(), tiempoVentanilla->min, tiempoVentanilla->max);
            nueva_ventanilla->setRestaurant(currentRestaurant);
            ventanillas->add(nueva_ventanilla);
        }

        std::thread miHilo(&simulador::generar_carros, this, colaEsperaCarro);
        miHilo.join();
        
    }



    void generar_carros(List<Carro> colaEsperaCarros){
        int carroID = 1;

        std::this_thread::sleep_for(std::chrono::milliseconds(configCarros.intervalo*60*1000)); 
        while (carroID >= configCarros.cantidad){

            //Se generan carros de forma infinita cada un intervalo de tiempo que se transforma a milisegundo
            for (int i = 0; i <= configCarros.cantidad; i++){
                Carro *carro = new Carro(carroID++);
                colaEsperaCarros.enqueue(*carro);

            }
        }
    }

    void ingreso_ventanilla(List<string> colaEsperaCarros){

        ConfigSimulacion vent;
        int cont = 0;

        while (cont >= vent.ventanillas){
            Carro carro = colaEsperaCarros.dequeue();
            //Se llama a la funcion insertar 
            ventanillas->insertCarroVentanilla(cont, carro);
            cont++;
        }

    }

    void ingreso_restaurant(vector<string> orden)
    {
        ConfigJson comidas;
        bebidas = comidas.getBebidas();
        comidasPesadas = comidas.getcomidasPesadas();
        postres = comidas.getpostres();
        extras = comidas.getextras();
        
        //For para agregar las comidas pesadas
        for (const string& comida : orden){
            if (find(comidasPesadas.begin(), comidasPesadas.end(), comida) != comidasPesadas.end()) {
                pilaBolsa.push(*comida);
            }
        }

        //For para agregar los extras        
        for (const string& comida : orden){
            if (find(extras.begin(), extras.end(), comida) != extras.end()){
                pilaBolsa->push(*comida);
            }
            
        }
        
        //For para agregar los postres
        for (const string& comida : orden){
            if (find(postres.begin(), postres.end(), comida) != postres.end()){
                pilaBolsa->push(*comida);
            }
        }

        //For para agregar las bebidas
        for (const string& comida : orden){
            if (find(bebidas.begin(), bebidas.end(), comida) != bebidas.end()){
                pilaBolsa->push(*comida);
            }
        }
    }

    void tiempo_ventanilla(vector<Carro> &pCarro)
    {
        // Se toma el tiempo de atencion de cada carro
    }
};

#endif