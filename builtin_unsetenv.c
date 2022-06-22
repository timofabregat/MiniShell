#include "minish.h"

int builtin_unsetenv (int argc, char ** argv){
    if(argc > 1){                                  
        for(int i = 1; i < argc; i++){              //Recorro entre la cantidad de variables que me pasan
            if(getenv(argv[i]) != NULL){
                int retorno;
                retorno = unsetenv(argv[i]);            //Usamos unsetenv que devuelve 0 si se elimina correctamente la variable
                if(retorno == 0){   
                    printf("La variable %s fue eliminada correctamente.\n",argv[i]);
                }
                else{
                    printf("\033[1;31m");           //unsetenv no devolvio 0 por lo que hubo un error al eliminar la variable.
                    error(EXIT_SUCCESS,0,"\033[31mError al eliminar la variable de ambiente %s\033[0m",argv[i]);
                }
            }
            else{                           //No se encuentra la variable de ambiente
                printf("\033[1;31m");
                error(EXIT_SUCCESS,0,"\033[31mNo Existe la variable de ambiente %s\033[0m",argv[i]);
            }
        }
        return EXIT_SUCCESS;
    }
    else{                           //Error: caso en el que no me pasan argumentos con unsetenv
        printf("\033[1;31m");
        error(EXIT_SUCCESS,0,"\033[31mFaltan Argumentos\033[0m");
        return EXIT_FAILURE;
    }
};