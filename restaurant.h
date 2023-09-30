#include <iostream>
#include <string>
#include "lista.h"
#include "reseta.h"

using namespace std;

class Restaurant
{
private:
    id orden; // Se usara dento de conocerOrden para saber que orden se va a cocinar
    vector<string> ingredientes_orden;
    vector<string> orden_orden; // este es el orden de las ordenes
    Queue<Order *> *ordenesacocinar;

public:
    Restaurant(Queue<Order *> *pOrderQueue)
    {
        // Se crean las ordenes del restaurante
        // soltar un hilo en cocinar
    }

    void addOrder(Order *pNewOrder)
    {
        // meter la orden en la cola de ordenesacocinar
    }

    // thread
    void cocinar(){
        // siempre y cuando no este vacia la cola de ordenes
        // saco una, espero el tiempo de preparacion
        // y sigue al siguiente paso

        // Preparacion de las ordenes
    };
}