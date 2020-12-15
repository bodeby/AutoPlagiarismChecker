#ifndef PROTOTYPES_H
#define PROTOTYPES_H

// STRUCTS 
typedef struct PlagMatch {
    char text[300];
    int line_num;
    int word_num;
    char match_text[300];
    int match_line_num;
    int match_word_num;
} PlagMatch;

typedef struct FileInfo {
    char file_path_one[100];
    char file_path_two[100];
} FileInfo;

// FUNCTIONS
void run_checks();
char *load_file(char fp[]);
//void prep_array(char arr_one[]);
void locate_cryptic(char str_one[], char str_two[]);
int cryptic_finder(PlagMatch cMatches[], char **sentences_one, char **sentences_two, int sc_one, int sc_two, int size, int capacity);
void eval_results(PlagMatch *vMatches, int vmSize, PlagMatch *cMatches, int cmSize, char fp_one[], char fp_two[]);

#endif // PROTOTYPES.H
