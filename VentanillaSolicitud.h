#ifndef _VENTANILLA_
#define _VENTANILLA_ 1

#include <iostream>
#include <string>
#include <random>
#include <thread>
#include <chrono>
#include <functional>
#include <vector>

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
            
            //Estos numeros aleatorios que se generar aqui son la cantidad de ordenes que van a tener cada vector, es decir puede ser que por vuelta
            //el vector de comidaPesada tenga 2 ordenes y así con los 4
            //aqui va a ser la cantidad

            int cantComida = distribution(generator);
            int cantBebida = distribution(generator);
            int cantExtra = distribution(generator);
            int cantPostre = distribution(generator);


            //hacer un for de la cantidad de cada uno y llamar a una funcion
            //Se defininen los vectores donde se van a guardar las partes de las ordenes
            vector<string> comidaPesada;
            vector<string> extraOrden;
            vector<string> postreOrden;
            vector<string> bebidaOrden;

            //Un for de cada uno que recorre la cantidad antes mencionanada y se genera otro numero por vuelta que me escoje una del total enviando un numero
            //eso llama la funcion de abajo que ocupa ese numero, una lista y el vector para que se le agregue la cosa que pide
            for (int i = 0; i < cantComida; i++)
            {
                int comida = distribution(generator);
                generarParteOrden(comida, comidasPesadas, comidaPesada);
            }

            for (int i = 0; i < cantBebida; i++)
            {
                int bebida = distribution(generator);
                generarParteOrden(bebida, bebidas, extraOrden);
            }

            for (int i = 0; i < cantExtra; i++)
            {
                int extra = distribution(generator);
                generarParteOrden(extra, extras, postreOrden);
            }

            for (int i = 0; i < cantPostre; i++)
            {
                int postre = distribution(generator);
                generarParteOrden(postre, postres, bebidaOrden);
            }
            
            
            orden *ordenNueva = new orden(carro_nuevo, comidaPesada, extraOrden, postreOrden, bebidaOrden);
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

    void generarParteOrden(int cantParteOrden, List<string> pListaParteOrden, vector<string> pvectorParteOrden){
        pvectotParteOrden.push_back(pListaParteOrden->getDataRandom(cantParteOrden));
    }

    void setRestaurant(Restaurant *current)
    {
        currentRestaurant = current;
    }
};

#endif