#include <stdio.h>
#define SIZE 7

//CURSOR BASED 
typedef struct{
    char elem;
    int link;
}Nodetype;

typedef struct{
    Nodetype Nodes[SIZE];
    int avail;
}VirtualHeap;

typedef int List;

//CURSOR BASED OPERATORS
void initVH(VirtualHeap*);
int allocSpace(List, VirtualHeap *);
void insert(List, VirtualHeap*, char);
//============================================================================================================
int main(){
    List L = -1;
    VirtualHeap VH;
    initVH(&VH);
    L = allocSpace(L, &VH);
    insert(L, &VH, 'A');
    printf("%c", VH.Nodes[L].elem);

    return 0;
}
//============================================================================================================
void initVH(VirtualHeap *A){
    for (int i = -1; i < SIZE; i++){
        (*A).Nodes[i+1].link = i;
    }
    (*A).avail = SIZE-1;
}

int allocSpace(List L, VirtualHeap *A){
    int retval = (*A).avail;
    if ((*A).avail == -1){
        printf("Allocate Space not successful (returned -1 value)");
    }else{
        (*A).avail = (*A).Nodes[retval].link;
        (*A).Nodes[retval].link = L;
    }
    return retval;
}

void insert(List L,VirtualHeap *A, char toAdd){
    (*A).Nodes[L].elem = toAdd;
}