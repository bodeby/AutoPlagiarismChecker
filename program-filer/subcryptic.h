#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define C_VAL_MIN 32
#define C_VAL_MAX 126


// Project Headers
#include "subtools.h"

/* Check if string is worth checking */
bool check_string(char str_one[], char str_two[]) {
    double len_one = strlen(str_one);
    double len_two = strlen(str_two);
    double len_dif = ((fabs(len_one - len_two) / ((len_one + len_two) / 2) ) * 100);
    double len_int_diff = fabs(len_one - len_two) / 2;
    int levenDist = editDist(str_one, str_two);

    printf("--------------------\n");
    printf("procent afvigelse %.2f%%\n", len_dif);
    printf("Levenstein: %d \n", levenDist);
    printf("--------------------\n");

    
    if ( levenDist% 2 == 0 && len_int_diff == levenDist){
        return true;
    }
    
    return false;
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
    int len_count = sizeof(wordlist_one) / sizeof(char);
    int cryptic_pos_one[len_count];
    int cryptic_pos_two[len_count];
    bool cryptic_flag = false;

    for (int i = 0; i < wc_one; i++) {
        // Wordlist one check
        for (int j = 0; j < (int) strlen(wordlist_one[i]); j++) {
            int ascii_one = wordlist_one[i][j];
            if (ascii_one < C_VAL_MIN || ascii_one > C_VAL_MAX) {
                cryptic_flag = true;
                cryptic_pos_one[i] = 1;
            } else {
                cryptic_pos_one[i] = 0;
            }
            
        }

        // Wordlist two check
        for (int k = 0; k < (int) strlen(wordlist_two[i]); k++) {
            int ascii_two = wordlist_two[i][k];
            if (ascii_two < C_VAL_MIN|| ascii_two > C_VAL_MAX) {
                cryptic_flag = true;
                cryptic_pos_two[i] = 1;                
            } else {
                cryptic_pos_two[i] = 0;
            }
        }
    }

    for (int t = 0; t < (int) (sizeof(cryptic_pos_one) / sizeof(int)); t++) {
        printf("CP1: %d\n", cryptic_pos_one[t]);
    }

    for (int q = 0; q < (int) (sizeof(cryptic_pos_two) / sizeof(int)); q++) {
        printf("CP2: %d\n", cryptic_pos_two[q]);
    }

    return cryptic_flag;
}
