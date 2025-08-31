#include "funcion.h"

void crearArchivo(const char* nombArch){
    FILE* pf = fopen(nombArch,"wb");
    if(!pf)
        return;

    //dni | apelNomb[50] | baja

    t_alumnos alum[] =
    {
        {43928283,"Perez Juan", 0},{39524212,"Gomez Luis", 0},
        {38573294,"Sanchez Martin", 0},{44859392,"Diaz Luisa", 0},
        {45678901,"Martinez Laura", 0},{90123456,"Torres Lucia", 0},
        {11223344,"Ramirez Diego", 0},{23456789,"Perez Maria", 0},
        {12345678,"Gomez Juan", 0},{89012345,"Sanchez Pablo", 0}
    };

    fwrite(alum,sizeof(t_alumnos),sizeof(alum) / sizeof(t_alumnos),pf);
    fclose(pf);
}

int cmpDNI(const void* a, const void* b){
    t_indice* t1 = (t_indice*)a;
    t_indice* t2 = (t_indice*)b;

    return t1->dni - t2->dni;
}

void crearIndiceArbolBinBusq(const char* nombArch,const char* indice, tArbolBinBusq* arbol){
    t_indice ti;
    t_alumnos alum;
    long pos = 0;

    FILE* pf = fopen(nombArch,"rb");
    FILE* ind = fopen(indice,"wb");
    if(!pf || !ind)
        return;

    while(fread(&alum,sizeof(t_alumnos),1,pf)){
        ti.dni = alum.dni;
        ti.pos = pos;
        insertarArbolRecBinBusq(arbol,&ti,sizeof(t_indice),cmpDNI);
        fwrite(&ti,sizeof(t_indice),1,ind);
        pos++;
    }
    fclose(pf);
    fclose(ind);
}

void imprimirIndice(void* d){
    t_indice* ti = (t_indice*)d;

    printf("%d | %ld\n",ti->dni,ti->pos);
}

void imprimirAlumnos(void* d){
    t_alumnos* ti = (t_alumnos*)d;

    printf("%d | %s | %d\n",ti->dni,ti->apelNomb,ti->baja);
}

void baja(tArbolBinBusq* p, const char* nombArch, t_indice* d){
    t_alumnos alum;
    FILE* pf = fopen(nombArch,"r+b"); //archivo de alumnos inicial
    if(!pf)
        return;

    tNodoArbol ** aux = buscarNodoArbolBinBusq(p,d,cmpDNI);
    if(aux == NULL){
        printf("Este DNI no existe.\n");
    }
    else{
        t_indice* cast = (t_indice*)(*aux)->info;
        long pos = cast->pos;
        fseek(pf,pos * sizeof(t_alumnos),SEEK_SET);
        fread(&alum,sizeof(t_alumnos),1,pf);
        alum.baja = 1;
        fseek(pf, pos * sizeof(t_alumnos), SEEK_SET);
        fwrite(&alum,sizeof(t_alumnos),1,pf);
        eliminarRaizArbolBinBusq(aux);
    }
    fclose(pf);
}

void mostrarAlumnos(const char* nombArch){
    t_alumnos alum;
    FILE* pf = fopen(nombArch,"rb");
    if(!pf)
        return;

    while(fread(&alum,sizeof(t_alumnos),1,pf)){
        imprimirAlumnos(&alum);
    }
    fclose(pf);
}

void menu(){
    int opc;
    tArbolBinBusq arbol;
    t_indice ti;

    crearArbolBinBusq(&arbol);
    crearArchivo("alumnos.dat");

    do{
        do{
            printf("1 - Crear Indice\n");
            printf("2 - Baja\n");
            printf("0 - Salir\n");
            printf("Opcion: ");
            scanf("%d",&opc);
        }while(opc < 0 || opc > 2);
        switch(opc){
        case 1:
            vaciarArbolBinBusq(&arbol);
            crearIndiceArbolBinBusq("alumnos.dat","alumnos.idx",&arbol);
            printf("INDICE CREADO\n");
            recorrerEnOrdenArbolBinBusq(&arbol,NULL,imprimirIndice);
            break;
        case 2:
            recorrerEnOrdenArbolBinBusq(&arbol,NULL,imprimirIndice);
            printf("INGRESE DNI:");
            scanf("%d",&ti.dni);
            baja(&arbol,"alumnos.dat",&ti);
            fflush(stdin);
            break;
        }
    }while(opc != 0);
    mostrarAlumnos("alumnos.dat");
    vaciarArbolBinBusq(&arbol);
}
