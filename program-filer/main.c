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
}

void open_files() {
    char fp_one[] = "./test-files/lotr-org.txt";
    char fp_two[] = "./test-files/lotr-plag.txt";
    FILE *file_org;
    FILE *file_plag;
    char file_org_content[150];
    char file_plag_content[150];

    /* get file one */
    printf("--------- OPEN FILE ---------\n");
    printf("File one:  ");
    print_str(fp_one);

    /* get file two */
    printf("File two:  ");
    print_str(fp_two);

    /* Open Files */
    file_org = fopen(fp_one, "r");
    file_plag = fopen(fp_two, "r");

    /* Test if Files are empty */
    if (file_org == NULL || file_plag == NULL) {
        printf("ERROR\n");
    } else {
        printf("File contents not NULL.\n");
    }

    printf("\nFILE ONE: \n");
    while (fgets(file_org_content, 150, file_org) != NULL) {
        puts(file_org_content);
        
    } 
    printf("\nFILE TWO: \n");
    while (fgets(file_plag_content, 150, file_plag) != NULL) {
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
    open_files();
    char navn[] = "Markus Frederik";
    char nytNavn[] = "Oscar Tommy";
    char pigerne[] = "Sara Alberte";

    find_cryptic(nytNavn, pigerne);
    
    open_files();

    return EXIT_SUCCESS;
}
