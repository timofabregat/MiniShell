#include "minish.h"

//Funciones auxiliares de la lista/stack
//Se entiende que se pudo haber mergeado los dos inserts para atender a las diferentes listas
//delete list se utilizara para limpiar la lista historial del archivo una vez que sea utilizada
// Reverse se utiliza para dar vuelta el stack/lista para que sea ingesado al archivo en orden
void insert(char* data){
    struct Node *link = (struct Node*)malloc(sizeof(struct Node));

    strcpy(link->data,data);

    link -> next = head;

    head = link;
}

void insert2(char* data){
    struct Node *link = (struct Node*)malloc(sizeof(struct Node));

    strcpy(link->data,data);

    link -> next = curr;

    curr = link;
}

void print_list(struct Node* head){
    struct Node *pointer = head;
    printf("[");

    while(pointer != NULL){
        printf("(%s),",pointer->data);
        pointer = pointer -> next;
    }
    printf("]\n");
}

void reverse(struct Node** head){
    struct Node* prev = NULL;
    struct Node* curr = *head;
    struct Node* next;

    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev; 
}

void deleteList(){
    struct Node* act = curr;
    struct Node* next;

    while(act != NULL){
        next = act->next;
        free(act);
        act = next;
    }

    curr = NULL;
}