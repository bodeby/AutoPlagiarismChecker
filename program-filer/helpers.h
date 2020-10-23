#include <stdio.h>
#include <string.h>

/* print char array as string */
void print_str(char array[]) {
    for (unsigned long i = 0LU; i < strlen(array); i++) {
        printf("%c", array[i]);
    }
    printf("\n");
}

