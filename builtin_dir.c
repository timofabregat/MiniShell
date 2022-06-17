#include "minish.h"


int builtin_dir (int argc, char ** argv){
    if(argc == 1){
        DIR *dir;
        struct dirent *dp;
        struct stat *fs;
        int x;
        if ((dir = opendir (".")) == NULL) {
            printf("\033[1;31m");
            error(EXIT_SUCCESS,0,"\033[31mNo se pudo leer el directorio actual\033[0m");
            return EXIT_FAILURE; 
        }
        else{
            while ((dp = readdir(dir)) != NULL) {
                x = stat(dp->d_name, fs);
                if( x==-1 ){
                    printf("\033[1;31m");
                    error(EXIT_SUCCESS,0,"\033[31mError al leer el archivo\033[0m");
                    return EXIT_FAILURE;
                }
                else{
                    permisos(fs);
                    printf("%s  %ld  %s %s\n", getpwuid(fs->st_uid)->pw_name, fs->st_size, strtok(ctime(&fs->st_mtime), "\n"), dp->d_name);
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

void permisos(struct stat *fs){
    printf( (S_ISDIR(fs->st_mode)) ? "d" : "-");
    printf( (fs->st_mode & S_IRUSR) ? "r" : "-");
    printf( (fs->st_mode & S_IWUSR) ? "w" : "-");
    printf( (fs->st_mode & S_IXUSR) ? "x" : "-");
    printf( (fs->st_mode & S_IRGRP) ? "r" : "-");
    printf( (fs->st_mode & S_IWGRP) ? "w" : "-");
    printf( (fs->st_mode & S_IXGRP) ? "x" : "-");
    printf( (fs->st_mode & S_IROTH) ? "r" : "-");
    printf( (fs->st_mode & S_IWOTH) ? "w" : "-");
    printf( (fs->st_mode & S_IXOTH) ? "x" : "-");
    printf(" ");
}