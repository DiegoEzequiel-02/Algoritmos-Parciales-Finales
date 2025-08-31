#include "funcion.h"

void crearArchivo(const char* nombArch){
    FILE* pf = fopen(nombArch,"wb");
    if(!pf)
        return;

    t_vehiculos v[5]=
    {
        {"AAA111",10,200},{"BBB111",5,100},{"AAA222",10,300},{"CCC111",1,100},{"DDD111",5,500}
    };
    fwrite(v,sizeof(t_vehiculos),sizeof(v) / sizeof(t_vehiculos),pf);
    fclose(pf);
}

int cmpAntig(const void*a, const void*b){
    t_contar* tv1 = (t_contar*)a;
    t_contar* tv2 = (t_contar*)b;

    return tv1->antig - tv2->antig;
}

void imprimir(const void* a){
    t_contar* ptr = (t_contar*)a;

    printf("%d | %.f\n",ptr->antig,(float)(ptr->kms/ptr->repes));
}

void leerArchivo(const char* nombArch, tArbolBinBusq* p){
    t_vehiculos v;
    t_contar c;

    FILE* pf = fopen(nombArch,"rb");
    if(!pf)
        return;

    while(fread(&v,sizeof(t_vehiculos),1,pf)){
        c.antig = v.antig;
        tNodoArbol** aux = buscarNodoArbolBinBusq(p,&c,cmpAntig);
        if(aux == NULL){
            c.repes = 1;
            c.kms = v.kms;
            insertarArbolRecBinBusq(p,&c,sizeof(t_contar),cmpAntig);
        }else{
            t_contar* ptr = (t_contar*)(*aux)->info;
            ptr->kms += v.kms;
            ptr->repes++;
        }
    }
    fclose(pf);

}
