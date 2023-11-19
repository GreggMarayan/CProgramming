#include <stdio.h>
#define SIZE 8

//CURSOR BASED 
typedef struct{
    char elem;
    int link;
}Nodetype;

typedef struct{
    Nodetype Nodes[SIZE];
    int avail;
}VH;

typedef struct{
    int front;
    int rear;
    VH Heap;
}Queue;


void initQueue(Queue*);
int allocSpace(Queue*);
void deallocSpace(Queue*);
void enQueue(Queue*, char);
void deQueue(Queue*);
int isEmpty(Queue);

//============================================================================================================
int main(){
    Queue Q;
    initQueue(&Q);
    enQueue(&Q, 'A');

    printf("%c",Q.Heap.Nodes[Q.rear].elem);
    return 0;
}
//============================================================================================================
void initQueue(Queue *Q){
    Q->front = -1;
    Q->rear = -1;
    Q->Heap.avail = SIZE-1;

    for (int i = -1; i < SIZE; i++){
        Q->Heap.Nodes[i+1].link = i;
    }
}

int allocSpace(Queue *Q){
    int retval = Q->Heap.avail;
    if (Q->Heap.avail == -1){
        printf("Allocate Space not Successful (returned -1 Value)");
    }else{
        Q->Heap.avail = Q->Heap.Nodes[retval].link;
        Q->Heap.Nodes[retval].link = -1;
    }  
    return retval;
}

void deallocSpace(Queue *Q){

}

void enQueue(Queue *Q, char toAdd){
    Q->rear = allocSpace(Q);
    Q->Heap.Nodes[Q->rear].elem = toAdd;

    if (isEmpty((*Q))){
        Q->front = Q->rear;
    }
}

int isEmpty(Queue Q){
    return (Q.front == -1 && Q.front == -1)?1:0;
}

void deQueue(Queue *Q){
    
}