#include "minish.h"

#define MAXLINE 1024

int globalstatret = 0;

void
prompt(char *ps) {
    // ps is the prompt string
    fprintf(stderr, "(%s) ^D to exit > ", ps);
}

void
sigint_handler(int signum) {                    // the handler for SIGINT
    fprintf(stderr, "Interrupt! (signal number %d)\n", signum);
}

int
main(int argc, char *argv[]) {
    char cwd[MAXCWD];
    char line[MAXLINE];
    struct sigaction oldact, newact;
    char **argv2=malloc(sizeof(char*)*MAXLINE);
    
    sigaction(SIGINT, NULL, &newact);           // the  previous action for SIGINT is saved in oldact
    newact.sa_handler = sigint_handler;
    sigaction(SIGINT, &newact, NULL);           // set SIGINT handler for loop

    for (;;) {
        getcwd(cwd, sizeof(cwd));
        prompt(cwd);
        if (fgets(line, MAXLINE, stdin) == NULL) {  // EOF
            // ============== NEW CODE HERE ==============
            if (feof(stdin)) {
                break;      // normal EOF, break loop
            } else {
                continue;   // not EOF, read system call was interrupted, continue loop
            }
        }
        argc = linea2argv(line, MAXLINE, argv2);
        if(argc > 0){
            globalstatret = ejecutar(argc,argv2);
        }
    }
    fputc('\n', stderr);
    fprintf(stderr, "Exiting %s ...\n", cwd);
    exit(EXIT_SUCCESS);
}
