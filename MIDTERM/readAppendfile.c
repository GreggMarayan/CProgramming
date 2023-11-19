#include <stdio.h>
#include <stdlib.h>
#define MAX 5                   // update the macro to adjust size of input records.
typedef struct
{
    char FN[24]; // firstname
    char MI;     // middle initial
    char LN[16]; // lastname
} Nametype;

typedef struct
{
    Nametype name;
    int ID;
    char course[8]; // BSCS, BSIS, BSIT
    int yrLevel;
} Studtype;

void displayHeader();
void displayStudent(Studtype S);
void writeFile();
void InputData(Studtype *S);
void readFile();
void readAppendfile();











int main()
{
    readAppendfile();


    // writeFile();
    readFile();

    return 0;
}




















void displayHeader()
{
    printf("\n\n");
    printf("%-10s", "ID No.");
    printf("%-16s", "Lastname");
    printf("%-24s", "Firstname");
    printf("%-3s", "MI");
    printf("%-8s", "Course");
    printf("%5s", "Year");
    printf("\n");
    printf("%-10s", "======");
    printf("%-16s", "========");
    printf("%-24s", "=========");
    printf("%-3s", "==");
    printf("%-8s", "======");
    printf("%5s", "====");
}

void displayStudent(Studtype S)
{
    printf("\n");
    printf("%-10d", S.ID);
    printf("%-16s", S.name.LN);
    printf("%-24s", S.name.FN);
    printf("%-3c", S.name.MI);
    printf("%-8s", S.course);
    printf("%5d", S.yrLevel);
}

void readFile()
{
    FILE *fp;
    Studtype B;
    int limit = 1;
    char fileToRead[30];
    printf("Enter file to read (eg. file.txt):\n");
    scanf("%s", &fileToRead);
    if (!(fp = fopen(fileToRead, "rb")))
    {
        printf("Could not open file / File Does not exist");
    }
    else
    {
        displayHeader();
        while (fread(&B, sizeof(Studtype), 1, fp))
        {
            displayStudent(B); 
        }
       fclose(fp);  
    }
}

void writeFile()
{
    FILE *fp;
    Studtype B;
    char fileToWrite[30];
    printf("Enter file to write (eg. file.txt):\n");
    if (!(fp = fopen(fileToWrite, "wb")))
    {
        printf("Could not open file");
    }
    else
    {
        for (int i = 0; i < MAX; i++)
        {
            printf("\n\nEnter record for student %d", i+1);
            InputData(&B);
            fwrite(&B, sizeof(Studtype),1,fp);
        }
       fclose(fp);  
    }
}

void InputData(Studtype *S){
    printf("\nEnter First Name, Middle Initial, Last Name, ID Number, Course and Year:\n\n");
    scanf("%s %s %s %d %s %d", &((*S).name.FN), &((*S).name.MI), &((*S).name.LN), &((*S).ID), &((*S).course), &((*S).yrLevel));
}


void readAppendfile(){
    FILE *fp1, *fp2;
    Studtype temp[MAX];


    char firstFile[50], secondFile[50];
    printf("Enter the name of the file to be read: ");
    scanf("%s", firstFile);
    printf("Enter the name of the file to be added: ");
    scanf("%s", secondFile);


    if(!(fp1 = fopen(firstFile,"rb"))){
        printf("Could not open file to be read / File not found");
    }else{
       fread(temp,sizeof(Studtype), MAX, fp1);
       fclose(fp1);
    }

    if (!(fp2 = fopen(secondFile, "ab"))){
        printf("Could not open file to be read / File not found");
    }else{
        fwrite(temp, sizeof(Studtype), MAX, fp2);
        fclose(fp2);
    }
    
}