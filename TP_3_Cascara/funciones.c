#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"


EMovie* movie_new()
{
    return malloc(sizeof(EMovie));
}


EMovie* movie_newP()
{
    EMovie* this = movie_new();

    int retorno = -1;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[200];

    if(!getValidString("\nTitulo? ","\nEso no es un Titulo","El maximo es 40",titulo,40,2))
    {
        if(!getValidString("\nGenero? ","\nEso no es un Genero","El maximo es 40",genero,40,2))
        {
            if(!getValidInt("\nDuracion? ","\nEso no es una duracion valido",&duracion,0,500,2))
            {
                if(!getValidString("\nDescripcion? ","\nEso no es una descripcion","El maximo es 40",descripcion,40,2))
                {
                    if(!getValidInt("\nPuntaje? ","\nEso no es un puntaje valido",&puntaje,0,10,2))
                    {
                        if(!getValidString("\nLink Imagen? ","\nEso no es un link","El maximo es 40",linkImagen, 200,2))
                        {
                            retorno = 0;
                            funciones_setTitulo(this,titulo);
                            funciones_setGenero(this,genero);
                            funciones_setDuracion(this,duracion);
                            funciones_setDescripcion(this,descripcion);
                            funciones_setPuntaje(this,puntaje);
                            funciones_setLinkImagen(this,linkImagen);
                            funciones_setId(this);
                            printf("\nHa cargado una pelicula\n");
                            return this;
                        }
                    }
                }
            }
        }
    }
    return retorno;
}


void funciones_add(EMovie* array[],int cantidadMaxima,int* cantidadActual)
{
    if(*cantidadActual < cantidadMaxima)
    {
    array[*cantidadActual]  = movie_newP();
    (*cantidadActual)++;
    }
}

int mostrarPelicula(EMovie* array[], int index)
{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[200];
    int id;

    funciones_getTitulo(array[index], titulo);
    funciones_getGenero(array[index], genero);
    funciones_getDuracion(array[index], &duracion);
    funciones_getDescripcion(array[index], descripcion);
    funciones_getPuntaje(array[index], &puntaje);
    funciones_getLinkImagen(array[index], linkImagen);
    funciones_getId(array[index],&id);

    printf("\n%s - %s - %d - %s - %d - %s - %d\n",titulo,genero,duracion,descripcion,puntaje,linkImagen,id);
    return 0;
}


void cargarAlArchivo(EMovie* array[],int indice)
{

    FILE *miArchivo;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[200];
    miArchivo = fopen("data.txt","a");

    if(miArchivo!=NULL)
    {
        funciones_getTitulo(array[indice], titulo);
        funciones_getGenero(array[indice], genero);
        funciones_getDuracion(array[indice], &duracion);
        funciones_getDescripcion(array[indice], descripcion);
        funciones_getPuntaje(array[indice], &puntaje);
        funciones_getLinkImagen(array[indice], linkImagen);
        fprintf(miArchivo,"%s,%s,%d,%s,%d,%s\n",titulo,genero,duracion,descripcion,puntaje,linkImagen);
        printf("\nBIEN");
    }
    fclose(miArchivo);
}

//------------------------------------------BORRAR------------------------------------------------

EMovie* funciones_newPar(char* titulo,char* genero,int duracion,char* descripcion,int puntaje,char* linkImagen)
{
    EMovie* this = movie_new();

    if(       !funciones_setTitulo(this,titulo)
       &&     !funciones_setGenero(this,genero)
       &&     !funciones_setDuracion(this,duracion)
       &&     !funciones_setDescripcion(this,descripcion)
       &&     !funciones_setPuntaje(this,puntaje)
       &&     !funciones_setLinkImagen(this,linkImagen)
       &&     !funciones_setId(this))
    {
                return this;
    }
    return NULL;
}

void arraymovies_add(EMovie* array[],int cantidadMaxima,int* cantidadActual, int indice, char* titulo,char* genero,int duracion,char* descripcion,int puntaje,char* linkImagen)
{
    if(*cantidadActual < cantidadMaxima)
    {
    array[indice]  = funciones_newPar(titulo,genero,duracion,descripcion,puntaje,linkImagen);
    (*cantidadActual)++;
    }
}

