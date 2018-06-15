#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"
#define LIM_MOVIE 100

int main()
{
    EMovie* movie[LIM_MOVIE];
    int menu;
    int auxId;

    int cantidadActual = 0;
    int cantidadMaxima = LIM_MOVIE;
    int auxIndice;

    char auxTitulo[40];


    do
    {
        getValidInt("\n\n1.Agregar pelicula\n2.Borrar pelicula\n3.Modificar pelicula\n4.Generar pagina web\n5.Salir\n"
                    ,"\nNo valida\n",&menu,0,5,1);

        switch(menu)
        {
            case 1:
                auxIndice=cantidadActual;
                funciones_add(movie,&cantidadMaxima,&cantidadActual);
                mostrarPelicula(movie,auxIndice);
                cargarAlArchivo(movie,auxIndice);
                break;
            case 2:
                cantidadActual = 0;
                cargarDeArchivo(movie,&cantidadMaxima,&cantidadActual);
                mostrarIdTitulo(movie,cantidadActual);
                getValidInt("\n\nIngrese un id a eliminar: \n","\nId no valido\n",&auxId,0,cantidadActual,2);
                guardarTodoMenos(movie,cantidadActual,auxId);
                //mostrarIdTitulo(movie,cantidadActual);
                break;
            case 3:
                cantidadActual = 0;
                cargarDeArchivo(movie,&cantidadMaxima,&cantidadActual);
                mostrarIdTitulo(movie,cantidadActual);
                getValidInt("\n\nIngrese un id a eliminar: \n","\nId no valido\n",&auxId,0,cantidadActual,2);
                break;
            case 4:
                cargarDeArchivo(movie,&cantidadMaxima,&cantidadActual);
                crearHTML(movie,&cantidadActual);
                break;
        }

    }while(menu != 5);

    return 0;
}
