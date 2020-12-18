#ifndef SUBTOOLS_H
#define SUBTOOLS_H
#include <stdio.h>
#include <string.h>
#include "prototypes.h"

// Check if Memory has been properly allocated
int checkMem(char *arr) {
    if (arr == NULL) {
        fprintf(stderr, "Array memory not allocated");
        return EXIT_FAILURE;
    } else {
        //printf("\nMemory Allocated Properbly\n");
        return EXIT_SUCCESS;
    }
}

int checkPlagMem(PlagMatch *arr) {
    if (arr == NULL) {
        fprintf(stderr, "Array memory not allocated");
        return EXIT_FAILURE;
    } else {
        //printf("\nMemory Allocated Properbly\n");
        return EXIT_SUCCESS;
    }
}

// Count number of words in string
int count_words(char input_str[]) {
    int word_count = 0;
    int input_length = (int) strlen(input_str);

    // Count spaces (Eg count the numbers of words)
    for (int i = 0; i < input_length; i++) {
        // Check for spaces in string
        if ((int) input_str[i] == 32 || (int) input_str[i] == '\t') {
            // Dont add to word_count if first or last char is space or tab.
            if (i != 0 && i != (input_length-1)) {
                word_count += 1;
            }
        }
    }

    word_count += 1;
    
    return word_count;
}

// Append character to string
void append(char *arr, int index, char value, int *size, int *capacity) {
    while (*size > *capacity) {
        arr = realloc(arr, sizeof(arr) + ((int) sizeof(char) * 256));
        *capacity = sizeof(arr);
    }
    arr[index] = value;
    *size = *size + 1;
}

// Append character to string
void plagAppend(PlagMatch *arr, int index, PlagMatch value, int *size, int *capacity) {
    while (*size > *capacity) {
        arr = realloc(arr, sizeof(arr) + sizeof(PlagMatch) + 256);
        *capacity = sizeof(arr);
    }
    arr[index] = value;
    *size = *size + 1;
}

// Create the plag match "objects"
PlagMatch createPlagMatch(char *str_one, char *str_two, int wn_one, int ln_one, int wn_two, int ln_two) {
    PlagMatch plag_result; // declare Stuct

    // append values from original file
    printf("CPM - String 1: %s\n", str_one); // test only fjernes inden afl
    strcpy(plag_result.text, str_one);
    plag_result.word_num = wn_one;
    plag_result.line_num = ln_one;

    // append values from test file
    printf("CPM - String 2: %s\n", str_two); // test only fjernes inden afl
    strcpy(plag_result.match_text, str_two);
    plag_result.match_word_num = wn_two;
    plag_result.match_line_num = ln_two;

    // return stuct
    return plag_result;
}

/* ----------- LEVENSHTEIN ALGORITHM -------------
* Made by Ben Bullock
* link: https://www.lemoda.net/c/levenshtein */
static int editDist (const char * string_one, const char * string_two)
{
    int len1 = strlen(string_one);
    int len2 = strlen(string_two);

    int matrix[len1 + 1][len2 + 1];
    int i;
    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (i = 0; i <= len2; i++) {
        matrix[0][i] = i;
    }
    for (i = 1; i <= len1; i++) {
        int j;
        char c1 = string_one[i-1];
        for (j = 1; j <= len2; j++) {

            char c2 = string_two[j-1];
            if (c1 == c2) {
                matrix[i][j] = matrix[i-1][j-1];
            }
            else {
                int delete = matrix[i-1][j] + 1;
                int insert = matrix[i][j-1] + 1;
                int substitute = matrix[i-1][j-1] + 1;
                int minimum = delete;
                if (insert < minimum) {
                    minimum = insert;
                }
                if (substitute < minimum) {
                    minimum = substitute;
                }
                matrix[i][j] = minimum;
            }
        }
    }
    return matrix[len1][len2];
}

#endif // SUBTOOLS_H
