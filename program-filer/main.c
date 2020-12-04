/*
* Titel: Automatisk Plagiat Kontrol
* Software - 1. semester (09/10/2020 - 18/12/2020)
* Aalborg universitet CPH
* 
* Gruppe: SW0001
* - Markus Hye-Knudsen, Oscar Maxwell
* - Sara Granquist, Tommy Grenaae
* - Frederik Bode Thorbensen
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
#include "subverbatim.h"
//#include "subpreproc.h"
#include "nverbatim.h"
#include "prototypes.h"

void run_checks();
char *load_file(char fp[]);
void prep_array(char arr_one[]);
void find_cryptic(char str_one[], char str_two[], PlagMatch *cMatches);
void find_synonym(char str_one[], char str_two[], char *synonym_res, bool *synonym_check);
void eval_results(PlagMatch *vMatches, int vmSize, PlagMatch *sMatches, int smSize, PlagMatch *cMatches, int cmSize);

// Main Function
int main(void)
{
    run_checks();
    return EXIT_SUCCESS;
}

void run_checks()
{
    char fp_one[] = "./test-files/lotr-org.txt";
    char fp_two[] = "./test-files/lotr-plag.txt";

    // List of Verbatim Match Struct elements
    PlagMatch vMatches[0];
    int vmSize = (int)(sizeof(vMatches) / sizeof(PlagMatch));

    // List of Parahrased Match Struct elements
    PlagMatch sMatches[0];
    int smSize = (int)(sizeof(sMatches) / sizeof(PlagMatch));

    // Lust of Cryptic Match Struct elements
    PlagMatch cMatches[1];
    int cmSize = (int)(sizeof(cMatches) / sizeof(PlagMatch));

    //param[in] : File path to txt-file.
    //param[out]: Array with all text in txt.
    char *arr_txt1 = load_file(fp_one);
    char *arr_txt2 = load_file(fp_two);

    //Preprocessing
    int sc_one = 0;
    int sc_two = 0;
    char **pre_arr = preprocessing(arr_txt1, &sc_one);
    char **pre_arr2 = preprocessing(arr_txt2, &sc_two);

    // Verbatim

    nverbatim(pre_arr, pre_arr2, sc_one, sc_two, vMatches);
    //verbatim(pre_arr, pre_arr2);

    //param[in] :
    //param[out]:
    /*
    find_verbatim(Arr_one_s1, Arr_two_s1, *verbatim_res, *verbatim_check);
    */

    // TEST ONLY
    char test_str1[] = "The quick brown fox jumps over the lazy dog";
    char test_str2[] = "The quick browп fox jumps over the lazy dog";

    printf("Test: %c v\n", NULL);

    //param[in] : the two strings to be compared
    //param[out]: match on non match;
    find_cryptic(test_str1, test_str2, cMatches);

    // param[in] : all the PlagMatch arrays and their sizes
    eval_results(vMatches, vmSize, sMatches, smSize, cMatches, cmSize);

    // free dynamic allocated file arrays
    free(arr_txt1);
    free(arr_txt2);

    free(pre_arr);
    free(pre_arr2);
}

//param[in] : text file of type .txt
//param[out]: char array (pointer) with text from file in array
char *load_file(char fp[])
{
    FILE *file = fopen(fp, "r");

    //param[in] : opened file in read mode
    //param[out]: returns if file is empty or not
    check_file(file);

    //param[in] : opened file in read mode
    //param[out]: number of char in file as size_t
    size_t size_of_arr = calc_sarray(file);
    char *txt_arr = malloc(size_of_arr * sizeof(char));

    //param[in] : content of file, array, size of array
    //param[out]: array with content of file
    write_array(file, txt_arr, size_of_arr);

    if (txt_arr != NULL)
    {
        printf("File: %s load success\n", fp);
    }
    else
    {
        printf("File: %s load unsuccesfull\n", fp);
    }

    fclose(file);
    return txt_arr;
}

/*
void find_verbatim(char Arr_one_s1, char Arr_two_s1) {
    printf("Find verbatim");
}
*/

void find_cryptic(char str_one[], char str_two[], PlagMatch *cMatches)
{
    check_string(str_one, str_two); // useless so far

    int wc_one = count_words(str_one); // get number of words in string 1
    int wc_two = count_words(str_two); // get number of words in string 2

    // Create wordlist, split sentences into words and fill wordlist
    char **wordlist_one = malloc(wc_one * sizeof(char *));
    sentence_splliter(str_one, wordlist_one, wc_one);

    // Create wordlist, split sentences into words and fill wordlist
    char **wordlist_two = malloc(wc_two * sizeof(char *));
    sentence_splliter(str_two, wordlist_two, wc_two);

    // checking for cryptic characters
    bool result = check_crypt(wordlist_one, wc_one, wordlist_two, wc_two);
    printf("Cryptic check result: %s \n", result ? "true" : "false");

    if (result)
    {
        PlagMatch found_match;
        strcpy(found_match.text, str_one);
        found_match.word_num = 0;
        found_match.line_num = 0;
        strcpy(found_match.match_text, str_two);
        found_match.match_word_num = 0;
        found_match.match_line_num = 0;

        cMatches[0] = found_match;
    }

    free(wordlist_one);
    free(wordlist_two);
}

/* 
void find_synonym(char str_one[], char str_two[], char *synonym_res, bool *synonym_check) {
    *synonym_check = true;
    *synonym_res = "test";

    printf("Synonym");
}
*/

void eval_results(PlagMatch *vMatches, int vmSize, PlagMatch *sMatches, int smSize, PlagMatch *cMatches, int cmSize)
{

    printf("\n-----------------------------------------------\n");
    printf("-----------------------------------------------\n");
    printf("RESULTS FROM EVALUATION:\n");
    printf("-----------------------------------------------\n");
    //printf("FILE: %s\n", information->file_path_one);
    //printf("CHECKED AGAINST: %s\n", information->file_path_two);
    printf("FILE: hej\n");
    printf("CHECKED AGAINST: hej2\n");
    printf("-----------------------------------------------\n\n");

    printf("VERBATIM - (found %d matches):\n\n", vmSize);
    for (int i = 0; i < vmSize; i++)
    {
        printf("- File 1 [line %2d, word %2d]: '%s'\n", vMatches[i].line_num, vMatches[i].word_num, vMatches[i].text);
        printf("- File 2 [line %2d, word %2d]: '%s'\n\n", vMatches[i].match_line_num, vMatches[i].match_word_num, vMatches[i].match_text);
    }
    printf("\n");

    printf("PARAPHRASING (found %d matches):\n\n", smSize);
    for (int i = 0; i < smSize; i++)
    {
        printf("- File 1 [line %2d, word %2d]: '%s'\n", sMatches[i].line_num, sMatches[i].word_num, sMatches[i].text);
        printf("- File 2 [line %2d, word %2d]: '%s'\n\n", sMatches[i].match_line_num, sMatches[i].match_word_num, sMatches[i].match_text);
    }
    printf("\n");

    printf("CRYPTIC (found %d matches):\n\n", cmSize);
    for (int i = 0; i < cmSize; i++)
    {
        printf("- File 1 [line %2d, word %2d]: %s\n", cMatches[i].line_num, cMatches[i].word_num, cMatches[i].text);
        printf("- File 2 [line %2d, word %2d]: %s\n\n", cMatches[i].match_line_num, cMatches[i].match_word_num, cMatches[i].match_text);
    }
}
