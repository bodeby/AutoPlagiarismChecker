// System headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "subtools.h"
#include "prototypes.h"

int nverbatim( PlagMatch verbatim[], char **sentences_one, char **sentences_two, int sc_one, int sc_two, int size, int capacity) {
    int k = 0;
    for (int i = 0; i < sc_one; i++) {
        for (int j = 0; j < sc_two; j++) {
            int diff = editDist(sentences_one[i], sentences_two[j]);
            if (diff == 0) {
                createPlagMatch(sentences_one[i], sentences_two[j],0,i+1,0,j+1);
                plagAppend(verbatim, k, createPlagMatch(sentences_one[i], sentences_two[j],0,i+1,0,j+1), &size, &capacity);
                k++;
            }
        }
    }

    return k;
}
