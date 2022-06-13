#include "minish.h"

FILE *fPtr;

int counter(FILE *fPtr){

    int count = 0;

    char c;

    fopen(HISTORY_FILE,"r");

    c = getc(fPtr);

    while(c != NULL){
        if(c == '\n'){
            count = count +1;
        }
        c = getc(fPtr);
    }

    fclose(fPtr);
    return count;
}

int builtin_history (int argc, char ** argv){
    fPtr = fopen(HISTORY_FILE,"r");

    int i = 0;

    /*fPtr = fopen(".minish_history","r");
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];
    while (fgets(buffer,MAX_LENGTH, fPtr))
    {
        printf("%s",buffer);
    }*/

    if(argc == 1){
        int x = counter(fPtr);
        printf("%d",x);
        int imp = x - 10;

        const unsigned MAX_LENGTH = 256;
        char buffer[MAX_LENGTH];
        while (fgets(buffer,MAX_LENGTH, fPtr) && i <= x)
        {   
            printf("ENTRE");
            if(i >= imp){
              printf("%s",buffer);  
            }
            i++;
        }

    }
    
    fclose(fPtr);
    return 0;
};