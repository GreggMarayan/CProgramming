#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char elem;
    struct node *link;
}*LIST;

typedef struct{
    LIST front;
    LIST rear;
}Queue;

void initQueue(Queue*);
void enQueue(Queue*, char);
int isEmpty(Queue);
void deQueue(Queue*);
char front(Queue*);

int main(){
    Queue Q;
    initQueue(&Q);
    enQueue(&Q, 'A');
    enQueue(&Q, 'B');
    enQueue(&Q, 'C');
    deQueue(&Q);

    
    for (LIST trav = Q.front; trav != NULL; trav = trav->link)
    {
        printf("%c", trav->elem);
    } 
    
    

    return 0;
}

void initQueue(Queue *Q){
    (*Q).front = NULL;
    (*Q).rear = NULL;
}

int isEmpty(Queue Q){
    int retval = 0;
    if (Q.front == NULL && Q.rear == NULL){
        retval = 1;
    }
    return retval;
}

void enQueue(Queue *Q, char A){
    LIST temp = (LIST)malloc(sizeof(struct node));
    temp->elem = A;
    temp->link = NULL;

    if (!isEmpty(*Q)){
        Q->rear->link = temp;
        Q->rear = Q->rear->link;
    }else{
    Q->front = temp;
    Q->rear = temp;
    }

    temp = NULL;
    free(temp);
}

void deQueue(Queue *Q){
    if (!isEmpty(*Q)){
        if (Q->front->link == NULL){
            LIST temp = (*Q).front;
            initQueue(Q);
            free(temp);
        }
    
        LIST temp = (*Q).front;
        (*Q).front = temp->link;
        free(temp);
    } 
}

char front(Queue *Q){
    if (!isEmpty(*Q))
    {
        return Q->front->elem;
    }
}