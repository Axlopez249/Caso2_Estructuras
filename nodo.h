#ifndef nodo_h
#define nodo_h 2

#include <iostream>
#include <string>

using namespace std;


struct nododoble {
    void* data = nullptr;
    struct nodo* sig = nullptr;
    struct nodo* ant = nullptr;

};

#endif