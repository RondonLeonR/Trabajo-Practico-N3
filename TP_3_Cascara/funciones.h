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
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[]);

void crearArchivo(EMovie* movie,int limite);

void DarDeBaja(EMovie* movie,int limite);

void mostrarPeliculas(EMovie movie[],int limite);

int buscarPorId(EMovie movie[],int limite,int id);

void modificarPelicula(EMovie* movie,int limite);

void crearPaginaWeb(EMovie* movie,int limite);

void mensaje(int flag);
#endif // FUNCIONES_H_INCLUDED
