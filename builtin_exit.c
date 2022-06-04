#include "minish.h"

int builtin_exit (int argc, char ** argv){
    if (argc == 1){
        exit(globalstatret);
        return globalstatret;
    }
    else if(argc == 2){
        if(isdigit(argv[1])){     
            exit(atoi(argv[1]));
            return atoi(argv[1]);
        }
        else{
            return -1;// Completar error.
        }
    }
    else{
        return -1;    // Completar error.
    }
};