void cargarDeArchivo(EMovie* array[],int cantidadMaxima, int* cantidadActual)
{
    FILE *miArchivo;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[200];
    int indice;
    miArchivo = fopen("data.txt","r");

    if(miArchivo!=NULL)
    {
        do
        {
            indice++;
            fscanf(miArchivo,"%[^,],%[^,],%d,%[^,],%d,%[^\n]\n",titulo,genero,&duracion,descripcion,&puntaje,linkImagen);
            printf("\nBIEN");
            arraymovies_add(array,cantidadMaxima, cantidadActual,indice,titulo,genero,duracion,descripcion,puntaje,linkImagen);
        }while(!feof(miArchivo));
        fclose(miArchivo);
    }
}

 int mostrarIdTitulo(EMovie* array[], int cantidadActual)
{
    int i;
    int retorno = -1;
    char titulo[20];
    int id;
    for(i=1;i<=cantidadActual;i++)
    {
        funciones_getId(array[i],&id);
        funciones_getTitulo(array[i], titulo);
        printf("\n%d - %s\n",id,titulo);
    }
    return retorno;
}

void guardarTodoMenos(EMovie* array[],int limite,int id)
{
    FILE *miArchivo;
    int i;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[200];
    int auxId;
    int numero = 5;
    int auxIndice;

    miArchivo = fopen("data.txt","w");
    if(miArchivo!=NULL)
    {
        auxIndice=buscarPorId(array,limite,id);
        for(i=1; i<=limite; i++)
        {
            if(i!=auxIndice)
            {
                numero++;
                funciones_getTitulo(array[i], titulo);
                funciones_getGenero(array[i], genero);
                funciones_getDuracion(array[i], &duracion);
                funciones_getDescripcion(array[i], descripcion);
                funciones_getPuntaje(array[i], &puntaje);
                funciones_getLinkImagen(array[i], linkImagen);
                funciones_getId(array[i],&auxId);
                fprintf(miArchivo,"%s,%s,%d,%s,%d,%s,%d\n",titulo,genero,duracion,descripcion,puntaje,linkImagen,auxId);
            }

        }
        fclose(miArchivo);
    }
}

//----------------MODIFICAR-----------------------------------

int buscarPorId(EMovie* array[],int limite, int id)
{
    int retorno = -1;
    int i;
    int auxId;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            funciones_getId(array[i], id);
            if(auxId == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

void modificar(EMovie* array[], int indice)
{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[200];

    if(!getValidString("\nTitulo? ","\nEso no es un Titulo","El maximo es 40",titulo,40,2))
    {
        if(!getValidString("\nGenero? ","\nEso no es un Genero","El maximo es 40",genero,40,2))
        {
            if(!getValidInt("\nDuracion? ","\nEso no es una duracion valido",&duracion,0,500,2))
            {
                if(!getValidString("\nDescripcion? ","\nEso no es una descripcion","El maximo es 40",descripcion,40,2))
                {
                    if(!getValidInt("\nPuntaje? ","\nEso no es un puntaje valido",&puntaje,0,10,2))
                    {
                        if(!getValidString("\nLink Imagen? ","\nEso no es un link","El maximo es 40",linkImagen, 200,2))
                        {
                            funciones_setTitulo(array[indice],titulo);
                            funciones_setGenero(array[indice],genero);
                            funciones_setDuracion(array[indice],duracion);
                            funciones_setDescripcion(array[indice],descripcion);
                            funciones_setPuntaje(array[indice],puntaje);
                            funciones_setLinkImagen(array[indice],linkImagen);
                        }
                    }
                }
            }
        }
    }
}

//-------------------------------------------HTML-------------------------------------------------

void crearHTML(EMovie* array[],int cantidadActual)
{

    FILE *miArchivo;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int i;
    miArchivo = fopen("index.html","w");

    if(miArchivo!=NULL)
    {
        fprintf(miArchivo,"<!DOCTYPE html>\n");
        fprintf(miArchivo,"<html lang='en'>\n");
        fprintf(miArchivo,"<head>\n");
        fprintf(miArchivo,"    <meta charset='utf-8'>\n");
        fprintf(miArchivo,"    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
        fprintf(miArchivo,"    <meta name='viewport' content='width=device-width, initial-scale=1'>\n");
        fprintf(miArchivo,"    <title>Lista peliculas</title>\n");
        fprintf(miArchivo,"    <link href='css/bootstrap.min.css' rel='stylesheet'>\n");
        fprintf(miArchivo,"    <link href='css/custom.css' rel='stylesheet'>\n");
        fprintf(miArchivo,"</head>\n");
        fprintf(miArchivo,"<body>\n");
        fprintf(miArchivo,"    <div class='container'>\n");

        for(i=0;i<cantidadActual;i++)
        {
            funciones_getTitulo(array[i], titulo);
            funciones_getGenero(array[i], genero);
            funciones_getDuracion(array[i], &duracion);
            funciones_getDescripcion(array[i], descripcion);
            funciones_getPuntaje(array[i], &puntaje);
            funciones_getLinkImagen(array[i], linkImagen);
            fprintf(miArchivo,"\n");
            fprintf(miArchivo,"            <article class='col-md-4 article-intro'>\n");
            fprintf(miArchivo,"                <a href='#'>\n");
            fprintf(miArchivo,"                    <img class='img-responsive img-rounded' src=' %s ' alt=''>\n",linkImagen);
            fprintf(miArchivo,"                </a>\n");
            fprintf(miArchivo,"                <h3>\n");
            fprintf(miArchivo,"                    <a href='#'> %s </a>\n",titulo);
            fprintf(miArchivo,"                </h3>\n");
            fprintf(miArchivo,"				<ul>\n");
            fprintf(miArchivo,"					<li>Género: %s </li>\n",genero);
            fprintf(miArchivo,"					<li>Puntaje: %d </li>\n",puntaje);
            fprintf(miArchivo,"					<li>Duración: %d </li>		\n",duracion);
            fprintf(miArchivo,"				</ul>\n");
            fprintf(miArchivo,"                <p> %s </p>\n",descripcion);
            fprintf(miArchivo,"            </article>\n");
            fprintf(miArchivo,"\n");
        }
        fprintf(miArchivo,"        </div>\n");
        fprintf(miArchivo,"    </div>\n");
        fprintf(miArchivo,"    <script src='js/jquery-1.11.3.min.js'></script>\n");
        fprintf(miArchivo,"    <script src='js/bootstrap.min.js'></script>\n");
        fprintf(miArchivo,"	<script src='js/ie10-viewport-bug-workaround.js'></script>\n");
        fprintf(miArchivo,"	<script src='js/holder.min.js'></script>\n");
        fprintf(miArchivo,"</body>\n");
        fprintf(miArchivo,"</html>\n");
    }
    fclose(miArchivo);

}


//--------------------------------------GETERS Y SETERS--------------------------------------------
int funciones_setTitulo(EMovie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        strcpy(this->titulo,titulo);
        retorno = 0;
    }
    return retorno;
}
int funciones_getTitulo(EMovie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        strcpy(titulo , this->titulo);
        retorno = 0;
    }
    return retorno;
}

int funciones_setGenero(EMovie* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        strcpy(this->genero,genero);
        retorno = 0;
    }
    return retorno;
}
int funciones_getGenero(EMovie* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        strcpy(genero , this->genero);
        retorno = 0;
    }
    return retorno;
}

