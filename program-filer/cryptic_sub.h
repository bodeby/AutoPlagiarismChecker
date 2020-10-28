#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

/* Check if string is worth checking */
bool check_string(char str_one[], char str_two[]) {
    double len_one = strlen(str_one);
    double len_two = strlen(str_two);
    double threshold = 2.50;
    double len_dif = ((fabs(len_one - len_two) / ((len_one + len_two) / 2) ) * 100);

    printf("len_one: %.2f\n", len_one);
    printf("len_two: %.2f\n", len_two);
    printf("procent afvigelse %.2f%%\n", len_dif);
    printf("Threshold: %.2f%%\n", threshold);

    return true;
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
void count_words(char input_str[], int *word_count) {
    // Count spaces (Eg count the numbers of words)
    for (int i = 0; i < (int) strlen(input_str); i++) {
        // Check for spaces in string
        if ((int) input_str[i] == 32 || (int) input_str[i] == '\t') {
            *word_count += 1;
        }
    }
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

    // Init word_array arr[words counted][space needed for word of max 30 chars]
    int word_max = 30 * (int) sizeof(char);
    int word_pos = 0;
    char word_array[word_count][word_max];

    // Loop through string
    for (int i = 0; i < (int) strlen(input_str); i++) {
        int j = 0;
        // if character is not equal to space, append to array
        if ((int) input_str[i] != 32 || (int) input_str[i] != '\t') {
            append(arr, (int) i, input_str[i], &size, &capacity);
            j++;
            printf("Iteration: %d - content: %s\n", i, arr);
        }
        // if character is equal to space
        else {
            printf("Iteration: %d - content: cleared\n", i);
            strcpy(word_array[word_pos], arr[0]);    // Add Word to list
            word_pos += 1;                             // Set postion to next vacant spot
            j = 0;
        }
    }

    // Just for printing the char array.
    for (int i = 0; i < (int) strlen(arr); i++) {
        if (i+1 == (int) strlen(arr)) {
            printf("%c\n", arr[i]);
        } else {
            printf("%c", arr[i]);
        }
    }


    // Print out the words in word array 
    printf("\nWord in sentence: %i\n", word_count);
    for (int i = 0; i < word_count; i++) {
        printf("word_list[%d]: %s\n", i, word_array[i]);
    }

    free(arr);

}

