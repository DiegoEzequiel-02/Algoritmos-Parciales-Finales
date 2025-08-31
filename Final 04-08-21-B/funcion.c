#include "funcion.h"

void crearArchivo(const char* nombArch){
    FILE* pf = fopen(nombArch,"wt");
    if(!pf)
        return;

    fprintf(pf,"493;RT;Perez, Juan;948;345.75\n");
    fprintf(pf,"285;LP;Dario, Ruben;392;1453.66\n");
    fprintf(pf,"345;MF;Suarez, Romina;864;19838.4\n");
    fprintf(pf,"104;MF;Dominguez, Pedro;291;493.24\n");
    fprintf(pf,"938;RT;Ramirez, Sofia;573;123.45\n");
    fclose(pf);
}

int cmpNroCuenta(const void* a, const void* b) {
    const t_banco* b1 = (const t_banco*)a;
    const t_banco* b2 = (const t_banco*)b;

    if (b1->nroCuenta < b2->nroCuenta) return -1;
    if (b1->nroCuenta > b2->nroCuenta) return 1;
    return 0;
}


int cmpTipoCuenta(const void* a, const void* b){
    t_banco* b1 = (t_banco*)a;
    t_banco* b2 = (t_banco*)b;

    return strcmp(b1->tipoCuenta,b2->tipoCuenta);
}

int cmpClave(const void* a, const void* b){
    t_banco* b1 = (t_banco*)a;
    t_banco* b2 = (t_banco*)b;

    if (b1->extClave < b2->extClave) return -1;
    if (b1->extClave > b2->extClave) return 1;
    return 0;
}

void guardarDatos(const char* nombArch, tLista* p, int (*cmp)(const void*, const void*)){
    t_banco tb;
    FILE* pf = fopen(nombArch,"rt");
    if(!pf)
        return;

    char linea[100];
    while(fgets(linea,sizeof(linea),pf)){
        sscanf(linea,"%u;%[^;];%[^;];%u;%f\n",&tb.nroCuenta,tb.tipoCuenta,tb.aplNomb,&tb.extClave,&tb.saldo);
        insertarOrdenado(p,&tb,sizeof(t_banco),cmp);
    }

    fclose(pf);
}

void imprimir(const void* a){
    t_banco* b = (t_banco*)a;

    printf("%u | %s | %s | %u |%.2f\n",b->nroCuenta,b->tipoCuenta,b->aplNomb,b->extClave,b->saldo);
}

void generarResultado(const char* nombArch,tLista* p){
    FILE* pf = fopen(nombArch,"wb");
    if(!pf)
        return;

    tNodo* aux = *p;
    while(aux){
        t_banco* b = (t_banco*)aux->info;
        fwrite(b,sizeof(t_banco),1,pf);
        aux = aux->sig;
    }
    fclose(pf);
}

void leerArchivo(const char* nombArch){
    t_banco b;
    FILE* pf = fopen(nombArch,"rb");
    if(!pf)
        return;

    while(fread(&b,sizeof(t_banco),1,pf)){
        imprimir(&b);
    }
    fclose(pf);
}
