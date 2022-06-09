#include "minish.h"
#include <limits.h>
char PWD[MAXCWD];
int builtin_cd (int argc, char ** argv){
    char temp[MAXCWD];

    //Si se llama solo cd se llama a la funcion chdir con la variable HOME
    if(argc == 1){
        getcwd(PWD,sizeof(PWD));
        chdir(getenv("HOME"));
        return 0;
    }

    else{

        //Si se llama cd - se llama a la funcion chdir con la variable aux del pathname pasado
        if(strcmp(argv[1],"-") == 0){
            getcwd(temp,sizeof(temp));
            chdir(PWD);
            strcpy(PWD,temp);
            return 0;
        }

        //Si se utiliza un pathname se llama a chdir con el pathname y se chequea si existe el directorio
        else{
            getcwd(PWD,sizeof(PWD));
            int x = chdir(argv[1]);
            if(x != 0){
                printf("\033[1;31m");
                error(EXIT_SUCCESS,0,"\033[31mDirectorio no existe\033[0m");
                return -1;
            }
        }
    }

    //Built-in no soporta mas argumentos, igual siempre se agarra el error de directorio no existe antes
    if(argc > 2){
        printf("\033[1;31m");
        error(EXIT_SUCCESS,0,"\033[31mDemasiados Argumentos\033[0m");
        return -1;
    }
};