#include <stdio.h>
#include <string.h>
#include "funciones.h"
#define maxCant 100
#define NombreMax 30



int main(int argc, char *argv[])
{
    char nombres[maxCant][NombreMax];
    int cantidad[maxCant];
    float precio[maxCant];
    int opcion, frutas = 0;

    do
    {
        printf("\nINVENTARIO DE TIENDA DE FRUTAS\n\n");
        printf("Seleccione la opcion para configurar el inventario:\n");
        printf("1. Ingresar fruta\n");
        printf("2. Editar frutas\n");
        printf("3. Eliminar frutas\n");
        printf("4. Listar frutas\n");
        printf("5. Salir\n");
        printf("\tSeleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            IngresarFruta(nombres, cantidad, precio, frutas);
            frutas++; 
            break;
        case 2:
            EditarFruta(nombres, cantidad, precio, frutas);
            break;
        case 3:
            EliminarFruta(nombres, cantidad, precio, frutas);
            frutas--; 
            break;
        case 4:
            ListarFrutas(nombres, cantidad, precio, frutas);
            break;
        case 5:
            printf("Saliendo del programa\n");
            break;
        default:
            printf("La opcion no es valida, vuelva a ingresar\n");
        }
    } while (opcion != 5);

    return 0;
}
