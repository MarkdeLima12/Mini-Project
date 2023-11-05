#include <stdio.h>
#include <string.h>
#define MAX 120

int main()
{
    char fileName[] = "test.txt";
    char printString[MAX] = "";
    FILE *ptr, *write, *append;
    char hexEncrypt[MAX * 2] = "";
    int outChar;

    ptr = fopen("test.txt", "r+");
    append = fopen("test.crp", "a");
    write = fopen("test.crp", "w");

    do
    {
        fgets(printString, MAX, ptr);
        printf("%s\n", printString);
        printf("%d\n", strlen(printString));
        for (int i = 0; strlen(printString) > i; i++)
        {
            if (printString[i] == '\n')
            {
                fprintf(append, "%c", '\n');
            }
            else if (printString[i] == '\t')
            {
                fprintf(append, "%s", "TT");
            }
            else
            {
                printf("%c, %d\n", printString[i], printString[i]);
                outChar = (int)printString[i] - 16;
                if (outChar < 32)
                {
                    outChar = (outChar - 32) + 144;
                }
                // printf("This is outChar: %d\n", outChar);
                fprintf(append, "%X", outChar);
            }
        }
        printf("This is hexEncrypt: %s\n", hexEncrypt);
        printf("%s\n", printString);
    } while (!feof(ptr));
}
