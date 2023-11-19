#include <stdio.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int last;
}heap;

void initHeap(heap*);
void displayAll(heap);
void insert(heap*, int);
int deleteMin(heap*);
void swap(heap*, int, int);


int main(){
    heap H;
    initHeap(&H);
    insert(&H, 69);
    insert(&H, 1);
    insert(&H, 5);
    insert(&H, 39);
    insert(&H, 6);
    insert(&H, 15);
    insert(&H, 21);
    insert(&H, 14);
    insert(&H, 18);
    insert(&H, 31);
    displayAll(H);




    return 0;
}

void displayAll(heap H){
    for (int i = 0; i < MAX; i++){
        printf("%d|", H.elem[i]);
    }
    
}

void swap(heap *H, int parent, int child){
    int temp = H->elem[parent];
    H->elem[parent] = H->elem[child];
    H->elem[child] = temp;
}

void initHeap(heap *H){
    H->last = -1;

    for (int i = 0; i < MAX; i++){H->elem[i] = 0;}
}

void insert(heap *H, int N){
    int ParentNdx, ChildNdx;


    if (H->last < MAX - 1){
        H->elem[H->last + 1] = N; 
        H->last++;

        for(ChildNdx = H->last, ParentNdx = ((ChildNdx - 1) / 2);           // variable declaration;
            ParentNdx != ChildNdx;                                          // Constraint;
            ChildNdx = ParentNdx, ParentNdx = ((ChildNdx - 1) / 2)){        // increment;

                if (H->elem[ParentNdx] > H->elem[ChildNdx]){
                    swap(H, ParentNdx, ChildNdx);
                }        
        }

    }
}

int deleteMin(heap *H){
    if(H->last != -1){
        int retval = H->elem[0], leftNdx, rightNdx, swapNdx, pNdx = 0;
        H->elem[0] = H->elem[H->last];


        // for(leftNdx = (0 * 2) + 1, rightNdx = leftNdx + 1;){}

        leftNdx = (pNdx * 2) + 1;
        rightNdx = leftNdx + 1;

        swapNdx = (leftNdx >= rightNdx) ? rightNdx : leftNdx;
        swap(H,pNdx,swapNdx);
        pNdx = swapNdx;


        leftNdx = (pNdx * 2) + 1;
        rightNdx = leftNdx + 1;
        if(leftNdx < MAX)


        return retval;
    }
}