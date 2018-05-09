#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"

int buscarLugarLibre(EPersona* array,int limite);
int buscarPorDni(EPersona* array,int limite, int dni);

int initLista(EPersona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].estado=1;
        }
    }
    return retorno;
}

int agregarPersona(EPersona* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[40];
    int edad;
    int dni;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEse no es un nombre valido","\nEl maximo es 40\n",nombre,40,2))
            {
                if(!getValidInt("\nEdad? ","\nNo es una edad valida\n",&edad,0,150,2))
                {
                    if(!getValidInt("\nDNI? ","\nNo es un dni valido\n",&dni,0,100000000,2))
                    {
                        retorno = 0;
                        strcpy(array[i].nombre,nombre);
                        array[i].edad = edad;
                        array[i].dni = dni;
                        array[i].estado = 0;
                        printf("\n");
                    }
                }

            }

        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}

int borrarPersona(EPersona* array,int limite, int dni)
{
    int dniAEliminar;
    int retorno=-1;
    dniAEliminar = buscarPorDni(array,limite,dni);
    if(dniAEliminar>=0)
    {
        array[dniAEliminar].estado=1;
        retorno=0;
    }
    return retorno;
}

int mostrarListaPersonas(EPersona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        printf(" Nombre   \tEdad   \tDNI\n");
        for(i=0; i<limite; i++)
        {
            if(!array[i].estado)
            {
                printf("+ %s   \t%d   \t%d\n",array[i].nombre, array[i].edad, array[i].dni);
            }
        }
    }
    return retorno;
}

int ordenarPorDni(EPersona* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    EPersona auxiliarListaPersonas;

    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].estado && !array[i+1].estado)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden))//******
                    {
                        auxiliarListaPersonas = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarListaPersonas;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

int grafico(EPersona* array, int limite)
{
    int i;
    int menor=0;
    int adulto=0;
    int mayor=0;
    int maximo;
    int retorno = -1;

    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(!array[i].estado && array[i].edad<18)
            {
                menor++;
            }
            else if(!array[i].estado && array[i].edad>=18 && array[i].edad<=35)
            {
                adulto++;
            }
            else if(!array[i].estado && array[i].edad>35)
            {
                mayor++;
            }
        }
        if(menor >= adulto && menor >= mayor)
        {
            maximo = menor;
        }
        else if(adulto >= menor && adulto >= mayor)
        {
            maximo = adulto;
        }
        else
        {
            maximo = mayor;
        }

        printf("\n");
        for(i=maximo; i>0; i--)
        {
            if(i<=menor)
            {
                printf("+  *");
            }
            else
            {
                printf("+\t");
            }
            if(i<=adulto)
            {
                printf("\t *");
            }
            else
            {
                printf("\t");
            }
            if(i<=mayor)
            {
                printf("\t *\n");
            }
            else
            {
                printf("\t\n");
            }
        }
        printf("+|-----------------\n");
        printf(" |-18\t19-35\t+35\n\n");
    }
    return retorno;
}


//[---------------------------------------------------------]
int buscarLugarLibre(EPersona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].estado==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int buscarPorDni(EPersona* array,int limite, int dni)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].estado && array[i].dni==dni)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
