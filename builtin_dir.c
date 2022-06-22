#include "minish.h"

DIR *d;
char *path_directory;

int builtin_dir(int argc, char **argv){
    char **filespaths;
    filespaths = malloc(sizeof(char *)*1000);
    if(argc == 1){                                  
        if(listpaths("./", NULL, filespaths)){                  //En caso de tener solo dir, listo los archivos de mi directorio actual
            printf("\033[1;31m");
            error(EXIT_SUCCESS,0,"\033[31mError al leer el directorio actual\033[0m");
            return EXIT_FAILURE; 
        }
    }
    else if(argc == 2){
        if(listpaths(argv[1], NULL, filespaths) != 0){          //En caso de tener dir arg[1] chequeo si este ultimo es un directorio
            if(listpaths("./", argv[1], filespaths) != 0){          //Si no lo es, busco en mi directorio actual los archivos que contenga en su nombre argv[1] y los imprimo
                printf("\033[1;31m");
                error(EXIT_SUCCESS,0,"\033[31mError al leer el archivo\033[0m");
                return EXIT_FAILURE; 
            }
        }
    }
    else if(argc == 3){
        if(listpaths(argv[1], argv[2], filespaths) != 0){           //En este caso, tengo argv[1] que debe ser un directorio y argv[2] que es la palabra a buscar entre los archivos
            printf("\033[1;31m");
            error(EXIT_SUCCESS,0,"\033[31mEl primer argumento no es un directorio valido\033[0m");
            return EXIT_FAILURE; 
        }
    }
    else {
        printf("\033[1;31m");                                       //Para más argumentos error
        error(EXIT_SUCCESS,0,"\033[31mDemasiados Argumentos\033[0m");
        return EXIT_FAILURE; 
    }


    struct stat fs;
    int x;
    char *absolute_path;
    absolute_path = malloc(sizeof(char)*PATH_MAX);
    absolute_path = strdup(path_directory);
    char date[100];
    for(int i = 0; filespaths[i] != NULL; i++){     
        strcat(absolute_path, filespaths[i]);
        x = stat(absolute_path, &fs);
        absolute_path = strdup(path_directory);
        permisos(&fs);                              //funcion permisos() para traducir el octal de permisos de un archivo al string con drwx
        strftime(date, sizeof(date), "%b %d %H:%M", localtime(&fs.st_mtim.tv_sec));     //traduccion de fechas
        printf("%ld %5s %5s %5ld %s %s\n", fs.st_nlink, getpwuid(fs.st_uid)->pw_name, getgrgid(fs.st_gid)->gr_name, fs.st_size, date, filespaths[i]); //imprimo la metadata del archivo
    }
    return EXIT_SUCCESS;
}

int listpaths(char *path, char *str, char **filespaths){        //Funcion auxiliar que me lee los archivos de un directorio "path" sujeto a un str filtro o no, y me devuelve un array con el conjunto de nombres de los archivos que cumplen las condiciones
    d = opendir(path);                                  //Trato de abrir el directorio
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
        while((dir = readdir(d)) != NULL){              //Si efectivamente es un directorio y pude abrirlo, recorro sus archivos estudiando los casos
            if(str == NULL){                            //Si no tengo un string para compararlo a los nombres inserto en el array de archivos solo los que no comienzan por punto
                if(dir->d_name[0] != '.'){
                    filespaths[i] = dir->d_name;
                    i++;
                }
            }
            else{
                if(dir->d_name[0] != '.' && strstr(dir->d_name, str) != NULL){      //Si tengo filtro, comparo si la palabra esta contenida en el nombre y en ese caso la agrego al array
                    filespaths[i] = dir->d_name;
                    i++;
                }
            }
        }
        filespaths[i] = NULL;
        return EXIT_SUCCESS;
    }
    else{
        return EXIT_FAILURE;
    }
}

void permisos(struct stat *fs){                             //Funcion auxiliar permisos para traducir los bits de los permisos.
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