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
    List<configTiempo> * lista_tiempos;
    List<ventanillaS *> *ventanillas;
    ConfigSimulacion config;
    ConfigGeneradorCarros configCarros;
    
    


    int cantidadCarros;
    int carrosInvertalo;


public:
    Simulador(ConfigJson *pConfig, Restaurant *currentRestaurant)
    {
        config = pconfig.getConfigSimulacion();
        configCarros = config.getConfigCarros();
        ventanillas = new List<ventanillaS>();
        lista_tiempos = pConfig.getConfigTiempo();

        //LLamo esta funcion para saber cual es el tiempo que debo extraer para crear las ventanillas
        configTiempo *tiempoVentanilla = lista_tiempos->searchValue("Haciendo fila");

        //LLamo esta funcion para saber cual es el tiempo que debo extraer para cocinar en el restaurante
        configTiempo *tiempoRestaurant = lista_tiempos->searchValue("En espera");
        //Aqui incluyo los valores en el restaurante
        currentRestaurant->setMax(tiempoRestaurant->max);
        currentRestaurant->setMin(tiempoRestaurant->min);


        // recorrer la cantidad de ventanillas y crearlas
        for (int i = 0; i < config.ventanillas; i++) {
            vNueva = new ventanillaS();
            vNueva.setRestaurant();
            ventanillas->add(vNueva);
        }

        

        // aqui creo el hilo que va a generar los carros y le hago start
        for (int i = 0; i < config.ventanillas; i++)
        {
            ventanillaS nueva_ventanilla = new gen_ventanilla(i,config.getcomidasPesadas(), config.getBebidas(), config.getpostres(),
             config.getextras(), tiempoVentanilla.min, tiempoVentanilla.max);
            nueva_ventanilla.setRestaurant(currentRestaurant);
            ventanillas->add(nueva_ventanilla);
        }

        std::thread miHilo(generar_carros);
        miHilo.join();
        
    }



    void generar_carros(int pVentanilla){
        int carroID = 1;
        while (true){
            //Se generan carros de forma infinita cada un intervalo de tiempo que se transforma a milisegundo
            for (int i = 0; i <= configCarros.cantidad; i++){
                Carro *carro = new carro(carroID++);
                int ventanillaID = carroID % config.ventanillas;
                //Ingeso a las colas de ventanillas
                if (ventanillaID >= 0 && ventanillaID <config.ventanillas){
                    ventanillas[ventanillaID].addCarro(carro);
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(configCarros.intervalo*60*1000)); 
        }
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