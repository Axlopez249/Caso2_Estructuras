#ifndef _PILA_ 
#define _PILA_ 1


template <typename T>
class Stack {
    public:
    //Funciones basicas de pilas
        virtual void push(T* pValue) = 0; 
        virtual T* pop() = 0;
        virtual bool isEmpty() = 0;
};

#endif