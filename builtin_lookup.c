#include "minish.h"

struct builtin_struct *builtin_lookup(char *cmd){
    struct builtin_struct *builtin = NULL;
    for (builtin = builtin_arr; builtin->cmd != NULL; builtin++)
    {
        if(strcmp(builtin->cmd, cmd) == 0){
            return builtin;
        }
    }
    return builtin;
}