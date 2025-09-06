#include "funcion.h"

void crearArchivoReglas(const char* nombArch){
    FILE* pf = fopen(nombArch,"wt");
    if(!pf)
        return;

    fprintf(pf,"1 0.05 50000.00 10000.00\n");
    fprintf(pf,"2 0.15 26000.00 12000.00\n");
    fprintf(pf,"2 0.03 100000.00 20000.00\n");
    fprintf(pf,"3 0.25 1200.00 500.00\n");
    fprintf(pf,"1 0.14 73000.00 10000.00\n");
    fprintf(pf,"4 0.38 10000.00 2000.00\n");

    fclose(pf);
}

void crearArchivoClientes(const char* nombArch){
    FILE* pf = fopen(nombArch,"wb");
    if(!pf)
        return;

    t_cliente cli[] = {
        {"juanperez", "Juan", "Perez", 1},
        {"mariagomez", "Maria", "Gomez", 2},
        {"carlitos88", "Carlos", "Ramirez", 3},
        {"anabrito", "Ana", "Brito", 1},
        {"leonardo77", "Leonardo", "Fernandez", 2}
    };

    fwrite(cli,sizeof(t_cliente),sizeof(cli) / sizeof(t_cliente),pf);
    fclose(pf);
}

void crearArchivoProductos(const char* nombArch){
    FILE* pf = fopen(nombArch,"wb");
    if(!pf)
        return;

    t_producto pr[] = {
        {"zapDeport", "Zapatillas deportivas", 19999.90},
        {"camAlgBasic", "Camiseta algodon basica", 4999.50},
        {"noteHp15", "Notebook HP 15.6''", 429999.99},
        {"aurisInam", "Auriculares inalambricos", 28999.00},
        {"smartW", "Smartwatch resistente", 89999.90}
    };

    fwrite(pr,sizeof(t_producto),sizeof(pr) / sizeof(t_producto),pf);
    fclose(pf);
}

void imprimir(void* a){
    t_reglas* r = (t_reglas*)a;

    printf("%d %.2f %.2f %.2f\n",r->nivel,r->porcDescuento,r->topeDescuento,r->minimoParaEnvioGratis);
}

int cmpNivel(const void* a, const void* b){
    t_reglas* r1 = (t_reglas*)a;
    t_reglas* r2 = (t_reglas*)b;

    return r1->nivel - r2->nivel;
}

void bajarReglasALista(const char* nombArch, tLista* p){
    t_reglas reg;
    FILE* pf = fopen(nombArch,"rt");
    if(!pf)
        return;

    char linea[100];
    while(fgets(linea,sizeof(linea),pf)){
        sscanf(linea,"%d %f %f %f\n",&reg.nivel,&reg.porcDescuento,&reg.topeDescuento,&reg.minimoParaEnvioGratis);
        insertarOrdenado(p,&reg,sizeof(t_reglas),cmpNivel);
    }

    fclose(pf);
}

void crearOfertas(const char* client, const char* prods, const char* finTxT,tLista *p){
    t_cliente cliente;
    t_producto producto;
    t_oferta oferta;
    t_reglas reglas;
    FILE* cl = fopen(client,"rb");
    FILE* pr = fopen(prods,"rb");
    FILE* end = fopen(finTxT,"wt");

    if(!cl || !pr || !end){
        if(cl)
            fclose(cl);
        if(pr)
            fclose(pr);
        if(end)
            fclose(end);
        return;
    }

    fprintf(end, "%-20s\n", "Usuario");
    fprintf(end, "%40s %-10s %s\n","Producto", "Precio", "Envio Gratis");
    while(fread(&cliente,sizeof(t_cliente),1,cl)){
        strcpy(oferta.usuario,cliente.usuario);
        fprintf(end,"%-20s\n", oferta.usuario);
        fseek(pr, 0, SEEK_SET);
        while(fread(&producto,sizeof(t_producto),1,pr)){
            strcpy(oferta.producto, producto.codigo);
            oferta.precio = producto.precio;

            reglas.nivel = cliente.nivel;
            tNodo** nodo = buscarNivelEnLista(p,&reglas,cmpNivel);
            t_reglas* cast = (t_reglas*)(*nodo)->info;

            if(oferta.precio < cast->topeDescuento)
                oferta.precio -= oferta.precio * cast->porcDescuento;

            if(oferta.precio > cast->minimoParaEnvioGratis)
                oferta.envioGratis = true;
            else
                oferta.envioGratis = false;

            fprintf(end, "%40s %-10.2f %s\n", oferta.producto, oferta.precio,oferta.envioGratis ? "Si" : "No");
        }
    }
    fclose(cl);
    fclose(pr);
    fclose(end);
}
