#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

/** \brief Obtiene un int con rangos predeterminados
 * \param int* numero es un puntero a int en el cual guardaremos el resultado
 * \param char* mensaje es un mensaje en el cual pediremos al usuario que ingrese, y varia para que se utilice la funcion
 * \param char* mensajeError es un mensaje para validar el error
 * \param float rangoMin es el rango minimo el cual puede tener el numero
 * \param float rangoMax es el mango maximo que puede tener el numero
 * \return si esta mal -1, si esta ok 0
 *
 */
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

/** \brief Obtiene un flotante con rangos predeterminados
 * \param float* numero es un puntero a flotante en el cual guardaremos el resultado
 * \param char* mensaje es un mensaje en el cual pediremos al usuario que ingrese, y varia para que se utilice la funcion
 * \param char* mensajeError es un mensaje para validar el error
 * \param float rangoMin es el rango minimo el cual puede tener el numero
 * \param float rangoMax es el mango maximo que puede tener el numero
 * \return si esta mal -1, si esta ok 0
 *
 */
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

/** \brief Obtiene el factorial de un numero
 * \param un puntero a double en el cual guardaremos el resultado
 * \param por valor recibimos el numero al cual le aplicaremos la funcion
 * \return -1 si esta mal, 0 si esta ok
 *
 */
int getFactorial(double* pFactorial, int numero)
{
    int ret = -1;
    double auxDouble;
    int i;

    if(pFactorial != NULL)
    {
        if (numero == 1 || numero == 0)
        {
            auxDouble = 1;
        }
        else
        {
            if(numero < 0)
            {
                printf("No es posible sacar el factorial de un negativo");
            }
            else
            {
                for (i = 1; i <= numero; i++)
                {
                    auxDouble*=i;
                }
                *pFactorial = auxDouble;
                ret = 0;
            }
        }
    }
    return ret;
}

