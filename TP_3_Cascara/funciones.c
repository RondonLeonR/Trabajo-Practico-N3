#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define LIBRE 0
#define OCUPA 1
#define BORRAD -2

void Hardcodeo(EMovie movie[],int limite)
{
    int indice,i;
    int auxDuracion[]={111,118};
    char auxTitulo[2][50]= {"Deadpool 2","Los Increibles 2"};
    char auxGenero[2][50]= {"Accion","Comedia"};
    char auxDescripcion[2][400]={"Wade Wilson (Ryan Reynolds), mejor conocido como Deadpool, su nombre de batalla e identidad antiheroica, está de regreso con Deadpool 2 y en esta ocasión su misión será salvar a un chico llamado Russell (Julian Dennison) de las manos de un poderoso rival llamado Cable (Josh Brolin).","Los Increibles 2 comienza justo después del final de la primera parte. La familia Parr se ve nuevamente obligada a vivir vidas ordinarias, mientras que Helen obtiene un nuevo trabajo para liderar una campaña a favor de los 'supers' dejando a su esposo Bob con la difícil tarea de cuidar a sus tres hijos Violeta, Dash y Jack-Jack."};
    int auxPuntaje[]={100,90};
    char auxLink[2][100]={"http://es.web.img2.acsta.net/c_215_290/pictures/18/02/08/09/37/3289486.jpg","http://www.cinesargentinos.com.ar/poster/5520-los-increibles-2_168.jpg?1523630383"};

    for(i=0;i<2;i++)
    {
        strcpy(movie[i].titulo,auxTitulo[i]);
        strcpy(movie[i].genero,auxGenero[i]);
        movie[i].duracion=auxDuracion[i];
        strcpy(movie[i].descripcion,auxDescripcion[i]);
        strcpy(movie[i].linkImagen,auxLink[i]);
        movie[i].estado=OCUPA;
        movie[i].puntaje=auxPuntaje[i];
        movie[i].ID=i;
    }
}

void Inicializador(EMovie movie[],int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        movie[i].estado=LIBRE;
        movie[i].ID=i;
    }
}

