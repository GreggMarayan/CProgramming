#include <stdio.h>

typedef unsigned int SET;


void displayPattern(SET);

int main(){
    SET data = 5;
    displayPattern(data);
    return 0;
}

void displayPattern(SET S){
    int bits = (sizeof(SET)*8);
    SET mask  = 1 << bits-1;
    for (int i = 0; i < bits; i++){
        printf("%d|", (S & mask)?1:0);
        S = S << 1;
    }
    
}       