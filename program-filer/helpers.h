
/* print char array as string */
void print_str(char array[]) {
    for (int i = 0; i < strlen(array); i++) {
        printf("%c", array[i]);
    }
    printf("\n");
}