#include "minish.h"

int builtin_help(int argc, char ** argv){
    struct builtin_struct *builtin = NULL;

    // Si el comando es solo help, devolvemos todas las funcionalidades recorriendo su almacenamiento y devolviendo los atributos de la estructura
    if (argc == 1){
        for (builtin = builtin_arr; builtin->cmd != NULL; builtin++) //recorro
        {
            printf("%s\n",builtin->help_txt); //printeo sus atributos de descripciones
        }

        return EXIT_SUCCESS;
    }

    // Si el comando es help[built-in], chequeamos si existe en el arrat y devolvemos su atributo o un error
    else if(argc == 2){
        builtin = builtin_lookup(argv[1]); //Busco comando en particular
        if (builtin == NULL){
            printf("\033[1;31m");
            error(EXIT_SUCCESS,0,"\033[31mComando no existe en librearia\033[0m");
            return EXIT_FAILURE;
        }
        else{
            printf("%s\n",builtin->help_txt); //printeo su atributo de descripcion
            return EXIT_SUCCESS;
        }
    }

    // El built-in no soporta mas de dos argumentos
    else{
        printf("\033[1;31m");
        error(EXIT_SUCCESS,0,"\033[31mDemasiados Argumentos\033[0m"); 
        return EXIT_FAILURE;
    }
}