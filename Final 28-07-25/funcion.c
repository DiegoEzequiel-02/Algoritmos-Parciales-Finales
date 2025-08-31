#include "funcion.h"

int cmpPuntajes(const void*a, const void* b){
    t_puntaje* p1 = (t_puntaje*)a;
    t_puntaje* p2 = (t_puntaje*)b;

    return p1->puntaje - p2->puntaje;
}

void crearArchivo(const char* nombArch){
    FILE* pf = fopen(nombArch,"wt");
    if(!pf)
        return;

    fprintf(pf,"5\n");
    fprintf(pf,"AAA 500\n");
    fprintf(pf,"BBB 700\n");
    fprintf(pf,"DDD 540\n");
    fprintf(pf,"EEE 320\n");
    fprintf(pf,"FFF 630\n");
    fprintf(pf,"GGG 520\n");
    fprintf(pf,"HHH 710\n");
    fprintf(pf,"III 620\n");
    fclose(pf);
}

void crear_tabla_puntos(t_tabla_puntos* p, unsigned tam){
    crearLista(&p->tabla);
    p->tam = tam;
}

void leerArchivo(const char* nombArch){
    unsigned tam;
    t_puntaje punt;
    FILE* pf = fopen(nombArch,"rt");
    if(!pf)
        return;
    char linea[100];
    fgets(linea,sizeof(linea),pf);
    sscanf(linea,"%d\n",&tam);

    t_tabla_puntos ttp;
    crear_tabla_puntos(&ttp,tam);
    while(fgets(linea,sizeof(linea),pf)){
        sscanf(linea,"%s %u\n", punt.iniciales,&punt.puntaje);
        agregar_puntaje(&ttp,&punt);
    }
    imprimir_tabla_puntos(&ttp);
    vaciar_tabla_puntos(&ttp);
    fclose(pf);
}

int agregar_puntaje(t_tabla_puntos* p, const t_puntaje* dato){
    insertarOrdenadoTopN(&p->tabla,dato,sizeof(t_puntaje),cmpPuntajes,p->tam);
    return 1;
}

void imprimir_tabla_puntos(t_tabla_puntos* p){
    tNodo* aux = p->tabla;

    while(aux){
        imprimir(aux->info);
        aux = aux->sig;
    }
}

void imprimir(const void* a){
    t_puntaje* p1 = (t_puntaje*)a;

    printf("%s ..... %u\n",p1->iniciales,p1->puntaje);
}

void vaciar_tabla_puntos(t_tabla_puntos* p){
    vaciarLista(&p->tabla);
}

