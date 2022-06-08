#include "minish.h"

int builtin_pid (int argc, char ** argv){

    //Se encuentra el process id y se devuelve
    if(argc == 1){
        printf("Process ID: %d\n", getpid());
        return 0;
    }

    //Built-in no soporta mas argumentos
    else{
        printf("\033[1;31m");
        error(EXIT_SUCCESS,0,"\033[31mDemasiados Argumentos\033[0m");
        return -1;
    }
};