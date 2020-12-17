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


    char string1[] = "When the eccentric hobbit Bilbo Baggins leaves his home in the Shire, he gives his greatest treasure to his heir Frodo: a magic ring that makes its wearer invisible.";
    char string2[] = "Because of the difficulty Bilbo has in giving the ring away, his friend the wizard Gandalf the Grey suspects that the ring is more than it appears.";
    char string3[] = "Gandalf tells Frodo that the Ring must be destroyed to defeat Sauron's evil, but he also warns him that the Enemy has learned of the Ring's whereabouts from the creature Gollum and will seek to find it and kill its bearer.";
    char string4[] = "Despite the danger and hopelessness of the quest, Frodo accepts the burden and resolves to take the Ring to the safety of the elven stronghold of Rivendell.";
    char string5[] = "Some years later, Gandalf reveals to Frodo that the ring is in fact the One Ring, forged by Sauron the Dark Lord thousands of years before to enable him to dominate and enslave all of Middle-earth.";

    int len1 = strlen("When the eccentric hobbit Bilbo Baggins leaves his home in the Shire, he gives his greatest treasure to his heir Frodo: a magic ring that makes its wearer invisible.");
    int len2 = strlen("Because of the difficulty Bilbo has in giving the ring away, his friend the wizard Gandalf the Grey suspects that the ring is more than it appears.");
    int len3 = strlen("Gandalf tells Frodo that the Ring must be destroyed to defeat Sauron's evil, but he also warns him that the Enemy has learned of the Ring's whereabouts from the creature Gollum and will seek to find it and kill its bearer.");
    int len4 = strlen("Despite the danger and hopelessness of the quest, Frodo accepts the burden and resolves to take the Ring to the safety of the elven stronghold of Rivendell.");
    int len5 = strlen("Some years later, Gandalf reveals to Frodo that the ring is in fact the One Ring, forged by Sauron the Dark Lord thousands of years before to enable him to dominate and enslave all of Middle-earth.");
}
