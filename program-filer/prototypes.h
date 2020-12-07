#ifndef PROTOTYPES_H
#define PROTOTYPES_H

typedef struct PlagMatch {
    char text[200];
    int line_num;
    int word_num;
    char match_text[200];
    int match_line_num;
    int match_word_num;
} PlagMatch;

typedef struct FileInfo {
    char file_path_one[100];
    char file_path_two[100];
} FileInfo;

void run_checks();
char *load_file(char fp[]);
void prep_array(char arr_one[]);
void locate_cryptic(char str_one[], char str_two[], PlagMatch *cMatches);
void find_synonym(char str_one[], char str_two[], char *synonym_res, bool *synonym_check);
void eval_results(PlagMatch *vMatches, int vmSize, PlagMatch *cMatches, int cmSize, char fp_one[], char fp_two[]);

#endif // PROTOTYPES.H
