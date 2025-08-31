#include "funcion.h"

int cmpPotencia(const void* a, const void* b){
    t_polinomio* p1 = (t_polinomio*)a;
    t_polinomio* p2 = (t_polinomio*)b;

    return p1->potencia - p2->potencia;
}

void crearArchivos(const char* nombArch1, const char* nombArch2){
    int i;
    FILE* pf1 = fopen(nombArch1,"wt");
    FILE* pf2 = fopen(nombArch2,"wt");
    if(!pf1 || !pf2)
        return;

    t_polinomio p1[7] =
    {
        {3,-2},{2,8},{0,15},{2,-3},{1,6},{3,2},{3,6}
    };

    t_polinomio p2[7] =
    {
        {0,2},{0,1},{1,1},{1,-7},{2,4},{2,-2}
    };

    t_polinomio* ptr1 = p1;
    t_polinomio* ptr2 = p2;
    for(i = 0; i < sizeof(p1)/sizeof(t_polinomio);i++){
        fprintf(pf1,"X(%d)(%d)\n",ptr1->potencia,ptr1->coeficiente);
        ptr1++;
    }
    for(i = 0; i < sizeof(p2)/sizeof(t_polinomio);i++){
        fprintf(pf2,"X(%d)(%d)\n",ptr2->potencia,ptr2->coeficiente);
        ptr2++;
    }
    fclose(pf1);
    fclose(pf2);
}

void bajarArchivo(const char* nombArch, tArbolBinBusq* p){
    t_polinomio tp;
    FILE* pf = fopen(nombArch,"rt");
    if(!pf)
        return;

    char linea[100];
    while(fgets(linea,sizeof(linea),pf)){
        sscanf(linea,"X(%d)(%d)\n",&tp.potencia,&tp.coeficiente);
        tNodoArbol** aux = buscarNodoArbolBinBusq(p,&tp,cmpPotencia);
        if(aux == NULL){
            insertarArbolRecBinBusq(p,&tp,sizeof(t_polinomio),cmpPotencia);
        }else{
            t_polinomio* ptr = (t_polinomio*)(*aux)->info;
            ptr->coeficiente += tp.coeficiente;
            if(ptr->coeficiente == 0){
                eliminarRaizArbolBinBusq(aux);
            }
        }
    }

    fclose(pf);
}

void guardarDato(void* dato, void* arch){
    FILE* pf = (FILE*)arch;
    t_polinomio* p = (t_polinomio*)dato;

    fprintf(pf,"X(%d)(%d)\n",p->potencia,p->coeficiente);
}

void guardarPolinomio(const char* nombArch, tArbolBinBusq* p){
    FILE* pf = fopen(nombArch,"wt");
    if(!pf)
        return;

    recorrerEnOrdenArbolBinBusq(p,pf,guardarDato);
    fclose(pf);
}
