#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}*SET;

void initList(SET*);
void insertFirst(SET*, int);
void displayList(SET);
void DelElem(SET*, int);
SET setUnion(SET, SET);
void insertLast(SET*, int);


int main(){

    SET A;
    initList(&A);
    insertFirst(&A, 9);
    insertFirst(&A, 6);
    insertFirst(&A, 5);
    insertFirst(&A, 1);



    SET B;
    initList(&B);
    insertFirst(&B, 9);
    insertFirst(&B, 7);
    insertFirst(&B, 3);



    SET C;
    initList(&C);
    C = setUnion(A,B);
    displayList(C);

    return 0;
}

void initList(SET *L){
    *L = NULL;
}

void insertFirst(SET *L, int data){
    SET temp = (SET)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = *L;
    *L = temp;

    temp = NULL;
    free(temp);
}

void displayList(SET L){
    while(L != NULL){
        printf("%d", L->data);
        L = L->link;
    }
}
 
void DelElem(SET *L, int del){
    if (*L != NULL){
        SET *trav = L;
        for (; (*trav) != NULL && (*trav)->data != del; (trav) = &(*trav)->link){}
        if (*trav != NULL){
            SET temp = (*trav);
            (*trav) = temp->link;
            temp->link = NULL;
            free(temp);
        }   
    }
}

void insertLast(SET *L, int data){
    SET *trav = L;
    for(;(*trav)->link != NULL; trav = &(*trav)->link){}
    (*trav)->link = (SET)malloc(sizeof(struct node));
    trav = &(*trav)->link;
    (*trav)->data=data;
    (*trav)->link = NULL;
    trav = NULL;
    free(trav);
}




SET setUnion(SET A, SET B){
    SET C;
    int tempData;
    initList(&C);

    while (A != NULL && B != NULL){
        tempData = (A->data <= B->data) ? A->data : B->data;
        (tempData == A->data) ? (A = A->link): (B = B->link);
        (C != NULL) ? insertLast(&C,tempData) : insertFirst(&C,tempData);
    }

    if(A == NULL){
        A = B;
    }

    while (A != NULL){
        insertLast(&C, A->data);
        A = A->link;
    }
    

    return C;
}