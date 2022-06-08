#include "minish.h"

int builtin_help(int argc, char ** argv){
    struct builtin_struct *builtin = NULL;
    if (argc == 1){
        for (builtin = builtin_arr; builtin->cmd != NULL; builtin++)
        {
            printf("%s\n",builtin->help_txt);
        }
        return 0;
    }
    else if(argc == 2){
        builtin = builtin_lookup(argv[1]);
        if (builtin == NULL){
            printf("\033[1;31m");
            error(EXIT_SUCCESS,0,"\033[31mComando no existe en librearia\033[0m");
            return -1;
        }
        else{
            printf("%s\n",builtin->help_txt);
            return 0;
        }
    }
    else{
        error(EXIT_SUCCESS,0,"Demasiados Argumentos."); //COMPLETAR CON ERROR
        return -1;
    }
}