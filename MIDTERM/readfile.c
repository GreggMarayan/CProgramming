#include <stdio.h>
#include <stdlib.h>
#define MAX 20

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
void readFile();

int main()
{
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
            if (limit % 21 == 0)
        {
            printf("\n\n");
            system("pause");
        }
            displayStudent(B); 
            limit++;
        }
       fclose(fp);  
    }
}