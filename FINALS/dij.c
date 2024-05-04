#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define MAX 5
#define Z __INT_MAX__
#define min(a, b) ((a) < (b) ? (a) : (b))

typedef int MATRIX[MAX][MAX];
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

int *dij(MATRIX main)
{
    int *retval = (int *)malloc(sizeof(int) * MAX);

    int ctr, ndx, ind, smallndx, small = Z;
    int SET[MAX] = {1, 0, 0, 0, 0};

    memcpy(retval, main[0], sizeof(int) * MAX);
    retval[0] = 0;

    for (ctr = 1; ctr < MAX; ctr++)
    {
        for (ndx = 0; ndx < MAX; ndx++)
        {
            if (SET[ndx] != 1)
            {   
                small = retval[ndx];
                smallndx = ndx;
            }
        }

        SET[smallndx] = 1;

        for (ind = 0; ind < MAX; ind++)
        {
            if (SET[ndx] != 1)
            {
                SET[ndx] = min(SET[ndx], (SET[smallndx] + main[smallndx][ndx]));
            }
        }
    }

    return retval;
}
