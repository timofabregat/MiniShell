#include "minish.h"


int builtin_dir (int argc, char ** argv){
    if(argc == 1){
        return printlines(".");
    }
    else if(argc == 2){
        DIR *dir2;
        struct dirent *dp2;
        struct stat *fs2;
        fs2 = malloc(sizeof(struct stat));
        int x2;
        if ((dir2 = opendir (".")) == NULL) {
            printf("\033[1;31m");
            error(EXIT_SUCCESS,0,"\033[31mNo se pudo leer el directorio actual\033[0m");
            free(fs2);
            return EXIT_FAILURE; 
        }
        else{
            while ((dp2 = readdir(dir2)) != NULL) {
                x2 = stat(dp2->d_name, fs2);
                if( x2==-1 ){
                    printf("\033[1;31m");
                    error(EXIT_SUCCESS,0,"\033[31mError al leer el archivo\033[0m");
                    return EXIT_FAILURE;
                }
                else{
                    if((strcmp(dp2->d_name,argv[1]) == 0) && (S_ISDIR(fs2->st_mode) != 0)){
                        printlines(argv[1]);
                    }
                    else{

                    }
                }
            }
            free(fs2);
            closedir(dir2);
            return EXIT_SUCCESS;
        }
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

int printlines(char *name){
    DIR *dir;
    struct dirent *dp;
    struct stat *fs;
    fs = malloc(sizeof(struct stat));
    int x;
    if ((dir = opendir (name)) == NULL) {
        printf("\033[1;31m");
        error(EXIT_SUCCESS,0,"\033[31mNo se pudo leer el directorio actual\033[0m");
        free(fs);
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
        free(fs);
        closedir(dir);
        return EXIT_SUCCESS;
    }
}