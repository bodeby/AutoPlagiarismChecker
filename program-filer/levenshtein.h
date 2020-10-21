/* LEVENSHTEIN ALGORITHM */
#include <string.h>
#include <stdio.h>

static int distance (const char * word1,
                     const char * word2)
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