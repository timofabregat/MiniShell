#include "minish.h"

int externo(int argc, char ** argv){
    struct sigaction oldact, newact;
    pid_t pid;                          // process ID: an unsigned integer type
    int wait_status;                    // wait status will be filled by waitpid syscall
    /*fprintf(stderr, "Will execute command %s\n",argv[0]);
    fprintf(stderr, "Will fork command %s\n", argv[0]);*/

    sigaction(SIGINT, NULL, &oldact);   // the  previous action for SIGINT is saved in oldact
    newact = oldact;

    if ((pid = fork()) < 0) {           // fork error, i.e. too many processes
        error(0, errno, "fork error\n"); // will fprintf the error and go on
        return EXIT_FAILURE;
    }

    else if (pid == 0) {                 // child process
        newact.sa_handler = SIG_DFL;
        sigaction(SIGINT, &newact, NULL);   // reset SIGINT default for child
        execvp(argv[0] , &argv[0]);
        error(EXIT_FAILURE, errno, "execvp error\n"); // if exec not successful, just exit child
    }

    else {
        newact.sa_handler = SIG_IGN;
        sigaction(SIGINT, &newact, NULL);   // ignore SIGINT while waiting
        waitpid(pid, &wait_status, 0);
        sigaction(SIGINT, &oldact, NULL);   // restore SIGINT when child finishes
        //fprintf(stderr, "Ended child process %s\n",argv[0]);
    }
    return 0; 
};