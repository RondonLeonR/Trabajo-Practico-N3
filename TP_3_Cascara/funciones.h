#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[400];
    int puntaje;
    char linkImagen[100];
    int estado;
    int ID;
}EMovie;

void Hardcodeo(EMovie movie[],int limite);

void Inicializador(EMovie movie[],int limite);

int buscarLugarLibre(EMovie* movie,int limite);

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie* movie,int limite);

/**
 *  Crea un archivo binario
 * \param movie EMovie* La estructura a ser usada
 * \param limite int El limite de la estructura
 * \return void No retorna nada, solo crea el archivo
 */
void crearArchivo(EMovie* movie,int limite);

/**
 *  Borra una pelicula del archivo
 * \param movie EMovie* La estructura a ser eliminada
 * \param limite int El limite de la estructura
 * \return void No retorna nada.
 */
void DarDeBaja(EMovie* movie,int limite);

/**
 *  Mostrar el listado de los titulos ingresados
 * \param movie[] EMovie La estructura a ser usada
 * \param limite int El limite de la estructura
 * \return void No devuelvo solo muestro
 */
void mostrarPeliculas(EMovie movie[],int limite);

/**
 *  Busco por ID para borrar o modificar alguna Pelicula
 * \param movie[] EMovie La estructura a ser usada
 * \param limite int El limite de la estructura
 * \param id int El ID a ser buscado
 * \return int Devuelvo si se encontro el Id ingresado
 */
int buscarPorId(EMovie movie[],int limite,int id);

/**
 *  Modifica una Pelicula
 * \param movie EMovie* La estructura a ser usada
 * \param limite int El limite de la estructura
 * \return void No devuelvo nada, solo Modifico el archivo
 */
void modificarPelicula(EMovie* movie,int limite);

/**
 *  Creo la pagina web
 * \param movie EMovie* La estructura a ser usada
 * \param limite int El limite de la estructura
 * \return void No retorna nada solo crea la pagina
 */
void crearPaginaWeb(EMovie* movie,int limite);

/**
 *  Muestra un mensaje si no se creo la pagina. Cuando no se da a la opcion 4 o 3
 * \param flag int El que me dice si ingreso al punto 3 o 4
 * \return void No devuelvo nada solo muestro un mensaje
 */
void mensaje(int flag);
#endif // FUNCIONES_H_INCLUDED
