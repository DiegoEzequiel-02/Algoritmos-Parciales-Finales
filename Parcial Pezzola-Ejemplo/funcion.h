#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED
#include "tArbolBinBusq.h"

typedef struct{
    int dni;
    char materia[11];
    int anio;
    char periodo[7];
    int nota;
}t_alumnos;

typedef struct{
    int cont;
    float total;
}t_prom;

int cmp(const void* a, const void* b);
int cmpBuscarDNI(const void* a, const void* b);
void crearArchivo(const char* nombArch);
int cmpMateria(const void* a, const void* b);
void guardarMaterias(void* dato, void* arbol, void* comp);
void guardarDatos(void* datos, void* f);
void obtenerProm(void* datos, void* aux);
void buscarAlumnoPorDNIYGenerarInforme(tArbolBinBusq* p);
void cargarArbol(const char* nombArch, tArbolBinBusq* p);

void imprimir(void* a, void* b);

#endif // FUNCION_H_INCLUDED
