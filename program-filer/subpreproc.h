#include <stdio.h>
#include <string.h>

#include "subcryptic.h"
#include "subloadfile.h"
#include "subpreproc.h"
#include "subtools.h"

void preprocessing (/*char *navn_paa_fil*/) 
{

    char navn_paa_fil[100] = "Hej mit navn er Oscar.\n og jeg er 22";
    int text_size=strlen(navn_paa_fil);
    //char test[text_size];
    char p[text_size];
    int i=0;

    /*for (int i = 0; i<=text_size; i++) 
    {*/ //https://www.tutorialspoint.com/c_standard_library/c_function_strncpy.htm
        p[i]=*strncpy(navn_paa_fil,p,i);
        p[i+1]=*strncpy(navn_paa_fil,p,i+1);

        char tekst1[i];
        char tekst2[i+1];

        tekst1[i] = *strncpy(navn_paa_fil,p,i);
        tekst2[i+1] = *strncpy(navn_paa_fil,p,i+1);
        printf("%s %s",tekst1[i],tekst2[i+1]);
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
