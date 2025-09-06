#include "funcion.h"

int cmp(const void* a, const void* b){
    const t_alumnos* al1 = (const t_alumnos*)a;
    const t_alumnos* al2 = (const t_alumnos*)b;

    if(al1->dni != al2->dni)
        return al1->dni - al2->dni;

    if(al1->anio != al2->anio)
        return al1->anio - al2->anio;

    int rc = strcmp(al1->periodo, al2->periodo);
    if(rc != 0)
        return rc;

    return strcmp(al1->materia, al2->materia);
}

int cmpBuscarDNI(const void* a, const void* b){
    const t_alumnos* al1 = (const t_alumnos*)a;
    const t_alumnos* al2 = (const t_alumnos*)b;
    return al1->dni - al2->dni;
}

void crearArchivo(const char* nombArch){
    FILE* pf = fopen(nombArch,"wb");
    if(!pf)
        return;

    t_alumnos alumnos[] = {
    {45123987, "Matematica", 2023, "2023-1", 8},
    {45123987, "Fisica",     2023, "2023-2", 6},
    {45123987, "Quimica",    2024, "2024-1", 9},

    {38976543, "Historia",   2023, "2023-1", 7},
    {38976543, "Programac",  2024, "2024-2", 10},

    {42789123, "Estadist",   2022, "2022-2", 5},
    {42789123, "Ingles",     2023, "2023-1", 9},
    {42789123, "Biologia",   2024, "2024-1", 4},

    {39876123, "Literatur",  2022, "2022-1", 7},
    {39876123, "Economia",   2023, "2023-2", 6}
    };


    fwrite(alumnos,sizeof(t_alumnos),sizeof(alumnos)/sizeof(t_alumnos),pf);
    fclose(pf);
}

int cmpMateria(const void* a, const void* b){
    t_alumnos* al1 = (t_alumnos*)a;
    t_alumnos* al2 = (t_alumnos*)b;
    return strcmp(al1->materia, al2->materia);
}

void guardarMaterias(void* dato, void* arbol, void* comp){
    t_alumnos* alum = (t_alumnos*)dato;
    tArbolBinBusq* ar = (tArbolBinBusq*)arbol;
    t_alumnos* dni = (t_alumnos*)comp;

    if(alum->dni == dni->dni){
        insertarRecArbolBinBusq(ar,alum,sizeof(t_alumnos),cmpMateria);
    }
}

void guardarDatos(void* datos, void* f){
    FILE* pf = (FILE*)f;
    t_alumnos* al = (t_alumnos*)datos;

    fprintf(pf,"%-10s %6s %2d\n",al->materia,al->periodo,al->nota);
}

void obtenerProm(void* datos, void* aux){
    t_prom* pr = (t_prom*)aux;
    t_alumnos* al = (t_alumnos*)datos;

    pr->cont++;
    pr->total += al->nota;
}

void buscarAlumnoPorDNIYGenerarInforme(tArbolBinBusq* p){
    t_alumnos alum;
    char arch[100] = "Materias_Aprobadas_";
    char txt[5] = ".txt";
    char numero[10];
    tArbolBinBusq materias;
    t_prom pr = {0, 0.0f};
    crearArbolBinBusq(&materias);

    printf("Ingrese DNI:");
    scanf("%d",&alum.dni);

    tNodoArbol** aux = buscarNodoArbolBinBusq(p,&alum,cmpBuscarDNI);
    if(aux != NULL){
        t_alumnos* cast = (t_alumnos*)(*aux)->info;
        sprintf(numero,"%d", alum.dni);
        strcat(arch,numero);
        strcat(arch,txt);
        FILE* pf = fopen(arch,"wt");
        if(!pf)
            return;
        recorrerEnOrdenParaMateriasArbolBinBusq(p,&materias,cast,guardarMaterias);
        fprintf(pf,"   INFORME DE MATERIAS APROBADAS\n");
        fprintf(pf,"---------DNI: %d---------\n",alum.dni);
        recorrerEnOrdenArbolBinBusq(&materias,&pr,obtenerProm);
        fprintf(pf, "Materias aprobadas: %d \t Promedio: %.2f\n",pr.cont,
        pr.cont ? (pr.total / (float)pr.cont) : 0.0f);
        fprintf(pf, "\n");
        fprintf(pf,"%-10s %6s Nota\n","Materia","Periodo");
        recorrerEnOrdenArbolBinBusq(&materias,pf,guardarDatos);
        vaciarArbolBinBusq(&materias);

        printf("Archivo para el DNI %d creado (%s).\n", alum.dni,arch);
        fclose(pf);
    }
    else{
        printf("No existe este DNI.\n");
    }

}

void cargarArbol(const char* nombArch, tArbolBinBusq* p){
    t_alumnos ta;
    FILE* pf = fopen(nombArch,"rb");
    if(!pf)
        return;

    while(fread(&ta,sizeof(t_alumnos),1,pf)){
        insertarRecArbolBinBusq(p,&ta,sizeof(t_alumnos),cmp);
    }

    fclose(pf);
}

void imprimir(void* a, void* b){
    t_alumnos* al = (t_alumnos*)a;

    printf("%d %s %s %d\n",al->dni,al->materia,al->periodo,al->nota);
}
