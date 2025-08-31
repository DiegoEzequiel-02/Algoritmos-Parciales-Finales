#include "tLista.h"

void crearLista(tLista* p){
    *p = NULL;
}

int insertarMejoresNLista(tLista* p, const void* d, unsigned cantBytes,int (*cmp)(const void*, const void*), int n) {
    tNodo *nue = malloc(sizeof(tNodo));
    if (!nue) return 0;

    nue->info = malloc(cantBytes);
    if (!nue->info) {
        free(nue);
        return 0;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = NULL;

    // Insertar en la lista ordenada
    tNodo **pp = p;
    while (*pp && cmp((*pp)->info, d) < 0) { // ascendente
        pp = &(*pp)->sig;
    }
    nue->sig = *pp;
    *pp = nue;

    // Ahora recorrer para eliminar los que superan el podio N
    tNodo **q = p;
    int pos = 1;  // posición actual
    tNodo *prev = NULL;
    while (*q) {
        if (prev) {
            // Si el valor actual es distinto del anterior, incrementamos posición
            if (cmp((*q)->info, prev->info) != 0)
                pos++;
        }
        prev = *q;

        if (pos > n) {
            // cortar la lista aquí
            tNodo *elim = *q;
            *q = NULL; // el anterior queda como final
            while (elim) {
                tNodo *tmp = elim->sig;
                free(elim->info);
                free(elim);
                elim = tmp;
            }
            break;
        }
        q = &(*q)->sig;
    }

    return 1;
}


void mapLista(tLista* p, void(*accion)(const void*)){
    tNodo* aux = *p;
    while(aux){
        accion(aux->info);
        aux = aux->sig;
    }
}

void vaciarLista(tLista* p){
    while(*p){
        tNodo* aux = *p;
        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}
