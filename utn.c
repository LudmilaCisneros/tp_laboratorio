#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int utn_getInt(int* numero, char* mensaje,char* mensajeError,int rangoMin, int rangoMax)
{
    int ret = -1;
    int auxNum;

    printf("%s",mensaje);
    scanf("%i",&auxNum);

    if(numero != NULL)
    {
        while(auxNum<rangoMin || auxNum>rangoMax)
            {
                printf("%s",mensajeError);
                scanf("%i",&auxNum);
            }
        *numero = auxNum;
        ret = 0;
    }

    return ret;
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

float utn_getFloat(float* numero, char* mensaje,char* mensajeError,float rangoMin, float rangoMax)
{
    int ret = -1;
    float auxNum;

    if(numero != NULL)
    {
        printf("%s",mensaje);
        scanf("%f",&auxNum);

        while(auxNum<rangoMin || auxNum>rangoMax)
        {
            printf("%s",mensajeError);
            scanf("%f",&auxNum);
        }
        *numero = auxNum;
        ret = 0;
    }

    return ret;
}
