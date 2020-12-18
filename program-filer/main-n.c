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
#include <locale.h>

// Group Header Files
#include "prototypes.h"
#include "subloadfile.h"
#include "subpreproc.h"
#include "subverbatim.h"
#include "subcryptic.h"
#include "subtools.h"

int main(void) {
    // set local dependt information
    // LC_TYPE for character classification
    setlocale(LC_CTYPE, "en_GB");
    run_checks();
    return EXIT_SUCCESS;
}

void run_checks() {
    // set paths to files
    char *fp_one = "./test-files/lotr-org.txt";
    char *fp_two = "./test-files/lotr-plag.txt";

    //param[in] : File path to txt-file.
    //param[out]: Array with all text in txt.
    char *arr_txt1 = load_file(fp_one);
    char *arr_txt2 = load_file(fp_two);

    // Output seperator
    printf("-----------------------------------------------\n");

    //Preprocessing
    int sc_one = 0;
    int sc_two = 0;
    char **pre_arr = preprocessing(arr_txt1, &sc_one);
    char **pre_arr2 = preprocessing(arr_txt2, &sc_two);

    // free dynamic allocated file arrays
    free(arr_txt1);
    free(arr_txt2);

    // Create verbatim struct element
    int v_size = 0;
    int v_init_capacity = 1;
    int v_capacity = v_init_capacity;
    PlagMatch *vMatches = malloc(v_init_capacity * sizeof(PlagMatch));

    // Find verbatim elements
    int verbatim_count = nverbatim(vMatches, pre_arr, pre_arr2, sc_one, sc_two, v_size, v_capacity);

    // Test print - For Dynamic - Matches Static
    for (int i = 0; i < verbatim_count; i++) {
        printf("+ File 1 [line %2d, match]: '%s'\n", vMatches[i].line_num, vMatches[i].text);
        printf("+ File 2 [line %2d, match]: '%s'\n\n", vMatches[i].match_line_num, vMatches[i].match_text);
    }

    // Copy dynamic array elements to static array
    // PlagMatch static_vMatches[verbatim_count];
    // if (verbatim_count > 0) {
    //     for (int i = 0; i < verbatim_count; i++) {
    //         static_vMatches[i] = vMatches[i];
    //     }
    // } 

    // // Free allocated memory after copying to static array
    // free(vMatches);

    // Test print - For Static - Matches Dynamic 
    // printf("\n\nVerbatim test- should be (%d)\n", verbatim_count);
    // for (int i = 0; i < verbatim_count; i++) {
    //     printf("- File 1 [line %2d, match]: '%s'\n", static_vMatches[i].line_num, static_vMatches[i].text);
    //     printf("- File 2 [line %2d, match]: '%s'\n\n", static_vMatches[i].match_line_num, static_vMatches[i].match_text);
    // }

    // Create Crypt struct array
    int c_size = 0;
    int c_init_capacity = 1;
    int c_capacity = c_init_capacity;
    PlagMatch *cMatches = malloc(c_init_capacity * sizeof(PlagMatch));

    // Find cryptic elements
    int cryptic_count = cryptic_finder(cMatches, pre_arr, pre_arr2, sc_one, sc_two, c_size, c_capacity);

    // Copy dynamic array elements to static array
    // PlagMatch static_cMatches[cryptic_count];
    // if (cryptic_count > 0) {
    //     for (int i = 0; i < cryptic_count; i++) {
    //         static_cMatches[i] = cMatches[i];
    //     }
    //     free(cMatches);
    // } else {
    //     free(cMatches);
    // }

    // Test Print
    // printf("Cryptic test - should be (%d)\n", cryptic_count);
    // for (int i = 0; i < cryptic_count; i++) {
    //     printf("- File 1 [line %2d, match]: '%s'\n", static_cMatches[i].line_num, static_cMatches[i].text);
    //     printf("- File 2 [line %2d, match]: '%s'\n\n", static_cMatches[i].match_line_num, static_cMatches[i].match_text);
    // }

    // pass all results to evaluate results for user output
    eval_results(vMatches, verbatim_count, cMatches, cryptic_count, fp_one, fp_two);
    //eval_results(static_vMatches, verbatim_count, static_cMatches, cryptic_count, fp_one, fp_two);
    free(vMatches);
    free(cMatches);
}

