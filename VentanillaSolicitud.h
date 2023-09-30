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
    List<string> *bebidas;
    List<string> *comidasPesadas;
    List<string> *postres;
    List<string> *extras;
    Restaurant *currentRestaurant;

    int id_carro;
    int id_orden; // Los nombres de las recetas son un string no un int
public:
    ventanillaS(List<string> *pcomidas, List<string> *prefrescos, List<String> *postres, List<String> *extras, int minTiempoEnFila, int maxTimpoEnFila)
    {
        // arrancar el hilo de procesamiento
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