#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// Project Headers
#include "subtools.h"

/* Check if string is worth checking */
bool check_string(char str_one[], char str_two[]) {
    double len_one = strlen(str_one);
    double len_two = strlen(str_two);
    double threshold = 1.50;
    double len_dif = ((fabs(len_one - len_two) / ((len_one + len_two) / 2) ) * 100);

    printf("len_one: %.2f\n", len_one);
    printf("len_two: %.2f\n", len_two);
    printf("procent afvigelse %.2f%%\n", len_dif);
    printf("Threshold: %.2f%%\n", threshold);

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

void sentence_splliter(char input_str[], char **word_list, int wc ) {
    int size = 0;
    int init_capacity = 256;
    int capacity = init_capacity;
    char *temp_arr = malloc(init_capacity * sizeof(char));

    // Check if memory has been correctly allocated
    checkMem(temp_arr);

    // Init word_array arr[words counted][space needed for word of max 30 chars]
    int word_max = 30 * sizeof(char);
    int pos_word = 0;
    char word_array[wc][word_max];

    // Loop through string
    int j = 0;
    for (int i = 0; i <= (int) strlen(input_str); i++) {
        // if character is not equal to space, append to array
        if ((input_str[i] != 32 || input_str[i] == '\t') && i != (int) strlen(input_str)) {
            append(temp_arr, (int) j, input_str[i], &size, &capacity);
            j++;
        } else { // if character is equal to space
            strncpy(word_array[pos_word], temp_arr, j);  // Add Word to list
            word_array[pos_word][j] = '\0';         // Add \0 to word
            pos_word++;                             // Set postion to next vacant spot
            j = 0;
        }
    }
    
    // ======= TEST PRINT =======
    printf("\nWord in sentence: %i\n", wc);
    for (int i = 0; i < wc; i++) {
        printf("word_list[%d]: %s\n", i, word_array[i]);
    }
    // ======= TEST PRINT =======

    // ALLOCATE AND FILL INPUT PARAMATER **WORD_LIST
    j = 0;
    for (int i = 0; i < wc; i++) {
        int wlen = strlen(word_array[i])+1;
        int wlen_size = sizeof(char)* wlen;
        word_list[i] = malloc(sizeof(char)* wlen);
        printf("wl[%d]-size: %d", i, sizeof(word_list));
        printf(" len: %d, size: %d\n", wlen, wlen_size);
    }

    for (int i = 0; i < wc; i++) {
        int word_len = strlen(word_array[i]+1);
        for (int j = 0; j < word_len; j++) {
            word_list[i][j] = word_array[i][j];
        }
    }

    for (int i = 0; i < wc-1; i++) {
        //printf("%s\n", word_list[0][0]);
    }


    // FREE ALLOCATED MEMORY AFTER USAGE
    free(temp_arr);
}


// Split words in to 2-dim array of words.
void word_splitter(char input_str[]) {
    int size = 0;
    int init_capacity = 256;
    int capacity = init_capacity;
    char *arr = malloc(init_capacity * sizeof(char));

    // Check if memory has been correctly allocated
    checkMem(arr);

    // Count number of words in string
    int word_count = count_words(input_str);

    // Init word_array arr[words counted][space needed for word of max 30 chars]
    int word_max = 30 * (int) sizeof(char);
    int pos_word = 0;
    char word_array[word_count][word_max];

    // Loop through string
    int j = 0;
    for (int i = 0; i <= (int) strlen(input_str); i++) {
        
        // if character is not equal to space, append to array
        if ((input_str[i] != 32 || input_str[i] == '\t') && i != (int) strlen(input_str)) {
            append(arr, (int) j, input_str[i], &size, &capacity);
            j++;
            //printf("Iteration: %2d - content: %s\n", i, arr);
        }
        // if character is equal to space
        else {
            //printf("Iteration: %2d - content: cleared\n", i); 
            strncpy(word_array[pos_word], arr, j);  // Add Word to list
            word_array[pos_word][j] = '\0';         // Add \0 to word
            pos_word++;                             // Set postion to next vacant spot
            j = 0;
        }
    }
    // Print out the words in word array 
    /*
    printf("\nWord in sentence: %i\n", word_count);
    for (int i = 0; i < word_count; i++) {
        printf("word_list[%d]: %s\n", i, word_array[i]);
    }
    */

    /*
    for(int j = 0; j < word_count; j++) {
        for (int k = 0; k < word_count; k++) {
            int diff = editDist(word_array[j], word_array[k]);
            if (diff != 0) {
                printf("Difference: %s & %s = %d\n", word_array[j], word_array[k], diff);
            }
        }
    }
    */

    free(arr);
}

