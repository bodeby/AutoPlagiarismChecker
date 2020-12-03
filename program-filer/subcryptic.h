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

    printf("--------------------\n");
    printf("len_one: %.2f\n", len_one);
    printf("len_two: %.2f\n", len_two);
    printf("procent afvigelse %.2f%%\n", len_dif);
    printf("Threshold: %.2f%%\n", threshold);
    printf("--------------------\n");

    return true;
}

// split sentences to word list
void sentence_splliter(char input_str[], char **wordlist, int wc ) {
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

    // 
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
    
    free(temp_arr); // FREE ALLOCATED MEMORY AFTER USAGE

    for (int i = 0; i < wc; i++) {
        int word_length = strlen(word_array[i]); // find the length of the word
        wordlist[i] = malloc(word_length * sizeof(char)); // allocate space for the word
        strcpy(wordlist[i], word_array[i]); // copy words into the wordlist
    }
}

// Find Cryptic characters
bool check_crypt(char **wordlist_one, int wc_one, char **wordlist_two, int wc_two) {
    int c_val_min = 32;
    int c_val_max = 126;

    // UNCLEAR
    for (int i = 0; i < wc_one; i++) {
        for ( int j = 0; j < wc_two; j++) {
            int check_sum = editDist(wordlist_one[i], wordlist_two[j]);
            if( check_sum != 0) {
                //printf("Words: %s & %s dont match - checksum: %d\n", wordlist_one[i], wordlist_two[j], check_sum);
            }
        }
    }

    bool cryptic_flag = false;
    int len_count = sizeof(wordlist_one) / sizeof(char);
    printf("Len: %d\n", len_count);

    for (int i = 0; i < len_count; i++) {
        printf("Round: %d \n", i);
        for (int j = 0; j < (int) strlen(wordlist_one[i]); j++) {
            int ascii_one = wordlist_one[i];
            int ascii_two = wordlist_two[i];

            if (ascii_one < c_val_min || ascii_one > c_val_max) {
                cryptic_flag = true;
                printf("1C!%d \n", ascii_one);
            } else if (ascii_two < c_val_min || ascii_two > c_val_max) {
                cryptic_flag = true;
                printf("2C!%d \n", ascii_two);
            } else {
                printf("0N!%d \n", ascii_one);
                printf("0N!%d \n", ascii_two);
            }
            
        }
    }

    return cryptic_flag;
}
