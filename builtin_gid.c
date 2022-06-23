#include "minish.h"

int builtin_gid (int argc, char ** argv){
    if(argc == 1){
        printf("ID grupo principal: %d - Nombre: %s\n",getgid(),getgrgid(getgid())->gr_name);                               //Se imprime el grupo principal usando la funcion getgid y gergrgid
        gid_t grouplist[NGROUPS_MAX];
        int ngroups = getgroups(NGROUPS_MAX, grouplist);                              //getgroups nos devuelve el numero de grupos secundarios y llena el array grouplist con los mismos
        for(int i = 0; i < ngroups; i++){
            printf("ID grupo secundario n°%d: %d - Nombre: %s\n", i, grouplist[i], getgrgid(grouplist[i])->gr_name);        //recorremos e imprimos los grupos con sus ids
        }
        return EXIT_SUCCESS;
    }

    //built-in no soporta mas de un argumento
    else{
        printf(RED);
        error(EXIT_SUCCESS,0,"\033[31mDemasiados Argumentos\033[0m");
        return EXIT_FAILURE; 
    }
};