#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

//Funciones criterio
int employee_compareSueldo(void* pEmployeeA,void* pEmployeeB);
int employee_compareNombre(void* pEmployeeA,void* pEmployeeB);
int employee_compareId(void* pEmployeeA,void* pEmployeeB);
int employee_compareHorasTrabajadas(void* pEmployeeA,void* pEmployeeB);

#endif // employee_H_INCLUDED
