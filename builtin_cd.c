#include "minish.h"
#include <limits.h>
char PWD[MAXCWD];
FILE *fPtr;
int builtin_cd (int argc, char ** argv){
    char temp[MAXCWD];

    //Si se llama solo cd se llama a la funcion chdir con la variable HOME
    if(argc == 1){
        getcwd(PWD,sizeof(PWD));
        chdir(getenv("HOME"));
<<<<<<< HEAD

        fPtr = fopen(HISTORY_FILE, "w");
        fputs("cd\n",fPtr);
        fclose(fPtr);

        return 0;
=======
        return EXIT_SUCCESS;
>>>>>>> 8f5f5e0444082fc71c97f04461d5fc7843f75999
    }

    else{

        //Si se llama cd - se llama a la funcion chdir con la variable aux del pathname pasado
        if(strcmp(argv[1],"-") == 0){
            getcwd(temp,sizeof(temp));
            chdir(PWD);
            strcpy(PWD,temp);
<<<<<<< HEAD

            fPtr = fopen(HISTORY_FILE, "w");
            fputs("cd\n",fPtr);
            fclose(fPtr);

            return 0;
=======
            return EXIT_SUCCESS;
>>>>>>> 8f5f5e0444082fc71c97f04461d5fc7843f75999
        }

        //Si se utiliza un pathname se llama a chdir con el pathname y se chequea si existe el directorio
        else{
            getcwd(PWD,sizeof(PWD));
            int x = chdir(argv[1]);
            if(x != 0){
                printf("\033[1;31m");
                error(EXIT_SUCCESS,0,"\033[31mDirectorio no existe\033[0m");
                return EXIT_FAILURE;
            }

            fPtr = fopen(HISTORY_FILE, "w");
            fputs("cd\n",fPtr);
            fclose(fPtr);

            return 0;
        }
    }

    //Built-in no soporta mas argumentos, igual siempre se agarra el error de directorio no existe antes
    if(argc > 2){
        printf("\033[1;31m");
        error(EXIT_SUCCESS,0,"\033[31mDemasiados Argumentos\033[0m");
        return EXIT_FAILURE;
    }
};