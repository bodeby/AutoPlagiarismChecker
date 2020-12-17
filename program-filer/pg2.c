/* System Headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "subtools.h"
#include "subcryptic.h"

int main(void) {
    
    // TEST ONLY -- To be removed
    char test_str1[] = "The quick brown fox jumps over the lazy dog brown";
    char test_str2[] = "The quick browп fox jumps over the lazy dog browп";

    int len_one = strlen(test_str1);
    int len_two = strlen(test_str2);
    int len_diff = (int) abs(len_one-len_two);
    int editDistance = editDist(test_str1, test_str2);

    printf("Levendist (M) %d\n", editDist("M", "М"));

    if (editDistance != 0 && editDistance %2 == 0 && editDistance / 2 == len_diff) {
        int wc_one = count_words(test_str1);
        int wc_two = count_words(test_str2);

        // Create wordlist, split sentences into words and fill wordlist
        char **wordlist_one = malloc(wc_one * sizeof(char *));
        split_sentences(test_str1, wordlist_one, wc_one);

        // Create wordlist, split sentences into words and fill wordlist
        char **wordlist_two = malloc(wc_two * sizeof(char *));
        split_sentences(test_str2, wordlist_two, wc_two);

        for (int i = 0; i < wc_one; i++) {
            int w_len_one = strlen(wordlist_one[i]);
            int w_len_two = strlen(wordlist_two[i]);
            int w_len_diff = (int) abs(w_len_one-w_len_two);
            int w_editDistance = editDist(wordlist_one[i], wordlist_two[i]);

            printf("%s - %s; dist - %d\n", wordlist_one[i], wordlist_two[i], editDist(wordlist_one[i], wordlist_two[i]));
            if(w_editDistance != 0 && w_editDistance % 2 == 0 && w_editDistance / 2 == w_len_diff) {
                if (check_chars(wordlist_one, wc_one, wordlist_two)) {
                    printf("found word at pos: %d\n", i+1);
                }
            }
        }
    }

}
