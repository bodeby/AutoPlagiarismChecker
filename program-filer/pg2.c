/* System Headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "subtools.h"
#include "subcryptic.h"

int main(void) {
    // set paths to files
    char *fp_one = "./test-files/pancake-org.txt";
    char *fp_two = "./test-files/pancake-plag.txt";

    // TEST ONLY
    //char test_str1[] = "The quick brown fox jumps over the lazy dog brown";
    //char test_str2[] = "The quick browп fox jumps over the lazy dog browп";

    // TEST 2
    char test_str1[] = "Some years later, Gandalf reveals to Frodo that the ring is in fact the One Ring, forged by Sauron the Dark Lord thousands of years before to enable him to dominate and enslave all of Middle-earth.";
    char test_str2[] = "Some years later, Gaпdalf reveals to Frodo that the ring is in fact the One Ring, forged by Sauron the Dark Lord thousands of years before to enable him to dominate and enslave all of Мiddle-earth.";

    // VERBATIM START
    int vSize = 0;
    int vCapacity_init = 1;
    int vCapacity = vCapacity_init;
    PlagMatch *vMatches = malloc(vCapacity_init * sizeof(PlagMatch));

    // Apppend matches to verbatim
    plagAppend(vMatches, vSize, createPlagMatch(test_str1, test_str2, 4, 17, 23, 4), &vSize, &vCapacity);
    plagAppend(vMatches, vSize, createPlagMatch(test_str1, test_str2, 5, 18, 24, 5), &vSize, &vCapacity);
    plagAppend(vMatches, vSize, createPlagMatch(test_str1, test_str2, 1, 7, 27, 6), &vSize, &vCapacity);


    int verbatim_count = 3;
    // Copy dynamic array elements to static array
    PlagMatch static_vMatches[verbatim_count];
    if (verbatim_count > 0) {
        for (int i = 0; i < verbatim_count; i++) {
            static_vMatches[i] = vMatches[i];
        }
        free(vMatches);
    } else {
        free(vMatches);
    }

    // CRYPTIC DIRECT
    int Size = 0;
    int Capacity_init = 1;
    int Capacity = Capacity_init;
    PlagMatch *cMatches = malloc(Capacity_init * sizeof(PlagMatch));

    int k = 0;
    if (check_string(test_str1, test_str2)) {
        int wc_one = count_words(test_str1); // get number of words in string 1
        int wc_two = count_words(test_str2); // get number of words in string 2

        // Create wordlist, split sentences into words and fill wordlist
        char **wordlist_one = malloc(wc_one * sizeof(char *));
        split_sentences(test_str1, wordlist_one, wc_one);

        // Create wordlist, split sentences into words and fill wordlist
        char **wordlist_two = malloc(wc_two * sizeof(char *));
        split_sentences(test_str2, wordlist_two, wc_two);
                

        // Compare words across = Size is a counter
        for (int i = 0; i < wc_one; i++) {
            if(check_string(wordlist_one[i], wordlist_two[i])) {
                if (check_chars(wordlist_one, wc_one, wordlist_two)) {
                    printf("- found word at pos: %d insert at: %d\n", i+1,Size);
                    plagAppend(cMatches, Size, createPlagMatch(test_str1, test_str2,i+1,1,i+1,1), &Size, &Capacity);
                    k++;
                }
            }
        }

        free(wordlist_one); // free memory for wordlist_one
        free(wordlist_two); // free memory for wordlist_two
    }

    int cryptic_count = k;
     // Copy dynamic array elements to static array
    PlagMatch static_cMatches[cryptic_count];
    if (cryptic_count > 0) {
        for (int i = 0; i < cryptic_count; i++) {
            static_cMatches[i] = cMatches[i];
        }
        free(cMatches);
    } else {
        free(cMatches);
    }

    // Send values to eval_results
    eval_results(static_vMatches, verbatim_count, static_cMatches, cryptic_count, fp_one, fp_two);
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
