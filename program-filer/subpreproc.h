
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **preprocessing(char *ori_file)
{

    int count = 0;
    int sentence_count = 0;
    int count_holder = 0;
    int size_of_string[100];
    int character_count = 0;
    int count2 = 0;

    while (ori_file[count] != '\0')
    {
        character_count++;

        if (ori_file[count] == '\n')
        {
            sentence_count++;
            size_of_string[count2] = character_count;
            count2++;
            character_count = 0;
        }
        count++;
    }
    char **sentence_arr = (char **)malloc((sentence_count) * sizeof(char *));

    if (sentence_arr == 0)
    {
        printf("Failure accured");
        exit(EXIT_SUCCESS);
    }
    for (int i = 0; i < sentence_count; i++)
    {
        sentence_arr[i] = (char *)malloc(size_of_string[i] * sizeof(char));
        if (sentence_arr == 0)
        {
            printf("Failure accured");
            exit(EXIT_SUCCESS);
        }
    }

    sentence_count = 0;
    count = 0;
    count_holder = 0;
    while (ori_file[count] != '\0')
    {
        if (ori_file[count] == '\n')
        {
            ori_file[count] = ' ';
            count++;
            for (int i = 0; i < (count - count_holder); i++)
            {
                //printf("S: %d  j: %d  B: %c\n", sentence_count, j, ori_file[j + count_holder]);
                sentence_arr[sentence_count][i] = ori_file[i + count_holder];
            }
            sentence_count++;
            count_holder = count;
        }
        count++;
    }

    return sentence_arr;
}
