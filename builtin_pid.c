#include "minish.h"

int builtin_pid (int argc, char ** argv){
    if(argc == 1){
        printf("Process ID: %d\n", getpid());
        return 0;
    }
    else{
        return -1; //Completar error
    }
};