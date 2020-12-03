/* System Headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Gruppens Headers */
#include "subcryptic.h"
#include "subloadfile.h"
#include "subtools.h"

void func(char **ptr, int size);

int main(void) {
    int size = 8;
    char **dptr = malloc(size*sizeof(char *));

    // passing double pointer values to function
    func(dptr, size);

    // Printing dobbelt pointer
    for (int i = 0; i < size; i++) {
        printf("---------------\n");
        for (int j = 0; j < 4; j++) {
            printf("value[%d][%d] = %c\n", i, j, dptr[i][j]);
        }
    }
    
    // free memory allocation of dobbelt pointer
    free(dptr);

    return EXIT_SUCCESS;
}

void func(char **dptr, int size) {
    // predefined words - words from sentence.
    char wordlist[8][5] = {
        "abe",
        "kat",
        "hest",
        "and",
        "ged",
        "hund",
        "fisk",
        "ravn"
    };



    for (int i = 0; i < size; i++) {
        dptr[i] = malloc(30);
        printf("word[%d]: %s\n", i, wordlist[i]);
        strcpy(dptr[i], wordlist[i]);
    }
}


