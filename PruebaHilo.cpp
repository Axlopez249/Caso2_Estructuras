#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

// Función que se ejecutará continuamente en un hilo
void funcionContinua() {
    int c = 0;
    while (c <= 5) {
        // Coloca aquí la lógica que deseas que se ejecute continuamente

        // Por ejemplo, puedes imprimir un mensaje cada segundo
        cout << "Tarea continua..." << c++ << endl;

        // Pausa el hilo durante un segundo
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main() {
    // Crear un objeto de hilo y pasarle la función continua
    thread hilo(funcionContinua);

    // Puedes realizar otras tareas en la función main si es necesario

    // Esperar a que el hilo continúe ejecutándose
    hilo.join();

    return 0;
}

