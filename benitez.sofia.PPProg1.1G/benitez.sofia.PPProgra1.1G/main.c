#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char procesador[30];
    char marca[30];
    float precio;

}eNotebook;

float aplicarDescuento(int precio);
int contarCaracteres(char cadena[], char caracter);
void ordenarPorMarca(eNotebook notebooks[], int tam);

int main()
{
    float precio;
    char cadena[]="Bienvenido";
    int cant;

    cant=contarCaracteres(cadena, 'e');
    printf("ej 2: %d\n", cant);

    precio=aplicarDescuento(500);
    printf("ej 1: %f\n", precio);


    eNotebook notebooks[6]={
        {1, "intel", "HP", 200000},
        {2, "intel", "Lenovo", 25000},
        {3, "intel", "Apple", 500000},
        {4, "intel", "BGH", 22000},
        {5, "intel", "HP", 150000},
    };

    ordenarPorMarca(notebooks, 6);

    for(int i=0; i<6; i++)
    {
        printf("%s\n", notebooks[i].marca);
        printf("%f\n", notebooks[i].precio);
    }

    return 0;
}


float aplicarDescuento(int precio)
{
    float precioConDescuento;

    precioConDescuento=precio-(precio*0.05);

    return precioConDescuento;
}


int contarCaracteres(char cadena[], char caracter)
{
    int cantidad;
    int contador=0;

    for(int i=0; i<strlen(cadena); i++)
    {
        if(caracter==cadena[i])
        {
            contador++;
        }
    }
    cantidad=contador;

    return cantidad;
}


void ordenarPorMarca(eNotebook notebooks[], int tam)///marca alfabeticamente y precio ascendente
{
    eNotebook aux;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if((strcmp(notebooks[i].marca, notebooks[j].marca)>0) || ((strcmp(notebooks[i].marca, notebooks[j].marca)>0) && notebooks[i].precio >notebooks[j].precio))
            {
                aux=notebooks[i];
                notebooks[i]=notebooks[j];
                notebooks[j]=aux;
            }
        }
    }
}
