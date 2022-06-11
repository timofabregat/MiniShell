#include "minish.h"

int builtin_status (int argc, char ** argv){

    //Si se llama, se devuelve la variable globa/ambiente de status
    if(argc == 1){
        printf("Ultimo status: %d\n", globalstatret);
        return EXIT_SUCCESS;
    }

    //Built-in no soporta mas argumentos
    else{
        printf("\033[1;31m");
        error(EXIT_SUCCESS,0,"\033[31mDemasiados Argumentos\033[0m");
        return EXIT_FAILURE;
    }
};