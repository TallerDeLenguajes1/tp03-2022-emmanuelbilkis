#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Producto {

    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100

}typedef Producto;

struct Cliente {

    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
                        // “CantidadProductosAPedir”
}typedef Clientes;


float calculoPrecioPorProducto(int cantProducto, int precioUnitario);

int main()
{
    srand(time(NULL));   
    int cantidadProductos,cantidadClientes,aleatorioTipoProducto;
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    float precioTotal = 0; 
    float sumaTotal = 0;
    char *Buff = (char *)malloc(sizeof(char)*100);
     char *Buff2 = (char *)malloc(sizeof(char)*100);

    printf("Ingrese la cantidad de clientes : \n");
    scanf("%d",&cantidadClientes);
    fflush(stdin);
    Clientes ** mClientes = (Clientes **) malloc(sizeof(Clientes) * cantidadClientes);
    // aca reserve solo las filas, cada fila es un vector de puntero simple q apunta a un vector de clientes 


    for (int i = 0; i < cantidadClientes ; i++)
    {   
        // reservo memoria para cada fila de clientes
        mClientes[i] = (Clientes *) malloc(sizeof(Clientes));
        mClientes[i]->CantidadProductosAPedir = rand() % 4 + 1;
        mClientes[i]->ClienteID = i+1;
        printf("\nIngrese nombre del cliente %d:\n",i+1);
        gets(Buff);
        fflush(stdin);
        mClientes[i]->NombreCliente = (char *)malloc((strlen(Buff)+1));
        //Almaceno un espacio en memoria para guardar el nombre del cliente
        strcpy(mClientes[i]->NombreCliente,Buff);
        mClientes[i]->Productos = (Producto*) malloc(sizeof(Producto) * mClientes[i]->CantidadProductosAPedir );
        

        for (int j = 0; j < mClientes[i]->CantidadProductosAPedir; j++)
        {   
            
            mClientes[i]->Productos->Cantidad = rand() % 9 + 1 ;
            mClientes[i]->Productos->PrecioUnitario = rand() % 100;
            mClientes[i]->Productos->ProductoID = j+1;
            
            aleatorioTipoProducto = rand() % 5 ;
            strcpy(Buff2,TiposProductos[aleatorioTipoProducto]);
            mClientes[i]->Productos->TipoProducto = (char *) malloc((strlen(Buff2)+1));
            strcpy(mClientes[i]->Productos->TipoProducto, Buff2);
        }
        
    }


    for (int i = 0; i < cantidadClientes ; i++)
    {   
        sumaTotal = 0;
        printf("\n********************Cliente numero [%d]****************************\n",i+1);
        printf("Nombre: %s | Numero ID: %d\n",mClientes[i]->NombreCliente,mClientes[i]->ClienteID);
        printf("Cantidad de productos a pedir: %d \n",mClientes[i]->CantidadProductosAPedir);
        
        for (int j = 0; j < mClientes[i]->CantidadProductosAPedir; j++)
        {
            printf("\n-----------Producto [%d]----------------- \n",j+1);
            printf("Tipo de producto a pedir : %s | ID: %d \n",mClientes[i]->Productos->TipoProducto,mClientes[i]->Productos->ProductoID);
            printf("Precio unitario: %f \n",mClientes[i]->Productos->PrecioUnitario);
            printf("Cantidad pedida: %d\n",mClientes[i]->Productos->Cantidad);
            precioTotal = calculoPrecioPorProducto(mClientes[i]->Productos->Cantidad,mClientes[i]->Productos->PrecioUnitario);
            printf("Precio total a pagar : %f \n", precioTotal);
            sumaTotal = sumaTotal + precioTotal;
        }

        printf("\n**Total a pagar de todos los productos : %f** \n", sumaTotal);
        
    }

    free(mClientes);
    
    return 0;
}

float calculoPrecioPorProducto(int cantProducto, int precioUnitario)
{
    return cantProducto * precioUnitario;
}


// problema genera siempre el mismo aleatorio en los productos.