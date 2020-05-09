#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct{

int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;

}sEmployee;

int initEmployees(sEmployee listEmployees[], int len);
int buscarLibre(sEmployee listEmployees[], int len);
int altaUnEmpleado(sEmployee listEmployees[], int len);
int altaEmpleados(sEmployee listEmployees[], int len);

#endif // ARRAYEMPLOYEES_H_INCLUDED
