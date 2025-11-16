#include "funcion.h"

void crearArchivo(const char* nombArch){
    FILE* pf = fopen (nombArch,"wt");
    if(!pf)
        return;

    fprintf(pf,"ccC++d-- RRrRa\n");
    fprintf(pf,"+++__**+\n");

    fclose(pf);
}

void analizarLinea(const char* linea, tPila* p){
    if(pilaVacia(p))
        printf("No contiene ninguna clave.\n");

    char fin,ini;
    tPila aux;
    crearPila(&aux);

    while(!pilaVacia(p)){
        desapilar(p,&fin,sizeof(char));

        if(!pilaVacia(&aux)){
            verTope(&aux,&ini,sizeof(char));
            if(AMINUS(ini) == AMINUS(fin)){
                desapilar(&aux,&ini,sizeof(char));
            }else{
                apilar(&aux,&fin,sizeof(char));
            }
        }else{
            apilar(&aux,&fin,sizeof(char));
        }
    }

    while(!pilaVacia(&aux)){
        desapilar(&aux,&ini,sizeof(char));
        apilar(p,&ini,sizeof(char));
    }
}

void guardarLinea(const char* linea, tPila* p){
    char car;
    tPila aux;
    crearPila(&aux);

    while(*linea){
        if(*linea != '\n'){
            car = *linea;
            apilar(&aux,&car,sizeof(char));
        }
        linea++;
    }

    while(!pilaVacia(&aux)){
        desapilar(&aux,&car,sizeof(char));
        apilar(p,&car,sizeof(char));
    }
}

void imprimirEnArchivoNuevo(FILE* out, tPila* p, const char* linea){
    char car;
    if(!pilaVacia(p)){
        while(!pilaVacia(p)){
            desapilar(p,&car,sizeof(char));
            fprintf(out,"%c",car);
        }
        fprintf(out,"\n");
    }
}

void leerArchivo(const char* nombArch, const char* archAux){
    FILE* pf = fopen (nombArch,"rt");
    FILE* out = fopen (archAux,"wt");
    if(!pf)
        return;

    char linea[100];
    tPila p;
    crearPila(&p);
    while(fgets(linea,sizeof(linea),pf)){
        guardarLinea(linea,&p);
        analizarLinea(linea,&p);
        imprimirEnArchivoNuevo(out,&p, linea);
    }
    fclose(pf);
    fclose(out);

    remove(nombArch);
    rename(archAux,nombArch);
}
