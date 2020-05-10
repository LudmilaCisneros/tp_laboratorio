
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include "ArrayEmployees.h"
#include "utn.h"

/*2.1 Función initEmployees
2.2 Función addEmployees
2.3 Función findEmployeeById
2.4 Función removeEmployee
2.5 Función sortEmployeeByName
2.6 Función printEmployees*/

/** \brief Genera los ids.
 * \return el proximo id ha utilizar
 */
static int id = 0;

static int autoIncrementId(void)
{

    return id++;
}

/** \brief Para indicar que todas las posiciones del array estan vacias
 *         esta funcion pone la bandera (isEmpty) en TRUE en todas las posiciones del array
 * \param listEmployee[] el array de empleados
 * \param len es el tamaño del array de empleados
 * \return int return (-1) En caso de error. (0) si esta ok.
 */
int initEmployees(sEmployee listEmployees[], int len)
{
    int ret = -1;
    int i;

    if(listEmployees != NULL && len >= 0)
    {
        for(i=0;i<len;i++)
        {
            listEmployees[i].isEmpty = 0;
        }
        ret = 0;
    }

    return ret;
}
/** \brief Busca un lugar libre en el array de lista empleados
 * \param recibe el array empleados
 * \param recibe el len
 * \return (-1) En caso de error. (index) si esta ok.
 *
 */
int buscarLibre(sEmployee listEmployees[], int len)
{
    int index = -1;
    int i;

    if(listEmployees != NULL && len >= 0)
    {
        for(i=0;i<len;i++)
        {
            if(listEmployees[i].isEmpty == 0)
            {
                index = i;
            }
        }
        if(index == -1)
        {
            printf("\nNo hay espacio");
        }
    }
    return index;
}

/** \brief Realiza el alta de un empleado
 * \param recibe el array de la lista de empleados
 * \param recibe el largo de la lista
 * \return (-1) En caso de error. (0) si esta ok.
 *
 */
int addEmployees(sEmployee listEmployees[], int len, int id, char* name, char* lastName, float salary, int sector)
{
    int ret = -1;
    int index;


    if(listEmployees != NULL && len >= 0)
    {
        index = buscarLibre(listEmployees,len);

        if(index != -1)
        {
            strncpy(listEmployees[index].name,name,sizeof(listEmployees[index].name));
            strncpy(listEmployees[index].lastName,lastName,sizeof(listEmployees[index].lastName));
            listEmployees[index].salary = salary;
            listEmployees[index].sector = sector;
            listEmployees[index].isEmpty = 1;
            listEmployees[index].id = autoIncrementId();
        }
        ret = 0;
    }

    return ret;
}
/** \brief Realiza alta de empleados
 * \param recibe la lista de empleados
 * \param recibe el largo de la lista
 * \return (-1) En caso de error. (0) si esta ok
 *
 */
int altaEmpleados(sEmployee listEmployees[], int len)
{
    int ret = -1;
    int i;
    char respuesta;
    char name[51];
    char lastName[51];
    float salary;
    int sector;

    if(listEmployees != NULL && len >= 0)
    {
        for(i=0;i<len;i++)
        {
            utn_getString(name,"\nIngrese el nombre: ","\nError",3,51,3);
            utn_getString(lastName,"\nIngrese el apellido: ","\nError",3,51,3);
            utn_getFloat(&salary,"\nIngrese el salario: ","\nError",0,FLT_MAX);
            utn_getInt(&sector,"\nIngrese el sector: ","\nError",0,INT_MAX);

            if(addEmployees(listEmployees,len,id,name,lastName,salary,sector) == 0)
            {
                printf("\nAlta Exitosa");
            }

            respuesta = utn_getChar("\n¿Quiere continuar cargando altas? (s/n):","\nError",'n','s');
            if(respuesta == 'n')
            {
                break;
            }
        }
        ret = 0;
    }
    return ret;
}

/** \brief busca el id pasado por parametro
 * \param listEmployees[]
 * \param len int
 * \param id int
 * \return (-1) En caso de error. (index) si esta ok.
 *
 */
int findEmployeeById(sEmployee listEmployees[], int len, int id)
{
    int index = -1;
    int i;

    if(listEmployees != NULL && len >= 0)
    {
        for(i=0;i<len;i++)
        {
            if(id == i && listEmployees[i].isEmpty == 1)
            {
                index = i;
                break;
            }
        }

        if(index == -1)
        {
            printf("No existe ese empleado");
        }
    }

    return index;
}

/** \brief Modifica algun campo de un empleado
 * \param la lista de empleados
 * \param el largo de la lista
 * \return (-1) En caso de error. (0) si esta ok
 *
 */
int modificarEmpleado(sEmployee listEmployees[], int len)
{
    int ret = -1;
    int idAux;
    int index;

    if(listEmployees != NULL && len >= 0)
    {
        //mostrarEmpleados();
        utn_getInt(&idAux,"\nIngrese el id: ","\nError",0,1000);
        index = findEmployeeById(listEmployees,len,idAux);

        utn_getString(listEmployees[index].name,"\nIngrese el nombre: ","\nError",3,51,3);
        utn_getString(listEmployees[index].lastName,"\nIngrese el apellido: ","\nError",3,51,3);
        utn_getFloat(&listEmployees[index].salary,"\nIngrese el salario: ","\nError",0,FLT_MAX);
        utn_getInt(&listEmployees[index].sector,"\nIngrese el sector: ","\nError",0,INT_MAX);
        ret = 0;
    }

    return ret;
}

/** \brief Elimina de manera logica un empleado
 * \param la lista de empleados
 * \param el tama;o del array
 * \return (-1) En caso de error. (0) si esta ok.
 *
 */
int removeEmployee(sEmployee listEmployees[], int len, int id)
{
    int ret = -1;
    int index;

    if(listEmployees != NULL && len >= 0)
       {
         index = findEmployeeById(listEmployees, len, id);
         listEmployees[index].isEmpty = 0;
         ret = 0;
       }

    return ret;
}

/** \brief Elimina un empleado
 * \param listEmployees[]
 * \param len
 * \return (-1) En caso de error. (0) si esta ok.
 *
 */
int borrarEmpleado(sEmployee listEmployees[], int len)
{
    int ret = -1;
    int idAux;

    if(listEmployees != NULL && len >= 0)
    {
        //mostrarEmpleados
        utn_getInt(&idAux,"\nIngrese el id: ","\nError",0,1000);
        if(removeEmployee(listEmployees,len,idAux) == 0)
        {
            ret = 0;
        }

    }
    return ret;
}






