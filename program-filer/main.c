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
//#include "subpreproc.h"

void run_checks();
char *load_file(char fp[]);
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
    char *arr_txt1 = load_file(fp_one);
    char *arr_txt2 = load_file(fp_two);

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
    char cryptic_res[256];
    bool cryptic_check = false;
    find_cryptic(test_str1, test_str2, &cryptic_res, &cryptic_check);
    //find_cryptic(Arr_one_s2, Arr_two_s2, *cryptic_res, *cryptic_check);

    //param[in] :
    //param[out]:
    /*char *synonym_res;
    bool *synonym_check = false;
    find_synonym(Arr_one_s2, Arr_two_s2, *synonym_res, *synonym_check);
    */

   eval_results(cryptic_check);
   free(arr_txt1);
   free(arr_txt2);
}


char *load_file(char fp[]) {
    FILE *file = fopen(fp, "r");

    //param[in] : opened file in read mode
    check_file(file);

    //param[in] : opened file in read mode
    //param[out]: number of char in file as size_t    
    size_t size_of_arr = size_of_array_calculated(file);
    char *txt_arr = malloc(size_of_arr * sizeof(char));
 
    //param[in] : content of file, array, size of array
    //param[out]: array with content of file
    write_array(file, txt_arr, size_of_arr);

    fclose(file);

    if (txt_arr != NULL) {
        printf("File: %s load success\n", fp);
    } else {
        printf("File: %s load unsuccesfull\n", fp);
    }
    return txt_arr;
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
    *cryptic_res = "l";
    //int diff = editDist(str_one, str_two);
    //printf("edit distance: %i\n", diff);

    check_string(str_one, str_two, &cryptic_check);
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


char eval_results(cryptic_check) {
    printf("Evaluate Results\n");

    if (cryptic_check == false) {
        printf("Evidence of cryptic substituion not found\n");
    } else {
        printf("Evidence of cryptic substituion not found\n");
    }
    return EXIT_SUCCESS;
}
