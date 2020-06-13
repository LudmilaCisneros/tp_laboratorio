#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"
#include "Controller.h"

/** \brief Muestra menu de opciones,
 * y le pide al usuario que ingrese una opcion
 * \return int con la opcion
 */
int menu()
{
	int option;

	printf("\n****************************************************");
	printf("\nMENU: ");
	printf("\n1.Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
	printf("\n2.Cargar los datos de los empleados desde el archivo data.csv (modo binario).");
	printf("\n3.Alta de empleado.");
	printf("\n4.Modificar datos de empleado.");
	printf("\n5.Baja de empleado.");
	printf("\n6.Listar empleados.");
	printf("\n7.Ordenar empleados.");
	printf("\n8.Guardar los datos de los empleados en el archivo data.csv (modo texto).");
	printf("\n9.Guardar los datos de los empleados en el archivo dataBin.csv (modo binario).");
	printf("\n10.Salir");
	printf("\n****************************************************");

	utn_getInt(&option,"\nIngrese la opcion:","\nError\n",1,10,3);

	return option;
}

/** \brief Generate and keep track of the ids.
 * \return int Return the next id to use.
 *
 */
static int autoIncremenId(void)
{
    static int id=1;
    return id++;
}
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int returnAux;
	FILE* pFile;

	pFile = fopen(path,"r");

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		returnAux=parser_EmployeeFromText(pFile,pArrayListEmployee);
		printf("\nSe leyeron del archivo %d elementos en modo texto",returnAux);
	}
	else
	{
		printf("El archivo no fue abierto");
		returnAux=-1;
	}
	fclose(pFile);
	return returnAux;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int returnAux;
	FILE* pFile;

	pFile = fopen(path,"rb");

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		returnAux=parser_EmployeeFromBinary(pFile,pArrayListEmployee);
		printf("\nSe leyeron del archivo %d elementos en modo binario",returnAux);
	}
	else
	{
		printf("El archivo no fue abierto");
		returnAux=-1;
	}
	fclose(pFile);
	return returnAux;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int returnAux=-1;
	char pNombreAux[100];
	int pHorasAux;
	int pSueldoAux;
	Employee* employee;

	if(pArrayListEmployee!=NULL)
	{
		if(utn_getString(pNombreAux,"\nIngrese el nombre:","Error",4,90,3)==0 &&
		   utn_getInt(&pHorasAux,"\nIngrese las horas trabajadas: ","Error",0,600,3)==0 &&
		   utn_getInt(&pSueldoAux,"\nIngrese el sueldo: ","Error",0,100000,3)==0)
		{
			employee=employee_new();
			employee_setId(employee,autoIncremenId());
			employee_setNombre(employee,pNombreAux);
			employee_setHorasTrabajadas(employee,pHorasAux);
			employee_setSueldo(employee,pSueldoAux);
			ll_add(pArrayListEmployee,employee);

			returnAux=0;
		}
		else
		{
			printf("Ocurrio un error");
		}
	}
    return returnAux;
}

