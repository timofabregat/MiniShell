#include "minish.h"

struct builtin_struct *builtin_lookup(char *cmd){
    struct builtin_struct *builtin = NULL;

    // Se recorre el array de built-ins para encontrar el especificado
    for (builtin = builtin_arr; builtin->cmd != NULL; builtin++)
    {
        if(strcmp(builtin->cmd, cmd) == 0){  //si encuentro lo retorno
            return builtin;
        }
    }
    return NULL;
}