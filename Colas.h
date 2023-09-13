#ifndef Colas_h
#define Colas_h 1

#include "lista.h"



class cola{


    public:
        struct lista cola;
        
        void enqueue(void *pDato){
            cola.agr(pDato);
        }

        void *dequeue(){
            return cola.eliminar();
        }

    
};



#endif
