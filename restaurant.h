#ifndef _RESTAURANT_
#define _RESTAURANT_ 1

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <string>

#include <thread>
#include <chrono>
#include <random>

#include <vector>
#include <algorithm>
#include <map>

#include "configJson.cpp"
#include "lista.h"
#include "orden.h"


using namespace std;

class Restaurant
{
private:
    Queue<orden> *ordenesacocinar;
    int min;
    int max;
    string elemento;
    string elementoOrden;
    List<string> *acomodo;

    List<string> *bebidas;
    List<string> *comidasPesadas;
    List<string> *postres;
    List<string> *extras; 

    List<string> *stack = new List<string>;
    Stack<string> *pilaBolsa = stack;

public:
    Restaurant(Queue<orden> *pOrderQueue)
    {
        // Se crean las ordenes del restaurante
        // soltar un hilo en cocinar
        ordenesacocinar = pOrderQueue;
        std::thread miHilo(&Restaurant::cocinar, this);
        miHilo.detach();
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

        while (true)
        {
            if (!ordenesacocinar->isEmpty())
            {
                orden *ordenExtraida = ordenesacocinar->dequeue();
                //tengo la orden a mano
                
                //Aqui hay que hacer algo con esa orden
                //podria ser que agreguemos un orden especifcico en el json y lo extraigamos como lista de string
                //para luego compararla y crear una pila 
                //esa pila ya finalmente se puede utilizar luego para imprimir la informacion del carro que ya pasó

                //o tambien se puede utilizar la idea que usted tenia que sinceramente no sé cómo funciona

                cout<< "Sacando orden del restaurante"<<endl;

                

                
            }
            int numeroAleatorio = distribution(generator);
            std::this_thread::sleep_for(std::chrono::milliseconds(numeroAleatorio*1000)); 
        }
        
        // siempre y cuando no este vacia la cola de ordenes
        // saco una, espero el tiempo de preparacion
        // y sigue al siguiente paso

    }


    //Voy a revisar mejor esto
    void ingreso_restaurant(vector<string> orden){
        ConfigJson comidas;
        bebidas = comidas.getBebidas();
        comidasPesadas = comidas.getcomidasPesadas();
        postres = comidas.getpostres();
        extras = comidas.getextras();
        acomodo = comidas.getacomodo();
        
        for (int i = 0; i < acomodo->getSize(); ++1){
            elemento = acomodo->find(i);
            if (elemento != nullptr){
                for (int j = 0; j < orden.size(); ++j){
                    elementoOrden = orden[j];
                    if (elemento == elementoOrden){
                        pilaBolsa->push(new string(elementoOrden));
                    }
                }
            }
        }
        cout << "Lista Acomodada:" << endl;
        pilaBolsa->printValues();//Da error
    }

    void setMin(int pmin){
        min = pmin;
        
    }

    void setMax(int pmax){
        max = pmax;
    }

    void setAcomodo(List<string> *pacomodo){
        acomodo = pacomodo;
    }
};

#endif