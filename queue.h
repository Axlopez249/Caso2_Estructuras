#ifndef _COLA_ 
#define _COLA_ 1

template <typename T>
class Queue {
    public:
    //Funciones basicas de colas
        virtual void enqueue(T* pValue) = 0;
        virtual T* dequeue() = 0;
        virtual bool isEmpty() = 0;
};

#endif