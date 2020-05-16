
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include "ArrayEmployees.h"
#include "utn.h"

/** \brief Genera los ids.
 * \return el proximo id ha utilizar
 */
static int id = 0;

static int autoIncrementId(void)
{

    return id++;
}

/** \brief Hardcodeo de empleados para pruebas
 * \param  recibe la lista de empleados
 * \param recibe el tamaño del array
 * \return int return En caso de que no haya empleados, el array apunte a NULL o el len sea menor a 0 (-1) o (0) si esta ok.

int hardcodeoEmployees(sEmployee listEmployees[], int len)
{
    int ret = -1;
    int i;
    int id[5] = {0,1,2,3,4};
    char name[5][51] = {"matias","pedro","liliana","octavio","julio"};
    char lastName[5][51] = {"rodriguez","argento","alfonzo","rodriguez","diaz"};
    float salary[5] = {5000,800,900,5400,6000};
    int sector[5] = {1,2,3,5,4};
    int isEmpty[5] = {1,1,1,1,1};

    if(listEmployees != NULL && len >= 0)
    {
        for(i=0; i<len; i++)
        {
            listEmployees[i].id = id[i];
            strcpy(listEmployees[i].name, name[i]);
            strcpy(listEmployees[i].lastName, lastName[i]);
            listEmployees[i].salary = salary[i];
            listEmployees[i].sector = sector[i];
            listEmployees[i].isEmpty = isEmpty[i];
        }
        ret = 0;
    }
    return ret;
}*/

/** \brief Para indicar que todas las posiciones del array estan vacias
 *         esta funcion pone la bandera (isEmpty) en TRUE en todas las posiciones del array
 * \param listEmployee[] el array de empleados
 * \param len es el tamaño del array de empleados
 * \return int return En caso de que no haya empleados, el array apunte a NULL o el len sea menor a 0 (-1) o (0) si esta ok.
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

/** \brief Muestra todos los empleados
 * \param listEmployees
 * \param int len
 * \return int return En caso de que no haya empleados, el array apunte a NULL o el len sea menor a 0 (-1) o (0) si esta ok.
 */
int printEmployees(sEmployee listEmployees[], int len)
{
    int ret = -1;

    int i;

    if(listEmployees != NULL && len >= 0)
    {
        for(i=0;i<len;i++)
        {
            if(listEmployees[i].isEmpty == 1)
            {
                mostrarUnEmpleado(listEmployees,len,i);
                ret = 0;
            }
        }
        if(ret == -1)
        {
            printf("\nNo hay empleados cargados\n");
        }
    }
    return ret;
}

/** \brief Muestra un empleado
 * \param listEmployees
 * \param int len
 * \return int return (-1) En caso de error. (0) si esta ok.
 *
 */
int mostrarUnEmpleado(sEmployee listEmployees[], int len, int index)
{
    int ret = -1;

    if(listEmployees != NULL)
    {
            printf("\nId: %d\nNombre: %s\nApellido: %s\nSalario: %.2f\nSector: %d\n",listEmployees[index].id,
                                                                                     listEmployees[index].name,
                                                                                     listEmployees[index].lastName,
                                                                                     listEmployees[index].salary,
                                                                                     listEmployees[index].sector);
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
            utn_getString(name,"\nIngrese el nombre: ","\nError, reingrese: ",3,51,3);
            utn_getString(lastName,"\nIngrese el apellido: ","\nError, reingrese: ",3,51,3);
            utn_getFloat(&salary,"\nIngrese el salario: ","\nError, reingrese: ",0,FLT_MAX);
            utn_getInt(&sector,"\nIngrese el sector: ","\nError, reingrese: ",0,INT_MAX);

            if(addEmployees(listEmployees,len,id,name,lastName,salary,sector) == 0)
            {
                printf("\nAlta Exitosa");
            }

            respuesta = utn_getChar("\n¿Quiere continuar cargando altas? (s/n): ","\nError, reingrese: ",'n','s');
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
            if(id == listEmployees[i].id && listEmployees[i].isEmpty == 1)
            {
                index = i;
                break;
            }
        }

        if(index == -1)
        {
            printf("\nNo existe ese empleado");
        }
    }

    return index;
}

/** \brief Modifica algun campo de un empleado
 * \param la lista de empleados
 * \param el largo de la lista
 * \return (-1) En caso de que el puntero sea NULL o el size sea menor a 0. (0) si esta ok.
 *
 */
int modificarEmpleado(sEmployee listEmployees[], int len)
{
    int ret = -1;
    int idAux;
    int index;

    if(listEmployees != NULL && len >= 0)
    {
        if(printEmployees(listEmployees,len) == 0)
        {
            utn_getInt(&idAux,"\nIngrese el id: ","\nError, reingrese: ",0,1000);
            index = findEmployeeById(listEmployees,len,idAux);

            if(index != -1)
            {
                utn_getString(listEmployees[index].name,"\nIngrese el nombre: ","\nError, reingrese: ",3,51,3);
                utn_getString(listEmployees[index].lastName,"\nIngrese el apellido: ","\nError, reingrese: ",3,51,3);
                utn_getFloat(&listEmployees[index].salary,"\nIngrese el salario: ","\nError, reingrese: ",0,FLT_MAX);
                utn_getInt(&listEmployees[index].sector,"\nIngrese el sector: ","\nError, reingrese: ",0,INT_MAX);
                printf("\nEmpleado modificado exitosamente\n");
                ret = 0;
            }

        }

    }

    return ret;
}

