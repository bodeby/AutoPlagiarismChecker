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

// System Headers 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Gruppens Headers 
#include "subtools.h"
#include "subcryptic.h"
#include "subloadfile.h"
#include "subpreproc.h"

void run_checks();
char load_file(char fp_one[], char fp_two[]);
void prep_array(char arr_one[]);
void find_cryptic(char str_one[], char str_two[],char *cryptic_res, bool *cryptic_check);
void find_synonym(char str_one[], char str_two[],char *synonym_res, bool *synonym_check);
char eval_results();


// Main Function  
int main(void) {
    run_checks();
    return EXIT_SUCCESS;
}


void run_checks() {
    char fp_one[] = "./test-files/lotr-org.txt";
    char fp_two[] = "./test-files/lotr-plag.txt";

    //param[in] : File path to txt-file.
    //param[out]: Array with all text in txt.
    char Arr_one_s1[256];
    char Arr_two_s1[256];
    *Arr_one_s1 = load_file(fp_one, fp_two);
    *Arr_two_s1 = load_file(fp_two, fp_two);

    //param[in] : Array with all text in txt.
    //param[out]: 2-dim Array of all sentences.
    /*  
    char Arr_one_s2[256];
    char Arr_two_s2[256];
    *Arr_one_s2 = prep_array(Arr_one_s1);
    *Arr_two_s2 = prep_array(Arr_two_s1);
    prep_array(Arr_one_s1);
    prep_array(Arr_two_s1);
    */


    //param[in] :
    //param[out]:
    /*
    char *verbatim_res;
    bool *verbatim_check = false;
    find_verbatim(Arr_one_s1, Arr_two_s1, *verbatim_res, *verbatim_check);
    */

    // TEST ONLY
    char test_str1[] = "The quick brown fox jumps over the lazy dog";
    char test_str2[] = "The quick browп fox jumps over the lazy dog";

    //param[in] :
    //param[out]:
    char *cryptic_res[256];
    bool *cryptic_check = false;
    find_cryptic(test_str1, test_str2, *cryptic_res, cryptic_check);
    //find_cryptic(Arr_one_s2, Arr_two_s2, *cryptic_res, *cryptic_check);

    //param[in] :
    //param[out]:
    /*char *synonym_res;
    bool *synonym_check = false;
    find_synonym(Arr_one_s2, Arr_two_s2, *synonym_res, *synonym_check);
    */
}


char load_file(char fp_one[], char fp_two[]) {
    
    // Open Files 
    FILE *file_org = fopen(fp_one, "r");
    FILE *file_plag = fopen(fp_two, "r");

    // Size of arrays calculated
    size_t start_pos1 = ftell(file_org);
    fseek(file_org, 0, SEEK_END);
    size_t size_of_arr1 = ftell(file_org);
    fseek(file_org, start_pos1, SEEK_SET);

    size_t start_pos2 = ftell(file_plag);
    fseek(file_plag, 0, SEEK_END);
    size_t size_of_arr2 = ftell(file_plag);
    fseek(file_plag, start_pos2, SEEK_SET);

    //Array of arrays initialized
    char *file_org_content[size_of_arr1][size_of_arr1];
    char *file_plag_content[size_of_arr2][size_of_arr2];

    // get file one 
    printf("--------- LOAD FILES ---------\n");
    printf("File one:  ");
    print_str(fp_one);

    // get file two 
    printf("File two:  ");
    print_str(fp_two);

    // Open Files 
    file_org = fopen(fp_one, "r");
    file_plag = fopen(fp_two, "r");

    // Test if files are empty 
    if (file_org == NULL || file_plag == NULL) {
        printf("ERROR\n");
    } else {
        printf("File contents not NULL.\n");
    }
    //Reading files
    printf("\nFILE ONE: \n");
    for(int i = 0; i <= (int) size_of_arr1; i++) {
        fscanf(file_org, "%1c", *file_org_content[i]);
    }

    for(int j = 0; j <= (int) size_of_arr2; j++) {
        fscanf(file_plag, "%1c", *file_plag_content[j]);
    }

    // Close Files
    fclose(file_org);
    fclose(file_plag);
    return 'c';
}


/*
void prep_array(char arr_one[]) {
    printf("test");
}
*/


/*
void find_verbatim(char Arr_one_s1, char Arr_two_s1, char *verbatim_res[], bool *verbatim_check) {
    *verbatim_check = true;
    *verbatim_res[4] = "test";

    print_str(Arr_one_s1);
    print_str(Arr_two_s1);
    printf("Find verbatim");
}
*/


void find_cryptic(char str_one[], char str_two[], char *cryptic_res, bool *cryptic_check) {
    *cryptic_check = true;
    *cryptic_res = memcpy(cryptic_res,"test",sizeof("test"));;
    int diff = editDist(str_one, str_two);
    printf("edit distance: %i\n", diff);

    // cryptic_sub header 
    word_splitter(str_one);
    word_splitter(str_two);
}


/* 
void find_synonym(char str_one[], char str_two[], char *synonym_res, bool *synonym_check) {
    *synonym_check = true;
    *synonym_res = "test";

    print_str(str_one);
    print_str(str_two);
    printf("Synonym");
}
*/


char eval_results() {
    printf("Evaluate Results");
    return EXIT_SUCCESS;
}
