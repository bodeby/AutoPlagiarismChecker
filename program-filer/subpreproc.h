
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **preprocessing(char *ori_file, int *sc)
{
    int count = 0;
    int count2 = 0;
    int sentence_count = 0;
    int character_count = 0;
    int size_of_string[100];
    int size_of_ori_file = strlen(ori_file);

    //count chars until end of sentence
    for (int i = 0; i < size_of_ori_file; i++)
    {
        character_count++;

        //If end of sentence
        if (ori_file[count] == '.')
        {
            //increment number of sentences found
            sentence_count++;

            //store number of chars in int array and increment
            size_of_string[count2] = character_count + 1;
            count2++;
            character_count = 0; //Nulstiller karakterer, da der startes en ny sætning
        }
        //move on to next char in file
        count++;
    }

    //store number of sentences for later use
    *sc = sentence_count + 1;

    //size of array of sentences memory allocated
    char **sentence_arr = (char **) malloc((sentence_count+1) * sizeof(char *));
    if (sentence_arr == 0)
    {
        printf("Failure occured\n");
        exit(EXIT_SUCCESS);
    }

    //allocate memory for each sentence with size stored in size_of_string array
    for (int i = 0; i < sentence_count; i++)
    {
        sentence_arr[i] = (char *) malloc(size_of_string[i] * sizeof(char));
        if (sentence_arr == 0)
        {
            printf("Failure occured\n");
            exit(EXIT_SUCCESS);
        }
    }

    // Nulstiller sentence count
    sentence_count = 0;
    char temp_arr[300];
    int j = 0;

    for (int i = 0; i < size_of_ori_file; i++)
    {
        temp_arr[j++] = ori_file[i];

        // if current char is equal to .
        if (ori_file[i] == '.') {
            // replace . with \0 at the end of each line.
            temp_arr[j] = '\0';
            strncpy(sentence_arr[sentence_count++],temp_arr, j);
            j=0;
            i++;
        } else {
            //printf("%c", ori_file[i]);
        }
    }
    
    // for (int i = 0; i < sentence_count; i++) {
    //     printf("\nInner %d: %s\n", i, sentence_arr[i]);
    // }
    
    return sentence_arr;
}
