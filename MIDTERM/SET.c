#include <stdio.h>
#include <stdlib.h>
#define size 10

typedef int SET[10];

SET* setUnion(SET, SET);

int main(){
    SET A = {1,1,0,1,0,1,0,0,0,1};
    SET B = {0,0,0,1,0,1,0,1,1,1};
    SET *C = setUnion(A, B);

    // Displaying the resulting set obtained from the union operation
    printf("Set A: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("Set B: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");

    printf("Resulting Set (Union of A and B): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", (*C)[i]);
    }
    printf("\n");

    return 0;
}

SET* setUnion(SET A, SET B){
    SET *C = malloc(sizeof(SET));
    if(C != NULL){
        int ndx;
        for(ndx = 0; ndx < size; ndx++){
            (*C)[ndx] = (A[ndx] || B[ndx]) ? 1 : 0;
        }
    return C;
    }
}
