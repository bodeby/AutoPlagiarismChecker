#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int preprocessing (void) 
{

    char ori_file[100] = "Hej mit navn er Oscar.\nJeg er 22 aar.\nJeg gaar paa uni.\n Oscar drikker vand\n og aeder hele tiden";
    int text_size1=strlen(ori_file);

    char new_file[text_size1];
    strncpy (new_file, ori_file, text_size1);

    int count = 0;
    int line_control = 0;
    int line_location = 0; 
    char the_file[text_size1][text_size1];
    int count1 = 0;

    while (new_file[count] != '\0') 
    {
        if (new_file[count] == '\n') 
        {
            new_file[count] = ' ';
            line_location = count;
            for (int j = 0;j<line_location;j++) 
            {
                the_file[line_control][j] = new_file[j+count1];
            }
            line_control++;
            count1=count;
        }
        count++;
    }
    for (int k=0;k<10;k++) 
    {
        printf("%c",the_file[3][k]);
    }
    return EXIT_SUCCESS;
}