//param[in] : text file of type .txt
//param[out]: char array (pointer) with text from file in array
char *load_file(char fp[]) {
    FILE *file = fopen(fp, "r");

    //param[in] : opened file in read mode
    //param[out]: returns if file is empty or not
    check_file(file);

    //param[in] : opened file in read mode
    //param[out]: number of char in file as size_t
    size_t size_of_arr = calc_sarray(file);
    char *txt_arr = malloc((size_of_arr+1) * sizeof(char));
    //param[in] : content of file, array, size of array
    //param[out]: array with content of file
    write_array(file, txt_arr, size_of_arr);


    if (txt_arr != NULL) {
        printf("File: %s load success\n", fp);
    } else {
        printf("File: %s load unsuccesfull\n", fp);
    }

    fclose(file);
    return txt_arr;
}

//param[in] : Array of PlagMatches, sentences of file one, sentences of file two, #sentences_one, #sentences_two, size of array, and capacity
//param[out]: Updated array of PlagMatches, size and capacity.
int cryptic_finder(PlagMatch cMatches[], char **sentences_one, char **sentences_two, int sc_one, int sc_two, int size, int capacity) {
    int k = 0;
    for (int i = 0; i < sc_one; i ++) {
        for (int j = 0; j < sc_two; j++) {
            if (check_string(sentences_one[i], sentences_two[j])) {

                // DEV INFO
                // printf("--------------------\n");
                // printf("FOUND -  suspected cryptic\n");
                // printf("--------------------\n");
                // printf("string 1: %s\n", sentences_one[i]);
                // printf("string 2: %s\n", sentences_two[j]);
                // printf("--------------------\n\n");
                // DEV INFO END

                int wc_one = count_words(sentences_one[i]); // get number of words in string 1
                int wc_two = count_words(sentences_two[j]); // get number of words in string 2

                // Create wordlist, split sentences into words and fill wordlist
                char **wordlist_one = malloc(wc_one * sizeof(char *));
                split_sentences(sentences_one[i], wordlist_one, wc_one);

                // Create wordlist, split sentences into words and fill wordlist
                char **wordlist_two = malloc(wc_two * sizeof(char *));
                split_sentences(sentences_two[j], wordlist_two, wc_two);
                
                // Compare words across
                for (int i = 0; i < wc_one; i++) {
                    if(check_string(wordlist_one[i], wordlist_two[i])) {
                        if (check_chars(wordlist_one, wc_one, wordlist_two)) {
                            printf("- found word at pos: %d\n", i+1);
                            plagAppend(cMatches, k, createPlagMatch(sentences_one[i], sentences_two[j],i+1,i+1,i+1,j+1), &size, &capacity);
                            k++;
                        }
                    }
                }
                free(wordlist_one); // free memory for wordlist_one
                free(wordlist_two); // free memory for wordlist_two
            }
        }
    }
}

//param[in] : array of PlagMatches, sizes of arrays and file paths
void eval_results(PlagMatch *vMatches, int vSize, PlagMatch *cMatches, int cSize, char fp_one[], char fp_two[])
{
    printf("\n-----------------------------------------------\n");
    printf("           RESULTS FROM EVALUATION:\n");
    printf("-----------------------------------------------\n");
    printf("FILE 1: %s\n", fp_one);
    printf("FILE 2: %s\n", fp_two);
    printf("-----------------------------------------------\n\n");

    printf("VERBATIM - (found %d matches):\n\n", vSize);
    for (int i = 0; i < vSize; i++)
    {
        printf("- File 1 [line %2d, match]: '%s'\n", vMatches[i].line_num, vMatches[i].text);
        printf("- File 2 [line %2d, match]: '%s'\n\n", vMatches[i].match_line_num, vMatches[i].match_text);
    }
    printf("\n");

    printf("CRYPTIC - (found %d matches):\n\n", cSize);
    for (int i = 0; i < cSize; i++)
    {
        printf("- File 1 [line %2d, word %2d]: %s\n", cMatches[i].line_num, cMatches[i].word_num, cMatches[i].text);
        printf("- File 2 [line %2d, word %2d]: %s\n\n", cMatches[i].match_line_num, cMatches[i].match_word_num, cMatches[i].match_text);
    }
}
