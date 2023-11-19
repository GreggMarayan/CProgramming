#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node *link;
}*LIST;

void initList(LIST*);
void insertFirst(LIST*, char);
void displayList(LIST);
void DelElem(LIST*, char);

int main(){

    LIST A;

    initList(&A);
    insertFirst(&A, 'a');
    insertFirst(&A, 'b');
    insertFirst(&A, 'c');
    DelElem(&A, 'b');
    displayList(A);

    return 0;
}

void initList(LIST *L){
    *L = NULL;
}

void insertFirst(LIST *L, char data){
    LIST temp = (LIST)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = *L;
    *L = temp;

    temp = NULL;
    free(temp);
}

void displayList(LIST L){
    while(L != NULL){
        printf("%c", L->data);
        L = L->link;
    }
}

void DelElem(LIST *L, char del){
    if (*L != NULL){
        LIST *trav = L;
        for (; (*trav) != NULL && (*trav)->data != del; (trav) = &(*trav)->link){}
        if (*trav != NULL){
            LIST temp = (*trav);
            (*trav) = temp->link;
            temp->link = NULL;
            free(temp);
        }   
    }
}