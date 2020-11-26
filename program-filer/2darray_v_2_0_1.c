#include <stdio.h>
#include <stdlib.h>

char** double_pointer_array(int n, char *count);

int main(void){
    int n = 3;
    char *count = "Hej dine fjols";
    char **test;

    test = double_pointer_array(n, count);
    for(int i = 0; i < n; i++){
        printf("[%d]: %s \n",i, test[i]);
    }
    free(test);
    return 0;
}

char** double_pointer_array(int n, char *count){
    //laver et array med int pointere
    char **pointer_arr = malloc(n*sizeof(char *));
    int length_arr[] = {3, 4, 5};
    int index = 0;

    for(int i = 0; i < n; i++){
        //for hver pointer allokeres m pladser, her af typen int
        pointer_arr[i] = malloc(length_arr[i]*sizeof(char));
        for(int j = 0; j < length_arr[i]; j++){
            pointer_arr[i][j] = count[j + index];
        }
        index = index + length_arr[i]+1;
    }
    return pointer_arr;
}