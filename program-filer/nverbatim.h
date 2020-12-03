// System headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "subtools.h"

void nverbatim(char **sentences_one, char **sentences_two, int sc_one, int sc_two) {

    printf("len 1: %d, len 2: %d\n", sc_one, sc_two);
    for (int i = 0; i < sc_one; i++) {
        for (int j = 0; j < sc_two; j++) {
            int diff = editDist(sentences_one[i], sentences_two[j]);
            if (diff == 0) {
                printf("Verbatim!!!!!\n");
            } else {
                printf("Awwww.. editDist: %d at [%d,%d]\n", diff, i, j);
            }
        }
    }
}