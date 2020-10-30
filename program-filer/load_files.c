#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subloadfile.h"
//#include "subtools.h"

char load_file(char fp_one[]) {
    FILE *file_org = fopen(fp_one, "r");

    //param[in] : opened file in read mode
    check_file(file_org);

    //param[in] : opened file in read mode
    //param[out]: number of char in file as size_t    
    size_t size_of_arr1 = size_of_arrays_calculated(file_org);
    char file_org_content[size_of_arr1];
 
    //param[in] : content of file, array, size of array
    //param[out]: array with content of file
    write_array(file_org, file_org_content, size_of_arr1);

    fclose(file_org);

    if (file_org_content != NULL) {
        printf("File: %s load success\n", fp_one);
    } else {
        printf("File: %s load unsuccesfull\n", fp_one);
    }
    return;
}

void run_checks() {
    char fp_one[] = "./test-files/lotr-org.txt";
    char fp_two[] = "./test-files/lotr-plag.txt";
    //char test_str1[] = "The quick brown fox jumps over the lazy dog";
    //char test_str2[] = "The quick browп fox jumps over the lazy dog";
    //find_cryptic(test_str1, test_str2);
    load_file(fp_one);
    load_file(fp_two);
}

// Main Function  
int main(void) {
    run_checks();

    return EXIT_SUCCESS;
}