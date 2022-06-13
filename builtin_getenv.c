#include "minish.h"

int builtin_getenv (int argc, char ** argv){
    //Se busca el built in con getenv, si existe si devuelve el valor
    if(argc > 1){
        for(int i = 1; i < argc; i++){
            char *env;
            env = getenv(argv[i]);
            if(env != NULL){
                printf("%s = %s\n",argv[i],env);
            }
            else{
                printf("\033[1;31m");
                error(EXIT_SUCCESS,0,"\033[31mNo Existe la variable de ambiente %s\033[0m",argv[i]);
                return EXIT_FAILURE;
            }
        }
        return EXIT_SUCCESS;
    }
    
    //argumentos no validos para built in
    else{
        printf("\033[1;31m");
        error(EXIT_SUCCESS,0,"\033[31mFaltan argumentos\033[0m");
        return EXIT_FAILURE;
    }
};