#include "minish.h"

int builtin_exit (int argc, char ** argv){
    if (argc == 1){
        exit(globalstatret);
        return globalstatret;
    }
    else if(argc == 2){
        if(esNumero(argv[1])){
            int x = atoi(argv[1]);
            exit(x);
            return x;
        }
        else{
            return -1; //Completar error.
        }
    }
    else{
        return -1;    // Completar error.
    }
};

int esNumero(char numero[])
{
    for (int i = 0; numero[i] != 0; i++)
    {
        if (!isdigit(numero[i]))
            return 0;
    }
    return 1;
}