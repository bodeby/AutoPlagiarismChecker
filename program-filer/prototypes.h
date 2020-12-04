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

#endif // PROTOTYPES.H