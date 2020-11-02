#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// Project Headers
#include "subtools.h"

/* Check if string is worth checking */
bool check_string(char str_one[], char str_two[], bool *cryptic_check) {
    double len_one = strlen(str_one);
    double len_two = strlen(str_two);
    double threshold = 1.50;
    double len_dif = ((fabs(len_one - len_two) / ((len_one + len_two) / 2) ) * 100);

    printf("len_one: %.2f\n", len_one);
    printf("len_two: %.2f\n", len_two);
    printf("procent afvigelse %.2f%%\n", len_dif);
    printf("Threshold: %.2f%%\n", threshold);

    if (len_dif >= threshold) {
        *cryptic_check = true;
    } else {
        *cryptic_check = false;
    }

    return true;
}

// Find Cryptic characters
void loc_crypt(char input_str[]) {
    int c_val_min = 32;
    int c_val_max = 126;

    for (int i = 0; i < (int) strlen(input_str); i++) {
        if ((int) input_str[i] < c_val_min || (int) input_str[i] > c_val_max) {
            printf("Cryp: %c - %i\n", input_str[i], (int) input_str[i]);
        } else {
            printf("Norm: %c - %i\n",input_str[i], (int) input_str[i]);
        }
    }
}

// Split words in to 2-dim array of words.
void word_splitter(char input_str[]) {
    int size = 0;
    int init_capacity = 256;
    int capacity = init_capacity;
    char *arr = malloc(init_capacity * sizeof(char));
    int word_count = 0;

    // Check if memory has been correctly allocated
    checkMem(arr);

    // Count number of words in string
    count_words(input_str, &word_count);
    word_count++;

    // Init word_array arr[words counted][space needed for word of max 30 chars]
    int word_max = 30 * (int) sizeof(char);
    int word_pos = 0;
    char word_array[word_count][word_max];

    // Loop through string
    int j = 0;
    for (int i = 0; i < (int) strlen(input_str); i++) {
        
        // if character is not equal to space, append to array
        if ((int) input_str[i] != 32 || (int) input_str[i] == '\t') {
            append(arr, (int) j, input_str[i], &size, &capacity);
            j++;
            //printf("Iteration: %2d - content: %s\n", i, arr);
        }
        // if character is equal to space
        else {
            //printf("Iteration: %2d - content: cleared\n", i); 
            strncpy(word_array[word_pos], arr, j);  // Add Word to list
            word_array[word_pos][j] = '\0';         // Add \0 to word
            word_pos++;                             // Set postion to next vacant spot
            j = 0;
        }
    }

    // Print out the words in word array 
    printf("\nWord in sentence: %i\n", word_count);
    for (int i = 0; i < word_count; i++) {
        printf("word_list[%d]: %s\n", i, word_array[i]);
    }

    free(arr);

}

