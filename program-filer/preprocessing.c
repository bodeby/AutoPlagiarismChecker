#include <stdio.h>
#include <string.h>

int main (void) 
{

    char navn_paa_ori_fil[100] = "Hej mit navn er Oscar.\nJeg er 22 aar.\nJeg går på uni.";
    int text_size1=strlen(navn_paa_ori_fil);

    char navn_paa_ny_fil[text_size1];
    strncpy (navn_paa_ny_fil, navn_paa_ori_fil, text_size1);

    int tæller = 0;
    int tæller_punktom = 0;

    while (navn_paa_ny_fil[tæller] != '\0'){ // \0 = NULL

        if (navn_paa_ny_fil[tæller] == '\n'){
            navn_paa_ny_fil[tæller] = ' ';

        }
        if (navn_paa_ny_fil[tæller] == '.'){
            tæller_punktom += 1;
        }
        tæller += 1;
    }
    
    int text_size2=strlen(navn_paa_ny_fil);

    printf("\nOri string: %d størrelse \n%s\n\n",text_size1, navn_paa_ori_fil);
    printf("Der er %d punktom i string\n\n", tæller_punktom);
    printf("Rettet string: %d størrelse \n%s\n\n",text_size2, navn_paa_ny_fil);

    return 0;
}