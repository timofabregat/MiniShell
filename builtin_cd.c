#include "minish.h"
#include <limits.h>
char PWD[MAXCWD];
int builtin_cd(int argc, char ** argv)
{
    char temp[MAXCWD];

    //Si se llama solo cd se llama a la funcion chdir con la variable de ambiente HOME
    if(argc == 1){
        getcwd(PWD,sizeof(PWD)); // Almaceno directorio corriente
        chdir(getenv("HOME")); //obtengo variable home y muevo a ese directorio con chdir
        return 0;
        return EXIT_SUCCESS;
    }

    else{

        //Si se llama cd - se llama a la funcion chdir con la variable aux del pathname pasado
        if(strcmp(argv[1],"-") == 0){
            getcwd(temp,sizeof(temp)); // Almaceno directorio corriente
            chdir(PWD); //Esta variable almacena el directorio previo
            strcpy(PWD,temp); // Cambio el directorio previo

            return 0;

            return EXIT_SUCCESS;

        }

        //Si se utiliza un pathname se llama a chdir con el pathname y se chequea si existe el directorio
        else{
            getcwd(PWD,sizeof(PWD)); //Almaceno directorio corriente
            int x = chdir(argv[1]);
            if(x != 0){
                printf(RED);
                error(EXIT_SUCCESS,0,"\033[31mDirectorio no existe\033[0m");
                return EXIT_FAILURE;
            }

            return 0;
        }
    }

    //Built-in no soporta mas argumentos, igual siempre se agarra el error de directorio no existe antes
    if(argc > 2){
        printf(RED);
        error(EXIT_SUCCESS,0,"\033[31mDemasiados Argumentos\033[0m");
        return EXIT_FAILURE;
    }
}