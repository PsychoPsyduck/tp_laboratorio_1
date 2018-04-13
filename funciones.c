#include <stdio.h>
#include <stdlib.h>


/** \brief Toma un dato float y lo devuelve al puntero resultado
 *
 * \param mensaje char* Imprime un msj al usuario
 * \param mensajeError char* Imprime un msj de error al usuario
 * \param reintentos int cantidad de reintentos
 * \param resultado float* A donde envia el resultado
 * \return int retorna 0
 *
 */
int getFloat(char* mensaje,char* mensajeError,int reintentos,float* resultado)
{
    float auxiliar;
    do
    {
        reintentos--;
        printf("%s", mensaje);
        scanf("%f", &auxiliar);
        if(!isdigit(auxiliar))
        {
            *resultado = auxiliar;
            break;
        }
        printf("%s", mensajeError);
    }while(reintentos >= 0);
    return 0;
}

/** \brief pide 2 valores y los devuelve sumados al puntero restulrado
 *
 * \param val1 float primer valor ingresado
 * \param val2 float segundo valor ingresado
 * \param resultado float* A donde envia el resultado
 * \return int retorna 0
 *
 */
int suma(float val1, float val2, float* resultado)
{
    *resultado=val1 + val2;
    return 0;
}

/** \brief pide 2 valores y los devuelve restados al puntero resultado
 *
 * \param val1 float primer valor ingresado
 * \param val2 float segundo valor ingresado
 * \param resultado float* A donde envia el resultado
 * \return int retorna 0
 *
 */
int resta(float val1, float val2, float* resultado)
{
    *resultado=val1 - val2;
    return 0;
}

/** \brief pide 2 valores y los devuelve multiplicados al puntero resultado
 *
 * \param val1 float primer valor ingresado
 * \param val2 float segundo valor ingresado
 * \param resultado float* A donde envia el resultado
 * \return int retorna 0 si se pudo dividir. si el divisor es 0 retorna -1
 *
 */
int division(float val1, float val2, float* resultado)
{
    int retorno=0;
    if(!val2)
    {
        retorno = -1;
    }
    else
    {
        *resultado = val1/val2;
    }
    return retorno;
}

/** \brief
 *
 * \param val1 float primer valor ingresado
 * \param val2 float segundo valor ingresado
 * \param resultado float* A donde envia el resultado
 * \return int retorna 0
 *
 */
int multi(float val1, float val2, float* resultado)
{
    *resultado = val1*val2;
    return 0;
}

/** \brief pide un valor y lo devuelve factorizado
 *
 * \param numero float el valor que pide
 * \param resultado float* el valor se devuelve en el puntero restulado
 * \return int retorna 0 si se puede factorizar, -1 si el numero es mayor a 12, -2 en caso de ser negativo
 *
 */
int calcularFactorial(float numero, float* resultado)
{
    int retorno = -2;
    float acum=1;
    float i;
    if(numero>0 && numero<13)
    {
        retorno=0;
        for(i = numero; i>0; i--)
        {
        acum = acum*i;
        }
        *resultado=acum;
    }
    else if(numero>12)
    {
        retorno=-1;
    }
    return retorno;
}

/** \brief pide 2 valores y devuelve un msj con su factorial, solo de ser posible su factoreo. Sino da un msj con el error.
 *
 * \param val1 float primer valor ingresado
 * \param val2 float segundo valor ingresado
 * \return int retorna 0
 *
 */
int factorial(float val1, float val2)
{
    float result1;
    float result2;
    if(!calcularFactorial(val1, &result1))
    {
        printf("El resultado de la primer factorial es: %f \n", result1);
    }
    else if(calcularFactorial(val1, &result1)==-1)
    {
        printf("Recuerde que la calculadora no factorea correctamente nros mayores a 12. \n");
    }
    else if(calcularFactorial(val1, &result1)==-2)
    {
        printf("El primer numero no puede ser factorizado\n");
    }
    if(!calcularFactorial(val2, &result2))
    {
        printf("El resultado de la segunda factorial es: %f \n", result2);
    }
    else if(calcularFactorial(val2, &result2)==-1)
    {
        printf("Recuerde que la calculadora no factorea correctamente nros mayores a 12. \n");
    }
    else if(calcularFactorial(val2, &result2)==-2)
    {
        printf("El segundo numero no puede ser factorizado\n");
    }
    return 0;
}
