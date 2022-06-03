#include "minish.h"

int builtin_exit (int argc, char ** argv){
    if (argc == 1){
        exit(globalstatret);
        return globalstatret;
    }
    else if(argc == 2){
        if(isdigit(argv[1])){      // Preguntar en clase.
            exit(atoi(argv[1]));
            return atoi(argv[1]);
        }
        else{
            // Completar error.
        }
    }
    else{
            // Completar error.
    }
};