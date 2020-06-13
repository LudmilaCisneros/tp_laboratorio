#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "utn.h"

/*********************************************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
**********************************************************************************/

int main()
{
    int option;
    LinkedList* pArrayListEmployee = ll_newLinkedList();//creo una nueva linkedlist(malloc)

    do{
    	option = menu();

    	switch(option)
            {//modo texto
                case 1:
                	controller_loadFromText("data.csv",pArrayListEmployee);
                break;

                case 2://modo binario
                	controller_loadFromBinary("data.bin",pArrayListEmployee);
                break;

                case 3://ALTA
                	controller_addEmployee(pArrayListEmployee);
                break;

                case 4://MODIFICAR
                	controller_editEmployee(pArrayListEmployee);
                break;

                case 5://BAJA EMPLEADO
                	controller_removeEmployee(pArrayListEmployee);
                break;

                case 6://LISTAR EMPLEADO
                	controller_ListEmployee(pArrayListEmployee);
                break;

                case 7://ORDENAR EMPLEADO
                	controller_sortEmployee(pArrayListEmployee);
                break;

                case 8://GUARDAR MODO TEXTO
                	controller_saveAsText("data.csv",pArrayListEmployee);
                break;

                case 9://GUARDAR MODO BINARIO
                	controller_saveAsBinary("data.bin",pArrayListEmployee);
                break;

                case 10:///SALIR
                break;

                default:
                	printf("Opcion invalida");
                break;
        }
    }while(option != 10);

    return 0;
}

