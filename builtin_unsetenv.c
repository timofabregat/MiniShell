#include "minish.h"

int builtin_unsetenv (int argc, char ** argv){
    if(argc > 1){
        for(int i = 1; i < argc; i++){
            if(getenv(argv[i]) != NULL){
                int retorno;
                retorno = unsetenv(argv[i]);
                if(retorno == 0){
                    printf("La variable %s fue eliminada correctamente.\n",argv[i]);
                }
                else{
                    printf("\033[1;31m");
                    error(EXIT_SUCCESS,0,"\033[31mError al eliminar la variable de ambiente %s\033[0m",argv[i]);
                }
            }
            else{
                printf("\033[1;31m");
                error(EXIT_SUCCESS,0,"\033[31mNo Existe la variable de ambiente %s\033[0m",argv[i]);
            }
        }
        return EXIT_SUCCESS;
    }
    else{
        printf("\033[1;31m");
        error(EXIT_SUCCESS,0,"\033[31mFaltan Argumentos\033[0m");
        return EXIT_FAILURE;
    }
};