/** \brief Modificar datos de empleado
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	{
	    int returnAux=-1;
	    int option;
	    int index;
	    char bufferModificacionStr[200];
	    char bufferModificacionInt[200];
	    int bufferID;
	    int bufferHoras;
	    int bufferSueldo;
	    char bufferNombre[200];
	    Employee* pAux=NULL;

	    if(pArrayListEmployee!=NULL)
	    {
	    	controller_ListEmployee(pArrayListEmployee);
	        if(utn_getInt(&bufferID,"\nID a modificar: ","\nError",1,4545454,3)==0)
	        {
	            if(controller_searchEmployeeById(pArrayListEmployee,bufferID,&index)==-1)
	            {
	                printf("\nNo existe este ID");
	            }
	            else
	            {
	                do
	                {
	                	pAux=ll_get(pArrayListEmployee,index);
	                    employee_getId(pAux,&bufferID);
	                    employee_getNombre(pAux,bufferNombre);
	                    employee_getHorasTrabajadas(pAux,&bufferHoras);
	                    employee_getSueldo(pAux,&bufferSueldo);
	                    printf("\n ID: %d   Nombre: %s  Horas: %d   Sueldo: %d",bufferID,bufferNombre,bufferHoras,bufferSueldo);

	                    utn_getInt(&option,"\n¿Que desea modificar?: \n1.Nombre \n2.Horas \n3.Sueldo \n4.(salir)","\nError",1,6,3);
	                    switch(option)
	                    {
	                        case 1:
	                            utn_getString(bufferModificacionStr,"\nNombre: ","\nError",1,200,3);
	                            employee_setNombre(pAux,bufferModificacionStr);
	                            break;
	                        case 2:
	                            utn_getString(bufferModificacionInt,"\nHoras: ","\nError",1,200,3);
	                            employee_setHorasTrabajadas(pAux,atoi(bufferModificacionInt));
	                            break;
	                        case 3:
	                            utn_getString(bufferModificacionInt,"\nSueldo: ","\nError",1,200,3);
	                            employee_setSueldo(pAux,atoi(bufferModificacionInt));
	                            break;

	                        case 4:
	                            break;
	                        default:
	                            printf("\nOpcion no valida");
	                    }
	                }while(option!='4');
	                returnAux=0;
	            }
	        }
	    }
	    return returnAux;
	}
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int returnAux=-1;
	int auxId;
	controller_ListEmployee(pArrayListEmployee);
	auxId = utn_getInt(&auxId,"\nIngrese el ID del empleado a eliminar: \n","\nError\n",0,541544544,4);
	if(pArrayListEmployee != NULL)
	{
		for(int i=0;i<ll_len(pArrayListEmployee);i++)
		{
			if(i==auxId)
			{
				ll_remove(pArrayListEmployee,auxId);
			}
		}
	returnAux=0;
	}
	else
	{
		printf("Error");
	}
    return returnAux;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int returnAux=0;
    int len;
    if(pArrayListEmployee!=NULL)
    {
        if(ll_len(pArrayListEmployee)>0)
        {
            len=ll_len(pArrayListEmployee);
            for(i=0; i<len; i++)
            {
                controller_PrintEmployee(pArrayListEmployee,i);
            }
            returnAux=0;
        }
        else
        {
            printf("No existen registros cargados.");
        }
    }
    return returnAux;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	{
	    int ret = -1;
	    if(pArrayListEmployee != NULL)
	    {
	        int order;
	        int option;
	        if(ll_len(pArrayListEmployee)>0)
	        {
	            if(utn_getInt(&option,"Seleccione criterio para ordenar:\n1.Id\n2.Nombre\n3.Horas Trabajadas\n4.Sueldo\n-> ","Opcion invalida\n",1,4,10)==0)
	            {
	                if(utn_getInt(&order,"Seleccione orden:\n1.Ascendente\n2.Descendente\n-> ","Opcion invalida\n",1,2,10)==0)
	                {
	                    if(order==2)
	                    {
	                        order=0;
	                    }
	                    switch(option)
	                    {
	                    case 1:
	                        ll_sort(pArrayListEmployee,employee_compareId,order);
	                        break;
	                    case 2:
	                        ll_sort(pArrayListEmployee,employee_compareId,order);
	                        ll_sort(pArrayListEmployee,employee_compareNombre,order);
	                        break;
	                    case 3:
	                        ll_sort(pArrayListEmployee,employee_compareId,order);
	                        ll_sort(pArrayListEmployee,employee_compareHorasTrabajadas,order);
	                        break;
	                    case 4:
	                        ll_sort(pArrayListEmployee,employee_compareId,order);
	                        ll_sort(pArrayListEmployee,employee_compareSueldo,order);
	                        break;
	                    }
	                    ret = 0;
	                    printf("Operacion completada");
	                }
	                else
	                {
	                    printf("Demasiados intentos erroneos, operacion cancelada.");
	                }
	            }
	            else
	            {
	                printf("Demasiados intentos erroneos, operacion cancelada.");
	            }
	        }
	        else
	        {
	            printf("No existen registros cargados.");
	        }
	    }
	    return ret;
	}
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	Employee* bufferEmployee;
	FILE* pFile;
	int bufferId;
	char bufferNombre[4096];
	int bufferHorasTrabajadas;
	int bufferSueldo;
	int i;
	int ret=0;
	int len;

	pFile=fopen(path,"w");
	if(pArrayListEmployee!=NULL && pFile!=NULL)
		{
	        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");//escribo en el archivo
	        len=ll_len(pArrayListEmployee);
	        for(i=0; i<len; i++)
	        {
	            bufferEmployee=(Employee*)ll_get(pArrayListEmployee,i);
	            employee_getId(bufferEmployee,&bufferId);
	            employee_getNombre(bufferEmployee,bufferNombre);
	            employee_getHorasTrabajadas(bufferEmployee,&bufferHorasTrabajadas);
	            employee_getSueldo(bufferEmployee,&bufferSueldo);
	            fprintf(pFile,"%d,%s,%d,%d\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);//escribo en un archivo
	            ret++;
	        }
	        fclose(pFile);
	    }
	    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    Employee* bufferEmployee;
    FILE* pFile;
    int i;
    int returnAux=0;
    int len;
    pFile=fopen(path,"wb");
    if(pArrayListEmployee!=NULL && pFile!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        for(i=0; i<len; i++)
        {
            bufferEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            fwrite(bufferEmployee,sizeof(Employee),1,pFile);
            returnAux++;
        }
        fclose(pFile);
    }
    return returnAux;
}

/** \brief Obtiene el mayor id del LinkedList y lo carga en la estructura empleado.
 * \param pArrayListEmployee LinkedList*
 * \param id int
 * \param index int*
 * \return int
 */
