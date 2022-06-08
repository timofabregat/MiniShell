#include "minish.h"

int builtin_gid (int argc, char ** argv){
    if(argc == 1){
        printf("ID grupo principal: %d - Nombre: %s\n",getgid(),getgrgid(getgid())->gr_name);
        gid_t grouplist[NGROUPS_MAX];
        int ngroups = getgroups(NGROUPS_MAX, grouplist);
        for(int i = 0; i < ngroups; i++){
            printf("ID grupo secundario n°%d: %d - Nombre: %s\n", i, grouplist[i], getgrgid(grouplist[i])->gr_name);
        }
        return 0;
    }

    //built-in no soporta mas de un argumento
    else{
        printf("\033[1;31m");
        error(EXIT_SUCCESS,0,"\033[31mDemasiados Argumentos\033[0m");
        return -1; 
    }
};