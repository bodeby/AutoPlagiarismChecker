// System Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void verbatim(char arr1[][40], char arr2[][40])
{
    char verb_arr2[1000][40];
    int size_of_arr1 = sizeof(arr1);
    int i;
    int j = 0;
    int q = 0;
    int l;
    int m = 0;
    int n = 0;
    int largest_array = 0;
    int p;

    for (p = 0; p < (int)size_of_arr1 + 1; p++)
    {
        if (largest_array < (int)strlen(arr1[p]))
        {
            largest_array = (int)strlen(arr1[p]);
        }
    }

    for (i = 0; i <= (int)size_of_arr1; i++)
    {
        for (n = 0; n <= (int)size_of_arr1; n++)
        {
            q = 0;
            for (j = 0; j <= (int)strlen(arr1[i]) - 1; j++)
            {
                if (arr1[i][j] == arr2[n][j])
                {
                    q++;
                    if (q == (int)strlen(arr1[i]))
                    {

                        printf("Its the same!\n");
                        for (l = 0; l < (int)strlen(arr1[i]); l++)
                        {
                            verb_arr2[m][l] = arr1[i][l];
                        }
                        m++;
                    }
                }
            }
        }
    }

    for (int k = 0; k <= (int)size_of_arr1; k++)
    {
        printf("%s\n", verb_arr2[k]);
    }
}