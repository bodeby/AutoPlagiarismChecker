/* System Headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "subtools.h"
#include "prototypes.h"
#include "subverbatim.h"
#include "subcryptic.h"
#include "subloadfile.h"

int main(void) {
    // set paths to files
    char *fp_one = "./test-files/lotr-org.txt";
    char *fp_two = "./test-files/lotr-plag.txt";

    //param[in] : File path to txt-file.
    //param[out]: Array with all text in txt.
    char *arr_txt1 = load_file(fp_one);
    char *arr_txt2 = load_file(fp_two);

    //test to show that load_file works
    printf("\n\n-----------First file string:-----------\n%s\n\n", arr_txt1);
    printf("\n-----------Second file string:-----------\n%s\n\n", arr_txt2);

    // TESTSET 1:
    int sc_one = 5;
    char testset_one[5][300] = {
        "When the eccentric hobbit Bilbo Baggins leaves his home in the Shire, he gives his greatest treasure to his heir Frodo: a magic ring that makes its wearer invisible.",
        "Because of the difficulty Bilbo has in giving the ring away, his friend the wizard Gandalf the Grey suspects that the ring is more than it appears.",
        "Gandalf tells Frodo that the Ring must be destroyed to defeat Sauron's evil, but he also warns him that the Enemy has learned of the Ring's whereabouts from the creature Gollum and will seek to find it and kill its bearer.",
        "Despite the danger and hopelessness of the quest, Frodo accepts the burden and resolves to take the Ring to the safety of the elven stronghold of Rivendell.",
        "Some years later, Gandalf reveals to Frodo that the ring is in fact the One Ring, forged by Sauron the Dark Lord thousands of years before to enable him to dominate and enslave all of Middle-earth."
    };

    int sc_two = 5;
    char testset_two[5][300] = {
        "When the eccentric hobbit Bilbo Baggins leaves his home in the Shire, he gives his greatest treasure to his heir Frodo: a staff who gives the wearer invisible.",
        "Because of the difficulty Bilbo has in giving the ring away, his friend the wizard Gandalf the Grey suspects that the ring is more than it appears.",
        "Gandalf tells Frodo that the Ring must be destroyed to defeat Sauron's evil, but he also warns him that the Enemy has learned of the Ring's whereabouts from the creature Gollum and will seek to find it and Кill its bearer.",
        "Some years later, Gandalf reveals to Frodo that the ring is in fact the One Ring, forged by Sauron the Dark Lord thousands of years before to enable him to dominate and enslave all of Мiddle-earth.",
        "Despite the danger and hopelessness of the quest, Frodo accepts the burden and resolves to take the Ring to the safety of the elven stronghold of Rivendell."
    };

    // skal slettes !
    char test_str1[] = "Some years later, Gandalf reveals to Frodo that the ring is in fact the One Ring, forged by Sauron the Dark Lord thousands of years before to enable him to dominate and enslave all of Middle-earth.";
    char test_str2[] = "Some years later, Gaпdalf reveals to Frodo that the ring is in fact the One Ring, forged by Sauron the Dark Lord thousands of years before to enable him to dominate and enslave all of Мiddle-earth.";

    // VERBATIM START
    int vSize = 0;
    int vCapacity_init = 30;
    int vCapacity = vCapacity_init;
    PlagMatch *vMatches = malloc(vCapacity_init * sizeof(PlagMatch));

    // Find verbatim elements
    //int verbatim_count = nverbatim(vMatches, testset_one, testset_two, sc_one, sc_two, vSize, vCapacity);
    int verbatim_count = 0;
    int vCount = 0;
    for (int i = 0; i < sc_one; i++) {
        for (int j = 0; j < sc_two; j++) {
            int line_current_one = i;
            int line_current_two = j;

            int diff = editDist(testset_one[i], testset_two[j]);
            if (diff == 0) {
                strcpy(vMatches[vCount].text, testset_one[i]);
                strcpy(vMatches[vCount].match_text, testset_two[j]);
                vMatches[vCount].word_num = i+1;
                vMatches[vCount].match_word_num = i+1;
                vMatches[vCount].line_num = line_current_one;
                vMatches[vCount].match_line_num = line_current_two;
                vCount++;
            }

            verbatim_count = vCount;
        }
    }


    // CRYPTIC DIRECT
    int cSize = 0;
    int cCapacity_init = 30;
    int cCapacity = cCapacity_init;
    PlagMatch *cMatches = malloc(cCapacity_init * sizeof(PlagMatch));

    // counters
    int cryptic_count = 0;
    int cCount = 0;

    for (int i = 0; i < sc_one; i ++) {
        for (int j = 0; j < sc_two; j++) {
            if (check_string(testset_one[i], testset_two[j])) {
                int wc_one = count_words(testset_one[i]); // get number of words in string 1
                int wc_two = count_words(testset_two[j]); // get number of words in string 2

                // Create wordlist, split sentences into words and fill wordlist
                char **wordlist_one = malloc(wc_one * sizeof(char *));
                split_sentences(testset_one[i], wordlist_one, wc_one);
                //printf("Ord 1: %s\n", wordlist_one[i]); // test output

                // Create wordlist, split sentences into words and fill wordlist
                char **wordlist_two = malloc(wc_two * sizeof(char *));
                split_sentences(testset_two[j], wordlist_two, wc_two);
                //printf("Ord 2: %s\n", wordlist_two[i]); // test output

                // Compare words across = Size is a counter
                int line_current_one = i;
                int line_current_two = j;
                int shortest = wc_one;
                if (wc_one > wc_two) { shortest = wc_two;} 
                else if (wc_one < wc_two) { shortest = wc_one;}

                for (int i = 0; i < shortest; i++) {
                    if(check_string(wordlist_one[i], wordlist_two[i])) {
                        if(check_chars(wordlist_one, shortest, wordlist_two)) {
                            strcpy(cMatches[cCount].text, wordlist_one[i]);
                            strcpy(cMatches[cCount].match_text, wordlist_two[i]);
                            cMatches[cCount].word_num = i+1;
                            cMatches[cCount].match_word_num = i+1;
                            cMatches[cCount].line_num = line_current_one;
                            cMatches[cCount].match_line_num = line_current_two;

                            cCount++;
                        }
                    } 
                }
                free(wordlist_one);
                free(wordlist_two);
            }

            cryptic_count = cCount;
        }
    }

    // Send values to eval_results
    eval_results(vMatches, verbatim_count, cMatches, cryptic_count, fp_one, fp_two);
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

//param[in] : array of PlagMatches, sizes of arrays and file paths
void eval_results(PlagMatch *vMatches, int vSize, PlagMatch *cMatches, int cSize, char fp_one[], char fp_two[]) {
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
