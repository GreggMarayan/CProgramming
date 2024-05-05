#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 5
#define Z 99999 // INT_MAX sometimes gives me a value of a negative number for some reason
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

int* dij(MATRIX main){

    //copy the costs from the source vertex
    int* retval = malloc(sizeof(int) * MAX);
    memcpy(retval, main[0],(sizeof(int) * MAX));

    int small, smallndx, ndx, ctr;

    //initialize the set
    int SET[MAX] = {1,0,0,0,0};
    
    for(ctr = 1; ctr < MAX; ctr++){
    
        //Loops through the retval to determine the shortest path to another vertex
        for(ndx = 0, small = Z; ndx < MAX; ndx++){
            if(!SET[ndx] && retval[ndx] < small){
                small = retval[ndx];
                smallndx = ndx;
            }
        }

        //Sets the next shortest vertex it found as visited in the set
        SET[smallndx] = 1;

        //loops through the the main from the smallest vertex to find any other shorter path that the source vertex has found already
        for(ndx = 0; ndx < MAX; ndx++){
            if(!SET[ndx]){
                retval[ndx] = min(retval[ndx], (retval[smallndx] + main[smallndx][ndx]));
            }
        }
    }

    retval[0] = 0;
    return retval;
}