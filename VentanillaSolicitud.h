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
    List<string> *refrescos;
    List<string> *comidas;
    List<string> *postres;
    Restaurant *currentRestaurant;

    int id_carro;
    int id_orden; // Los nombres de las recetas son un string no un int
public:
    ventanillaS(List<string> *comidas, List<string> *refrescos, List<String> *postres, int minTiempoEnFila, int maxTimpoEnFila)
    {
        // arrancar el hilo de procesamiento
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
    }
};