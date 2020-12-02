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

    for (int i = 0; i < wc_one; i++) {
        for ( int j = 0; j < wc_two; j++) {
            int check_sum = editDist(wordlist_one[i], wordlist_two[j]);
            if( check_sum != 0) {
                printf("Words: %s & %s dont match - checksum: %d\n", wordlist_one[i], wordlist_two[j], check_sum);
            }
        }
    }

    for (int i = 0; i < strlen(wordlist_two[2]); i++) {
        int ascii_val = wordlist_two[2][i];
        if (ascii_val < c_val_min || ascii_val > c_val_max){
            printf("Cryptic: Found\n");
            return true;
        } else {
            printf("Cyptic Not Found\n");
            return false;
        }
    }


}
