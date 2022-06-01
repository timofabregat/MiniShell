#include "linea2argv.h"
#include <stdlib.h>
#include <stdio.h>

#define MAXLINE 1024


int
main(int argc, char *argv[]) {
    char str[MAXLINE];
    char **argv2=malloc(sizeof(char*)*MAXLINE);

    fgets(str, MAXLINE, stdin);

    printf("%d\n",linea2argv(str,argc,argv2));

    return 0;
}