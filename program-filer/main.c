/*
* Titel: Automatisk Plagiat Kontrol
* Software - 1. semester (09/10/2020 - 18/12/2020)
* Aalborg universitet CPH
* 
* Gruppe: SW0001
* - Markus Hye-Knudsen, Oscar Maxwell
* - Sara Granquist, Tommy Grenaae
* - Alberte Østergaard Andersen, Frederik Bode Thorbensen
*/

/* System Headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Gruppens Headers */
#include "helpers.h"
#include "levenshtein.h" /* external */

void find_cryptic(char str_one[], char str_two[]) {
    print_str(str_one);
    print_str(str_two);

    int diff = editDist(str_one, str_two);
    printf("edit distance: %i\n", diff);

    int c_val_min = 33;
    int c_val_max = 126;

    int ch = 'A';
    printf("Char value: %i\n", ch);
}

void load_files() {
    char fp_one[] = "./test-files/lotr-org.txt";
    char fp_two[] = "./test-files/lotr-plag.txt";
    

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

    char file_org_content[size_of_arr1];
    char file_plag_content[size_of_arr2];

    /* get file one */
    printf("--------- OPEN FILE ---------\n");
    printf("File one:  ");
    print_str(fp_one);
   
    /* get file two */
    printf("File two:  ");
    print_str(fp_two);

    /* Test if Files are empty */
    if (file_org == NULL || file_plag == NULL) {
        printf("ERROR\n");
    } else {
        printf("File contents not NULL.\n");
    }

    printf("\nFILE ONE: \n");
    while (fgets(file_org_content, size_of_arr1, file_org) != NULL) {
        puts(file_org_content);
        
    } 
    printf("\nFILE TWO: \n");
    while (fgets(file_plag_content, size_of_arr2, file_plag) != NULL) {
        puts(file_plag_content);
    
    }

    /* Close Files*/
    fclose(file_org);
    fclose(file_plag);
    printf("--------- END OPEN FILE ---------\n");

    return;
}
/* Main Loop */
int main(void) {
    int dist = editDist("sitten", "kitten");
    printf("Edit distance: %i\n", dist);
    char navn[] = "Markus Frederik";
    char nytNavn[] = "Oscar Tommy";
    char pigerne[] = "Sara Alberte";

    find_cryptic(nytNavn, pigerne);
    
    load_files();

    return EXIT_SUCCESS;
}
