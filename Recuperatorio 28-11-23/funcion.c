#include "funcion.h"

void crearArchProductos(const char* nombArch){
    FILE* pf = fopen(nombArch,"wb");
    if(!pf)
        return;

    t_productos prod [15] =
    {
        {"martillo azul",10,500.00},{"martillo rojo",15,500.00},
        {"martillo negro",3,500.00},{"destornillador",100,200.00},
        {"llave 10'",12,450.00},{"llave 8'",2,450.00},
        {"llave 6'",32,450.00},{"mecha 8'",45,150.00},
        {"mecha 6'",34,150.00},{"mecha 10'",6,150.00},
        {"pinza",13,660.00},{"alicate",21,660.00},
        {"cutter",2,300.00},{"lapiz",5,100.00},
        {"serrucho",10,650.00}
    };

    fwrite(&prod,sizeof(t_productos),15,pf);
    fclose(pf);
}

void leerProductos(const char* nombArch, tCola* productos){
    t_productos prod;
    FILE* pf = fopen(nombArch,"rb");
    if(!pf)
        return;

    while(fread(&prod,sizeof(t_productos),1,pf)){
        ponerEnCola(productos,&prod,sizeof(t_productos));
    }

    fclose(pf);
}

void leerPedidos(const char* nombArch, tCola* pedidos){
    char linea[100];
    t_pedidos ped;
    FILE* pf = fopen(nombArch,"rt");
    if(!pf)
        return;

    while(fgets(linea,sizeof(linea),pf)){
        sscanf(linea,"%6d %2d %d\n", &ped.cod_ped,&ped.cod_prod,&ped.cant);
        ponerEnCola(pedidos,&ped,sizeof(t_pedidos));
    }
    fclose(pf);
}

int procesarPedidos(const char* archProd, const char* archPedidos) {
    FILE* fpProd = fopen(archProd, "r+b");
    FILE* fpPed = fopen(archPedidos, "rt");
    if(!fpProd || !fpPed)
        return 0;

    tCola colaPedidos;
    crearCola(&colaPedidos);

    char linea[16];
    t_pedidos pedido;

    // Paso 1: cargar pedidos en cola
    while(fgets(linea, sizeof(linea), fpPed)) {
        sscanf(linea, "%6d%6d%3d", &pedido.cod_ped, &pedido.cod_prod, &pedido.cant);
        ponerEnCola(&colaPedidos, &pedido, sizeof(t_pedidos));
    }

    // Paso 2: procesar pedidos
    while(sacarDeCola(&colaPedidos, &pedido, sizeof(t_pedidos))) {
        long pos = pedido.cod_prod - 1; // ajustar a índice desde 0

        fseek(fpProd, pos * sizeof(t_productos), SEEK_SET);
        t_productos prod;
        fread(&prod, sizeof(t_productos), 1, fpProd);

        if(prod.stock >= pedido.cant)
            prod.stock -= pedido.cant;
        else
            prod.stock = 0; // o algún otro manejo de error

        fseek(fpProd, pos * sizeof(t_productos), SEEK_SET);
        fwrite(&prod, sizeof(t_productos), 1, fpProd);
    }

    fclose(fpProd);
    fclose(fpPed);
    return 1;
}

