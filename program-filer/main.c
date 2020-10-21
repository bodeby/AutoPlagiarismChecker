/*
* Titel: Automatisk Plagiat Kontrol
* Software - 1. semester (09/10/2020 - 25/12/2020)
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
#include "levenshtein.h"

/* Levenshtein distance algorithm */
void ls_algo() {
    printf("ls");
    return;
}

void find_cryptic(char str_one[], char str_two[]) {
    print_str(str_one);
    print_str(str_two);
}

void open_file() {
    char fp_one[] = "";
    char fp_two[] = "";

    /* get file one */
    printf("File one:");
    scanf("%c", &fp_one);

    /* get file two */
    printf("\nFile two:");
    scanf("%c", &fp_two);
    
    printf("%c", fp_one);
    print_str(fp_one);
    print_str(fp_two);

    return;
}


/* Main Loop */
int main(void) {
    char navn[] = "Markus Frederik";
    char nytNavn[] = "Oskar Tommy";
    char pigerne[] = "Sara Alberte";

    find_cryptic(nytNavn, pigerne);
    
    open_file();

    return EXIT_SUCCESS;
}