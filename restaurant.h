#ifndef _RESTAURANT_
#define _RESTAURANT_ 1

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include <thread>
#include <chrono>
#include <random>

#include "lista.h"
#include "orden.h"


using namespace std;

class Restaurant
{
private:
    Queue<orden> *ordenesacocinar;
    int min;
    int max;

public:
    Restaurant(Queue<orden> *pOrderQueue)
    {
        // Se crean las ordenes del restaurante
        // soltar un hilo en cocinar
        ordenesacocinar = pOrderQueue;
        
    }

    void addOrder(orden* pNewOrder)
    {
        ordenesacocinar->enqueue(pNewOrder);
    }

    // thread
    void cocinar(){
        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<int> distribution(min, max); 

        while (!ordenesacocinar->isEmpty())
        {
            orden *ordenExtraida = ordenesacocinar->dequeue();
            //tengo la orden a mano

            

            int numeroAleatorio = distribution(generator);

            std::this_thread::sleep_for(std::chrono::milliseconds(numeroAleatorio*60*1000)); 
        }
        
        // siempre y cuando no este vacia la cola de ordenes
        // saco una, espero el tiempo de preparacion
        // y sigue al siguiente paso

    }

    void setMin(int pmin){
        min = pmin;
        
    }

    void setMax(int pmax){
        max = pmax;
    }
};

#endif