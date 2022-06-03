#include "minish.h"

void builtin_help(){
    printf("- builtin_exit[N]: Termina el shell, admiteun parametro que es el status de retorn. Sin ningun parametro, usa como retorno el del ultimo comando ejecutado\n");
    printf("\n");
    printf("- builtin_pid: Muestra el process id del shell.\n");
    printf("\n");
    printf("- builtin_uid: Muestra el userid como número y también el nombre de usuario.\n");
    printf("\n");
    printf("- builtin_gid:  Muestra el grupo principal y los grupos secundarios del usuario.\n");
    printf("\n");
    printf("- builtin_getenv[variable..]: Muestra los valores de dichas variables de ambiente. Los parámetros son las variables de ambiente para las cuales se quiere saber el valor. La salida es una serie de líneas variable=valor.\n");
    printf("\n");
    printf("- builtin_setenv variable valor: Define una variable nueva de ambiente o cambia el valor de una variable de ambiente existente.\n");
    printf("\n");
    printf("- builtin_unsetenv var[var..]: Elimina variables de ambiente.\n");
    printf("\n");
    printf("- builtin_cd[dir]: Cambiar el directorio corriente, admite un parámetro. Además, hace deja “seteada” la variable de ambiente PWD con el pathname absoluto del directorio corriente. El valor del parámetro puede ser:\n\t -cd xxx (cambia al directorio xxx)\n\t - cd - (cambia al directorio anterior)\n\t - cd (cambia al directorio de la variable HOME)\n");
    printf("\n");
    printf("- builtin_status: Muestra el status de retorno del último comando ejecutado, en general sería 0 para un comando que funcionó en forma exitosa y un valor diferente si hubo errores.\n");
    printf("\n");
    printf("- builtin_help[comando]: Admite hasta un parámetro que será el comando, para el cual se escribirá una ayuda más extensa. Sin argumentos escribe un texto de ayuda indicando qué comandos internos existen.\n");
    printf("\n");
    printf("- builtin_dir[text/directorio]: Simula una ejecución simplificada del comando ls -l. Sin argumentos muestra la lista de archivos del directorio corriente. Con un único argumento, será un texto que:\n\t - si corresponde a un directorio existente, muestra la lista de todos los archivos de ese directorio.\n\t - si no es un directorio, muestra todos los archivos cuyo nombre contenga ese texto.\nCon dos argumentos, el funcionamiento es la fusión de los dos casos anteriores: el primer argumento debe ser un directorio (si no, es un error) y el segundo es el texto de filtro.\n");
    printf("\n");
    printf("- builtin_history[N]: Muestra los N (por defecto 10) comandos anteriores, que deben almacenarse para ejecuciones posteriores del minish, en el archivo $HOME/.minish_history).\n");
}

void builtin_help(char *command){
    struct builtin_struct *builtin = NULL;
    builtin = builtin_lookup(command);

    if (builtin == NULL)
    {
        printf("Comando no existe en libreria.\n");
    }

    else{

        if (strcmp(builtin->cmd,"builtin_exit") == 0){
            printf("- builtin_exit[N]: Termina el shell, admiteun parametro que es el status de retorn. Sin ningun parametro, usa como retorno el del ultimo comando ejecutado\n");
        }
        else if(strcmp(builtin->cmd,"builtin_pid") == 0){
            printf("- builtin_pid: Muestra el process id del shell.\n");
        }
        else if(strcmp(builtin->cmd,"builtin_uid") == 0){
            printf("- builtin_uid: Muestra el userid como número y también el nombre de usuario.\n");
        }
        else if(strcmp(builtin->cmd,"builtin_gid") == 0){
            printf("- builtin_gid:  Muestra el grupo principal y los grupos secundarios del usuario.\n");
        }
        else if(strcmp(builtin->cmd,"builtin_getenv") == 0){
            printf("- builtin_getenv[variable..]: Muestra los valores de dichas variables de ambiente. Los parámetros son las variables de ambiente para las cuales se quiere saber el valor. La salida es una serie de líneas variable=valor.\n");
        }
        else if(strcmp(builtin->cmd,"builtin_setenv") == 0){
            printf("- builtin_setenv variable valor: Define una variable nueva de ambiente o cambia el valor de una variable de ambiente existente.\n");
        }
        else if(strcmp(builtin->cmd,"builtin_unsetenv") == 0){
            printf("- builtin_unsetenv var[var..]: Elimina variables de ambiente.\n");
        }
        else if(strcmp(builtin->cmd,"builtin_cd") == 0){
            printf("- builtin_cd[dir]: Cambiar el directorio corriente, admite un parámetro. Además, hace deja “seteada” la variable de ambiente PWD con el pathname absoluto del directorio corriente. El valor del parámetro puede ser:\n\t -cd xxx (cambia al directorio xxx)\n\t - cd - (cambia al directorio anterior)\n\t - cd (cambia al directorio de la variable HOME)\n");
        }
        else if(strcmp(builtin->cmd,"builtin_status") == 0){
            printf("- builtin_status: Muestra el status de retorno del último comando ejecutado, en general sería 0 para un comando que funcionó en forma exitosa y un valor diferente si hubo errores.\n");
        }
        else if(strcmp(builtin->cmd,"builtin_help") == 0){
            printf("- builtin_help[comando]: Admite hasta un parámetro que será el comando, para el cual se escribirá una ayuda más extensa. Sin argumentos escribe un texto de ayuda indicando qué comandos internos existen.\n");
        }
        else if(strcmp(builtin->cmd,"builtin_dir") == 0){
            printf("- builtin_dir[text/directorio]: Simula una ejecución simplificada del comando ls -l. Sin argumentos muestra la lista de archivos del directorio corriente. Con un único argumento, será un texto que:\n\t - si corresponde a un directorio existente, muestra la lista de todos los archivos de ese directorio.\n\t - si no es un directorio, muestra todos los archivos cuyo nombre contenga ese texto.\nCon dos argumentos, el funcionamiento es la fusión de los dos casos anteriores: el primer argumento debe ser un directorio (si no, es un error) y el segundo es el texto de filtro.\n");
        }
        else if(strcmp(builtin->cmd,"builtin_dir") == 0){
            printf("- builtin_history[N]: Muestra los N (por defecto 10) comandos anteriores, que deben almacenarse para ejecuciones posteriores del minish, en el archivo $HOME/.minish_history).\n");
        }
    }
}