#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Funtions.h"
#include <limits.h>

void abrirMenu()
{
    int option;
    int numero1;
    int numero2;
    int flag1=0;
    int flag2=0;
    int flag3=0;
    int pSuma;
    int pResta;
    int pMultiplica;

    do
    {
        printf("\n1. Ingresar 1er operando (A=x)");
        printf("\n2. Ingresar 2do operando (B=y)");
        printf("\n3. Calcular todas las operaciones\na) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division (A/B)\nd) Calcular la multiplicacion (A*B)\ne) Calcular el factorial (A!)");
        printf("\n4. Informar resultados\na) “El resultado de A+B es: r”\nb) “El resultado de A-B es: r”\nc) “El resultado de A/B es: r” o “No es posible dividir por cero”\nd) “El resultado de A*B es: r”\ne) “El factorial de A es: r1 y El factorial de B es: r2”");
        printf("\n5. Salir");

        option = utn_getInt("\nIngrese la option: ","\nError, Reingrese: ",1,6);

        switch(option)
        {
        case 1://Pedir numero1
            if((numero1 = utn_getInt("\nIngrese el primer numero: ","Error, Reingrese: ",0,INT_MAX) == 0))
            {
                flag1 = 1;
            }
            break;

        case 2://Pedir numero2
            if(flag1==1)
            {
                if((numero2 = utn_getInt("\nIngrese el segundo numero: ","Error, Reingrese: ",0,INT_MAX) == 0))
                {
                    flag2=1;
                }
            }
            else
            {
                printf("\n Error, No se cargo el numero 1.");
            }
            break;

        case 3://Calcular todas las operaciones
            if(flag1 == 1 && flag2 == 1)
            {
                sumar(&pSuma,numero1,numero2);
                restar(&pResta,numero1,numero2);
                multiplicar(&pMultiplica,numero1,numero2);
            }
            else
            {
                printf("No ingreso los dos numeros para operar.");
            }
            break;

        case 4://Informar resultados
            if(flag1 == 1 && flag2 == 1 && flag3 == 1)
            {
                printf("\nEl resultado de la suma es: %d",pSuma);
                printf("\nEl resultado de la resta es: %d",pResta);
                printf("\nEl resultado de la multiplicacion es: %d",pMultiplica);
            }
            else
            {
                printf("No ingreso los dos numeros para operar o no calculo todavia.");
            }
            break;

        case 5://Salir
            break;

        default:
            printf("ERROR, opcion inexistente");

        }
    }
    while(option != 5);

    int sumar(int* pSuma, int numero1, int numero2)
    {
        int ret = -1;
        int auxResultado;

        if(pSuma  != NULL )
        {
            auxResultado = (numero1 + numero2);
            *pSuma = auxResultado;
            ret = 0;
        }

        return ret;
    }

    int restar(int* pResta, int numero1, int numero2)
    {
        int ret = -1;
        int auxResultado;

        if(pResta  != NULL )
        {
            auxResultado = (numero1 - numero2);
            *pResta = auxResultado;
            ret = 0;
        }

        return ret;
    }

    int multiplicar(int* pMultiplica, int numero1, int numero2)
    {
        int ret = -1;
        int auxResultado;

        if(pMultiplica  != NULL )
        {
            auxResultado = (numero1 * numero2);
            *pMultiplica = auxResultado;
            ret = 0;
        }

        return ret;
    }
}
