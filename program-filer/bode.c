#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "prototypes.h"
#include "subtools.h"

int main(void) {

    char test_str1[] = "The quick brown fox jumps over the lazy dog brown";
    char test_str2[] = "The quick browп fox jumps over the lazy dog browп";

    int len_one = strlen(test_str1);
    int len_two = strlen(test_str2);
    int len_diff = (int) abs(len_one-len_two);
    int editDistance = editDist(test_str1, test_str2);


    char streng1[] = " Hej med dig fede ko";
    char streng2[] = "Hej med dig fede ko";
    char streng3[] = "Hej med dig fede ko ";

    printf("\nString 1: %d\nString 2: %d\nString 3: %d\n", count_words(streng1), count_words(streng2), count_words(streng3));
    printf("first: %c, last: %c\n", streng2[0], streng2[strlen(streng2)-1]);
}