/** \brief Elimina de manera logica un empleado
 * \param la lista de empleados
 * \param el tama;o del array
 * \return (-1) En caso de que el puntero sea NULL o el size sea menor a 0. (0) si esta ok.
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
 * \return (-1) En caso de que el puntero sea NULL o el size sea menor a 0. (0) si esta ok.
 *
 */
int borrarEmpleado(sEmployee listEmployees[], int len)
{
    int ret = -1;
    int idAux;

    if(listEmployees != NULL && len >= 0)
    {
        if(printEmployees(listEmployees,len) == 0)
        {
            utn_getInt(&idAux,"\nIngrese el id: ","\nError, reingrese: ",0,1000);
            if(removeEmployee(listEmployees,len,idAux) == 0)
            {
                printf("\nEmpleado eliminado exitosamente\n");
                ret = 0;
            }
        }

    }
    return ret;
}

/** \brief swapea 2 empleados
 * \param listEmployees[]
 * \param posicion del array i
 * \return void
 */
void swapEmployee(sEmployee listEmployees [], int i)
{
    sEmployee auxEmployee;

    auxEmployee = listEmployees[i];
    listEmployees[i] = listEmployees[i+1];
    listEmployees[i+1] = auxEmployee;

}

/** \brief Ordena los empleados por apellido y sector, el usuario debe indicar el orden.
 * \param array empleados
 * \param tamaño del array
 * \return (-1) En caso de que el puntero sea NULL o el size sea menor a 0. (0) si esta ok.
 *
 */
int sortEmployees(sEmployee listEmployees[], int len, int order)
{
    int ret = -1;
    int i;
    int flagSwap;

    if(listEmployees != NULL && len >= 0)
    {
        do
        {
            flagSwap = 0;

            for(i=0; i<len-1; i++)
            {
                if(order == 0 && strcmp(listEmployees[i].lastName, listEmployees[i+1].lastName) > 0)//A-Z
                {
                    swapEmployee(listEmployees,i);
                    flagSwap = 1;
                }
                if(order == 1 && strcmp(listEmployees[i].lastName, listEmployees[i+1].lastName) < 0)//Z-A
                {
                    swapEmployee(listEmployees,i);
                    flagSwap = 1;
                }
                if(strcmp(listEmployees[i].lastName,listEmployees[i+1].lastName) == 0)
                {
                    if(order == 0 && listEmployees[i].sector > listEmployees[i+1].sector)
                    {
                        swapEmployee(listEmployees,i);
                        flagSwap=1;
                    }
                    if(order == 1 && listEmployees[i].sector < listEmployees[i+1].sector)
                    {
                        swapEmployee(listEmployees,i);
                        flagSwap=1;
                    }
                }
            }

        } while(flagSwap);

        ret = 0;
    }

    return ret;
}

//total y promedio de los salarios, y cuantos empleados superan el salario promedio
/** \brief Encuentra la cantidad de empleados que hay cargados
 * \param array empleados
 * \param len
 * \return (-1) En caso de que el puntero sea NULL o el size sea menor a 0. La cantidad de empleados si esta ok.
 */
int cantidadEmpleados(sEmployee listEmployees[], int len)
{
    int ret = -1;
    int i;
    int cantidadEmpleados = 0;

    if(listEmployees != NULL && len >= 0)
    {
        for(i=0;i<len;i++)
        {
            if(listEmployees[i].isEmpty == 1)
            {
                cantidadEmpleados++;
            }
        }
        ret = cantidadEmpleados;
    }

    return ret;
}
/** \brief Obtiene la cantidad de empleados que superan el promedio de salarios
 * \param array empleados
 * \param len
 * \return (-1) En caso de que el puntero sea NULL o el size sea menor a 0. si esta ok la cantidad de empleados que superan el promedio de salarios
 *
 */
int cantidadEmpleadosQueSuperanElPromedio(sEmployee listEmployees[], int len, float promedioSalarios)
{
    int ret = -1;
    int i;
    int cantidadSuperanPromedio = 0;

    if(listEmployees != NULL && len >= 0)
    {
        for(i=0;i<len;i++)
        {
            if(listEmployees[i].isEmpty == 1 && listEmployees[i].salary > promedioSalarios)
            {
                cantidadSuperanPromedio++;
            }
        }
        ret = cantidadSuperanPromedio;
    }
    return ret;
}

/** \brief total y promedio de los salarios, y cuantos empleados superan el salario promedio
 * \param array empleados
 * \param len
 * \return (-1) En caso de que el puntero sea NULL o el size sea menor a 0. (0) si esta ok.
 */
int totalYPromedioSalariosEmpleados(sEmployee listEmployees[], int len)
{
    int ret = -1;
    int i;
    double totalSalarios = 0;
    float promedioSalarios;
    int cantEmpleados = 0;
    int cantidadSuperanPromedio = 0;

    if(listEmployees != NULL && len >= 0)
    {
        for(i=0;i<len;i++)
        {
            if(listEmployees[i].isEmpty == 1)
            {
                totalSalarios += listEmployees[i].salary;
            }

        }
        cantEmpleados = cantidadEmpleados(listEmployees,len);
        promedioSalarios = utn_sacarPromedio(totalSalarios,cantEmpleados);
        cantidadSuperanPromedio = cantidadEmpleadosQueSuperanElPromedio(listEmployees,len,promedioSalarios);

        printf("\nEl total de los salarios es: %.2f, el promedio de los salarios es: %.2f, y la cantidad de empleados que superan el promedio de salarios es: %d\n",totalSalarios,promedioSalarios,cantidadSuperanPromedio);
        ret = 0;
    }

    return ret;
}










