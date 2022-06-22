#include "minish.h"

FILE *fPtr;


int list_size2 = 0; // tamano lista utilizada para printear historial remoto
/*Notar que su uso una estructura de lista enlazada estilo stack para almacenar los comandos locales
  temporalmente antes de escribirlos en el archivo. Adicionalmente se utiliza otra lista para poder traer el archivo
  .minish_history y printearlo de ser necesario.
*/
// Se entiende que se podria usar una funcion aux para printear las listas
int builtin_history (int argc, char ** argv){

    //retornar 10 comandos
    if(argc == 1){
        
        if(list_size >= 10){ //Revisar si da con los comandos locales
            struct Node *pointer = head;
            for(int i=0;i<10;i++){ //recorro local
                printf("%s",pointer->data); //printeo cada nodo
                pointer = pointer ->next;   //avanzo un nodo
            }
            printf("\n");
            return EXIT_SUCCESS;
        }

        else{ //Sino se llega con los locales, insertar en lista los restantes del historial y printearlos luego de los locales
              //Tener en cuenta que para acceder al archivo .minish_history se debe ir al home del ambiente.
            struct Node *pointer = head;
            for(int i=0;i<list_size;i++){ //printeo locales
                printf("%s",pointer->data);
                pointer = pointer ->next;
            }

            getcwd(PWD,sizeof(PWD)); //guardo dir corriente
            chdir(getenv("HOME"));   //debo entrar al directorio home para utilizar el archivo
            fPtr = fopen(HISTORY_FILE, "r"); //abro el archivo en read
            
            int cnt = 10-list_size;   //calculo cuantos adicionales debo printear
            char str[1024];
            while(fgets(str,1024,fPtr) != NULL){ //cargo archivo, se entiende que se podria reducir la carga
                insert2(str);
                list_size2++;
            }

            struct Node *pointer2 = curr;
            for(int i=0;i<cnt && i < list_size2;i++){ //printeo los necesarios de la lista del archivo
                printf("%s",pointer2->data);
                pointer2 = pointer2 ->next;
            }

            chdir(PWD); //vuelvo al directorio corriente
            printf("\n");
            deleteList();
            return EXIT_SUCCESS;
        }

    }

    else if (argc == 2){
        if(esNumero(argv[1])){ // chequear si es numero
            int x = atoi(argv[1]); //transformo a int el string
            
            if(list_size >= x){ // Revisar si da con los comandos locales
                struct Node *pointer = head;
                for(int i=0;i<x;i++){ //recorro hasta necesario
                    printf("%s",pointer->data); //printeo cada nodo
                    pointer = pointer ->next;
                }
                printf("\n");
                return EXIT_SUCCESS;
            }

            else{ // Sino buscar meter restantes en lista del historial y printearlos luego de printear los locales
                struct Node *pointer = head;
                for(int i =0; i<list_size;i++){ //printeo locales
                    printf("%s",pointer->data);
                    pointer = pointer ->next;
                }

                getcwd(PWD,sizeof(PWD)); //guardo dir corriente
                chdir(getenv("HOME"));   //cambio de dir para utilizar el archivo .minish_history
                fPtr = fopen(HISTORY_FILE, "r"); //

                int cnt = x - list_size; //calculo restantes
                char str[1024];
                while(fgets(str,1014,fPtr) != NULL){ //cargo archivo a lista
                    insert2(str);
                    list_size2++;
                }    

                struct Node *pointer2 = curr;
                for(int i=0;i<cnt && i < list_size2;i++){ //printeo restantes
                    printf("%s",pointer2->data);
                    pointer2 = pointer2 ->next;
                }
                printf("\n");
                deleteList(); //Elimino lista utilizada para printear historial remoto
                chdir(PWD);
                return EXIT_SUCCESS;                
            }
        }
        else{
            //No se especifica un numero
            printf("\033[1;31m");
            error(EXIT_SUCCESS,0,"\033[31mArgumento no valido\033[0m");
            return EXIT_FAILURE;
        }
    }

    else{
        //Se utilizan mas de dos argumentos
        printf("\033[1;31m");
        error(EXIT_SUCCESS,0,"\033[31mDemasiados Argumentos\033[0m"); 
        return EXIT_FAILURE;
    }
};