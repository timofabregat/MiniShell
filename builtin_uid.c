#include "minish.h"

int builtin_uid (int argc, char ** argv){

    /*Se busca el id de usuario, se encuentra el password asociado al id
     y a su vez el nombre de usuario asociado al password*/
    if(argc == 1){
        struct passwd *pws;
        int id = geteuid();
        pws = getpwuid(id);
        printf("User ID: %d\nUsername: %s\n",id,pws->pw_name);
        return EXIT_SUCCESS;
    }

    //Built-in no soporta mas de un argumento
    else{
        printf("\033[1;31m");
        error(EXIT_SUCCESS,0,"\033[31mDemasiados Argumentos\033[0m");
        return EXIT_FAILURE; 
    }
};