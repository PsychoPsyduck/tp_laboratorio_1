#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"
#include "ArrayList.h"
#define LIM_MOVIE 100

int main()
{
    ArrayList* plistaPeliculas;
    plistaPeliculas = al_newArrayList();
    int menu;
    EMovie* auxArrayEmovie;
    do
    {
        getValidInt("\n\n1.Agregar pelicula\n2.Borrar pelicula\n3.Modificar pelicula\n4.Generar pagina web\n5.Salir\n"
                    ,"\nNo valida\n",&menu,0,5,1);

        switch(menu)
        {
                case 1:
                funciones_cargarPelicula(auxArrayEmovie,plistaPeliculas);
                break;
            case 2:
                plistaPeliculas = al_newArrayList();
                funciones_cargarDeArchivo(plistaPeliculas);
                funciones_borrarPelicula(plistaPeliculas);
                break;
            case 3:
                plistaPeliculas = al_newArrayList();
                funciones_cargarDeArchivo(plistaPeliculas);
                funciones_modificarPelicula(plistaPeliculas);
                break;
            case 4:
                plistaPeliculas = al_newArrayList();
                funciones_cargarDeArchivo(plistaPeliculas);
                funciones_crearHTML(plistaPeliculas);
                break;
            case 5:
                menu=5;
                break;
        }

    }while(menu != 5);

    return 0;
}
