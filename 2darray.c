#include <stdio.h>
#include <stdlib.h>

void printndim(int **test, int n, int m);

int main(void){
    int n = 3;
    int m = 4;
    int count = 0;

    int **test = malloc(n*sizeof(int *));

    for(int i = 0; i <n; i++){
        m = 4;
        test[i] = malloc(m*sizeof(int));
        for(int j = 0; j < m; j++){
            test[i][j] = count;
            count++;
        }
    }

    printndim(test, n, m);
    free(test);
    return 0;
}

void printndim(int **test, int n, int m){
    for(int i = 0; i <n; i++){
        for(int j = 0; j < m; j++){
            printf("[%d][%d]: %d \n",i, j, test[i][j]);
        }
    }
}