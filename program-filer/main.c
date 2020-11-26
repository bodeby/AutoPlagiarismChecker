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

typedef struct PlagMatch
{
    char text[200];
    int line_num;
    int word_num;
    char match_text[200];
    int match_line_num;
    int match_word_num;
} PlagMatch;

void run_checks();
char *load_file(char fp[]);
void prep_array(char arr_one[]);
void find_cryptic(char str_one[], char str_two[]);
void find_synonym(char str_one[], char str_two[], char *synonym_res, bool *synonym_check);
char eval_results();

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

    //Preprocessing
    char **pre_arr = preprocessing(fp_one);
    free(pre_arr);

    //Verbatim
    verbatim(fp_one, fp_two);

    // List of Verbatim Match Struct elements
    PlagMatch vMathces[4] = {
        {"a magic ring that makes its wearer", 10, 5, "a magic ring that makes its wearer", 12, 4},
        {"ring is more than it appears", 5, 5, "ring is more than it appears", 5, 4},
        {"Enemy has learned of the Ring's whereabouts", 43, 5, "Enemy has learned of the Ring's whereabouts", 43, 4},
        {"a magic ring that makes its wearer", 10, 5, "a magic ring that makes its wearer", 12, 4},
    };

    PlagMatch sMathces[4] = {
        {"a magic ring that makes its wearer", 10, 5, "a magic ring that makes its wearer", 12, 4},
        {"ring is more than it appears", 5, 5, "ring is more than it appears", 5, 4},
        {"Enemy has learned of the Ring's whereabouts", 43, 5, "Enemy has learned of the Ring's whereabouts", 43, 4},
        {"a magic ring that makes its wearer", 10, 5, "a magic ring that makes its wearer", 12, 4},
    };

    PlagMatch cMathces[4] = {
        {"a magic ring that makes its wearer", 10, 5, "a magic ring that makes its wearer", 12, 4},
        {"ring is more than it appears", 5, 5, "ring is more than it appears", 5, 4},
        {"Enemy has learned of the Ring's whereabouts", 43, 5, "Enemy has learned of the Ring's whereabouts", 43, 4},
        {"a magic ring that makes its wearer", 10, 5, "a magic ring that makes its wearer", 12, 4},
    };

    printf("-------- STRUCT TEST -----------\n");
    for (int i = 0; i < 4; i++)
    {
        printf("- File 1: '%s' at line %d, word %d\n", vMathces[i].text, vMathces[i].line_num, vMathces[i].word_num);
        printf("- File 2: '%s' at line %d, word %d\n\n", vMathces[i].match_text, vMathces[i].match_line_num, vMathces[i].match_word_num);
    }
    printf("-------- STRUCT TEST END -----------\n\n");

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
    find_cryptic(test_str1, test_str2);

    //param[in] :
    //param[out]:
    /*char *synonym_res;
    bool *synonym_check = false;
    find_synonym(Arr_one_s2, Arr_two_s2, *synonym_res, *synonym_check);
    */

    /* [param:in]
   - vMatches : array of structs,
   - sMatches : array of structs,
   - cMatches : array of structs,
   */
    eval_results();
    free(arr_txt1);
    free(arr_txt2);
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

void find_cryptic(char str_one[], char str_two[])
{
    //int diff = editDist(str_one, str_two);
    //printf("edit distance: %i\n", diff);

    check_string(str_one, str_two);
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

char eval_results()
{
    printf("\n-----------------------------------------------\n");
    printf("-----------------------------------------------\n");
    printf("RESULTS FROM EVALUATION:\n");
    printf("-----------------------------------------------\n");
    printf("FILE: file_lotr.txt\n");
    printf("CHECK AGAINST: file2_lotr.txt, file3_lotr.txt\n");
    printf("-----------------------------------------------\n\n");

    printf("VERBATIM:\n");
    printf(" - File 1: 'When the eccentric hobbit Bilbo Baggins leaves his home in the Shire, \nhe gives his greatest treasure to his heir Frodo: a magic ring that makes its wearer invisible'\n");
    printf(" - File 2: 'When the eccentric hobbit Bilbo Baggins leaves his home in the Shire, \nhe gives his greatest treasure to his heir Frodo: a magic ring that makes its wearer invisible'\n");
    printf("\n");

    printf("PARAPHRASING: \n Not found\n\n");

    printf("CRYPTIC: \n Not found\n\n");
}
