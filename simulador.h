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

#include "json.hpp"

#include "carro.h"
//#include "reseta.h"
#include "ventanillaSolicitud.h"

using namespace std;

class simulador
{
private:
    List<ventanillaS *> *ventanillas;
    ConfigSimulacion config;
    ConfigGeneradorCarros configCarros
    int cantidadCarros;
    int carrosInvertalo;

public:
    Simulador(ConfigJson *pConfig, Restaurant *currentRestaurant)
    {
        config = pconfig.getConfigSimulacion();
        configCarros = config.getConfigCarros();
        ventanillas = new List<ventanillaS>();

        // recorrer la cantidad de ventanillas y crearlas
        // for por cantidad de ventanillas (
        // nueva = new ventanillaS(pConfig->,,,);
        // nueva.setRestaurant();
        //     ventanillas->add(nueva)
        //
        //)

        // aqui creo el hilo que va a generar los carros y le hago start
        for (int i = 0; i < config.ventanillas; i++)
        {
            ventanillaS nueva_ventanilla = new ventanillaS(pconfig.getcomidasPesadas(), config.getBebidas(), config.getpostres(),
             config.getextras(), configCarros.min, configCarros.max);
            nueva_ventanilla.setRestaurant(currentRestaurant);
            ventanillas->add(nueva_ventanilla);
        }

        std::thread miHilo(generar_carros);
        miHilo.join();
        
    }

    void generar_carros()
    {
        while (true)
        {
            //Se generan carros de forma infinita cada un intervalo de tiempo que se transforma a milisegundo
            for (int i = 0; i <= configCarros.cantidad; i++)
            {
                carro *carro = new carro();
                //Aqui se continua pero no tengo muy clara la idea

            }
            std::this_thread::sleep_for(std::chrono::milliseconds(configCarros.intervalo*60*1000));
            
        }
        
        // Se generan carros para la simulacion en forma infinita
        // Se van metiendo cada carro ventanilla por ventanilla
    }

    void ingreso_ventanilla(Queue<string[]> *pColaCarros, Queue<string[]> *pColaCarros2)
    {
        // Se ingresan los carros a la ventanilla
        // Aqui voy tomando las colas de lo carros que van ingresando
        // Voy asignandoles una orden para pasarlos al restaurante
        // El carro pasa a cola de espera mientras se prepara la comida
    }

    void ingreso_restaurant(vector<string> orden)
    {
        // Aqui se toma cada cosa de la orden y se va apilando segun un orden que tiene el restaurante
        // Se toma en cuenta el tiempo del estado que viene en las reglas del json con un numero random
        // Despues de apilado todo y teniendo el id del carro se busca en la cola de espera y se le hace dequeue
        // colocando el ultimo estado como true y llevando su comida apilada
    }

    void tiempo_ventanilla(vector<Carro> &pCarro)
    {
        // Se toma el tiempo de atencion de cada carro
    }
};