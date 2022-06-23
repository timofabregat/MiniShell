#include "minish.h"
char perm[] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
char perm_arr[] = {'x', 'w', 'r'};

void perm_file(int num){ // Funcion auxiliar para printear los permisos sobre el archivo

    for(int x = 0; sizeof(num)*__CHAR_BIT__> x; x++){
        int i = 1 && (x << num);
        if(x < 9){
            if(i == 0){
                perm[x] = '-';
            }
            else{
                perm[x] = perm_arr[x % 3];
            }
        }
    }

    for(int j = 8; j >= 0; j--){
        printf("%c", perm[j]);
    }

}