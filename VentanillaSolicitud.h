#include <iostream>
#include <string>
#include "lista.h"
#include "restaurant.h"
#include "carro.h"
#include "queue.h"

using namespace std;

class ventanillaS
{
private:
    Queue<Carro *> *carrosEsperando;
    vector<string> comidasPesadas_;
    vector<string> bebidas_;
    vector<string> postres_;
    vector<string> extras_;
    int tMin_;
    int tMax_;
    int idVent;
    Restaurant *currentRestaurant;

    int id_carro;
    int id_orden; // Los nombres de las recetas son un string no un int
public:
    gen_ventanilla(int pId, const vector<string>& comidasPesadas,as, const vector<string>& bebidas, 
    const vector<string>& postres, const vector<string>& extras, int tMin, int tMax, 
    extras, int tMin, int tMax):idVent_(pId), comidasPesadas_(comidasPesadas), bebidas_(bebidas), postres_(postres), extras_(extras), tMin_(tMin), tMax_(tMax) {
    }

    
    void ordenHilo(){
        std::thread miHilo(procesarOrden);
        miHilo.join();
    }

    void addCarro(Carro *pNewCarro)
    {
    }

    void procesarOrden()
    {
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