
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **preprocessing(char *ori_file, int *sc)
{
    int count = 0;
    int count2 = 0;
    int count_holder = 0;
    int sentence_count = 0;
    int character_count = 0;
    int size_of_string[100];
    int max_size = 0;
    int size_of_ori_file = strlen(ori_file);

    //count chars until end of sentence
    for (int i = 0; i < size_of_ori_file; i++) {
        character_count++; 

        //If end of sentence
        if (ori_file[count] == '\n') {
            //increment nunmber of sentences found
            sentence_count++;

            //store number of chars in int array and increment                         
            size_of_string[count2] = character_count +1;
            count2++;
<<<<<<< Updated upstream

            //update total number of chars read 
            total_character = total_character + character_count;
            
            //Nulstiller karakterer, da der startes en ny sætning
            character_count = 0;
=======
            character_count = 0; //Nulstiller karakterer, da der startes en ny sætning
>>>>>>> Stashed changes
        }
        //move on to next char in file
        count++;
    }
<<<<<<< Updated upstream


    //
    size_of_string[count2] = size_of_ori_file - total_character;
    sentence_count++;
=======
>>>>>>> Stashed changes

    //size of array of sentences memory allocated 
    char **sentence_arr = malloc((sentence_count) * sizeof(char *));
    if (sentence_arr == 0) {
        printf("Failure occured\n");
        exit(EXIT_SUCCESS);
    }

    //store number of sentences for later use
    *sc = sentence_count;

    //allocate memory for each sentence with size stored in size_of_string array
    for (int i = 0; i < sentence_count; i++) {
        sentence_arr[i] = (char *) malloc(size_of_string[i] * sizeof(char));
        if (sentence_arr == 0) {
            printf("Failure occured\n");
            exit(EXIT_SUCCESS);
        }
    }

     
    /* for (int i = 0; i < sentence_count; i++) {
        if (max_size < size_of_string[i]) {
            max_size = size_of_string[i];
        }
    } */

    // Nulstiller sentence count
    sentence_count = 0;
    count = 0;
    count_holder = 0;

    //char temp_arr[max_size];
    for (int i = 0; i < size_of_ori_file; i++) {
        
        printf("%c", ori_file[count]);

        // if current char is equal to newline
        if (ori_file[count] == '\n') {
            // replace \n with \0 at the end of each line.
            ori_file[count] = '\0';
            //count++; - spørg sara

            // Count er placeringen af den sidste karakter og count_holder er placeringen af den første
            for (int j = 0; j < (count - count_holder); j++) { 
                //printf("S: %d  j: %d  B: %c\n", sentence_count, j, ori_file[j + count_holder]);
                //Bliver placeret i et nyt array
                sentence_arr[sentence_count][j] = ori_file[j + count_holder];
            }
            sentence_count++;   
            count_holder = count;
        }
        count++;
    }
<<<<<<< Updated upstream

    // 
    // for (int i = 0; i < (size_of_ori_file - count_holder); i++) {
    //     sentence_arr[sentence_count][i] = ori_file[i + count_holder];
    // }
=======
>>>>>>> Stashed changes

    return sentence_arr;
}
