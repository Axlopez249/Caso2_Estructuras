#ifndef Lista 
#define Lista 1

#include "nodo.h"
#include "stack.h"
#include "queue.h"


using namespace std;

template <typename T> 
class List : public Stack<T>, public Queue<T> {
    private:
        Node<T> *first;
        Node<T> *last;
        unordered_map<int, Node<T>*> nodeIndex; 

    public:
        List() {
            first = NULL;
            last = NULL;
            size = 0;
        }

        Node<T>* getFirst() {
            //Sirve para visualizar el top de la pila
        }

        int getSize() {
            //return size;
        }

        bool isEmpty() {
            //return !size;
        }

        void add(T *pData){
            //Inserta en la cola, usada para encolar
        }

        // si el position es mayor a la cantidad, entonces inserto al final
        void insert(int pPosition, T *pData) {
            //recibe la posicion y el dato
            //usada por pila para insertar en el top de la pila

        }

        T* remove(int pPosition) {
            //Remueve de la lista, cola o pila
            //usada por la cola para remover el primero en entrar
            //usada por la pila para remover ultimo en entrar
        };

        void push(T* pValue) {
            //insert(0, pValue);
        }

        T* pop() {
            //Se llama a remove para eliminar el ultimo en entrar
        }

        void enqueue(T* pValue) {
            //se llama a add pasandole el dato
        }

        T* dequeue() {
            //se llama a remove para eliminar el primero en entrar
        }

        bool verificar_estado(){
            //Se utiliza para cuando se realizan moviemientos en las colas o pilas 
            //es para llevar un control
        }




};

#endif