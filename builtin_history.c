#include "minish.h"

FILE *fPtr;


int list_size2 = 0;

// Se entiende que se podria usar una funcion aux para printear las listas
int builtin_history (int argc, char ** argv){

    //retornar 10 comandos
    if(argc == 1){
        
        if(list_size >= 10){ //Revisar si da con los locales
            struct Node *pointer = head;
            for(int i=0;i<10;i++){
                printf("%s",pointer->data);
                pointer = pointer ->next;
            }
            printf("\n");
            return EXIT_SUCCESS;
        }

        else{ //Sino se llega con los locales, insertar en lista los restantes del historial y printearlos
            struct Node *pointer = head;
            for(int i=0;i<list_size;i++){
                printf("%s",pointer->data);
                pointer = pointer ->next;
            }

            getcwd(PWD,sizeof(PWD));
            chdir(getenv("HOME"));
            fPtr = fopen(HISTORY_FILE, "r");
            
            int cnt = 10-list_size;
            char str[1024];
            while(fgets(str,1024,fPtr) != NULL){
                insert2(str);
                list_size2++;
            }

            struct Node *pointer2 = curr;
            for(int i=0;i<cnt && i < list_size2;i++){
                printf("%s",pointer2->data);
                pointer2 = pointer2 ->next;
            }

            chdir(PWD);
            printf("\n");
            deleteList();
            return EXIT_SUCCESS;
        }

    }

    else if (argc == 2){
        if(esNumero(argv[1])){ // chequear si es numero
            int x = atoi(argv[1]);
            
            if(list_size >= x){ // Revisar si da con los locales
                struct Node *pointer = head;
                for(int i=0;i<x;i++){
                    printf("%s",pointer->data);
                    pointer = pointer ->next;
                }
                printf("\n");
                return EXIT_SUCCESS;
            }

            else{ // Sino buscar meter restantes en lista del historial y printearlos 
                struct Node *pointer = head;
                for(int i =0; i<list_size;i++){
                    printf("%s",pointer->data);
                    pointer = pointer ->next;
                }

                getcwd(PWD,sizeof(PWD));
                chdir(getenv("HOME"));
                fPtr = fopen(HISTORY_FILE, "r");

                int cnt = x - list_size;
                char str[1024];
                while(fgets(str,1014,fPtr) != NULL){
                    insert2(str);
                    list_size2++;
                }    

                struct Node *pointer2 = curr;
                for(int i=0;i<cnt && i < list_size2;i++){
                    printf("%s",pointer2->data);
                    pointer2 = pointer2 ->next;
                }
                printf("\n");
                deleteList();
                chdir(PWD);
                return EXIT_SUCCESS;                
            }
        }
        else{
            printf("\033[1;31m");
            error(EXIT_SUCCESS,0,"\033[31mArgumento no valido\033[0m");
            return EXIT_FAILURE;
        }
    }

    else{
        printf("\033[1;31m");
        error(EXIT_SUCCESS,0,"\033[31mDemasiados Argumentos\033[0m"); 
        return EXIT_FAILURE;
    }
};