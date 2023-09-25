#include <iostream>
#include <string>
#include <vector>
#include "lista.h"
#include "Hilos.h"
#include "restaurant.h"
#include <thread>
#include <chrono>

using namespace std;

int main(){
    vector<Reseta> resetas;
    vector<Carro> carros;

    Queue<string[]> *cola_carros1 = new List<string[]>();
    Queue<string[]> *cola_carros2 = new List<string[]>();

    //creo el restaurante con la informacion de las resetas
    Restaurant restaurant = new Restaurant(resetas);

    //Se generan los datos
    generar_carros(resetas, carros);

    //uso de un tipo de funcion lambda para utilizar en el hilo una funcion que tiene parametros
    thread hilo([&]() {
        ingresar_cola(carros, resetas, cola_carros1);
        ingresar_cola(carros, resetas, cola_carros2);
    });
    // Esperar a que el hilo continúe ejecutándose
    hilo.join();

    //lo siguiente es que vaya entrando a la ventanilla de solicitud
    //para eso se toman las colas de carro y con cada cierto tiempo se van pasando al restaurante



    return 0;

}