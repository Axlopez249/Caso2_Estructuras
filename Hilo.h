#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//Usados para el hilo
#include <thread>
#include <chrono>

//Usados para srand(), rand() y time()
#include <cstdlib>
#include <ctime>

#include "lista.h"
#include "queue.h"
#include "stack.h"

#include "json.hpp"

#include "carro.h"
#include "receta.h"
#include "ventanillaSolicitud.h"


using namespace std;

class hilos{
    private:
        
        Queue<string> *colaCarros;
        Stack<string> *pila;
        List<string> *lista = new List<string>();
    public:

        void generar_carros(Queue<Carro> *pColaCarros, Queue<Carro> *pColaCarros2){
            //Se generan carros para la simulacion...
            //Se van metiendo a la cola de los carros
        }


        void ingreso_ventanilla(Queue<Carro> *pColaCarros, Queue<Carro> *pColaCarros2, Queue<Carro> *colaEspera){
            //Se ingresan los carros a la ventanilla
            //Aqui voy tomando las colas de lo carros que van ingresando
            //Voy asignandoles una orden para pasarlos al restaurante
            //El carro pasa a cola de espera mientras se prepara la comida 
        }

        void ingreso_restaurant(vector<string>orden, Queue<Carro> *colaEspera){
            //Aqui se toma cada cosa de la orden y se va apilando segun un orden que tiene el restaurante
            //Se toma en cuenta el tiempo del estado que viene en las reglas del json con un numero random
            //Despues de apilado todo y teniendo el id del carro se saca de la cola de espera haciendo uso
            //de la otra funincion
        }

        void salidaVehiculo(Queue<Carro> *colaEspera){
            //Saca al carro de la cola de espera
            //impresion de los datos
        }

        void tiempo_ventanilla(vector<Carro> &pCarro){
            //Se toma el tiempo de atencion de cada carro
        }
};