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

                vector<vector<string>> ordenes;
                ordenes.push_back(ordenExtraida->getPostre());
                ordenes.push_back(ordenExtraida->getComida());
                ordenes.push_back(ordenExtraida->getExtra());
                ordenes.push_back(ordenExtraida->getBebida());

                //Se crea una pila por orden
                Stack<string> *pilaBolsa = new List<string>();
                //Se llena la pila
                ingreso_restaurant(ordenes, pilaBolsa);

                


                //Luego ya se puede imprimir lo que pidio ese carro con la fe de que este guardado todo bien
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
    void ingreso_restaurant(vector<vector<string>> porden, Stack<string> *ppilaBolsa){
        ConfigJson comidas;
        bebidas = comidas.getBebidas();
        comidasPesadas = comidas.getcomidasPesadas();
        postres = comidas.getpostres();
        extras = comidas.getextras();
        
        

        //elemento no tiene tipo de nada, me imagino que como la lista acomodo tiene string entonces lo que saque sera un puntero string
        for (int i = 0; i < acomodo->getSize(); i++){
            string *elemento = acomodo->find(i);
            if (elemento != nullptr){
                for (int j = 0; j < porden.size(); j++){
                    //se obtiene cada vector
                    vector<string> elementoOrden = porden[j];
                    //se recorre ese vector para compararlo con el elemento que tengo
                    //hasta que lo encuentre en alguno de todos los vectores, entonces lo mete a la pila
                    for (int i = 0; i < elementoOrden.size(); i++)
                    {
                        //Extraigo cada valor y comparo a ver si está
                        //si lo encuentra lo mando a la bola con el push
                        if (*elemento == elementoOrden[i]){
                            ppilaBolsa->push(elemento);

                            //mi idea es volver a poner el j=0 para que comience la comparacion desde el inicio porque en los movimientos que hizo buscando
                            //pudo haber dejado alguna comida que se necesita entonces es mejor de esa manera
                            j = 0;
                        }
                    }
                }
            }
        }
        cout << "Lista Acomodada:" << endl;

        //esto no va a funcionar porque esa funcion solo es para listas, no para pilas ni colas
        //pilaBolsa->printValues();//Da error
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