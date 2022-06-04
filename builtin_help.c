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
            printf("Comando no existe en libreria.\n");
            return -1;
        }
        else{
            printf("%s\n",builtin->help_txt);
            return 0;
        }
    }
    else{
        return -1; //COMPLETAR CON ERROR
    }
}