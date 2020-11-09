#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subtools.h"

// Test if file is empty
int check_file(FILE *file){
    if (file == NULL) {
        fprintf(stderr, "File Empty\n");
        return EXIT_FAILURE;
    } else{
        return EXIT_SUCCESS;
    }
}
//Calculates size of array needed
//param[in] : textfile
//param[out]: size of array needed, of type size_t
size_t calc_sarray(FILE *text){
    size_t start_pos = ftell(text);
    fseek(text, 0, SEEK_END);
    size_t size_of_arr = ftell(text);
    fseek(text, start_pos, SEEK_SET);
    return size_of_arr;
}

//Writes text from file into array
//param[in] : textfile, array and size of array
void write_array(FILE *text, char arr_txt[], size_t size_of_arr){
    for(int i = 0; i <= (int) size_of_arr; i++) {
        fscanf(text, "%c", &arr_txt[i]);
    }
    return;
}

