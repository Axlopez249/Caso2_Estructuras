#include <iostream>
#include <string>
#include "lista.h"
#include "reseta.h"
#include "orden.cpp"

using namespace std;

class Restaurant
{
private:
    vector<string> ingredientes_orden;
    vector<string> orden_orden; // este es el orden de las ordenes
    Queue<orden *> *ordenesacocinar;
    int min;
    int max;

public:
    Restaurant(Queue<Order *> *pOrderQueue)
    {
        // Se crean las ordenes del restaurante
        // soltar un hilo en cocinar
        ordenesacocinar = pOrderQueue;
        
    }

    void addOrder(Order *pNewOrder)
    {
        ordenesacocinar->enqueue(pNewOrder);
    }

    // thread
    void cocinar(){
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(min, max); 

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