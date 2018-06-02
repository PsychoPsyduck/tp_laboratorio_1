#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[200];
}EMovie;

#endif // FUNCIONES_H_INCLUDED


/** \brief Muestra la pelicula antes de cargar
 *
 * \param array[] EMovie* donde la guarda
 * \param indice int indice a guardar
 * \return int
 *
 */
int mostrarPelicula(EMovie* array[], int indice);


/** \brief agrega una pelicula a la lista
 *
 * \param array[] EMovie* toma la lista
 * \param cantidadMaxima int cantdad maxima
 * \param cantidadActual int* cantidad actual cargadas
 * \return void
 *
 */
void funciones_add(EMovie* array[],int cantidadMaxima,int* cantidadActual);

/** \brief carga la pelicula al archivo txt
 *
 * \param array[] EMovie* toma la lista
 * \param indice int indice a agregar
 * \return void
 *
 */
void cargarAlArchivo(EMovie* array[],int indice);

/** \brief crea el espacio para una pelicula
 *
 * \param titulo char* pide un titulo
 * \param genero char* pide el genero
 * \param duracion int pide la duracion
 * \param descripcion char* pide la descripcion
 * \param puntaje int pide el puntaje
 * \param linkImagen char* pide el link
 * \return EMovie*
 *
 */
EMovie* funciones_newPar(char* titulo,char* genero,int duracion,char* descripcion,int puntaje,char* linkImagen);

/** \brief crea la pelicula
 *
 * \param array[] EMovie* pide donde guardarla
 * \param cantidadActual int* cuantos hay
 * \param indice int indice a guyardar
 * \param titulo char* pide el titulo
 * \param genero char* pide el genero
 * \param duracion int pide la duracion
 * \param descripcion char* pide la descripcion
 * \param puntaje int pide el puntaje
 * \param linkImagen char* pide el link
 * \return void
 *
 */
void arraymovies_add(EMovie* array[],int* cantidadActual, int indice, char* titulo,char* genero,int duracion,char* descripcion,int puntaje,char* linkImagen);

/** \brief descarla los datos del archivo
 *
 * \param array[] EMovie* donde los almacena
 * \param cantidadActual int* cantidad actual al terminar
 * \return void
 *
 */
void cargarDeArchivo(EMovie* array[], int* cantidadActual);


/** \brief guarda todo al archivo menos la peliocula a eliminar
 *
 * \param array[] EMovie* de donde lo toma
 * \param cantidad int la cantidad
 * \param auxTitulo char* el titulo que no carga
 * \return void
 *
 */
void guardarTodoMenos(EMovie* array[],int cantidad,char* auxTitulo);

/** \brief busca un titulo
 *
 * \param array[] EMovie* pide la lista
 * \param limite int pide el limite
 * \param auxTitulo char* pide el titulo a buscar
 * \return int devuelve el indice
 *
 */
int buscarPorTitulo(EMovie* array[],int limite, char* auxTitulo);


/** \brief modifica una pelicula por indice
 *
 * \param array[] EMovie* pide la lista
 * \param indice int pide el indice
 * \return void
 *
 */
void modificar(EMovie* array[], int indice);

/** \brief crea el HTML
 *
 * \param array[] EMovie* pide la lista
 * \param indice int pide un total
 * \return void
 *
 */
void crearHTML(EMovie* array[],int indice);


//Geters y Seters
int funciones_setTitulo(EMovie* this, char* titulo);
int funciones_getTitulo(EMovie* this, char* titulo);
int funciones_setGenero(EMovie* this, char* genero);
int funciones_getGenero(EMovie* this, char* genero);
int funciones_setDescripcion(EMovie* this, char* descripcion);
int funciones_getDescripcion(EMovie* this, char* descripcion);
int funciones_setLinkImagen(EMovie* this, char* linkImagen);
int funciones_getLinkImagen(EMovie* this, char* linkImagen);
int funciones_setDuracion(EMovie* this, int duracion);
int funciones_getDuracion(EMovie* this, int* duracion);
int funciones_setPuntaje(EMovie* this, int puntaje);
int funciones_getPuntaje(EMovie* this, int* puntaje);



