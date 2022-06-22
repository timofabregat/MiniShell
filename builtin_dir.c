#include "minish.h"

DIR *d;
char *path_directory;

int builtin_dir(int argc, char **argv){
    char **names;
    names = malloc(sizeof(char *)*1000);
    if(argc == 1){
        if(listpaths("./", NULL, names)){
            printf("\033[1;31m");
            error(EXIT_SUCCESS,0,"\033[31mError al leer el directorio actual\033[0m");
            return EXIT_FAILURE; 
        }
    }
    else if(argc == 2){
        if(listpaths(argv[1], NULL, names) != 0){
            if(listpaths("./", argv[1], names) != 0){
                printf("\033[1;31m");
                error(EXIT_SUCCESS,0,"\033[31mError al leer el archivo\033[0m");
                return EXIT_FAILURE; 
            }
        }
    }
    else if(argc == 3){
        if(listpaths(argv[1], argv[2], names) != 0){
            printf("\033[1;31m");
            error(EXIT_SUCCESS,0,"\033[31mEl primer argumento no es un directorio valido\033[0m");
            return EXIT_FAILURE; 
        }
    }
    else {
        printf("\033[1;31m");
        error(EXIT_SUCCESS,0,"\033[31mDemasiados Argumentos\033[0m");
        return EXIT_FAILURE; 
    }


    struct stat fs;
    int x;
    char *absolute_path;
    absolute_path = malloc(sizeof(char)*PATH_MAX);
    absolute_path = strdup(path_directory);
    char time[100];
    for(int i = 0; names[i] != NULL; i++){
        strcat(absolute_path, names[i]);
        x = stat(absolute_path, &fs);
        absolute_path = strdup(path_directory);
        permisos(&fs);
        strftime(time, sizeof(time), "%b %d %H:%M", localtime(&fs.st_mtim.tv_sec));
        printf("%ld %5s %5s %5ld %s %s\n", fs.st_nlink, getpwuid(fs.st_uid)->pw_name, getgrgid(fs.st_gid)->gr_name, fs.st_size, time, names[i]);
    }
    return EXIT_SUCCESS;
}

int listpaths(char *path, char *filter, char **names){
    d = opendir(path);
    if(d){
        int n;
        for(n = 0; path[n] != '\0'; n++);
        if(path[n-1] != '/'){
            path = realloc(path, sizeof(char)*(n+1));
            path[n] = '/';
            path[n+1] = '\0';
        }
        path_directory = path;
        struct dirent *dir;
        int i = 0;
        while((dir = readdir(d)) != NULL){
            if(filter == NULL){
                if(dir->d_name[0] != '.'){
                    names[i] = dir->d_name;
                    i++;
                }
            }
            else{
                if(dir->d_name[0] != '.' && strstr(dir->d_name, filter) != NULL){
                    names[i] = dir->d_name;
                    i++;
                }
            }
        }
        names[i] = NULL;
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

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