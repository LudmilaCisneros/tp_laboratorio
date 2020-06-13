#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
	Employee* employee = (Employee*)malloc( sizeof(Employee));
	return employee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* employee=employee_new();

	if(employee!=NULL)
	{
		employee->horasTrabajadas=atoi(horasTrabajadasStr);
		//strncpy(employee->nombre,nombreStr,sizeof(nombreStr));
		strcpy(employee->nombre,nombreStr);
		employee->id=atoi(idStr);
		employee->sueldo=atoi(sueldoStr);
	}
	return employee;
}
/////////////////////GENERANDO SETTERS AND GETTERS/////////////////////
/** \brief Agrega un id a la lista
 * * \param Employee* this
 * * \param int id
 * * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok * */

int employee_setId(Employee* this,int id)
{
	int returnAux =-1;
	if(this!=NULL)
	{
		this->id=id;
		returnAux=0;
	}
	return returnAux;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Agrega el nombre a la lista
 * * \param Employee* this
 * * \param int id
 * * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok * */
int employee_getId(Employee* this,int* id)
{
	int returnAux=-1;

	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		returnAux=0;
	}
	return returnAux;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Agrega el nombre a la lista
 * * \param Employee* this
 * * \param int id
 * * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok * */
int employee_setNombre(Employee* this,char* nombre)
{
	int returnAux=-1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		returnAux=0;
	}
	return returnAux;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Agrega el nombre a la lista
 * * \param Employee* this
 * * \param int id
 * * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok * */
int employee_getNombre(Employee* this,char* nombre)
{
	int returnAux=-1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		returnAux=0;
	}
	return returnAux;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Agrega el nombre a la lista
 * * \param Employee* this
 * * \param int id
 * * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok * */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int returnAux=-1;

	if(this!=NULL && horasTrabajadas>=0)
	{
		this->horasTrabajadas=horasTrabajadas;
		returnAux=0;
	}
	return returnAux;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Agrega el nombre a la lista
 * * \param Employee* this
 * * \param int id
 * * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok * */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int returnAux=-1;

	if(this!=NULL && horasTrabajadas>=0)
	{
		*horasTrabajadas=this->horasTrabajadas;
		returnAux=0;
	}
	return returnAux;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Agrega el nombre a la lista
 * * \param Employee* this
 * * \param int id
 * * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok * */
int employee_setSueldo(Employee* this,int sueldo)
{
	int returnAux=-1;

	if(this!=NULL && sueldo>=0)
	{
		this->sueldo=sueldo;
		returnAux=0;
	}
	return returnAux;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Agrega el nombre a la lista
 * * \param Employee* this
 * * \param int id
 * * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok * */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int returnAux=-1;

	if(this!=NULL && sueldo>=0)
	{
		*sueldo=this->sueldo;
		returnAux=0;
	}
	return returnAux;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int employee_compareSueldo(void* pEmployeeA,void* pEmployeeB)
{
    int returnAux = 0;
    if(((Employee*)pEmployeeA)->sueldo > ((Employee*)pEmployeeB)->sueldo)
    {
        returnAux = 1;
    }
    if(((Employee*)pEmployeeA)->sueldo < ((Employee*)pEmployeeB)->sueldo)
    {
        returnAux = -1;
    }
    return returnAux;
}

int employee_compareNombre(void* pEmployeeA,void* pEmployeeB)
{
    int returnAux = 0;
    if(strcmp(((Employee*)pEmployeeA)->nombre,((Employee*)pEmployeeB)->nombre)>0)
    {
        returnAux = 1;
    }
    if(strcmp(((Employee*)pEmployeeA)->nombre,((Employee*)pEmployeeB)->nombre)<0)
    {
        returnAux = -1;
    }
    return returnAux;
}

int employee_compareId(void* pEmployeeA,void* pEmployeeB)
{
    int returnAux = 0;
    if(((Employee*)pEmployeeA)->id > ((Employee*)pEmployeeB)->id)
    {
        returnAux = 1;
    }
    if(((Employee*)pEmployeeA)->id < ((Employee*)pEmployeeB)->id)
    {
        returnAux = -1;
    }
    return returnAux;
}

int employee_compareHorasTrabajadas(void* pEmployeeA,void* pEmployeeB)
{
    int returnAux = 0;
    if(((Employee*)pEmployeeA)->horasTrabajadas > ((Employee*)pEmployeeB)->horasTrabajadas)
    {
        returnAux = 1;
    }
    if(((Employee*)pEmployeeA)->horasTrabajadas < ((Employee*)pEmployeeB)->horasTrabajadas)
    {
        returnAux = -1;
    }
    return returnAux;
}






