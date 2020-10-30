#include <stdio.h>
#include <string.h>

#include "subcryptic.h"
#include "subloadfile.h"
#include "subpreproc.h"
#include "subtools.h"

int main (void) 
{

    char navn_paa_ori_fil[100] = "Hej mit navn er Oscar.\nJeg er 22 aar.\nJeg går på uni.";
    int text_size1=strlen(navn_paa_ori_fil);

    char navn_paa_ny_fil[text_size1];
    strncpy (navn_paa_ny_fil, navn_paa_ori_fil, text_size1);

    int tæller = 0;
    int punktom_kontrol = 0;
    char punktom_lokation[100];

    while (navn_paa_ny_fil[tæller] != '\0'){ // \0 = NULL

        if (navn_paa_ny_fil[tæller] == '\n'){
            navn_paa_ny_fil[tæller] = ' ';
        }
        
        if (navn_paa_ny_fil[tæller] == '.'){
            punktom_lokation[punktom_kontrol] = tæller;
            punktom_kontrol += 1;
        }
        tæller += 1;
    }

    int tal1 = 0, tal2 = 0;

    char text1[100];
    tal2 = punktom_lokation[0];
    strncpy(text1, navn_paa_ny_fil, tal2);
    
    char text2[100];
    tal1 = punktom_lokation[0]+2; tal2 = punktom_lokation[1];
    strncpy(text2, navn_paa_ny_fil+tal1, (tal2 - tal1));

    char text3[100];
    tal1 = punktom_lokation[1]+2; tal2 = punktom_lokation[2];
    strncpy(text3, navn_paa_ny_fil+tal1, (tal2 - tal1));

    int text_size2=strlen(navn_paa_ny_fil);
    printf("\nOri string: %d størrelse \n%s\n\n",text_size1, navn_paa_ori_fil);
    printf("Rettet string: %d størrelse \n%s\n\n",text_size2, navn_paa_ny_fil);

    printf("text1: %s\n", text1);
    printf("text2: %s\n", text2);
    printf("text3: %s\n", text3);

    return 0;
}

//brug array [string] [mænge på største string]