#include<stdio.h>
void Swap(int size, int arr1[size], int arr2[size])
{
    int i, temp;
    for(i = 0; i < size; i++)
    {
        temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
    }
}
void Sort(int stuNum, int totEntr, int arr[stuNum][totEntr], int ord, int resp)
{
    int i, j;
    for(i = 0; i < stuNum; i++)
        for(j = i; j < stuNum; j++)
        {
            switch(ord)
            {
                case 1: if(arr[i][resp] > arr[j][resp])
                        Swap(totEntr,arr[i], arr[j]);
                        break;
                case -1: if(arr[i][resp] < arr[j][resp])
                        Swap(totEntr ,arr[i], arr[j]);
                        break;
            }
        }
}
int main()
{
    const int stuNum = 5, subNum = 3, totEntr = subNum+2;
    int info[stuNum][totEntr];
    enum {ROLL ,SUB1, SUB2, SUB3, TOTAL};
    enum {ASC = 1, DESC = -1};
    int i,j;
    for(i = 0; i < stuNum; i++)
    {
        printf("Enter Roll of student %d: ", i+1);
        scanf("%d", &info[i][ROLL]);
        info[i][TOTAL]=0;
        for(j = 0; j < subNum; j++)
        {
            printf("\tMarks of subject %d: ", i+1);
            scanf("%d", &info[i][SUB1+j]);
            info[i][TOTAL] += info[i][SUB1+j];
        }
    }
    int copyInfo[stuNum][totEntr];
    for(i = 0; i < stuNum; i++)
        for(j = 0; j < totEntr; j++)
            copyInfo[i][j] = info[i][j];
    printf("\n%80s","(a).");
    printf("\n%15s %15s %15s %15s %15s\n", "ROLL", "SUB 1", "SUB 2", "SUB 3", "TOTAL");
    for(i = 0; i< stuNum; i++)
    {
        for(j = 0; j < totEntr; j++)
            printf("%15d\t", copyInfo[i][j]);
        printf("\n");
    }
    printf("\n\n(b).\n");
    for(i = 0; i < subNum; i++)
    {
        Sort(stuNum, totEntr, copyInfo, DESC, SUB1+i);
        if()
        printf("Highest total marks at subject %d: %d\t\t Roll of the student who obtained it: %d\n", i+1, copyInfo[0][SUB1+i], copyInfo[0][ROLL]);
    }
    printf("\n(c).");
    Sort(stuNum, totEntr, copyInfo, DESC, TOTAL);
    printf("Highest total marks = %d\t\tRoll of the student who obtained it: %d\n", copyInfo[0][TOTAL], copyInfo[0][ROLL]);
}
