#include "minish.h"
void sort(int l, char file[MAXLINE][MAXLINE]){ //implementacion ordenamiento bubblesort
    int curr = 0,i = 0; //indices
    char var[MAXLINE]; //variable para almacenar linea temporal

    for (i = 0; i < l; i++){ //por cada lugar
        for (curr = 0; l>curr + 1;curr++){ //fijamos un indice de linea
            
            int next = curr + 1; // fijamos indice linea siguiente
            if (strcmp(file[curr], file[next]) > 0) // swap si la linea es mayo a la siguiente
            {
                strcpy(var, file[curr]); //comienza swap
                strcpy(file[curr], file[next]);
                strcpy(file[next], var);//finaliza swap
            }
        }
    }
}