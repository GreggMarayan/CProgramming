#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char Name[50];
    char Course[10];
    int id;
}studRec;

typedef struct node{
    studRec Stud;
    struct node *link;
}*LIST;

void init(LIST*);
void segregate(LIST*, LIST*, studRec Arr[]);
void insertF(LIST*, studRec);
void display(LIST);

int main(){

    //Array of Students
    studRec studs[4] = {{"Gregg","BSIT",1},{"Mark","BSCS",2},{"Hiro","BSIT",3},{"Stella","BSCS",4}};

    LIST CS, IT;
    init(&CS);
    init(&IT);

    segregate(&IT, &CS, studs);
    display(IT);
    display(CS);

    return 0;
}

void init(LIST *L){
    *L = NULL;
}

void segregate(LIST *IT, LIST *CS, studRec Arr[]){
    int ndx;
    for(ndx = 3; ndx >= 0; ndx--){
        (strcmp(Arr[ndx].Course, "BSCS") == 0) ? insertF(CS, Arr[ndx]) : insertF(IT, Arr[ndx]);
    }  
}

void display(LIST L){
    for(LIST trav = L; trav != NULL; trav = trav->link){
        printf("%s->", trav->Stud.Name);
    }
    printf("NULL\n");
}

void insertF(LIST *L, studRec data){
    LIST temp = NULL;
    temp = (LIST)malloc(sizeof(struct node));
    temp->Stud = data;
    temp->link = *L;
    *L = temp;
    temp = NULL;
    free(temp);
}