int funciones_setDescripcion(EMovie* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        strcpy(this->descripcion,descripcion);
        retorno = 0;
    }
    return retorno;
}
int funciones_getDescripcion(EMovie* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        strcpy(descripcion , this->descripcion);
        retorno = 0;
    }
    return retorno;
}

int funciones_setLinkImagen(EMovie* this, char* linkImagen)
{
    int retorno = -1;
    if(this != NULL && linkImagen != NULL)
    {
        strcpy(this->linkImagen,linkImagen);
        retorno = 0;
    }
    return retorno;
}
int funciones_getLinkImagen(EMovie* this, char* linkImagen)
{
    int retorno = -1;
    if(this != NULL && linkImagen != NULL)
    {
        strcpy(linkImagen , this->linkImagen);
        retorno = 0;
    }
    return retorno;
}

int funciones_setDuracion(EMovie* this, int duracion)
{
    int retorno = -1;
    if(this != NULL && duracion != NULL)
    {
        this->duracion = duracion;
        retorno = 0;
    }
    return retorno;
}
int funciones_getDuracion(EMovie* this, int* duracion)
{
    int retorno = -1;
    if(this != NULL && duracion != NULL)
    {
        *duracion = this->duracion;
        retorno = 0;
    }
    return retorno;
}

int funciones_setPuntaje(EMovie* this, int puntaje)
{
    int retorno = -1;
    if(this != NULL && puntaje != NULL)
    {
        this->puntaje = puntaje;
        retorno = 0;
    }
    return retorno;
}
int funciones_getPuntaje(EMovie* this, int* puntaje)
{
    int retorno = -1;
    if(this != NULL && puntaje != NULL)
    {
        *puntaje = this->puntaje;
        retorno = 0;
    }
    return retorno;
}

int funciones_setId(EMovie* this)
{
    static int ultimoId = 0;
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        ultimoId++;
        this->id = ultimoId;
    }
    return retorno;
}

int funciones_getId(EMovie* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}
