#include "minish.h"
#include <limits.h>
char PWD[MAXCWD];
int builtin_cd (int argc, char ** argv){
    char temp[MAXCWD];

    if(argc == 1){
        getcwd(PWD,sizeof(PWD));
        chdir(getenv("HOME"));
        return 0;
    }
    else{
        if(strcmp(argv[1],"-") == 0){
            getcwd(temp,sizeof(temp));
            chdir(PWD);
            strcpy(PWD,temp);
            return 0;
        }
        else{
            getcwd(PWD,sizeof(PWD));
            chdir(argv[1]);
            return 0;
        }
    }

    return 0;
};