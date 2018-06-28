#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"
#include "ArrayList.h"


EMovie* funciones_new()
{
    return malloc(sizeof(EMovie));
}

void funciones_delete(EMovie* this)
{
    if(this != NULL)
        free(this);
}

EMovie* funciones_newPar(char* titulo,char* genero,char* descripcion,char* linkImagen,int duracion,int puntaje)
{
    EMovie* this;
    this = funciones_new();

    if( !funciones_setTitulo(this,titulo) &&
        !funciones_setGenero(this,genero) &&
        !funciones_setDescripcion(this,descripcion) &&
        !funciones_setLinkImagen(this,linkImagen)&&
        !funciones_setDuracion(this,duracion)&&
        !funciones_setPuntaje(this,puntaje))
    {

        return this;
    }
    funciones_delete(this);
    return NULL;
}


int funciones_cargarPelicula(EMovie* lista,ArrayList* arrayList)
{
    EMovie* auxListaP;

    int retorno = -1;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[200];

    if(lista!=NULL && arrayList!=NULL)
    {
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
                                auxListaP=funciones_newPar(titulo,genero,descripcion,linkImagen,duracion,puntaje);
                                al_add(arrayList,auxListaP);
                                funciones_mostrarPelicula(auxListaP);
                                funciones_cargarAlArchivo(auxListaP);
                                printf("ok");
                                retorno =0;
                            }
                        }
                    }
                }

            }
        }
    }
    return retorno;
}


int funciones_mostrarPelicula(EMovie* this)
{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[200];

    funciones_getTitulo(this,titulo);
    funciones_getGenero(this,genero);
    funciones_getDuracion(this,&duracion);
    funciones_getDescripcion(this,descripcion);
    funciones_getPuntaje(this,&puntaje);
    funciones_getLinkImagen(this,linkImagen);

    printf("\n%s - %s - %d - %s - %d - %s\n",titulo,genero,duracion,descripcion,puntaje,linkImagen);
    return 0;
}


void funciones_cargarAlArchivo(EMovie* this)
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
        funciones_getTitulo(this, titulo);
        funciones_getGenero(this, genero);
        funciones_getDuracion(this, &duracion);
        funciones_getDescripcion(this, descripcion);
        funciones_getPuntaje(this, &puntaje);
        funciones_getLinkImagen(this, linkImagen);
        fprintf(miArchivo,"%s,%s,%d,%s,%d,%s\n",titulo,genero,duracion,descripcion,puntaje,linkImagen);
        printf("\nHa cargado una pelicula\n");
    }
    fclose(miArchivo);
}

//------------------------------------------BORRAR------------------------------------------------

void funciones_cargarDeArchivo(ArrayList* this)
{
    FILE *miArchivo;
    EMovie* auxListaP;
    char titulo[20];
    char genero[20];
    char auxDuracion[20];
    int duracion;
    char descripcion[50];
    char auxPuntaje[20];
    int puntaje;
    char linkImagen[200];
    miArchivo = fopen("data.txt","r");

    if(miArchivo!=NULL)
    {
        do
        {
            int parts = fscanf(miArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",titulo,genero,auxDuracion,descripcion,auxPuntaje,linkImagen);
            if(parts==6)
            {
                duracion=atoi(auxDuracion);
                puntaje=atoi(auxPuntaje);
                auxListaP=funciones_newPar(titulo,genero,descripcion,linkImagen,duracion,puntaje);
                al_add(this, auxListaP);
            }
        }while(!feof(miArchivo));
        fclose(miArchivo);
    }
}

int funciones_listarPeliculas(ArrayList* this)
{
    int retorno=-1;
    int i;
    if(this!=NULL)
    {
        for(i = 0; i < al_len(this); i++)
        {
            EMovie* auxiliar;
            auxiliar=al_get(this, i);
            printf("%d - %s\n", i + 1,auxiliar->titulo );
        }
    }
    return retorno;
}

void funciones_cargarTodoAlArchivo(ArrayList* this)
{

    FILE *miArchivo;
    int i;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[200];
    EMovie* auxListaP;
    miArchivo = fopen("data.txt","w");

    for(i=0;i<al_len(this);i++)
    {
        if(miArchivo!=NULL)
        {
            auxListaP=al_get(this,i);
            funciones_getTitulo(auxListaP, titulo);
            funciones_getGenero(auxListaP, genero);
            funciones_getDuracion(auxListaP, &duracion);
            funciones_getDescripcion(auxListaP, descripcion);
            funciones_getPuntaje(auxListaP, &puntaje);
            funciones_getLinkImagen(auxListaP, linkImagen);
            fprintf(miArchivo,"%s,%s,%d,%s,%d,%s\n",titulo,genero,duracion,descripcion,puntaje,linkImagen);
        }
    }
    printf("\nHa cargado la lista modificada\n");
    fclose(miArchivo);
}

int funciones_borrarPelicula(ArrayList* this)
{
    int retorno=-1;
    int idx;
    if(this!=NULL)
    {

        funciones_listarPeliculas(this);
        printf("Numero de Pelicula?\n");

        scanf("%d",&idx);
        if(idx>=0 && idx-1<al_len(this))
        {
            al_remove(this,idx-1);
            funciones_cargarTodoAlArchivo(this);
        }
        retorno=0;
    }
    return retorno;
}
//----------------MODIFICAR-----------------------------------



int funciones_modificarPelicula(ArrayList* this)
{
    int retorno=-1;
    char titulo[20];
    char genero[20];
    char descripcion[50];
    char linkImagen[50];
    int duracion;
    int puntaje;
    int idx;

    EMovie* auxListaP;
    if(this!=NULL)
    {
        funciones_listarPeliculas(this);
        printf("Numero de Pelicula?\n");

        scanf("%d",&idx);
        if((idx-1 >=0) && (idx-1 <al_len(this)))
        {
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
                                    auxListaP=funciones_newPar(titulo,genero,descripcion,linkImagen,duracion,puntaje);
                                    al_set(this,idx-1,auxListaP);
                                    funciones_cargarTodoAlArchivo(this);
                                    printf("\nHa cargado la lista modificada\n");
                                    retorno=0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return retorno;
}

//-------------------------------------------HTML-------------------------------------------------

void funciones_crearHTML(EMovie* this)
{

    FILE *miArchivo;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int i;
    EMovie* auxListaP;
    miArchivo = fopen("index.html","w");

    if(miArchivo!=NULL && this!=NULL)
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

        for(i=0;i<al_len(this);i++)
        {
            auxListaP=al_get(this,i);
            funciones_getTitulo(auxListaP, titulo);
            funciones_getGenero(auxListaP, genero);
            funciones_getDuracion(auxListaP, &duracion);
            funciones_getDescripcion(auxListaP, descripcion);
            funciones_getPuntaje(auxListaP, &puntaje);
            funciones_getLinkImagen(auxListaP, linkImagen);
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
        printf("\n\nArchivo creado con exito!!\n\n");
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
