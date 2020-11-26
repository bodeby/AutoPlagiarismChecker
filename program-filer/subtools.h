#ifndef SUBTOOLS_H
#define SUBTOOLS_H
#include <stdio.h>
#include <string.h>

// print char array as string 
void print_str(char array[]) {
    for (unsigned long i = 0LU; i < strlen(array); i++) {
        printf("%c", array[i]);
    }
    printf("\n");
}


// Check if Memory has been properly allocated
int checkMem(char *arr) {
    if (arr == NULL) {
        fprintf(stderr, "Array memory not allocated");
        return EXIT_FAILURE;
    } else {
        return EXIT_SUCCESS;
    }
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


// Count number of words in string
int count_words(char input_str[]) {
    int word_count = 0;

    // Count spaces (Eg count the numbers of words)
    for (int i = 0; i < (int) strlen(input_str); i++) {
        // Check for spaces in string
        if ((int) input_str[i] == 32 || (int) input_str[i] == '\t') {
            word_count += 1;
        }
    }
    word_count += 1;

    return word_count;
}


/* ----------- LEVENSHTEIN ALGORITHM -------------
* Made by Ben Bullock
* link: https://www.lemoda.net/c/levenshtein */
static int editDist (const char * word1, const char * word2)
{
    int len1 = strlen (word1);
    int len2 = strlen (word2);

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
        char c1 = word1[i-1];
        for (j = 1; j <= len2; j++) {

            char c2 = word2[j-1];
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
