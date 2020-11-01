#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main (void){
    
    char ori_file[200] = "Hej mit navn er Oscar.\nJeg er 22 aar.\nJeg gaar paa uni.\nOscar drikker vand\nog aeder hele tiden";
    int text_size_ori=strlen(ori_file);

    char new_file[text_size_ori];
    strncpy (new_file, ori_file, text_size_ori);

    int count = 0;
    int line_control = 1;
    int line_value1 = 0, line_value2 = 0, max_line_value = 0;

    while (new_file[count] != '\0'){
        
        if (new_file[count] == '\n'){
            line_control += 1;

            line_value2 = count;
            if (max_line_value < line_value2 - line_value1){
                max_line_value = line_value2 - line_value1;
            }
            line_value1 = line_value2;
        }
        count += 1;
    }
    if (max_line_value < text_size_ori - line_value1){
        max_line_value = text_size_ori - line_value1;
    }
    
    printf("%d\n", text_size_ori); //debugging
    printf("%d\n", line_value1);
    printf("%d\n", max_line_value);
    printf("%d\n", line_control);

    char array [line_control][max_line_value];

    count = 0;
    int last_count = 0;
    int line_count = 0;

    while (new_file[count] != '\0'){
        
        if (new_file[count] == '\n'){
            new_file[count] = ' ';
             strncpy (array[line_count], new_file+last_count, count - last_count);
             last_count = count;
             line_count += 1;
        }
        count += 1;
    }
    strncpy (array[line_count], new_file+last_count, text_size_ori - last_count);

    printf("\n%s\n", array[0]);
    printf("%s\n", array[1]);
    printf("%s\n", array[2]);
    printf("%s\n", array[3]);
    printf("%s\n", array[4]);

    return EXIT_SUCCESS;
}
