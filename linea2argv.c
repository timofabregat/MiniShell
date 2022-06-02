#include "linea2argv.h"

#define MAXLINE 1024

#include <string.h>
#include <ctype.h>

int linea2argv(char *linea, int argc, char **argv){
    
    for(int i =0; argv[i] != NULL; i++){
        free(argv[i]);
        argv[i];
    }

    int i = 0,j = 0,k = 0;
    char word[MAXLINE];
    for(;isspace(linea[i]);i++){
            ;
        }
    while(linea[i] != '\0'){
        if (linea[i] == '"'){
            i++;    //salteo la comilla de apertura
            for(j = 0;  linea[i] != '"' && k<argc; i++,j++){
                word[j] = linea[i];
            }
            i++;    //salteo la comilla de cierre
        }
        else if (linea[i] == "'" ){
            i++;    //salteo la comilla de apertura
            for(j = 0; linea[i] != "'" && k<argc; i++,j++){
                word[j] = linea[i];
            }
            i++;    //salteo la comilla de cierre
        }
        else{
            for(j = 0; !isspace(linea[i]) && k<argc; i++,j++){
                word[j] = linea[i];
            }
        }
        word[j] = '\0';
        argv[k] = strdup(word);
        k++;
        for(;isspace(linea[i]);i++){
            ;
        }
    }
    return k;
}