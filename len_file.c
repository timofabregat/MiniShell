#include "minish.h"

char file[MAXLINE][MAXLINE];
DIR *dir;
char *dir_path;

int len_file( char *busco,char *pwd){
    dir = opendir(pwd);
    if(dir){ // If is a directory:
        int x;
        for(x = 0; '\0' != pwd[x]; x++);

        if(pwd[x-1] != '/'){
            pwd[x+1] = '\0';
            pwd[x] = '/';
        }

        int k = 0;
        dir_path = strdup(pwd);
        struct dirent *d;

        while((d = readdir(dir)) != NULL){

            if(busco == NULL){
                if(d->d_name[0] != '.'){
                    strcpy(file[k], d->d_name);
                    k++;
                }
            }
            else{
                if((strstr(d->d_name, busco) != NULL) && (d->d_name[0] != '.')){
                    strcpy(file[k], d->d_name);
                    k++;
                }
            }
        }

        return k; // cantidad de elementos en el array de nombres
    }

    else{
        return -EXIT_FAILURE;
    }
}