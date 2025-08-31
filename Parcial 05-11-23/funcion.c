#include "funcion.h"

int cmpTitular(const void* a, const void* b){
    t_impuestos* i1 = (t_impuestos*)a;
    t_impuestos* i2 = (t_impuestos*)b;

    return strcmp(i1->titular,i2->titular);
}

int cmpTitularyPatente(const void* a, const void* b){
    t_impuestos* i1 = (t_impuestos*)a;
    t_impuestos* i2 = (t_impuestos*)b;

    if(strcmp(i1->titular,i2->titular)== 0){
        return strcmp(i1->patente,i2->patente);
    }

    return i1->titular - i2->titular;
}

int cmpVto(const void* a, const void* b){
    t_impuestos* i1 = (t_impuestos*)a;
    t_impuestos* i2 = (t_impuestos*)b;

    if(i1->vto.anio == i2->vto.anio){
        if(i1->vto.mes == i2->vto.mes)
            return i1->vto.dia - i2->vto.dia;
        return i1->vto.mes - i2->vto.mes;
    }
    return i1->vto.anio - i2->vto.anio;
}

int cmpDNI(const void* a, const void* b){
    t_impuestos* i1 = (t_impuestos*)a;
    t_impuestos* i2 = (t_impuestos*)b;

    return i1->dni - i2->dni;
}

int cmpDNIyPatente(const void* a, const void* b){
    t_impuestos* i1 = (t_impuestos*)a;
    t_impuestos* i2 = (t_impuestos*)b;

    if(i1->dni == i2->dni)
        return strcmp(i1->patente,i2->patente);
    return i1->dni - i2->dni;
}

void crearLote(const char* nombArch){
    FILE* pf = fopen(nombArch,"wb");
    if(!pf)
        return;

    t_impuestos vec [8] =
    {
        {"LS827FFS",3,"Perez Juan",12392392,{1976,11,4},3372.34},
        {"XG747KSD",2,"Rodriguez Jorge",21832483,{1983,6,12},37345.3},
        {"SP975MXJ",6,"Massa Dylan",32834821,{1998,7,14},83242.6},
        {"SD932GHD",1,"Pignatello Delfina",28318212,{2005,6,28},12383.2},
        {"ZZ784FDS",4,"Lopez Rosa",22838123,{1994,4,13},83829.2},
        {"KF583VGF",2,"Safdie Yami",48382173,{2001,8,15},4821.56},
        {"BC828JJA",5,"Ramirez Juan",23493843,{1986,7,24},5837.8},
        {"SP975MXJ",6,"Massa Dylan",32834821,{1998,7,14},1281.6}
    };
    fwrite(&vec,sizeof(t_impuestos),8,pf);
    fclose(pf);
}

void leerArchivo(const char* nombArch, tArbolBinBusq* p,int (*cmp)(const void*, const void*)){
    t_impuestos ti;
    FILE* pf = fopen(nombArch,"rb");
    if(!pf)
        return;

    while(fread(&ti,sizeof(t_impuestos),1,pf)){
        acumularDeuda(p,&ti,cmp);
    }
    fclose(pf);
}

void acumularDeuda(tArbolBinBusq* p, t_impuestos* ti, int (*cmp)(const void*, const void*)){
    tNodoArbol** nodo = buscarNodoNoClaveArbolBinBusq(p,ti,cmp);

    if(nodo == NULL){
        insertarRecArbolBinBusq(p,ti,sizeof(t_impuestos),cmp);
    }else{
        t_impuestos* impAux = (t_impuestos*)((*nodo)->info);
        impAux->importe += ti->importe;

    }
}

void obtenerDeudaTotal(void* dato, unsigned n, unsigned tam, void* total){
    t_impuestos* ti = (t_impuestos*)dato;
    float* valor = (float*)total;

    *valor += ti->importe;
}

