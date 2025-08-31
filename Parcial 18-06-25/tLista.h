#ifndef TLISTA_H_INCLUDED
#define TLISTA_H_INCLUDED
#include "tNodo.h"

void crearLista(tLista* p);
int agregarAlFinal(tLista* p, const void* d, unsigned cantBytes);
int sacarDelFrente(tLista* p, void* d, unsigned cantBytes);
int listaVacia(tLista* p);
#endif // TLISTA_H_INCLUDED
