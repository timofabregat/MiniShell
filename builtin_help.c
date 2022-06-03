#include "minish.h"

int builtin_help(int argc, char ** argv){
    struct builtin_struct *builtin = NULL;
    builtin = builtin_lookup(argv[0]);
    if (builtin == NULL){
        printf("Comando no existe en libreria.\n");
    }
    else{
        printf("%s",builtin->help_txt);
    }
}