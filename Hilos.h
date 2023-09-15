#include <iostream>
#include <string>
#include "lista.h"

using namespace std;

class hilos{
    private:
        
        Queue<string> *colaCarros;
        Stack<string> *pila;
        List<string> *lista = new List<string>();
    public:
        hilos(/*recibiria parametro de tipo lista para inicializar bien las colas y las pilas*/){
            //Se inicializa la clase
            
           
        }

        void hilacion(){
            //Aqui iria el codigo que permite el procesamiento continuo de los datos
            //colaCarros->dequeue();
        }

};