#ifndef TPILA_H_INCLUDED
#define TPILA_H_INCLUDED
#include "tNodo.h"

void crearPila(tPila* p);
int apilar(tPila* p, void* d, unsigned cantBytes);
int desapilar(tPila* p, void* d, unsigned cantBytes);
int pilaVacia(tPila* p);
int verTope(tPila* p, void* d, unsigned cantBytes);

#endif // TPILA_H_INCLUDED
