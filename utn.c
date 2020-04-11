#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int utn_getInt(char* mensaje,char* mensajeError,int rangoMin, int rangoMax)
{
    int numero;

    printf("%s",mensaje);
    scanf("%i",&numero);

    while(numero<rangoMin || numero>rangoMax)
    {
        printf("%s",mensajeError);
        scanf("%i",&numero);
    }
    return numero;
}

char utn_getChar(char* mensaje,char* mensajeError,char letra1, char letra2)
{
    char sexo;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&sexo);

    while(sexo != letra1 && sexo != letra2)
    {
        printf("%s",mensajeError);
        fflush(stdin);
        scanf("%c",&sexo);
    }
    return sexo;
}

float utn_getFloat(char* mensaje,char* mensajeError,float rangoMin, float rangoMax)
{
    float numero;

    printf("%s",mensaje);
    scanf("%f",&numero);

    while(numero<rangoMin || numero>rangoMax)
    {
        printf("%s",mensajeError);
        scanf("%f",&numero);
    }
    return numero;
}
