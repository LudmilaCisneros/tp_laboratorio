#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"


#define QTY_EMPLOYEES 1000

int main()
{
    sEmployee listEmployees[QTY_EMPLOYEES];

    int option;
    int subOption;
    int flag1 = 0;

    initEmployees(listEmployees, QTY_EMPLOYEES);

    do
    {
        printf("\n1.ALTA");
        printf("\n2.MODIFICAR");
        printf("\n3.BAJA");
        printf("\n4.INFORMAR");
        printf("\n 1.LISTADO DE LOS EMPLEADOS ORDENADOS ALFABETICAMENTE POR APELLIDO Y SECTOR");
        printf("\n 1.TOTAL Y PROMEDIO DE LOS SALARIOS, Y CUANTOS EMPLEADOS SUPERAN EL SALARIO PROMEDIO");
        printf("\n5.SALIR\n");
        utn_getInt(&option,"\nIngrese la opcion: ","\nError, reingrese: ",0,7);

        switch(option)
        {
        case 1:
            if(altaEmpleados(listEmployees,QTY_EMPLOYEES) == 0)
            {
                flag1 = 1;
            }
            break;

        case 2:
            if(flag1)
            {
                modificarEmpleado(listEmployees, QTY_EMPLOYEES);
            }
            else
            {
                printf("\nNo se han cargado empleados\n");
            }
            break;

        case 3:
            if(flag1)
            {
                borrarEmpleado(listEmployees, QTY_EMPLOYEES);
            }
            else
            {
                printf("\nNo se han cargado empleados\n");
            }
            break;

        case 4:
            if(flag1)
            {
                printf("\n 1.LISTADO DE LOS EMPLEADOS ORDENADOS ALFABETICAMENTE POR APELLIDO Y SECTOR");
                printf("\n 1.TOTAL Y PROMEDIO DE LOS SALARIOS, Y CUANTOS EMPLEADOS SUPERAN EL SALARIO PROMEDIO");

                utn_getInt(&subOption,"\nIngrese la opcion: ","\nError, reingrese: ",0,3);
                switch(subOption)
                {
                    case 1:
                    //1.listado de empleados ordenados alfab apellido y sector
                    break;

                    case 2:
                    //2.total y promedio de los salarios , y cuantos empleados superan el salario promedio
                    break;

                    default:
                        printf("\nOpcion Inexistente");
                        break;
                }
            }
            else{
                printf("\nNo se han cargado empleados\n");
            }
            break;

        case 5:
            //SALIR
            break;

        default:
            printf("\nOpcion Inexistente");
            break;
        }

    }
    while(option != 5);

    return 0;
}
