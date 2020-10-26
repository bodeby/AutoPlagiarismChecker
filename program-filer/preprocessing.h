#include <stdio.h>
#include <string.h>

void preprocessing (/*char *navn_paa_fil*/) 
{

    char navn_paa_fil[100] = "Hej mit navn er Oscar.\n og jeg er 22";
    int text_size=strlen(navn_paa_fil);
    char text[text_size]; 
    char p[text_size];
    int i=0;

    /*for (int i = 0; i<=text_size; i++) 
    {*/ //https://www.tutorialspoint.com/c_standard_library/c_function_strncpy.htm
        p[i]=*strncpy(navn_paa_fil,p,i);
        p[i+1]=*strncpy(navn_paa_fil,p,i+1);
        char tekst1 = *strncpy(navn_paa_fil,p,i);
        char tekst2 = *strncpy(navn_paa_fil,p,i+1);
        printf("%c %c",tekst1,tekst2);
        /*
        if (p[i]=='\\') 
        {
            if (p[i+1]=='n') 
                {
                    p[i] = NULL;
                    p[i+1] = NULL;
                    i--;

                }
        } 

    }*/
}