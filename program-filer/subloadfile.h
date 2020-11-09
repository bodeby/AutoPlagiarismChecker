#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subtools.h"

// Size of array calculated
size_t size_of_array_calculated(FILE *text){
    size_t start_pos = ftell(text);
    fseek(text, 0, SEEK_END);
    size_t size_of_arr = ftell(text);
    fseek(text, start_pos, SEEK_SET);
    return size_of_arr;
}

void write_array(FILE *text, char arr_txt[], size_t size_of_arr){
    for(int i = 0; i <= (int) size_of_arr; i++) {
        fscanf(text, "%c", &arr_txt[i]);
    }

    /*for(int i = 0; i <= (int) size_of_arr; i++) {
        printf("%c", arr_txt[i]); 
    } */
    return;
}

// Open Files
int check_file(FILE *file){

    // Test if files are empty 
    if (file == NULL) {
        fprintf(stderr, "File Empty\n");
        return EXIT_FAILURE;
    } else{
        return EXIT_SUCCESS;
    }
}
