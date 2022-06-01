#include "linea2argv.h"

#include <string.h>
#include <ctype.h>

int linea2argv(char *linea, __attribute__((unused)) int argc, char **argv)
{
    int pos_argv = 0;
    int word = 1;
    char *punt_line = NULL;
    punt_line = strdup(linea);

    while (*punt_line != '\n')
    {
        if ((isspace(*punt_line) || *punt_line == '\t') && word == 0)
        {
            word = 1; // no estas en la palabra
            pos_argv++;
            *punt_line = '\0';
        }
        else if (*punt_line != ' ' && word == 1)
        {
            word = 0;
            argv[pos_argv] = punt_line;
        }
        punt_line++;
    }

    *punt_line = '\0';
    pos_argv++;
    argv[pos_argv] = NULL;
    return pos_argv;
}
