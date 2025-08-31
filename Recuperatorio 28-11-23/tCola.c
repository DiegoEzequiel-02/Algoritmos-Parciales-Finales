#include "tCola.h"

void crearCola(tCola* p){
    p->pri = NULL;
    p->ult = NULL;
}

int ponerEnCola(tCola* p, const void* d, unsigned cantBytes){
    tNodo* nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
        return 0;

    nue->info = malloc(cantBytes);
    if(!nue->info){
        free(nue);
        return 0;
    }
    memcpy(nue->info,d,cantBytes);
    nue->tamInfo = cantBytes;

    if(!p->pri){
        p->pri = nue;
    }else{
        p->ult->sig = nue;
    }
    p->ult = nue;
    return 1;
}

int sacarDeCola(tCola* p, void* d, unsigned cantBytes){
    if(!p->pri)
        return 0;

    tNodo* aux = p->pri;
    p->pri = aux->sig;
    memcpy(d,aux->info,MIN(aux->tamInfo,cantBytes));
    free(aux->info);
    free(aux);

    if(!p->pri)
        p->ult = NULL;

    return 1;
}

int verPrimeroCola(tCola* p, void* d, unsigned cantBytes){
    if(!p->pri)
        return 0;

    memcpy(d,p->pri->info, MIN(p->pri->tamInfo,cantBytes));
    return 1;
}

int colaVacia(tCola* p){
    return p->pri == NULL;
}
