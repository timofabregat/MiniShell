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
    // Se encuentra el usuario para luego printear el path
    int j =0;

    struct passwd *pws; 
    int id = geteuid();
    pws = getpwuid(id); //se obtiene passord asociada al usuario

    fprintf(stderr, "%s:%s > ", pws->pw_name,ps); //se imprime el path en conjunto con el usuario
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
                
            }
            
        }
    } 
    /* Una vez finalizado vamos al home para acceder al arhcibo historial, hacemos un reverse de la lista
       y al recorrerla la vamos insertando a dicho arhivo
    */
    getcwd(PWD,sizeof(PWD)); //se guarda el directorio corriente
    chdir(getenv("HOME"));  //Voy al dir home para utilizar el archivo .minish_history
    fPtr = fopen(HISTORY_FILE,"a"); //Abro el archivo en formato append
    
    reverse(&head);  //Doy vueta la lista para ingresar los comandos en orden necesario

    struct Node *pointer = head;
    while(pointer != NULL){
        fprintf(fPtr, "%s",pointer->data); //Imprimo en archivo el nodo actual
        pointer = pointer -> next; //Avanzo de nodo
    }
    fclose(fPtr); //cierro Archivo
    chdir(PWD); //Retorno a dir corriente
    
    fputc('\n', stderr);
    fprintf(stderr, "Exiting %s ...\n", cwd);
    exit(EXIT_SUCCESS);
}
