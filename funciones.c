#include <stdio.h>
#include <string.h>
#include "funciones.h"
#define maxCant 100
#define NombreMax 30
void IngresarFruta(char nombres[][NombreMax], int cantidad[], float precio[], int frutas)
{
    if (frutas >= maxCant)
    {
        printf("INVENTARIO LLENO\n");
        return;
    }
    printf("Ingrese el nombre de la fruta: ");
    scanf("%s", nombres[frutas]);
    printf("Ingresar cantidad de la fruta: ");
    scanf("%d", &cantidad[frutas]);
    printf("Ingresar precio de la fruta: ");
    scanf("%f", &precio[frutas]);
    printf("FRUTA INGRESADA\n");
}

void EditarFruta(char nombres[][NombreMax], int cantidad[], float precio[], int frutas)
{
    char nombre[NombreMax];
    printf("Ingrese el nombre de la fruta que desea editar: ");
    scanf("%s", nombre);
    int index = buscarFruta(nombres, frutas, nombre);
    if (index == -1)
    {
        printf("FRUTA NO ENCONTRADA\n");
        return;
    }
    printf("Ingresar la nueva cantidad de la fruta: ");
    scanf("%d", &cantidad[index]);
    printf("Ingresar el nuevo precio de la fruta: ");
    scanf("%f", &precio[index]);
    printf("FRUTA EDITADA\n");
}

void EliminarFruta(char nombres[][NombreMax], int cantidad[], float precio[], int frutas)
{
    char nombre[NombreMax];
    printf("Ingresa el nombre de la fruta que deseas eliminar: ");
    scanf("%s", nombre);

    int index = buscarFruta(nombres, frutas, nombre);
    if (index == -1)
    {
        printf("Fruta no encontrada.\n");
        return;
    }
    
    for (int i = index; i < frutas - 1; i++)
    {
        strcpy(nombres[i], nombres[i + 1]);
        cantidad[i] = cantidad[i + 1];
        precio[i] = precio[i + 1];
    }
    frutas--;
    printf("FRUTA ELIMINADA\n");
}

void ListarFrutas(char nombres[][NombreMax], int cantidad[], float precio[], int frutas)
{
    if (frutas == 0)
    {
        printf("No hay frutas en el inventario.\n");
        return;
    }

    printf("Lista de Frutas:\n");
    for (int i = 0; i < frutas; i++)
    {
        printf("Nombre: %s, Cantidad: %d, Precio: %.2f\n", nombres[i], cantidad[i], precio[i]);
    }
}

int buscarFruta(char nombres[][NombreMax], int frutas, char nombre[])
{
    for (int i = 0; i < frutas; i++)
    {
        if (strcmp(nombres[i], nombre) == 0)
        {
            return i;
        }
    }
    return -1;
}
