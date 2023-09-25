#include <iostream>
#include <string>
#include <vector>
#include "lista.h"
#include "Hilos.h"
#include <thread>
#include <chrono>

using namespace std;

int main(){
    vector<Reseta> resetas;
    vector<Carro> carros;

    Queue<string[]> *cola_carros = new List<string[]>();

    generar_carros(resetas, carros);

    thread hilo(ingresar_cola(carros, resetas, cola_carros));

    // Esperar a que el hilo continúe ejecutándose
    hilo.join();
    return 0;

}