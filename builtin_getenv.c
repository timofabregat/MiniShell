#include "minish.h"

int builtin_getenv (int argc, char ** argv){
    if(argc > 1){
        for(int i = 1; i < argc; i++){
            char *env;
            env = getenv(argv[i]);
            if(env != NULL){
                printf("%s = %s\n",argv[i],env);
            }
            else{
                printf("No existe la variable de ambiente para %s\n",argv[i]);
            }
        }
        return 0;
    }
    else{
        return -1; //Completar error
    }
};