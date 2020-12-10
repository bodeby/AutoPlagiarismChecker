// System headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "subtools.h"
#include "prototypes.h"

PlagMatch *nverbatim(char **sentences_one, char **sentences_two, int sc_one, int sc_two) {
    int k = 0;
    for (int i = 0; i < sc_one; i++)
    {
        for (int j = 0; j < sc_two; j++)
        {
            int diff = editDist(sentences_one[i], sentences_two[j]);
            if (diff == 0) {
                k++;
            }
        }
    }
    PlagMatch *vMatches = (PlagMatch *) malloc(k * sizeof(PlagMatch));
    if(vMatches == NULL){
        exit(EXIT_FAILURE);
    }
    int k = 0;
    for (int i = 0; i < sc_one; i++)
    {
        for (int j = 0; j < sc_two; j++)
        {
            int diff = editDist(sentences_one[i], sentences_two[j]);
            if (diff == 0) {
                strcpy(vMatches[k].text, sentences_one[i]);
                strcpy(vMatches[k].match_text, sentences_two[j]);
                vMatches[k].line_num = i + 1;
                vMatches[k].match_line_num = j + 1;
                k++;
            }
        }
    }
    return vMatches;
}