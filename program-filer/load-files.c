#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

void load_files(char fp_one[], char fp_two[]) {
    
    /* Open Files */
    FILE *file_org = fopen(fp_one, "r");
    FILE *file_plag = fopen(fp_two, "r");

    /* Size of arrays calculated*/
    size_t start_pos1 = ftell(file_org);
    fseek(file_org, 0, SEEK_END);
    size_t size_of_arr1 = ftell(file_org);
    fseek(file_org, start_pos1, SEEK_SET);

    size_t start_pos2 = ftell(file_plag);
    fseek(file_plag, 0, SEEK_END);
    size_t size_of_arr2 = ftell(file_plag);
    fseek(file_plag, start_pos2, SEEK_SET);

    /*Arrays for text initialized*/
    char file_org_content[size_of_arr1];
    char file_plag_content[size_of_arr2];

    /* get file one */
    printf("--------- LOAD FILES ---------\n");
    printf("File one:  ");
    print_str(fp_one);

    /* get file two */
    printf("File two:  ");
    print_str(fp_two);

    /* Open Files */
    file_org = fopen(fp_one, "r");
    file_plag = fopen(fp_two, "r");

    /* Test if files are empty */
    if (file_org == NULL || file_plag == NULL) {
        printf("ERROR\n");
    } else {
        printf("File contents not NULL.\n");
    }

    /*Reading files*/
    for(int i = 0; i <= size_of_arr1; i++) {
        fscanf(file_org, "%1c", &file_org_content[i]);
    }

    /*for(int i = 0; i <= size_of_arr1; i++) {
        printf("%c", file_org_content[i]);
    }*/
    for(int j = 0; j <= size_of_arr2; j++) {
        fscanf(file_plag, "%1c", &file_plag_content[j]);
    }

    /* Close Files*/
    fclose(file_org);
    fclose(file_plag);
    return;
}

int main(void){
    char fp_one[] = "./test-files/lotr-org.txt";
    char fp_two[] = "./test-files/lotr-plag.txt";
    load_files(fp_one, fp_two);
    return 0;
}