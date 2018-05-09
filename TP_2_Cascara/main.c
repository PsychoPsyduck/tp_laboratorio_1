#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"
#define LEN_PERSONAS 20


int main()
{
    int seguir;
    int menu;
    EPersona listaPersonas[LEN_PERSONAS];
    initLista(listaPersonas,LEN_PERSONAS);
    int auxDni;

    do
    {
        seguir=1;
        if(!getValidInt("1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por  nombre\n4- Imprimir grafico de edades\n5- Salir\n","\nNumero no valido\n",&menu,1,5,1))
        {
            switch(menu)
            {
            case 1:
                agregarPersona(listaPersonas,LEN_PERSONAS);
                break;
            case 2:
                if(!getValidInt("\nDNI? ","\nNo es un dni valido\n",&auxDni,0,100000000,2))
                {
                    if(!borrarPersona(listaPersonas,LEN_PERSONAS,auxDni))
                    {
                        printf("\nSe ha eliminado exitosamente\n");
                    }
                }
                break;
            case 3:
                printf("\n");
                ordenarPorDni(listaPersonas,LEN_PERSONAS,0);
                mostrarListaPersonas(listaPersonas,LEN_PERSONAS);
                printf("\n");
                break;
            case 4:
                grafico(listaPersonas,LEN_PERSONAS);
                break;
            case 5:
                seguir = 0;
                break;
            }
        }
    }while(seguir);


    return 0;
}
