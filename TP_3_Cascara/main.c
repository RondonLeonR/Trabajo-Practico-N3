#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANT 10

int main()
{
    EMovie movie[CANT];
    Inicializador(movie,CANT);
    Hardcodeo(movie,CANT);

    char seguir='s';
    int opcion=0;
    int flag2=0;


    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarPelicula(movie,CANT);
                break;
            case 2:
                system("cls");
                DarDeBaja(movie,CANT);
                break;
            case 3:
                system("cls");
                flag2=1;
                modificarPelicula(movie,CANT);
               break;
            case 4:
                system("cls");
                flag2=1;
                crearPaginaWeb(movie,CANT);
                break;
            case 5:
                mensaje(flag2);
                seguir = 'n';
                break;
        }
    }
    crearArchivo(movie,CANT);

    return 0;
}
