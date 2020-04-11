#ifndef FUNTIONS_H_INCLUDED
#define FUNTIONS_H_INCLUDED

/** \brief Despliega un menu de opciones.
 * \param void
 * \return -1 si esta mal, 0 si esta ok
 *
 */
void abrirMenu();
///////////////////////////////////////////////////////////////////////
/** \brief Suma dos numeros que recibe.
 * \param int* pSuma en donde guardaremos el resultado de la suma.
 * \param numero1
 * \param numero2
 * \return -1 si esta mal, 0 si esta ok.
 *
 */
int sumar(int* pSuma, int numero1, int numero2);
///////////////////////////////////////////////////////////////////////
/** \brief Resta dos numeros que recibe.
 * \param int* pResta en donde guardaremos el resultado de la resta.
 * \param numero1
 * \param numero2
 * \return -1 si esta mal, 0 si esta ok.
 *
 */
int restar(int* pResta, int numero1, int numero2);
///////////////////////////////////////////////////////////////////////
/** \brief Producto de dos numeros que recibe.
 * \param int* pMultiplica en donde guardaremos el resultado de la multiplicacion.
 * \param numero1
 * \param numero2
 * \return -1 si esta mal, 0 si esta ok.
 *
 */
int multiplicar(int* pMultiplica, int numero1, int numero2);
///////////////////////////////////////////////////////////////////////


#endif // FUNTIONS_H_INCLUDED
