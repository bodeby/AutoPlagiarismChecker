#include <stdio.h>
#include <string.h>

void preprocessing (/*char *navn_paa_fil*/) 
{

    char navn_paa_fil = 'Hej mit navn er Oscar.\n og jeg er 22';
    int text_size=strnlen(navn_paa_fil);
    char text[text_size]; 
    char p[text_size];

    for (int i = 0; i<=text_size; i++) 
    {
<<<<<<< HEAD
        text[i];
=======
        strncpy(text,p,i);
        if (p[i]=='\\') 
        {
        if (p[i+1]=='n') 
            {
                p[i] = NULL;
                p[i+1] = NULL;

            }
        } 
>>>>>>> f589e5dc714b69efdc9a63c40fff643036e8637c

    }
}