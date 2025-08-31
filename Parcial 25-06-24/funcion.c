#include "funcion.h"

void crearLote(const char* nombArch){
    FILE* pf = fopen(nombArch,"wt");
    if(!pf)
        return;

    fprintf(pf,"{}[]()\n");
    fprintf(pf,"{[()]}\n");
    fprintf(pf,"{([])}}}}}}\n");
    fclose(pf);
}

void guardarCaracteres(char* linea, tPila* p){
    while(*linea){
        if(ESCORCH(*linea) || ESLLAVE(*linea) || ESPARENT(*linea)){
            char car = *linea;
            apilar(p,&car,sizeof(char));
        }
        linea++;
    }
}

void leerArchivo(const char* nombArch){
    FILE* pf = fopen(nombArch,"rt");
    if(!pf)
        return;

    tPila p;
    crearPila(&p);
    char linea[100];
    while(fgets(linea,sizeof(linea),pf)){
        guardarCaracteres(linea,&p);
        if(analizarPila(&p))
            printf("La expresion %s esta bien parentizada\n",linea);
        else
            printf("La expresion %s no esta bien parentizada\n",linea);
        vaciarPila(&p);
    }
    fclose(pf);
}

int analizarPila(tPila* p){
    char aux,auxcierre;
    tPila pilaAux;
    crearPila(&pilaAux);

    while(!pilaVacia(p)){
        desapilar(p,&aux,sizeof(char));
        if(aux == ')' || aux == ']' || aux == '}'){
            apilar(&pilaAux,&aux,sizeof(char));
        }
        else{
            if(pilaVacia(&pilaAux))
                return 0;
            desapilar(&pilaAux,&auxcierre,sizeof(char));
            if(!SONCORCH(aux,auxcierre) && !SONLLAVE(aux,auxcierre) && !SONPARENT(aux,auxcierre)){
                return 0;
            }
        }
    }
    return pilaVacia(&pilaAux);
}
