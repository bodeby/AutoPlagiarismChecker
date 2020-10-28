#include <stdio.h>
#include <string.h>

int main (void) 
{

    char navn_paa_fil[100] = "Hej mit navn er Oscar.\n og jeg er 22";
    int text_size=strlen(navn_paa_fil);

    char p[text_size];
    int i=0;

    /*for (int i = 0; i<=text_size; i++) 
    {*/ //https://www.tutorialspoint.com/c_standard_library/c_function_strncpy.htm


        strncpy(navn_paa_fil,p,i);
        strncpy(navn_paa_fil,p,i+1);
        printf("%s",p);
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