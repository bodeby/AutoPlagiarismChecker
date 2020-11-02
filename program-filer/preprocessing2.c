#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main (void) 
{

    char ori_file[100] = "Hej mit navn er Oscar.\nJeg er 22 aar.\nJeg gaar paa uni.\n Oscar drikker vand\n og aeder hele tiden";
    int text_size1=strlen(ori_file);

    char new_file[text_size1];
    strncpy (new_file, ori_file, text_size1);

    int count = 0;
    int line_control = 1;

    while (new_file[count] != '\0'){

        if (new_file[count] == '\n'){
            line_control += 1;
        }
        count += 1;
    }
    char line_location[line_control];
    line_location[0] = 129;
    int a = line_location[0];
    printf("%d/n", a);
    count = 0;
    line_control = 1;

    while (new_file[count] != '\0'){

        if (new_file[count] == '\n'){
            new_file[count] = ' ';
            line_location[line_control] = count+1;
            line_control += 1;
        }
        count += 1;
    }
    return EXIT_SUCCESS;
}