void crearArchivoDeudas(const char* nombArch,tArbolBinBusq* p, void guardarDeuda(void*, unsigned, unsigned, void*)){
    float total;
    FILE* pf = fopen(nombArch,"wt");
    if(!pf)
        return;

    recorrerPreOrdenArbolBinBusq(p,pf,guardarDeuda);
    recorrerPreOrdenArbolBinBusq(p,&total,obtenerDeudaTotal);

    fprintf(pf,"DEUDA TOTAL: %2f\n",total);
    fclose(pf);
}

void guardarDeudaDNI(void* dato, unsigned n, unsigned tam, void* file){
    t_impuestos* ti = (t_impuestos*)dato;
    FILE* pf = (FILE*)file;

    fprintf(pf,"%d | %.2f\n",ti->dni,ti->importe);
}

void guardarDeudaDNIyPatente(void* dato, unsigned n, unsigned tam, void* file){
    t_impuestos* ti = (t_impuestos*)dato;
    FILE* pf = (FILE*)file;

    fprintf(pf,"%d | %s | %.2f\n",ti->dni,ti->patente,ti->importe);
}

void guardarTitular(void* dato, unsigned n, unsigned tam, void* file){
    t_impuestos* ti = (t_impuestos*)dato;
    FILE* pf = (FILE*)file;

    fprintf(pf,"%s | %.2f\n",ti->titular,ti->importe);
}

void guardarVto(void* dato, unsigned n, unsigned tam, void* file){
    t_impuestos* ti = (t_impuestos*)dato;
    FILE* pf = (FILE*)file;

    fprintf(pf,"%d / %d / %d | %.2f\n",ti->vto.anio,ti->vto.mes,ti->vto.dia,ti->importe);
}

void guardarTitularyPatente(void* dato, unsigned n, unsigned tam, void* file){
    t_impuestos* ti = (t_impuestos*)dato;
    FILE* pf = (FILE*)file;

    fprintf(pf,"%s | %s | %2.f\n",ti->titular,ti->patente,ti->importe);
}

void menu(){
    int opc = -1;

    crearLote("impuestosVencidos.dat");
    tArbolBinBusq arbol;

    while(opc != 0){
        do{
            printf("=====OBTENER DEUDA TOTAL POR:=====\n");
            printf("1 - DNI\n");
            printf("2 - DNI y Patente\n");
            printf("3 - Titular\n");
            printf("4 - Vencimiento\n");
            printf("5 - Titular y Patente\n");
            printf("0 - Salir\n");
            printf("Opcion:");
            scanf("%d",&opc);
        }while(opc < 0 || opc > 5);
        switch(opc){
        case 1:
            vaciarArbolBinBusq(&arbol);
            crearArbolBinBusq(&arbol);
            leerArchivo("impuestosVencidos.dat",&arbol,cmpDNI);
            crearArchivoDeudas("deuda.txt",&arbol,guardarDeudaDNI);
            break;
        case 2:
            vaciarArbolBinBusq(&arbol);
            crearArbolBinBusq(&arbol);
            leerArchivo("impuestosVencidos.dat",&arbol,cmpDNIyPatente);
            crearArchivoDeudas("deuda.txt",&arbol,guardarDeudaDNIyPatente);
            break;
        case 3:
            vaciarArbolBinBusq(&arbol);
            crearArbolBinBusq(&arbol);
            leerArchivo("impuestosVencidos.dat",&arbol,cmpTitular);
            crearArchivoDeudas("deuda.txt",&arbol,guardarTitular);
            break;
        case 4:
            vaciarArbolBinBusq(&arbol);
            crearArbolBinBusq(&arbol);
            leerArchivo("impuestosVencidos.dat",&arbol,cmpVto);
            crearArchivoDeudas("deuda.txt",&arbol,guardarVto);
            break;
        case 5:
            vaciarArbolBinBusq(&arbol);
            crearArbolBinBusq(&arbol);
            leerArchivo("impuestosVencidos.dat",&arbol,cmpTitularyPatente);
            crearArchivoDeudas("deuda.txt",&arbol,guardarTitularyPatente);
            break;
        }
    }
    printf("Adios!");
    vaciarArbolBinBusq(&arbol);
}
