#ifndef _VENTANILLA_
#define _VENTANILLA_ 1

#include <iostream>
#include <string>
#include <random>
#include <thread>
#include <chrono>
#include <functional>

#include "lista.h"
#include "restaurant.h"
#include "carro.h"
#include "orden.h"
#include "Alimento.h"


using namespace std;



class ventanillaSolicitud
{
private:
    Queue<Carro> *carrosEsperando = new List<Carro>();
    List<string> *bebidas = new List<string>();
    List<string> *comidasPesadas = new List<string>();
    List<string> *postres = new List<string>();
    List<string> *extras = new List<string>();

    int idVent;
    int tMin_;
    int tMax_;
    Restaurant *currentRestaurant;

public:
    ventanillaSolicitud(int pideVent, List<string> *pcomidas , List<string> *prefrescos ,
     List<string> *ppostres , List<string> *pextras , int minTiempoEnFila, int maxTimpoEnFila) {
    
        idVent = pideVent;
        bebidas = prefrescos;
        comidasPesadas = pcomidas;
        postres = ppostres;
        extras = pextras;
        tMin_ = minTiempoEnFila;
        tMax_ = maxTimpoEnFila;

        

        std::thread miHilo(&ventanillaSolicitud::procesarOrden, this);
        miHilo.detach();

    }

    void addCarro(Carro *pNewCarro)
    {
        carrosEsperando->enqueue(pNewCarro);
    }

    void procesarOrden()
    {
        std::random_device rd;
        std::mt19937 generator(rd());

        std::uniform_int_distribution<int> distribution(0, 3);
        std::uniform_int_distribution<int> distribution1(tMin_, tMax_);

        while (true)
        {
            if (!carrosEsperando->isEmpty())
            {
                Carro *carro_nuevo = carrosEsperando->dequeue();
            .
            //Parte donde se crea la orden 
            //La cantidad de objetos de las comida, bebidas y eso de cada lista es de 4 entonces se crea una funcion 
            //en el lista.h que tome un numero aleatorio
            //y recorra la lista la cantidad de veces de ese numero y luego retorna su data para ir construyendo la orden
            //Entonces el numero random serían 1-4 por lista
            //Se saca random para para realizar cada cierto tiempo
            int comida = distribution(generator);
            int bebida = distribution(generator);
            int extra = distribution(generator);
            int postre = distribution(generator);
            
            //Se llama la funcion
            //Se supone que retorna un puntero de lo que sea, pero ya se sabe que es string
            
            string comida_orden = comidasPesadas->getDataRandom(comida);
            string bebida_orden = comidasPesadas->getDataRandom(bebida);
            string extra_orden = comidasPesadas->getDataRandom(extra);
            string postre_orden = comidasPesadas->getDataRandom(postre);
            
            
            orden *ordenNueva = new orden(carro_nuevo, comida_orden, bebida_orden, postre_orden, extra_orden);
            currentRestaurant->addOrder(ordenNueva);

            cout<<"Agregado al restaurante"<<endl;

            //Se saca random para para realizar cada cierto tiempo
             
            }
            int numeroAleatorio = distribution1(generator);
            std::this_thread::sleep_for(std::chrono::milliseconds(numeroAleatorio*1000));
        }
        
        // ciclo infinito while la !carrosEsperando->isEmpty()
        // casa un carro de la cola
        // saca un random de cuando va a durar procesando
        // hace sleep
        // arma una orden aleatoria
        // crea un objeto orden
        // ocupa meterla a la siguiente cola que es la que tiene resturant
        // currentRestaurant->addOrder();
        // se procesa el elemento carro con su orden
        // Luego se usa el .h restaurant para prepararla
    }

    void setRestaurant(Restaurant *current)
    {
        currentRestaurant = current;
    }
};

#endif