#include "minish.h"


int builtin_dir (int argc, char ** argv){
    if(argc == 1){
        DIR *dir;
        struct dirent *dp;
        struct stat *fs;
	//fs = malloc(sizeof(struct stat));
        int x;
        if ((dir = opendir (".")) == NULL) {
            printf("\033[1;31m");
            error(EXIT_SUCCESS,0,"\033[31mNo se pudo leer el directorio actual\033[0m");
            return EXIT_FAILURE; 
        }
        else{
            while ((dp = readdir(dir)) != NULL) {
                x = stat(dp->d_name, fs);
	//		printf("%d - %s - %ld\n",fs->st_mode,dp->d_name,fs->st_ctime);
                if( x==-1 ){
                    printf("\033[1;31m");
                    error(EXIT_SUCCESS,0,"\033[31mError al leer el archivo\033[0m");
                    return EXIT_FAILURE;
                }
                else{
                    char *mtime;
                    printf("%o - %s - %ld - %ld - %s \n",fs->st_mode, getpwuid(fs->st_uid)->pw_name, fs->st_size, fs->st_mtime, dp->d_name);
                }
            }
            closedir(dir);
            return EXIT_SUCCESS;
        }
    }
    else if(argc == 2){

    }
    else if (argc == 3){

    }
    else{
        printf("\033[1;31m");
        error(EXIT_SUCCESS,0,"\033[31mDemasiados Argumentos\033[0m");
        return EXIT_FAILURE; 
    }
};
