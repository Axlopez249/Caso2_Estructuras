#ifndef lista_h
#define lista_h 0

#include <iostream>
#include <string>
#include <stdlib.h>
#include "nodo.h"

string dato;
int rActual;
int rNueva;

struct lista{
    private:
        struct nodo* head = nullptr;
        struct nodo* tail = nullptr;
        int size = 0;

    public:
        void agregar(void *pDato){
           /* struct nodo *nNuevo = (struct nodo *)malloc(sizeof(struct nodo));
            nNuevo->data = pDato;

            if(size == 0){
                head = nNuevo;
                tail = nNuevo;
            }
            else{
                nNuevo -> ant = tail;
                tail -> sig = nNuevo;
                tail = nNuevo;
            }
            size++;
            */
        }


        void *eliminar(){
            /*
            void *result = nullptr;
            struct nododoble *cursor = head;
     
            
            while(aux != nullptr){
                if(aux->titulo == dato){
                    if(aux == head){
                        head = head->sig;
                        head->ant = nullptr;
                    }else if(aux == tail){
                        tail = tail->ant;
                        tail->sig = nullptr;
                    }else{
                        aux->ant->sig = aux->sig;
                        aux->sig->ant = aux->ant;
                    }
                    delete aux;
                    return;
                }
                aux = aux->sig;
            }
            */
        }


};

#endif