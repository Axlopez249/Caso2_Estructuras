#ifndef _SIMULADOR_
#define _SIMULADOR_ 1

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Usados para el hilo
#include <thread>
#include <chrono>
#include <mutex> // Necesario para la protección del mutex
#include <memory> // Necesario para std::shared_ptr


// Usados para srand(), rand() y time()
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>


//#include "queue.h"
//#include "stack.h"
#include "lista.h"
#include "json.hpp"
#include "configJson.cpp"
#include "ConfigGeneradorCarros.h"
#include "ConfigSimulacion.h"
#include "configTiempo.h"
#include "Alimento.h"
#include "restaurant.h"
#include "carro.h"
#include "ventanillaSolicitud.h"
#include "Node.h"

using namespace std;
template <typename T> 
class simulador
{
private:

    std::mutex mtx;

    List<configTiempo> *lista_tiempos;
    List<ventanillaSolicitud > *ventanillas;
    ConfigGeneradorCarros configCarros;
    ConfigSimulacion config;
    
    int cantidadCarros;
    int carrosInvertalo;
    int randomOrden;

    List<string> *bebidas;
    List<string> *comidasPesadas;
    List<string> *postres;
    List<string> *extras; 
    //List<string> *stack = new List<string>;
    //Stack<string> *pilaBolsa = stack;
    configTiempo *tiempoTomandoOrden;
    Queue<Carro> *colaCarro;
    
public:
    simulador(ConfigJson *pConfig, Restaurant *currentRestaurant, Queue<Carro>*colaEsperaCarro)
    {
        
        config = pConfig->getConfigSimulacion();
        configCarros = pConfig->getConfigCarros();
        ventanillas = new List<ventanillaSolicitud>();
        lista_tiempos = pConfig->getConfigTiempo();
        colaCarro = colaEsperaCarro;

        comidasPesadas = pConfig->getcomidasPesadas();
        bebidas = pConfig->getBebidas();
        postres = pConfig->getpostres();
        extras = pConfig->getextras();

        
        
 
        

        //LLamo esta funcion para saber cual es el tiempo que debo extraer para crear las ventanillas
        configTiempo *tiempoVentanilla = lista_tiempos->searchValue("Haciendo fila");

        //LLamo esta funcion para saber cual es el tiempo que debo extraer para cocinar en el restaurante
        configTiempo *tiempoRestaurant = lista_tiempos->searchValue("En espera");

        tiempoTomandoOrden = lista_tiempos->searchValue("Solicitando la orden");


        //se saca el random
        std::random_device rd;
        std::mt19937 gen(rd()); // Mersenne Twister 19937 generator

        
        // Crear un objeto de distribución uniforme dentro del rango
        std::uniform_int_distribution<> dis(tiempoTomandoOrden->min, tiempoTomandoOrden->max);
        
        // Generar números aleatorios usando el generador y la distribución
        randomOrden = dis(gen);
        
        int tmin = tiempoVentanilla->min;
        int tmax = tiempoVentanilla->max;
        
        //Aqui incluyo los valores en el restaurante
        currentRestaurant->setMax(tiempoRestaurant->max);
        currentRestaurant->setMin(tiempoRestaurant->min);
    
        // aqui creo el hilo que va a generar los carros y le hago start
        
        for (int i = 0; i < config.ventanillas; i++)
        {
            
           ventanillaSolicitud *nueva_ventanilla = new ventanillaSolicitud(i, comidasPesadas, bebidas, postres,
             extras, tmin, tmax);
            //cout<<i<<endl;
            nueva_ventanilla->setRestaurant(currentRestaurant);
            ventanillas->add(nueva_ventanilla);
            //cout<<ventanillas->getSize();
        }

        
    }


    void generar_carros() {
        int carroID = 1;
        while (true) {
            //std::lock_guard<std::mutex> lock(sim->getMutex());
            for (int i = 0; i < configCarros.cantidad; i++)
            {
                Carro* carro = new Carro(carroID++);
                colaCarro->enqueue(carro);
            }
            //cout<<"hola1"<<endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(configCarros.intervalo * 1000));
        }
    }



    void ingreso_ventanilla(){
        while (true) {
            //std::lock_guard<std::mutex> lock(sim->getMutex());
            if (!colaCarro->isEmpty()) {

                for (int i = 0; i < ventanillas->getSize(); ++i) {
                    
                    //Me daba error el lista.h porque no funcionaba el include de ventanilla por lo que no me leia el objeto
                    Node<ventanillaSolicitud>* current = ventanillas->getFirst();
                    int contadorLocal = 0;
                    ventanillaSolicitud *ventanilla;
                    
                    while (current != nullptr) {
                        if (i == contadorLocal) {
                            //Se inserta en el nodo el carro
                            //current->getData()->addCarro(carro);
                            ventanilla = current->getData();
                            ventanilla->addCarro(colaCarro->dequeue());
                            break;
                        }
                        contadorLocal++;
                        current = current->getNext();
                    }


                    std::cout << "Ingresando carro a ventanilla " << i << std::endl;
                }
                cout<<"hola"<<endl;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(randomOrden* 1000));
        }

    }

/*
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
                pilaBolsa.push(comida);
            }
        }

        //For para agregar los extras        
        for (const string& comida : orden){
            if (find(extras.begin(), extras.end(), comida) != extras.end()){
                pilaBolsa->push(comida);
            }
            
        }
        
        //For para agregar los postres
        for (const string& comida : orden){
            if (find(postres.begin(), postres.end(), comida) != postres.end()){
                pilaBolsa->push(comida);
            }
        }

        //For para agregar las bebidas
        for (const string& comida : orden){
            if (find(bebidas.begin(), bebidas.end(), comida) != bebidas.end()){
                pilaBolsa->push(comida);
            }
        }
    }

    void tiempo_ventanilla(vector<Carro> &pCarro)
    {
        // Se toma el tiempo de atencion de cada carro
    }*/
};

#endif