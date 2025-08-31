#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED
#include "tPila.h"

#define ESCORCH(x)(x=='[' || x == ']')
#define ESLLAVE(x)(x=='{' || x == '}')
#define ESPARENT(x)(x=='(' || x == ')')

#define SONCORCH(x,y)(x=='[' && y == ']')
#define SONLLAVE(x,y)(x=='{' && y == '}')
#define SONPARENT(x,y)(x=='(' && y == ')')

void crearLote(const char* nombArch);
void guardarCaracteres(char* linea, tPila* p);
void leerArchivo(const char* nombArch);
int analizarPila(tPila* p);

#endif // FUNCION_H_INCLUDED
