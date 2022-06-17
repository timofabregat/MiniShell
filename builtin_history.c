#include "minish.h"

FILE *fPtr;


int list_size2 = 0;

int builtin_history (int argc, char ** argv){

    //retornar 10 comandos
    if(argc == 1){
        
        if(list_size >= 10){
            struct Node *pointer = head;
            for(int i=0;i<10;i++){
                printf("%s",pointer->data);
                pointer = pointer ->next;
            }
            return 0;
        }

        else{
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
            return 0;
        }

    }

    else if (argc == 2){
        if(esNumero(argv[1])){
            int x = atoi(argv[1]);
            
            if(list_size >= x){
                struct Node *pointer = head;
                for(int i=0;i<x;i++){
                    printf("%s",pointer->data);
                    pointer = pointer ->next;
                }
                return 0;
            }

            else{
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

                chdir(PWD);
                return 0;                
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