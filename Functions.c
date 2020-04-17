#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Functions.h"
#include <limits.h>

/** \brief Despliega un menu de opciones.
 * \param void
 * \return -1 si esta mal, 0 si esta ok
 *
 */
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
    int pDivide;
    double pFactorial1;
    double pFactorial2;

    do
    {
        if(flag1 == 1)
        {
            printf("\n1. Ingresar 1er operando (A=%d)",numero1);
        }
        else{
             printf("\n1. Ingresar 1er operando (A=x)");
        }

        if(flag2 == 1)
        {
            printf("\n2. Ingresar 2do operando (B=%d)",numero2);
        }
        else{
             printf("\n2. Ingresar 2do operando (B=y)");
        }

        printf("\n3. Calcular todas las operaciones\n a) Calcular la suma (A+B)\n b) Calcular la resta (A-B)\n c) Calcular la division (A/B)\n d) Calcular la multiplicacion (A*B)\n e) Calcular el factorial (A!)");
        printf("\n4. Informar resultados\n a) El resultado de A+B es: r\n b) El resultado de A-B es: r\n c) El resultado de A/B es: r o No es posible dividir por cero\n d) El resultado de A*B es: r\n e) El factorial de A es: r1 y El factorial de B es: r2");
        printf("\n5. Salir");

        utn_getInt(&option,"\n\n팇ngrese la opcion: ","\n|||Error, Reingrese: ||| ",1,6);
        system("cls");

        switch(option)
        {
        case 1:
            if((utn_getInt(&numero1,"\n팇ngrese el primer numero: ","|||Error, Reingrese: |||",0,INT_MAX) == 0))
            {
                printf("\n\n|||Se cargo el primer numero exitosamente.|||\n\n");
                flag1 = 1;
            }
            break;

        case 2:
            if(flag1 == 1)
            {
                if((utn_getInt(&numero2, "\n팇ngrese el segundo numero: ","|||Error, Reingrese: |||",0,INT_MAX) == 0))
                {
                    printf("\n\n|||Se cargo el segundo numero exitosamente.|||\n\n");
                    flag2 = 1;
                }
            }
            else
            {
                printf("\n\n|||Error, No se cargo el numero 1.\n\n|||");
            }
            break;

        case 3:
            if(flag1 == 1 && flag2 == 1)
            {
                if((sumar(&pSuma,numero1,numero2)==0 &&
                        restar(&pResta,numero1,numero2)==0 &&
                        multiplicar(&pMultiplica,numero1,numero2)==0) &&
                        dividir(&pDivide, numero1, numero2)==0 &&
                        getFactorial(&pFactorial1,numero1)==0 && getFactorial(&pFactorial2,numero2)==0)
                {
                    printf("\n\n|||Calculando...|||\n\n");
                    flag3 = 1;
                }
                else
                {
                    printf("\n\n||||Error|||\n\n");
                }
            }
            else
            {
                printf("\n\n|||No ingreso los dos numeros para operar.|||\n\n");
            }
            break;

        case 4:
            if(flag1 == 1 && flag2 == 1 && flag3 == 1)
            {
                printf("\n\n틿l resultado de la suma es: %d",pSuma);
                printf("\n틿l resultado de la resta es: %d",pResta);
                printf("\n틿l resultado de la multiplicacion es: %d",pMultiplica);
                printf("\n틿l resultado de la division es: %d",pDivide);
                printf("\n틿l resultado del factorial1 es: %.0f y factorial2: %.0f\n\n",pFactorial1,pFactorial2);
            }
            else
            {
                printf("\n\n|||No ingreso los dos numeros para operar o no calculo todavia.|||\n\n");
            }
            break;

        case 5:
                printf("\n\n|||Saliendo...|||\n\n");
            break;

        default:
            printf("\n\n|||ERROR, opcion inexistente|||\n\n");

        }
    }
    while(option != 5);

}

/** \brief Suma dos numeros que recibe.
 * \param int* pSuma en donde guardaremos el resultado de la suma.
 * \param numero1
 * \param numero2
 * \return -1 si esta mal, 0 si esta ok.
 *
 */
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

/** \brief Resta dos numeros que recibe.
 * \param int* pResta en donde guardaremos el resultado de la resta.
 * \param numero1
 * \param numero2
 * \return -1 si esta mal, 0 si esta ok.
 *
 */
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

/** \brief Producto de dos numeros que recibe.
 * \param int* pMultiplica en donde guardaremos el resultado de la multiplicacion.
 * \param numero1
 * \param numero2
 * \return -1 si esta mal, 0 si esta ok.
 *
 */
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

/** \brief Producto de dos numeros que recibe.
 * \param int* pMultiplica en donde guardaremos el resultado de la multiplicacion.
 * \param numero1
 * \param numero2
 * \return -1 si esta mal, 0 si esta ok.
 *
 */
int dividir(int* pDivide, int numero1, int numero2)
{
    int ret = -1;
    int auxResultado;

    if(pDivide  != NULL )
    {
        if(numero2 == 0)
        {
            printf("\nNo es posible dividir por cero");

        }
        else
        {
            auxResultado = (numero1 / numero2);
            *pDivide = auxResultado;
            ret = 0;
        }

    }

    return ret;
}


