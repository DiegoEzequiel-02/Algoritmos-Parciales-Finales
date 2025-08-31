#include "funcion.h"

void crearArchivo(const char* nombArch){
    FILE* pf = fopen(nombArch,"wb");
    if(!pf)
        return;

    t_alumnos alum[10] =
    {
        {"Cristaldo Axel",33023812,'A'},{"Hoz Lucas",43928132,'A'},{"Passarelli Agustin",39182183,'A'},{"Kiryczun Agustin",41292832,'A'},
        {"Nardelli Cecilia",44928287,'A'},{"Lorenzo Valentina",45698792,'A'},{"Bursa Karen",40392822,'A'},{"Rodriguez Mauro",41678382,'A'},
        {"Melissari Pedro",40938823,'A'},{"Munar Matias",42929382,'A'}
    };

    fwrite(alum,sizeof(t_alumnos),sizeof(alum) / sizeof(t_alumnos),pf);
    fclose(pf);
}

int cmpDNI(const void*a, const void*b){
    t_indice* ti1 = (t_indice*)a;
    t_indice* ti2 = (t_indice*)b;

    return ti1->valor - ti2->valor;
}

void crearIndice(const char* nombArch, tArbolBinBusq* ind){
    t_alumnos al;
    t_indice ti;
    FILE* pf = fopen(nombArch,"rb");
    if(!pf)
        return;

    long pos = 0;
    while(fread(&al,sizeof(t_alumnos),1,pf)){
        ti.pos = pos;
        ti.valor = al.dni;
        insertarArbolRecBinBusq(ind,&ti,sizeof(t_indice),cmpDNI);
        pos++;
    }

    fclose(pf);
}

void guardarDatos(void* dato, unsigned tam, void* file){
    FILE* pf = (FILE*)file;
    t_indice* ti = (t_indice*)dato;

    fwrite(ti,tam,1,pf);
}

void grabarArbol(const char* nombArch, tArbolBinBusq* ind){
    FILE* pf = fopen(nombArch,"wb");
    if(!pf)
        return;

    recorrerEnOrdenArbolBinBusq(ind,pf,guardarDatos);
    fclose(pf);
}

void baja(tArbolBinBusq* p, const char* nombArch){
    t_indice td;
    t_alumnos ta;
    FILE* pf = fopen(nombArch,"r+b");
    if(!pf)
        return;
    printf("Ingrese DNI a eliminar:");
    scanf("%d",&td.valor);
    tNodoArbol** aux = buscarNodoArbolBinBusq(p,&td,cmpDNI);
    if(aux == NULL){
        printf("Este DNI no existe\n");
    }else{
        t_indice* indx = (t_indice*)(*aux)->info;
        long offset = (indx->pos) * sizeof(t_alumnos);

        fseek(pf, offset, SEEK_SET);
        fread(&ta,sizeof(t_alumnos),1,pf);
        ta.estado = 'B';

        fseek(pf,offset,SEEK_SET);
        fwrite(&ta,sizeof(t_alumnos),1,pf);

        eliminarRaizArbolBinBusq(aux);
    }
    fclose(pf);
}

void mostrarAlumnos(const char* nombArch){
    t_alumnos ta;
    FILE* pf = fopen(nombArch,"rb");
    if(!pf)
        return;

    while(fread(&ta,sizeof(t_alumnos),1,pf)){
        imprimirAlumno(&ta);
    }
}

void imprimirAlumno(const void* a){
    t_alumnos* alum = (t_alumnos*)a;

    printf("%s %d %c\n", alum->nombre,alum->dni,alum->estado);
}

void mostrarIndice(const char* nombArch){
    t_indice ti;
    FILE* pf = fopen(nombArch,"rb");
    if(!pf)
        return;

    while(fread(&ti,sizeof(t_alumnos),1,pf)){
        imprimirIndice(&ti,0,NULL);
    }
}

void imprimirIndice(void* a, unsigned n, void* params){
    t_indice* alum = (t_indice*)a;

    printf("%d | %ld\n", alum->valor, alum->pos);
}

void menu(){
    int opc;

    tArbolBinBusq indice;
    crearArbolBinBusq(&indice);

    crearIndice("alumnos.dat",&indice);

    do{
        printf("========LISTA DE ALUMNOS========\n");
        mostrarAlumnos("alumnos.dat");
        do{
            printf("1 - BAJA\n");
            printf("2 - GRABAR ARBOL\n");
            printf("0 - SALIR\n");
            printf("Opcion: ");
            scanf("%d",&opc);
        }while(opc < 0 && opc > 2);
        switch(opc){
        case 1:
            baja(&indice,"alumnos.dat");
            break;
        case 2:
            grabarArbol("alumnos.idx",&indice);
            printf("\n========INDICE========\n");
            recorrerEnOrdenArbolBinBusq(&indice,NULL,imprimirIndice);
            break;
        }
    }while(opc != 0);
    vaciarArbolBinBusq(&indice);
}
