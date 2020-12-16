#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "prototypes.h"
#include "subtools.h"

int main(void) {

    int nums_one[] = {14,2,3,4};
    int nums_two[] = {5,6,7};
    int sc_one = 3;
    int sc_two = 2;

    for (int i = 0; i < sc_one+1; i++) {
        printf("\n");
        for (int j = 0; j < sc_two+1; j++) {
            printf("nums_one: %d - nums_two: %d\n", nums_one[i], nums_two[j]);
        }
    }

    char test_str1[] = "The quick brown fox jumps over the lazy dog brown";
    char test_str2[] = "The quick browп fox jumps over the lazy dog browп";

    int len_one = strlen(test_str1);
    int len_two = strlen(test_str2);
    int len_diff = (int) abs(len_one-len_two);
    int editDistance = editDist(test_str1, test_str2);

    printf("String 1: %s\nString2: %s\nLength Difference: %d\nEdit disstance: %d\n", test_str1, test_str2, len_diff, editDistance);

    printf("#words: %d\n", count_words(test_str1));

    char test_len[] = "Despite the danger and hopelessness of the quest, Frodo accepts the burden and resolves to take the Ring to the safety of the elven stronghold of Rivendell.";
    printf("Længde: %d", strlen(test_len));

}
