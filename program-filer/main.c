/*
* Titel: Automatisk Plagiat Kontrol
* Software - 1. semester (09/10/2020 - 18/12/2020)
* Aalborg universitet CPH
* 
* Gruppe: SW0001
* - Markus Hye Knudsen, Oscar Maxwell
* - Sara Granquist, Tommy Grenaae
* - Alberte Østergaard Andesen, Frederik Bode Thorbensen
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

    while (!feof(file_org)) {
        fgets(file_org_content, 150, file_org);
        /*puts(file_org_content);*/
    }

    while (!feof(file_plag)) {
        fgets(file_plag_content, 150, file_plag);
        /*puts(file_plag_content);*/
    }

    /* Close Files*/
    fclose(file_org);
    fclose(file_plag);

    printf("\nFILE ONE: \n");
    print_str(file_org_content);

    printf("\nFILE TWO: \n");
    print_str(file_plag_content);

    printf("--------- END OPEN FILE ---------\n");

    return;
}

/* Main Loop */
int main(void) {
    /* Mit navn er Johnny og min fars er det samme */
    char str_test1[] = ".Mit navn er Johnny og min fars er det samme.";
    char str_test2[] = ".Mit navn er Johппy og min fars er det samme.";
    find_cryptic(str_test1, str_test2);

    return EXIT_SUCCESS;
}
