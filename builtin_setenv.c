#include "minish.h"

int builtin_setenv(int argc, char ** argv){
    if(argc == 3){
        //se utiliza la funci'on setenv() para agregar una variable de ambiente al sistema o modificarla.
        int retorno = setenv(argv[1],argv[2],1);
        if(retorno == 0){
            printf("La variable %s fue creada/modificada con exito\n",argv[1]);
            return EXIT_SUCCESS;
        }
        else{
            // Si no se puede insertar/modificar la variable la funcion no retorna 0 y se informar el error
            printf(RED);
            error(EXIT_SUCCESS,0,"\033[31mError al crear o modificar la variable %s\033[0m",argv[1]);
            return EXIT_FAILURE;
        }
    }
    else{ 
        //Funcion no posee sufiecientes argumentos
        printf(RED);
        error(EXIT_SUCCESS,0,"\033[31mFaltan Argumentos\033[0m");
        return EXIT_FAILURE;
    }
};