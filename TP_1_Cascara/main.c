#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;

    float primerOperando=0;
    float segundoOperando=0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;


    while(seguir=='s')
    {
        printf("Ingrese un numero de operacion. Recuerde que los valores estan iniciados en 0 \n\n");
        printf("1- Ingresar 1er operando (A=%.2f)\n", primerOperando);
        printf("2- Ingresar 2do operando (B=%.2f)\n", segundoOperando);
        printf("3- Calcular la suma\n");
        printf("4- Calcular la resta\n");
        printf("5- Calcular la division\n");
        printf("6- Calcular la multiplicacion\n");
        printf("7- Calcular el factorial\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n\n");
        scanf("%d",&opcion);
        while(opcion<=0 || opcion>=10)
        {
            printf("Error. Ingrese un numero de operacion valido. \n");
            scanf("%d",&opcion);
        }
        switch(opcion)
        {
            case 1:
                getFloat("Ingrese un numero: ", "Error, ingrese solo numeros.\n", 5, &primerOperando);
                break;
            case 2:
                getFloat("Ingrese un numero: ", "Error, ingrese solo numeros.\n", 5, &segundoOperando);
                break;
            case 3:
                suma(primerOperando, segundoOperando, &resultadoSuma);
                printf("El resultado de la suma es: %.2f\n", resultadoSuma);
                break;
            case 4:
                resta(primerOperando, segundoOperando, &resultadoResta);
                printf("El resultado de la resta es: %.2f\n", resultadoResta);
                break;
            case 5:
                if(!(division(primerOperando, segundoOperando, &resultadoDivision)))
                {
                    printf("El resultado de la division es: %.2f\n", resultadoDivision);
                }
                else
                {
                    printf("No se puede dividir por 0\n");
                }
                break;
            case 6:
                multi(primerOperando, segundoOperando, &resultadoMultiplicacion);
                printf("El resultado de la multiplicacion es: %.2f\n", resultadoMultiplicacion);
                break;
            case 7:
                factorial(primerOperando, segundoOperando);
                printf("\n");
                break;
            case 8:
                suma(primerOperando, segundoOperando, &resultadoSuma);
                printf("El resultado de la suma es: %.2f\n", resultadoSuma);
                resta(primerOperando, segundoOperando, &resultadoResta);
                printf("El resultado de la resta es: %.2f\n", resultadoResta);
                if(!(division(primerOperando, segundoOperando, &resultadoDivision)))
                {
                    printf("El resultado de la division es: %.2f\n", resultadoResta);
                }
                else
                {
                    printf("No se puede dividir por 0\n");
                }
                multi(primerOperando, segundoOperando, &resultadoMultiplicacion);
                printf("El resultado de la multiplicacion es: %.2f\n", resultadoMultiplicacion);
                factorial(primerOperando, segundoOperando);
                printf("\n");
                break;
            case 9:
                seguir = 'n';
                break;
        }
        printf("Presione 's' para continuar operando. \n\n");
        fflush(stdin);
        seguir=getch();
    }
    return 0;
}
