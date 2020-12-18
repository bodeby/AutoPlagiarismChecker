#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "prototypes.h"
#include "subtools.h"

#include "subcryptic.h"
#include "subverbatim.h"

int main(void) {

    int sc_one = 4;
    char **wordlist_one[5][300] = {
        "On average, British people eat two pancakes per person on Pancake Day (though plenty of people will have three or four at least) which means 117 million pancakes will be eaten in one day.",
        "On a normal day, Brits eat 30 million eggs per day, but on Pancake Day that goes up to 52 million eggs and enough milk to fill more than 93 Olympic swimming pools.",
        "While some people might put chocolate spread or syrup on their pancakes, the most popular topping, by far, is lemon juice and sugar.",
        "But instead of the fine white sugar you put on top of cakes, British people use the same kind of sugar they put in their tea.",
        "If you want to try making British-style pancakes today, here's a simple recipe."
    };

    int sc_two = 2;
    char **wordlist_two[3][300] = {
        "On average, British people eat ten pancakes per person on Pancake Day which means 117 million pancakes will be eaten in one day.",
        "On a normal day, Brits eat 30 million eggs per day, but on Pancake Day that goes up to 52 million eggs and enough milk to fill more than 93 Olympic swimming pools.",
        "If you want to try making British-style pancakes today, here's a simple recipe."
    };

    // Create verbatim struct element
    int v_size = 0;
    int v_init_capacity = 1;
    int v_capacity = v_init_capacity;
    PlagMatch *vMatches = malloc(v_init_capacity * sizeof(PlagMatch));

    checkPlagMem(vMatches);
    
    // Find verbatim elements
    int verbatim_count = nverbatim(vMatches, wordlist_one, wordlist_two, sc_one, sc_two, v_size, v_capacity);

    // Test print - For Dynamic - Matches Static 
    for (int i = 0; i < verbatim_count; i++) {
        printf("- File 1 [line %2d, match]: '%s'\n", vMatches[i].line_num, vMatches[i].text);
        printf("- File 2 [line %2d, match]: '%s'\n\n", vMatches[i].match_line_num, vMatches[i].match_text);
    }

    // Copy dynamic array elements to static array
    PlagMatch static_vMatches[verbatim_count];
    if (verbatim_count > 0) {
        for (int i = 0; i < verbatim_count; i++) {
            static_vMatches[i] = vMatches[i];
        }
        free(vMatches);
    } else {
        free(vMatches);
    }
}

//param[in] : array of PlagMatches, sizes of arrays and file paths
void eval_results(PlagMatch *vMatches, int vSize, PlagMatch *cMatches, int cSize, char fp_one[], char fp_two[])
{
    printf("\n-----------------------------------------------\n");
    printf("           RESULTS FROM EVALUATION:\n");
    printf("-----------------------------------------------\n");
    printf("FILE 1: %s\n", fp_one);
    printf("FILE 2: %s\n", fp_two);
    printf("-----------------------------------------------\n\n");

    printf("VERBATIM - (found %d matches):\n\n", vSize);
    for (int i = 0; i < vSize; i++)
    {
        printf("- File 1 [line %2d, match]: '%s'\n", vMatches[i].line_num, vMatches[i].text);
        printf("- File 2 [line %2d, match]: '%s'\n\n", vMatches[i].match_line_num, vMatches[i].match_text);
    }
    printf("\n");

    printf("CRYPTIC - (found %d matches):\n\n", cSize);
    for (int i = 0; i < cSize; i++)
    {
        printf("- File 1 [line %2d, word %2d]: %s\n", cMatches[i].line_num, cMatches[i].word_num, cMatches[i].text);
        printf("- File 2 [line %2d, word %2d]: %s\n\n", cMatches[i].match_line_num, cMatches[i].match_word_num, cMatches[i].match_text);
    }
}
