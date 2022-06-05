#include "minish.h"

int builtin_status (int argc, char ** argv){
    if(argc == 1){
        printf("Ultimo status: %d\n", globalstatret);
        return 0;
    }
    else{
        return -1; //Completar error
    }
};