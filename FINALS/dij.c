#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 5
// #define Z INT_MAX -> results in negative value (better to use 999999 instead)
#define Z 999999

int min(int,int);

typedef int MATRIX[MAX][MAX];

int* floyds(MATRIX);
int *dij(MATRIX);


void print(MATRIX);

int main(void)
{

    MATRIX MATRIX = {{Z, 10, Z, 30, 100},
                     {Z, Z, 50, Z, Z},
                     {20, Z, Z, Z, 10},
                     {Z, Z, 20, Z, 60},
                     {Z, Z, Z, Z, Z}};
    int *wow = dij(MATRIX);
    for (int i = 0; i < 5; i++)
    {
        printf("%d -> %d\n",i+1,wow[i]);
    }
    

    return 0;
}


int min(int a, int b){
    return (a < b) ? a : b;
}

int* dij(MATRIX main)
{
    int* retval = malloc(sizeof(int) * MAX);
    int ctr, ndx, ind, smallndx, small;
    int SET[MAX] = {1, 0, 0, 0, 0};

    memcpy(retval, main[0], sizeof(int) * MAX);

    retval[0] = 0;

    for (ctr = 0; ctr < MAX; ctr++)
    {   
        for (ndx = 0, small = Z; ndx < MAX; ndx++){
            if (SET[ndx] != 1 && (retval[ndx] < small && retval > 0)){   
                small = retval[ndx];
                smallndx = ndx;
            }
        }

        SET[smallndx] = 1;

        for (ind = 0; ind < MAX; ind++)
        {
            if (!SET[ind]){
                retval[ind] = min(retval[ind], (retval[smallndx] + main[smallndx][ind]));
            }
        }
    }

    return retval;
}

int* floyds(MATRIX main){

    int *retval = malloc(sizeof(int) * MAX);
    for(int x = 0; x < MAX; x++){
        retval[x] = malloc(sizeof(int) * MAX);
    }





}
