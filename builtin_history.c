#include "minish.h"

FILE *fPtr;


int list_size2 = 0; // tamano lista utilizada para printear historial remoto
/*Notar que su uso una estructura de lista enlazada estilo stack para almacenar los comandos locales
  temporalmente antes de escribirlos en el archivo. Adicionalmente se utiliza otra lista para poder traer el archivo
  .minish_history y printearlo de ser necesario.
*/
// Se entiende que se podria usar una funcion aux para printear las listas ademas de mejorar los metodos de almacenamiento
int builtin_history (int argc, char ** argv){

    getcwd(PWD,sizeof(PWD)); //guardo dir corriente
    chdir(getenv("HOME"));   //debo entrar al directorio home para utilizar el archivo
    fPtr = fopen(HISTORY_FILE, "r"); //abro el archivo en read

    char str[2048];
    while(fgets(str,2048,fPtr)){
        insert2(str);
        list_size2++;
    }
    //fclose(fPtr);
    chdir(PWD);

    //retornar 10 comandos
    if(argc == 1){
        
        if(list_size >= 10){ //Revisar si da con los comandos locales
            struct Node *pointer = head;
            for(int i=0;i<10;i++){ //recorro local
                printf("%s",pointer->data); //printeo cada nodo
                pointer = pointer ->next;   //avanzo un nodo
            }
            printf("\n");
            deleteList();
            //printf("borre\n");
            list_size2 = 0;
            return EXIT_SUCCESS;
        }
        else{
            struct Node *pointer = head;
            for(int i=0;i<list_size;i++){ //recorro local
                printf("%s",pointer->data); //printeo cada nodo
                pointer = pointer ->next;   //avanzo un nodo
            }

            if(list_size2 + list_size >10){ // llego con ambas
                int cnt = 10-list_size;
                struct Node *pointer2 = curr;
                for(int i=0;i<cnt && i < list_size2;i++){ // imprimo las necesarias
                    printf("%s",pointer2->data);
                    pointer2 = pointer2 ->next;
                }
                deleteList();
                list_size2 =0;
                return EXIT_SUCCESS;
            }
            else{
                struct Node *pointer2 = curr;
                for(int i=0;i < list_size2;i++){ //sino tiro todo
                    printf("%s",pointer2->data);
                    pointer2 = pointer2 ->next;
                }
                deleteList();
                list_size2 = 0;
                return EXIT_SUCCESS;
            }
        }

    }

    else if (argc == 2){
        if(esNumero(argv[1])){ // chequear si es numero
            int x = atoi(argv[1]); //transformo a int el string
            
            if(list_size >= x){ //tengo en local
                struct Node *pointer = head;
                for(int i =0; i<x && i<list_size;i++){
                    printf("%s",pointer->data);
                    pointer = pointer ->next;
                }
                deleteList();
                list_size2 = 0;
                return EXIT_SUCCESS;
            }
            else{
                struct Node *pointer = head;
                for(int i =0; i<x && i<list_size;i++){
                    printf("%s",pointer->data);
                    pointer = pointer ->next;
                }

                if(list_size2+list_size > x){ // lego con ambas
                    int cnt = x - list_size;
                    struct Node *pointer2 = curr;
                    for(int i=0;i<cnt && i < list_size2;i++){ //printeo necesarias
                        printf("%s",pointer2->data);
                        pointer2 = pointer2 ->next;
                    }
                    deleteList();
                    list_size2 =0;
                    return EXIT_SUCCESS;
                }
                else{
                    struct Node *pointer2 = curr;
                    for(int i=0;i < list_size2;i++){ //sino tiro todo
                        printf("%s",pointer2->data);
                        pointer2 = pointer2 ->next;
                    }
                    deleteList();
                    list_size2 = 0;
                    return EXIT_SUCCESS;
                }
            }
        }
        else{
            //No se especifica un numero
            printf(RED);
            error(EXIT_SUCCESS,0,"\033[31mArgumento no valido\033[0m");
            return EXIT_FAILURE;
        }
    }

    else{
        //Se utilizan mas de dos argumentos
        printf(RED);
        error(EXIT_SUCCESS,0,"\033[31mDemasiados Argumentos\033[0m"); 
        return EXIT_FAILURE;
    }
};