int controller_searchEmployeeById(LinkedList* pArrayListEmployee,int id,int* index)
{
    int returnAux=-1;
    Employee* employee;
    int auxId;
    int i;

    if(pArrayListEmployee!=NULL)
    {
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            employee=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(employee,&auxId);
            if(auxId==id)
            {
                *index=i;
                returnAux=0;
            }
        }
    }
    return returnAux;
}

int controller_PrintEmployee(LinkedList* pArrayListEmployee, int index)
{
    Employee* bufferEmployee;
    int bufferId;
    char bufferNombre[4096];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    int returnAux=0;
    if(pArrayListEmployee!=NULL && index>=0 && index<ll_len(pArrayListEmployee))
    {
        bufferEmployee=(Employee*)ll_get(pArrayListEmployee,index);
        employee_getId(bufferEmployee,&bufferId);
        employee_getNombre(bufferEmployee,bufferNombre);
        employee_getHorasTrabajadas(bufferEmployee,&bufferHorasTrabajadas);
        employee_getSueldo(bufferEmployee,&bufferSueldo);
        printf("%d,%s,%d,%d\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
        returnAux=0;
    }
    return returnAux;
}
/*filtra por varios
 * LinkedList* ll_filter(LinkedList* this,int (pFunc)(void))
{
    LinkedList* returnAux = NULL;
    int i;
    int size;
    LinkedList* filterList = NULL;
    void* pElement;

    size = ll_len(this);
    if(this != NULL && pFunc != NULL)
    {
        filterList = ll_newLinkedList();
        if(filterList != NULL)
        {
            for(i=0; i<size; i++)
            {
                pElement = ll_get(this,i);
                if(pElement != NULL && pFunc(pElement) == 0)
                {
                    ll_add(filterList,pElement);
                }
            }
            returnAux = filterList;
        }
    }

    return returnAux;
}
si hay alguna que cumpla el criterio rompe
int ll_map(LinkedList* this,int (pFunc)(void))
{
    int returnAux;
    int size;
    int i;
    void* pElement;

    size = ll_len(this);
    if(this != NULL && pFunc != NULL)
    {
        returnAux = 0;
        for(i=0; i<size; i++)
        {
            pElement = ll_get(this,i);
            if(pElement != NULL && pFunc(pElement) == -1)
            {
                returnAux = -1*i; /// la multiplicacion indica hasta donde llego con el proceso en caso de que la funcion sea grande
                break;
            }
        }
    }
    return returnAux;
}*/

