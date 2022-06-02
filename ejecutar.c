#include "minish.h"

#define HELP_CD      "cd [..|dir] - cambia de directorio corriente"
#define HELP_DIR     "dir [str]- muestra archivos en directorio corriente, que tengan 'str'"
#define HELP_EXIT    "exit [status] - finaliza el minish con un status de retorno (por defecto 0)"
#define HELP_HELP    "help [cd|dir|exit|help|history|getenv|pid|setenv|status|uid]"
#define HELP_HISTORY "history [N] - muestra los últimos N (10) comandos escritos"
#define HELP_GETENV  "getenv var [var] - muestra valor de variable(s) de ambiente"
#define HELP_PID     "pid - muestra Process Id del minish"
#define HELP_SETENV  "setenv var valor - agrega o cambia valor de variable de ambiente"
#define HELP_STATUS  "status - muestra status de retorno de ultimo comando ejecutado"
#define HELP_UID     "uid - muestra nombre y número de usuario dueño del minish"
#define HELP_GID    "completar"     //completar
#define HELP_UNSETENV               //completar

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

int ejecutar(int argc, char **argv){
    //Condicion con argc?
    if(builtin_lookup(argv[0]) != NULL){
        return builtin_lookup(argv[0])->func(argc,argv);
    }
    else{
       return externo(argc, argv);
    }
}