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
        void generar_carros(std::vector<Receta>& pRecetas, std::vector<Carro>& pCarros, std::vector<String>& orden){
            //Se generan carros para la simulacion...
        }


        void ingresar_cola(vector<Carro> &pCarro, vector<Receta> &pReceta, Queue<string[]> *pColaCarros){
            //Se ingresan los carros a la cola de espera
        }


        void ingreso_ventanilla(Queue<string[]> *cola1, Queue<string[]> *cola2, Restaurant pRestaurante){
            //Se ingresan los carros a la ventanilla
        }

        void tiempo_ventanilla(vector<Carro> &pCarro){
            //Se toma el tiempo de atencion de cada carro
        }
};