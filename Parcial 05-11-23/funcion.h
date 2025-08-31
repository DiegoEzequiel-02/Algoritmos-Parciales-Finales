#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED
#include "tArbolBinBusq.h"

typedef struct{
    int anio;
    int mes;
    int dia;
}t_fecha;

typedef struct{
    char patente[8];
    int nroCuota;
    char titular[26];
    int dni;
    t_fecha vto;
    float importe;
}t_impuestos;

int cmpDNI(const void* a, const void* b);
int cmpDNIyPatente(const void* a, const void* b);
void guardarDeudaDNI(void* dato, unsigned tam, unsigned n, void* file);
void guardarDeudaDNIyPatente(void* dato, unsigned n, unsigned tam, void* file);
void crearLote(const char* nombArch);
void leerArchivo(const char* nombArch, tArbolBinBusq* p,int (*cmp)(const void*, const void*));
void acumularDeuda(tArbolBinBusq* p, t_impuestos* ti, int (*cmp)(const void*, const void*));
void crearArchivoDeudas(const char* nombArch,tArbolBinBusq* p, void guardarDeuda(void*, unsigned, unsigned, void*));
void guardarDeudaDNI(void* dato, unsigned n, unsigned tam, void* file);
void guardarDeudaDNIyPatente(void* dato, unsigned n, unsigned tam, void* file);
void menu();
void obtenerDeudaTotal(void* dato, unsigned n, unsigned tam, void* total);
#endif // FUNCION_H_INCLUDED
