// System Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char **verbatim(char arr1[][40], char arr2[][40])
{
    //struct PlagMatch StrVerbatim;
    char verb_arr2[1000][40]; //Output arrayet
    int size_of_arr1 = sizeof(arr1);
    int q = 0;
    int m = 0;
    //int largest_array = 0;

    /*for (int i = 0; i < (int)size_of_arr1 + 1; i++)
    {
        if (largest_array < (int)strlen(arr1[i]))
        {
            largest_array = (int)strlen(arr1[i]);
        }
    } Muligvis ligegyldig kode */

    for (int i = 0; i <= (int)size_of_arr1; i++) //i styrer sætninger i det første array
    {
        for (int n = 0; n <= (int)size_of_arr1; n++) //n styrer sætninger i det andet array
        {
            q = 0;                                              //q er antal tegn, der er ens i sætningerne
            for (int j = 0; j <= (int)strlen(arr1[i]) - 1; j++) //j styrer tegn i begge sætninger
            {
                if (arr1[i][j] == arr2[n][j]) //Hvis tegnet er det samme i begge sætninger
                {
                    q++;                           //Så er q antal tegn ens
                    if (q == (int)strlen(arr1[i])) //Hvis der er lige så mange ens tegn, som der er i sætningen
                    {
                        for (int l = 0; l < (int)strlen(arr1[i]); l++)
                        {
                            verb_arr2[m][l] = arr1[i][l]; //Så bliver sætningen sat ind i det nye array
                        }
                        m++;
                    }
                }
            }
        }
    }

    /*for (int k = 0; k <= (int)size_of_arr1; k++)
    {
        printf("%s\n", verb_arr2[k]);
    } */
    return verb_arr2;
}
