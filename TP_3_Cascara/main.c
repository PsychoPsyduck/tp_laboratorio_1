#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"



int main()
{
    EMovie* movie[10];
    int menu;

    int cantidadActual = 0;
    int cantidadMaxima = 10;
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
                funciones_add(movie,0,&cantidadActual);
                mostrarPelicula(movie,auxIndice);
                cargarAlArchivo(movie,auxIndice);
                break;
            case 2:
                if(!getValidString("\nTitulo a eliminar? ","\nEso no es un Titulo","El maximo es 40",auxTitulo,40,2))
                {
                    cargarDeArchivo(movie,&cantidadActual);
                    guardarTodoMenos(movie,cantidadActual,auxTitulo);
                }
                break;
            case 3:
                if(!getValidString("\nTitulo a eliminar? ","\nEso no es un Titulo","El maximo es 40",auxTitulo,40,2))
                {
                    cargarDeArchivo(movie,&cantidadActual);
                    modificar(movie, buscarPorTitulo(movie,cantidadActual,auxTitulo));
                }
                break;
            case 4:
                cargarDeArchivo(movie,&cantidadActual);
                crearHTML(movie,cantidadActual);
                break;
        }

    }while(menu != 5);

    return 0;
}
