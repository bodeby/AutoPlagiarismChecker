#include <stdio.h>
#include <string.h>

int main (void) 
{

    char navn_paa_ori_fil[100] = "Hej mit navn er Oscar.\nJeg er 22 aar.\nJeg gaar paa uni.";
    int text_size1=strlen(navn_paa_ori_fil);

    char navn_paa_ny_fil[text_size1];
    strncpy (navn_paa_ny_fil, navn_paa_ori_fil, text_size1);

    int tæller = 0;
    int linje_kontrol = 1;
    char linje_lokation[100];
    
    int a = 0;
    linje_lokation[0] = a;

    while (navn_paa_ny_fil[tæller] != '\0'){ // \0 = NULL

        if (navn_paa_ny_fil[tæller] == '\n'){
            navn_paa_ny_fil[tæller] = ' ';
            linje_lokation[linje_kontrol] = tæller+1;
            linje_kontrol += 1;
        }
        tæller += 1;
    }
    int lykke_tæller = 0;
    int max_size = 0;

    while (lykke_tæller < linje_kontrol)
    {
            printf("%d\n", linje_lokation[lykke_tæller]);
        if ((linje_lokation[lykke_tæller+1] - linje_lokation[lykke_tæller]) > max_size)
        {
            max_size = (linje_lokation[lykke_tæller+1] - linje_lokation[lykke_tæller]);
        }
        lykke_tæller += 1;
    }
    if ((text_size1 - linje_lokation[lykke_tæller-1]) > max_size)
    {
        max_size = (text_size1 - linje_lokation[lykke_tæller-1]);
    }
    printf("%d\n", lykke_tæller);
    printf("%d\n", max_size);
    char array [linje_kontrol][max_size];

    /*

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

    */

    return 0;
}

//brug array [string] [mænge på største string]