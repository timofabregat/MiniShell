#include "minish.h"

char file[MAXLINE][MAXLINE];
DIR *dir;
char *dir_path;

int builtin_dir(int argc, char **argv){

    dir_path = malloc(sizeof(char)*MAXCWD);
    int len;
    
    if(argc == 1){
        len = len_file(NULL,"./");

        if(-EXIT_FAILURE == len){
            free(dir_path);
            return EXIT_FAILURE;
        }
    }

    else if(argc == 2){
        len = len_file(NULL,argv[1]);
        if(-EXIT_FAILURE == len){ // Si devuelve error, argv[1] es un texto filtro:

            len = len_file(argv[1],"./");
            if(-EXIT_FAILURE == len){
                free(dir_path);
                printf(RED);
                error(EXIT_SUCCESS,0,"\033[31mDirectorio invalido: %s\033[0m",argv[1]);
                return EXIT_FAILURE;
            }
        }
    }

    else if(argc == 3){
        len = len_file(argv[2],argv[1]);
        if(-EXIT_FAILURE == len){
            free(dir_path);
            printf(RED);
            error(EXIT_SUCCESS,0,"\033[31mLlamada inadecuada a la funcion\033[0m");
            return EXIT_FAILURE;
        }
    }

    else {
        printf(RED);
        error(EXIT_SUCCESS,0,"\033[31mDemasiados argumentos\033[0m");
        return EXIT_FAILURE;
    }

    sort(len, file);

    int j = print_dir(len);

    free(dir_path);
    return j;
}