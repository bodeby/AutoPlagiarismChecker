// System Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Gruppens Headers
#include "subtools.h"
#include "subcryptic.h"
#include "subloadfile.h"

void verbatim(char arr1[][40], size_t size_of_arr1, char arr2[][40], char verb_arr2[1000][40]);
int main(void)
{
    char arr_test1[][40] = {"Hej mit navn er Oscar", "Jeg er 22 aar", "dfghdkjfgJeg gi", "Oscar drikker vand og aeder hele tiien"};
    char arr_test2[][40] = {"Hej mit navn er Oscar", "Jeg gaar på uni", "Jeg er 22 aar", "Oscar drikker vand og aeder hele tiden"};
    char verb_arr2[1000][40];
    verbatim(arr_test1, 3, arr_test2, verb_arr2);
    return 0;
}

void verbatim(char arr1[][40], size_t size_of_arr1, char arr2[][40], char verb_arr2[1000][40])
{
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