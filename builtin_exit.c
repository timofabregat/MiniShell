#include "minish.h"

int builtin_exit (int argc, char ** argv){

    //Si es solo exit se termina el programa con status actual
    if (argc == 1){
        exit(globalstatret);
    }

    //Si se especifica un status, se chequea si es valido y se termina el programa
    else if(argc == 2){
        if(esNumero(argv[1])){        //chequeo si es numero
            int x = atoi(argv[1]);    // Transformo a int el string
            exit(x);
        }
        else{
            printf(RED);
            error(EXIT_SUCCESS,0,"\033[31mArgumento no valido\033[0m");
            return EXIT_FAILURE;
        }
    }

    //Argumentos no validos
    else{
        printf(RED);
        error(EXIT_SUCCESS,0,"\033[31mDemasiados Argumentos\033[0m");
        return EXIT_FAILURE;
    }
};

//Funcion auxiliar para chequear si el argumento es un numero
int esNumero(char numero[])
{
    for (int i = 0; numero[i] != 0; i++)
    {
        if (!isdigit(numero[i]))
            return 0;
    }
    return 1;
}