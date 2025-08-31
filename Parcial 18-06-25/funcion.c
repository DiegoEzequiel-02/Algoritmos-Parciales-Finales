#include "funcion.h"

void crearLote(const char* nombArch){
    FILE* pf = fopen(nombArch,"wb");
    if(!pf)
        return;

    t_planta tp [8] =
    {
        {"L001",5,"OK"},
        {"L001",3,"OK"},
        {"L001",2,"FALLA"},
        {"L002",6,"FALLA"},
        {"L002",7,"FALLA"},
        {"L003",1,"OK"},
        {"L003",2,"FALLA"},
        {"L003",4,"OK"}
    };

    fwrite(&tp,sizeof(t_planta),8,pf);
    fclose(pf);
}

void leerArchivo(const char* nombArch,tLista* observados, tLista* aprobados, int porcFallas){
    float fallas = porcFallas / 100.0;
    int contLote = 0;
    int contFallas = 0;
    tLista auxLote;
    t_planta actual;
    char codLote[10];

    crearLista(&auxLote);

    FILE* pf = fopen(nombArch,"rb");
    if(!pf)
        return;

    if(fread(&actual, sizeof(t_planta), 1, pf) != 1){
        fclose(pf);
        return;
    }

    strcpy(codLote, actual.codLote);

    do {
        contLote = 0;
        contFallas = 0;
        crearLista(&auxLote); // limpiar lista auxiliar por cada lote

        do {
            // acumulamos el producto
            agregarAlFinal(&auxLote, &actual, sizeof(t_planta));
            contLote++;
            if(strcmp(actual.resultadoControl, "FALLA") == 0)
                contFallas++;

            // leemos el próximo producto
        } while(fread(&actual, sizeof(t_planta), 1, pf) == 1 &&
                strcmp(actual.codLote, codLote) == 0);

        // calcular si es observado o aprobado
        float porcentajeReal = ((float)contFallas) / contLote;
        t_planta tmp;

        if(porcentajeReal >= fallas){
            // Es observado
            while(!listaVacia(&auxLote)){
                sacarDelFrente(&auxLote, &tmp, sizeof(t_planta));
                agregarAlFinal(observados, &tmp, sizeof(t_planta));
            }
        } else {
            // Es aprobado
            while(!listaVacia(&auxLote)){
                sacarDelFrente(&auxLote, &tmp, sizeof(t_planta));
                agregarAlFinal(aprobados, &tmp, sizeof(t_planta));
            }
        }

        strcpy(codLote, actual.codLote); // actualizar codLote para el nuevo ciclo

    }while(!feof(pf));

    fclose(pf);
}

void guardarAprobados(const char* nombArch,tLista* aprobados){
    tLista fallas;
    t_planta tp;
    crearLista(&fallas);

    FILE* pf = fopen(nombArch,"wt");
    if(!pf)
        return;

    while(!listaVacia(aprobados)){
        sacarDelFrente(aprobados,&tp,sizeof(t_planta));
        if(strcmp(tp.resultadoControl, "FALLA") == 0)
            agregarAlFinal(&fallas,&tp,sizeof(t_planta));
        else
            fprintf(pf,"%s,%d,%s\n",tp.codLote,tp.idProducto,tp.resultadoControl);
    }
    while(!listaVacia(&fallas)){
        sacarDelFrente(&fallas,&tp,sizeof(t_planta));
        fprintf(pf,"%s,%d,%s\n",tp.codLote,tp.idProducto,tp.resultadoControl);
    }

    fclose(pf);
}

void guardarObservados(const char* nombArch,tLista* observados){
    tLista oks;
    t_planta tp;
    crearLista(&oks);
    FILE* pf = fopen(nombArch,"wt");
    if(!pf)
        return;

    while(!listaVacia(observados)){
        sacarDelFrente(observados,&tp,sizeof(t_planta));
        if(strcmp(tp.resultadoControl, "OK") == 0)
            agregarAlFinal(&oks,&tp,sizeof(t_planta));
        else
            fprintf(pf,"%s,%d,%s\n",tp.codLote,tp.idProducto,tp.resultadoControl);
    }
    while(!listaVacia(&oks)){
        sacarDelFrente(&oks,&tp,sizeof(t_planta));
        fprintf(pf,"%s,%d,%s\n",tp.codLote,tp.idProducto,tp.resultadoControl);
    }

    fclose(pf);
}

void imprimir(const void* a){
    t_planta* tp = (t_planta*)a;

    printf("%s,%d,%s\n",tp->codLote,tp->idProducto,tp->resultadoControl);
}

void leerYMostrar(const char* nombArch){
    t_planta tp;
    FILE* pf = fopen(nombArch,"rb");
    if(!pf)
        return;

    while(fread(&tp,sizeof(t_planta),1,pf)){
        imprimir(&tp);
    }

    fclose(pf);
}

void leerSalida(const char* nombArch){
    t_planta tp;
    char linea[100];
    FILE* pf = fopen(nombArch,"rt");
    if(!pf)
        return;

    while(fgets(linea,sizeof(linea),pf)){
        sscanf(linea, "%4[^,],%d,%5[^\n]", tp.codLote, &tp.idProducto, tp.resultadoControl);
        imprimir(&tp);
    }
    fclose(pf);
}

void menu(){
    int opc;
    int porcentaje = -1;
    tLista observados;
    tLista aprobados;
    char fallas[5];
    char loteAprob[20] = "lotesAprobados-";
    char loteObserv[20] = "lotesObservados-";

    crearLista(&observados);
    crearLista(&aprobados);

    crearLote("entrada.bin");

    do{
        do{
            printf("1 - Ingresar porcentaje de fallas\n");
            printf("2 - Procesar archivo de entrada\n");
            printf("3 - Mostrar archivo de entrada\n");
            printf("4 - Mostrar contenido de lotesAprobados / lotesObservados\n");
            printf("0 - Salir\n");
            printf("OPCION:");
            scanf("%d",&opc);
        }while(opc < 0 || opc > 4);
        switch(opc){
        case 1:
            strcpy(loteAprob, "lotesAprobados-");
            strcpy(loteObserv, "lotesObservados-");
            printf("Ingrese porcentaje de fallas: ");
            scanf("%d",&porcentaje);
            sprintf(fallas,"%d",porcentaje);
            strcat(loteAprob,fallas);
            strcat(loteAprob,".txt");
            strcat(loteObserv,fallas);
            strcat(loteObserv,".txt");
            break;
        case 2:
            if(porcentaje < 0){
                printf("NO INGRESO UN PORCENTAJE VALIDO.\n");
            }else{
                leerArchivo("entrada.bin",&observados,&aprobados,porcentaje);
                guardarObservados(loteObserv,&observados);
                guardarAprobados(loteAprob,&aprobados);
            }
            break;
        case 3:
            leerYMostrar("entrada.bin");
            break;
        case 4:
            if(porcentaje < 0){
                 printf("NO INGRESO UN PORCENTAJE VALIDO.\n");
            }else{
                printf("===APROBADOS===\n");
                leerSalida(loteAprob);
                printf("===OBSERVADOS===\n");
                leerSalida(loteObserv);
            }
            break;
        }
    }while(opc != 0);
}
