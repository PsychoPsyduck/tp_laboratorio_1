#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;
}EPersona;

#endif // FUNCIONES_H_INCLUDED

/** \brief Inicializa la lista con el estado en 1
 *
 * \param array EPersona* recibe un array
 * \param limite int recibe el limite del array
 * \return int retorna 0 si esta funciono correctamente, -1 si la lista esta vacia
 *
 */
int initLista(EPersona* array,int limite);

/** \brief Agrega una persona a la lista
 *
 * \param array EPersona* recibe un array
 * \param limite int recibe el limite del array
 * \return int retorna 0 si esta funciono correctamente, -1 si la lista esta vacia
 *
 */
int agregarPersona(EPersona* array,int limite);

/** \brief Borra una persona de la lista
 *
 * \param array EPersona* recibe un array
 * \param limite int recibe el limite del array
 * \param dni int recibe un dni como referencia
 * \return int retorna 0 si esta funciono correctamente, -1 si el dni es negativo
 *
 */
int borrarPersona(EPersona* array,int limite, int dni);

/** \brief Imprime los datos de la lista que no este vacios
 *
 * \param array EPersona* recibe un array
 * \param limite int recibe el limite del array
 * \return int retorna 0 si esta funciono correctamente, -1 si la lista esta vacia
 *
 */
int mostrarListaPersonas(EPersona* array,int limite);

/** \brief ordena la lista por dni, solo si el estado es 0
 *
 * \param array EPersona* recibe un array
 * \param limite int recibe el limite del array
 * \param orden int recibe 1 o 0 segun el orden ascendente o descentente
 * \return int retorna 0 si esta funciono correctamente, -1 si la lista esta vacia
 *
 */
int ordenarPorDni(EPersona* array,int limite, int orden);

/** \brief Imprime un grafico que muestra la cantidad de personas de cada edad
 *
 * \param array EPersona* recibe un array
 * \param limite int recibe el limite del array
 * \return int retorna 0 si esta funciono correctamente, -1 si la lista esta vacia
 *
 */
int grafico(EPersona* array, int limite);

