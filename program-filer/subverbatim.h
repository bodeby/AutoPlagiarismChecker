// System Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char **verbatim(char arr1[][40], char arr2[][40]) {
    char **verb_arr2 = malloc(100 * sizeof(char*)); //Output arrayet
    if(verb_arr2 == NULL){
        exit(EXIT_FAILURE);
    }
    int size_of_arr1 = sizeof(arr1);
    int countchar = 0;
    int verbindex = 0;
    for(int k = 0; k < 100; k++){
        verb_arr2[k] = malloc(40 * sizeof(char));
    }
    for (int i = 0; i <= (int)size_of_arr1; i++) { //i styrer sætninger i det første array
        for (int n = 0; n <= (int)size_of_arr1; n++) { //n styrer sætninger i det andet array
            countchar = 0;                                              //countchar er antal tegn, der er ens i sætningerne
            for (int j = 0; j <= (int)strlen(arr1[i]) - 1; j++) { //j styrer tegn i begge sætninger
                if (arr1[i][j] == arr2[n][j]){ //Hvis tegnet er det samme i begge sætninger
                    countchar++;                           //Så er countchar antal tegn ens
                    if (countchar == (int)strlen(arr1[i])) { //Hvis der er lige så mange ens tegn, som der er i sætningen
                        for (int l = 0; l < (int)strlen(arr1[i]); l++) {
                            verb_arr2[verbindex][l] = arr1[i][l]; //Så bliver sætningen sat ind i det nye array
                        }
                        verbindex++;
                    }
                }
            }
        }
    }

    /*for (int k = 0; k <= (int)size_of_arr1; k++)
    {
        printf("%s\n", verb_arr2[k]);
    } */
    return verb_arr2;
}
