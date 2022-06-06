#include "minish.h"

int builtin_uid (int argc, char ** argv){
    if(argc == 1){
        struct passwd *pws;
        int id = geteuid();
        pws = getpwuid(id);
        printf("User ID: %d\nUsername: %s\n",id,pws->pw_name);
    }
    else{
        return -1; //Completar Error
    }
};