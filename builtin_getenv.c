#include "minish.h"

int builtin_getenv (int argc, char ** argv){
    //Se busca el built in con getenv, si existe si devuelve el valor
    if(argc > 1){
        for(int i = 1; i < argc; i++){  // Por si se utiliza una lista de variables
            char *env;
            env = getenv(argv[i]); // Busco la variable indicada
            if(env != NULL){
                printf("%s = %s\n",argv[i],env);
            }
            else{
                printf(RED);
                error(EXIT_SUCCESS,0,"\033[31mNo Existe la variable de ambiente %s\033[0m",argv[i]);
                return EXIT_FAILURE;
            }
        }
        return EXIT_SUCCESS;
    }
    
    //argumentos no validos para built in
    else{
        printf(RED);
        error(EXIT_SUCCESS,0,"\033[31mFaltan argumentos\033[0m");
        return EXIT_FAILURE;
    }
};