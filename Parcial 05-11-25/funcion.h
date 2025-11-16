#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED
#define AMINUS(x)((x >= 'A' && x<='Z') ? (x+32) : (x))
#define ESLETRA(x)((x >= 'A' && x<='Z') || (x >= 'a' && x<='z'))
#include "tPila.h"

void crearArchivo(const char* nombArch);
void analizarLinea(const char* linea, tPila* p);
void guardarLinea(const char* linea, tPila* p);
void imprimirEnArchivoNuevo(FILE* out, tPila* p, const char* linea);
void leerArchivo(const char* nombArch, const char* archAux);

#endif // FUNCION_H_INCLUDED
