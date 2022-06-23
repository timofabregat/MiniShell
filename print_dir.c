#include "minish.h"
char file[MAXLINE][MAXLINE];
char *dir_path;

int print_dir(int len){
    struct stat f;
    char time[200];
    char abs_path[MAXLINE];
    strcpy(abs_path, dir_path); //almacenamos el path
    int z;

    for(int i = 0; i < len; i++){
        strcat(abs_path, file[i]); //concatenamos la linea al path
        z = stat(abs_path, &f); //chequeamos existencia del path
        strcpy(abs_path, dir_path);
        if(z == -1){ //fail de stat
            return EXIT_FAILURE;
        }

        if(S_ISDIR(f.st_mode) == 1){ //chequeamos si es dir
            printf("d");
        }else{
            printf("-");
        }

        perm_file(f.st_mode);
        

        strftime(time, sizeof(time), "%b %d %H:%M", localtime(&f.st_mtim.tv_sec)); //seteamos el time
        printf("  %ld", f.st_nlink); // seteamos link count
        printf("  %15s  %15s  %6ld", getpwuid(f.st_uid)->pw_name, getgrgid(f.st_gid)->gr_name, f.st_size); //printeamos username,groupname y tamano del file
        printf("  %s", time); //printeamos tiempo
        printf("  %s\n", file[i]);//printeamos filename
    }

    return EXIT_SUCCESS;
}