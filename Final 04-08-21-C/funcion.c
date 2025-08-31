#include "funcion.h"

int cmpTiempo(const void* a, const void* b){
    t_maraton* m1 = (t_maraton*)a;
    t_maraton* m2 = (t_maraton*)b;

    return m1->tiempo - m2->tiempo;
}

void crearArchivo(const char* nombArch){
    int i;
    FILE* pf = fopen(nombArch,"wt");
    if(!pf)
        return;

    t_maraton m[10]=
    {
        {32842932,"Pedro, Luis",34},
        {29244241,"Perez, Santiago",12},
        {41939382,"Medina, Lucia",23},
        {44594893,"Suarez, Carlos",12},
        {29394838,"Diaz, Ramona",10},
        {45678912,"Garcia, Gabriel",49},
        {12345678,"Ruiz Diaz, Juan",27},
        {29874631,"Valentin, Alejo",11},
        {33495836,"Pezetaka, Tiago",87},
        {10298131,"Mezzi, Leonel",19}
    };

    t_maraton* ptr = m;
    for(i = 0; i< (sizeof(m) / sizeof(t_maraton));i++){
        fprintf(pf,"%8d %-25s %-3d\n",ptr->dni,ptr->nombreApl,ptr->tiempo);
        ptr++;
    }
    fclose(pf);
}

void leerArchivo(const char* nombArch,tLista* p){
    t_maraton tm;
    FILE* pf = fopen(nombArch,"rt");
    if(!pf)
        return;

    char linea[100];
    while(fgets(linea,sizeof(linea),pf)){
        sscanf(linea, "%d %25[^\n] %d", &tm.dni, tm.nombreApl, &tm.tiempo);
        insertarMejoresNLista(p,&tm,sizeof(t_maraton),cmpTiempo,4);
    }
}

void imprimir(const void* a){
    t_maraton* m = (t_maraton*)a;

    printf("%d | %s | %d\n",m->dni,m->nombreApl,m->tiempo);
}
