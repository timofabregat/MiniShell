#include "minish.h"

//Se definen los textos de informacion
#define HELP_CD      "cd [..|dir]            - cambia de directorio corriente"
#define HELP_DIR     "dir [str]              - muestra archivos en directorio corriente, que tengan 'str'"
#define HELP_EXIT    "exit [status]          - finaliza el minish con un status de retorno (por defecto el status del último comando)"
#define HELP_HELP    "help [built-in]        - Muestra el pantalla la funcionalidad del built-in sleccionado"
#define HELP_HISTORY "history [N]            - muestra los últimos N (10) comandos escritos"
#define HELP_GETENV  "getenv var [var]       - muestra valor de variable(s) de ambiente"
#define HELP_PID     "pid                    - muestra Process Id del minish"
#define HELP_SETENV  "setenv var valor       - agrega o cambia valor de variable de ambiente"
#define HELP_STATUS  "status                 - muestra status de retorno de ultimo comando ejecutado"
#define HELP_UID     "uid                    - muestra nombre y número de usuario dueño del minish"
#define HELP_GID     "gid                    - muestra el grupo principal y los grupos secundarios del usuario."     //completar
#define HELP_UNSETENV "unsetenv var [var...]  - elimina variables de ambiente."       //completar 

//Array de informacion de Built-ins
struct builtin_struct builtin_arr[] = {
    { "cd", builtin_cd, HELP_CD },
    { "dir", builtin_dir, HELP_DIR},
    { "exit", builtin_exit, HELP_EXIT},
    { "getenv", builtin_getenv, HELP_GETENV},
    { "gid", builtin_gid, HELP_GID},
    { "help", builtin_help, HELP_HELP},
    { "history", builtin_history, HELP_HISTORY},
    { "pid", builtin_pid, HELP_PID},
    { "setenv", builtin_setenv, HELP_SETENV},
    { "status", builtin_status, HELP_STATUS},
    { "uid", builtin_uid, HELP_UID},
    { "unsetenv", builtin_unsetenv, HELP_UNSETENV},
    { NULL, NULL, NULL}
};

//Se chequea si la funcion llamada es un built o externa para ser ejecutadas
int ejecutar(int argc, char **argv){
    if(builtin_lookup(argv[0]) != NULL){
        return builtin_lookup(argv[0])->func(argc,argv);
    }
    else{
       return externo(argc, argv);
    }
}