int buscarLugarLibre(EMovie movie[],int limite)
{
    int i;
    int retorno=-1;

    for(i=0;i<limite;i++)
    {
        if(movie[i].estado==LIBRE)              //&&movie[i]!= NULL
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}


int agregarPelicula(EMovie movie[],int limite)
{
    int ind;
    int auxDuracion,auxPuntaje;

    ind = buscarLugarLibre(movie,limite);

    if(ind==-1)
    {
        printf("NO HAY MAS LUGAR!");
    }
    else
    {
        printf("\tSe ha encontrado un lugar.\n\nIngrese datos:");
        printf("\nIngrese el Titulo:");
        fflush(stdin);
        gets(movie[ind].titulo);
        printf("\nIngrese el Genero:");
        fflush(stdin);
        gets(movie[ind].genero);
        printf("\nIngrese el Puntaje de la pelicula(0 a 100):");
        scanf("%d",&auxPuntaje);
        movie[ind].puntaje=auxPuntaje;
        printf("\nIngrese la Duracion de la Pelicula:");
        scanf("%d",&auxDuracion);
        movie[ind].duracion=auxDuracion;
        printf("\nIngrese la descripcion de la Pelicula:");
        fflush(stdin);
        gets(movie[ind].descripcion);
        printf("\nIngrese el Link de la Imagen de Portada de la Pelicula:");
        fflush(stdin);
        gets(movie[ind].linkImagen);
        movie[ind].estado=OCUPA;
    }

}

void crearArchivo(EMovie* movie,int limite)
{
    int i;
    FILE *pArchivo;

    pArchivo = fopen("Peliculas.dat","wb");

    if(pArchivo!=NULL)
    {
        fprintf(pArchivo,"\nPELICULAS: \n");

        for(i=0;i<limite;i++)
        {
            if(movie[i].estado==OCUPA&&movie[i].estado!=LIBRE) //if(feof(archivo))
            {
                fprintf(pArchivo,"\n%d\t%s\n\t%s\n\t%d min\n\t%d\n\t%s",movie[i].ID,movie[i].titulo,movie[i].genero,movie[i].duracion,movie[i].puntaje,movie[i].descripcion);
            }
        }
    }
    fclose(pArchivo);
    system("cls");
}



void DarDeBaja(EMovie* movie,int limite)
{
    int id,idEncontrado;
    char opc;
    mostrarPeliculas(movie,limite);
    printf("Ingrese ID de la Pelicula que desea Borrar: ");
    scanf("%d",&id);
    idEncontrado = buscarPorId(movie,limite,id);

    if(idEncontrado==BORRAD)
    {
        printf("No se ha encontrado la opcion ingresada.\n");
        system("pause");
    }
    else
    {
        printf("Esta seguro que desea Borrar?? (s-n)");
        opc=getche();
        if(opc=='s'||opc=='S')
        {
            movie[idEncontrado].estado=BORRAD;
            printf("\nOperacion Realizada con Exito.\n");
            system("pause");
        }
        else if(opc=='n'||opc=='N')
        {
            printf("\nOperacion Cancelada.\n");
            system("pause");
        }
    }


}

void mostrarPeliculas(EMovie movie[],int limite)
{
    int i;

    for(i=0;i<limite;i++)
    {
        if(movie[i].estado==OCUPA&&movie[i].estado!=LIBRE)
        {
            printf("%d- %s\n",movie[i].ID,movie[i].titulo);
        }
    }
}

int buscarPorId(EMovie movie[],int limite,int id)
{
    int i,retorno;
    for(i=0;i<limite;i++)
    {
        retorno=-2;
        if(i==id&&movie[i].estado==OCUPA)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

void modificarPelicula(EMovie* movie,int limite)
{
    int id,idEncontrado,auxDuracion,auxPuntaje;
    char opc;
    mostrarPeliculas(movie,limite);
    crearPaginaWeb(movie,limite);
    printf("\t\tIngrese ID de la Pelicula que desea Modificar: ");
    scanf("%d",&id);
    idEncontrado = buscarPorId(movie,limite,id);

    if(idEncontrado==-2)
    {
        printf("\nLa opcion ingresada es Inexistente.\n");
        system("pause");
    }
    else
    {
        printf("\nOpcion encontrada.\nEsta seguro que desea Modificar? s--n");
        opc=getche();
        if(opc=='s'||opc=='S')
        {
            printf("\nReingrese los datos... \n");
            printf("\nReingrese el Titulo:");
            fflush(stdin);
            gets(movie[idEncontrado].titulo);
            printf("\nReingrese el Genero:");
            fflush(stdin);
            gets(movie[idEncontrado].genero);
            printf("\nReingrese el Puntaje de la pelicula(0 a 100):");
            scanf("%d",&auxPuntaje);
            movie[idEncontrado].puntaje=auxPuntaje;
            printf("\nReingrese la Duracion de la Pelicula:");
            scanf("%d",&auxDuracion);
            movie[idEncontrado].duracion=auxDuracion;
            printf("\nReingrese la descripcion de la Pelicula:");
            fflush(stdin);
            gets(movie[idEncontrado].descripcion);
            printf("\nReingrese el Link de la Imagen de Portada de la Pelicula:");
            fflush(stdin);
            gets(movie[idEncontrado].linkImagen);
        }
        else
        {
            printf("\nOperacion Cancelada.");
            getch();
        }

    }
}

void crearPaginaWeb(EMovie* movie,int limite)
{
    FILE* pArchivo;
    char link[50];
    int i;

    pArchivo = fopen("prueba.html","w");

    fprintf(pArchivo,"<html><head><title>Peliculas</title></head><body><div class='container'><div class='row'>");
    for(i=0;i<limite;i++)
    {
        if(movie[i].estado==OCUPA)
        {
        fprintf(pArchivo,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s'alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Género:%s</li><li>Puntaje:%d</li><li>Duración:%d</li></ul><p>%s</p></article>",movie[i].linkImagen,movie[i].titulo,movie[i].genero,movie[i].puntaje,movie[i].duracion,movie[i].descripcion);
        }
    }
    fprintf(pArchivo,"</div></div></body></html>");

    fclose(pArchivo);

    printf("\t\tPagina creada.\n");
    getch();
}

void mensaje(int flag)
{
    if(flag==0)
    {
        printf("\n\t\tNo se a creado la Pagina.\n");
        printf("\t\tSi la desea Seleccione la Opcion 4.");
        getch();
    }
}
