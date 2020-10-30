#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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
    printf("%d\n\n", max_size);
    char array [linje_kontrol][max_size];

    int maengde = 0;
    int maengde1 = 0;
    lykke_tæller = 0;

    while(lykke_tæller+1 < linje_kontrol)
    {
        maengde = (linje_lokation[lykke_tæller+1] - linje_lokation[lykke_tæller]);
        maengde1 = linje_lokation[lykke_tæller];
        printf ("%d   ", maengde);
        printf ("%d\n", lykke_tæller);
        strncpy(array[lykke_tæller], navn_paa_ny_fil+maengde1, maengde);
        
        lykke_tæller += 1;
    }
    maengde = (text_size1 - linje_lokation[lykke_tæller-1]);
    maengde1 = linje_lokation[lykke_tæller];
    strncpy(array[lykke_tæller], navn_paa_ny_fil+maengde1, maengde);

    lykke_tæller = 0;
    while (lykke_tæller < max_size )
    {
        array[0][max_size-lykke_tæller]
    }

    printf("\n%s\n", array[0]);
    printf("%s\n", array[1]);
    printf("%s\n", array[2]);

    return EXIT_SUCCESS;
}
