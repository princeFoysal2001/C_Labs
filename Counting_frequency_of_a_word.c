#include<stdio.h>
#include<ctype.h>
int main()
{
    printf("Enter the longer string: ");
    char mainStr[128];
    gets(mainStr);
    printf("Enter the string to be found: ");
    char inpWord[20];
    gets(inpWord);
    int i = 0,j = 0, freqCount = 0;
    char tempStr[20];
    while(mainStr[i] != '\0')
    {
        while(!isalpha(mainStr[i]) && mainStr[i] != '\0') {i++; continue;}
        while(isalpha(mainStr[i]))
        {
            tempStr[j] = mainStr[i];
            i++; j++;
        }
        tempStr[j] = '\0';
        j = 0;
        printf("%s\n", tempStr);
        if(mainStr[i] == '\0') break;
        if(!strcmpi(tempStr, inpWord))
            freqCount++;
    }
    printf("Frequency of the word: %d\n", freqCount);
}
