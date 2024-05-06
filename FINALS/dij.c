#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 5
#define Z 99999 // INT_MAX sometimes gives me a value of a negative number for some reason
// #define min(a, b) ((a) < (b) ? (a) : (b))

typedef int MATRIX[MAX][MAX];
int* dij(MATRIX,int);
void floyd(MATRIX, MATRIX);

void print(MATRIX);

int min(int a, int b) {return (a < b) ? a : b;}

int main(void)
{
    system("cls");
    MATRIX M = {    {Z, 10, Z, 30, 100},
                    {Z, Z, 50, Z, Z},
                    {20, Z, Z, Z, 10},
                    {Z, Z, 20, Z, 60},
                    {Z, Z, Z, Z, Z}
                    
                    };


    MATRIX rawr;
    floyd(M,rawr);
    print(rawr);

    system("pause");
    system("cls");

    for(int ndx = 0; ndx<MAX;ndx++)
        memcpy(rawr[ndx], dij(M,ndx), sizeof(int)*MAX);
    print(rawr);
    
    

    return 0;
}

int* dij(MATRIX main, int src){

    //copy the costs from the source vertex
    int* retval = malloc(sizeof(int) * MAX);
    memcpy(retval, main[src],(sizeof(int) * MAX));

    int small, smallndx, ndx, ctr = 0;

    //initialize the set, D, and 
    int SET[MAX] = {0};
    SET[src] = 1;
    retval[src] = 0;

    while(ctr < MAX){
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
        ctr++;
}
    return retval;
}

void floyd(MATRIX main, MATRIX retval){

    int i, j, k;

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            retval[i][j] = main[i][j]; 
    
    for(i = 0; i<MAX; i++)
        retval[i][i] = 0;

    for(k = 0; k<MAX;k++)
        for(i=0;i<MAX;i++)
            for(j=0;j<MAX;j++)
                retval[i][j] = ((retval[i][k] + retval[k][j]) < retval[i][j]) ? (retval[i][k] + retval[k][j]) : retval[i][j];
        
}







void print(MATRIX main){
    for(int ndx = 0; ndx < MAX; ndx++){
        for(int idx = 0; idx < MAX; idx++){
            printf("%6d", (main[ndx][idx] != Z) ? main[ndx][idx] : -1);
        }
        printf("\n");
    }
}