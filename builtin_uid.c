#include "minish.h"

int builtin_uid (int argc, char ** argv){

    /*Se busca el id de usuario, se encuentra el password asociado al id
     y a su vez el nombre de usuario asociado al password*/
    if(argc == 1){
        struct passwd *pws; 
        int id = geteuid(); //se encuentra la contrasena
        pws = getpwuid(id); //se encuentra la password asociada
        printf("User ID: %d\nUsername: %s\n",id,pws->pw_name); //se printeo el nombre asosciada a las password
        return EXIT_SUCCESS;
    }

    //Built-in no soporta mas de un argumento
    else{
        printf(RED);
        error(EXIT_SUCCESS,0,"\033[31mDemasiados Argumentos\033[0m");
        return EXIT_FAILURE; 
    }
};