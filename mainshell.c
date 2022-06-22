#include "minish.h"

#define MAXLINE 1024

int globalstatret = 0;
int list_size = 0;
struct Node *head = NULL;
struct Node *curr = NULL;

FILE *fPtr;

void
prompt(char *ps) {
    // ps is the prompt string
    // Se encuentra elusuario para luego printear el path
    int j =0;

    struct passwd *pws;
    int id = geteuid();
    pws = getpwuid(id);

    /*for(int i =5; ps[i] != '\0';i++,j++){
        ps[j] = ps[i];
    }
    ps[j] = '\0';*/
    fprintf(stderr, "%s:%s > ", pws->pw_name,ps);
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
        char **argv2=malloc(sizeof(char*)*MAXLINE);
        argc = linea2argv(line, MAXLINE, argv2);
        insert(line); // En esta linea se carga el comando a la lista local para luego ser cargada al archivo una vez finalizado el minish
        list_size++; //Aumentamos el tamano de lista/stack
        if(argc > 0){
            globalstatret = ejecutar(argc,argv2); //Status del minish
            for(int i =0; argv2[i] != NULL; ++i){ // Se libera el array donde tenemos los argumentos a leer para comandos
                free(argv2[i]);
                //argv[i];
            }
            //free(argv2);
        }
    } 
    /* Una vez finalizado vamos al home para acceder al arhcibo historial, hacemos un reverse de la lista
       y al recorrerla la vamos insertando a dicho arhivo
    */
    getcwd(PWD,sizeof(PWD));
    chdir(getenv("HOME"));
    fPtr = fopen(HISTORY_FILE,"a");
    
    reverse(&head);

    struct Node *pointer = head;
    while(pointer != NULL){
        fprintf(fPtr, "%s",pointer->data);
        pointer = pointer -> next;
    }
    fclose(fPtr);
    chdir(PWD);
    
    fputc('\n', stderr);
    fprintf(stderr, "Exiting %s ...\n", cwd);
    exit(EXIT_SUCCESS);
}
