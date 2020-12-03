#include <stdio.h>
#include <stdlib.h>

void printndim(int **test, int n, int m);
void fill_array(int ** test, int n, int m);

int main(void){
    // størrelse
    int n = 3;
    int m = 6;
    int **test = malloc(n*sizeof(int *));

    int count = 0;
    for(int i = 0; i <n; i++){
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

void fill_array(int **test, int n, int m) {
    int count = 0;
    for(int i = 0; i <n; i++){
        test[i] = malloc(m*sizeof(int));
        for(int j = 0; j < m; j++){
            test[i][j] = count;
            count++;
        }
    }
}


void printndim(int **test, int n, int m){
    for(int i = 0; i <n; i++){
        for(int j = 0; j < m; j++){
            printf("[%d][%d]: %d \n",i, j, test[i][j]);
        }
    }
}
