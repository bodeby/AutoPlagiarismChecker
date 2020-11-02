// System Headers 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Gruppens Headers 
#include "subtools.h"
#include "subcryptic.h"
#include "subloadfile.h"

int main(void){
    char arr_test1[] = {'Hej mit navn er Oscar', 'Jeg er 22 aar', 'Jeg gaar på uni', 'Oscar drikker vand og aeder hele tiden'};
    char arr_test2[] = {'Hej mit navn er Oscar', 'Jeg gaar på uni', 'Jeg er 22 aar', 'Oscar drikker vand og aeder hele tiden'};
    verbatim(arr_test1, 3, arr_test2, 3);
    return 0;
}

char *verbatim(char arr1[], size_t size_of_arr1, char arr2[], size_t size_of_arr2){
    char *verb_arr1 = malloc(size_of_arr1 * sizeof(char));
    int verbatimcount = 0;
    int index = 0;
    
    for(int i = 0; i < strlen(arr1[i]); i++){
        for(int j = 0; j < strlen(arr2[j]); j++){
            if(arr1[i] == arr2[j]){
                verb_arr1[index] = arr1[i];
                index++;
                verbatimcount++;                
            }
        }
    }
    for(int k = 0; k <= (int) size_of_arr1; k++){
        printf("%c\n", verb_arr1[k]);
    }
    return 'c';
}