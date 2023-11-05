#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define MAX 120

int main(char *argC[], char name[])
{
    const char fileNametxt[] = name;
    const char fileNamecrp[] = name;
    char switchCheck = argC[1];
    char printString[MAX] = "";
    FILE *ptr, *write, *append;
    int outChar;

    strncat(fileNametxt, ".txt", 4);
    strncat(fileNamecrp, ".crp", 4);
    switch (switchCheck)
    {
    case ' ':
    case 'e':
    case 'E':
    {
        ptr = fopen(fileNametxt, "r");
        append = fopen(fileNamecrp, "a");
        printf("%s", fileNamecrp);

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
                    outChar = (int)printString[i] - 16;
                    if (outChar < 32)
                    {
                        outChar = (outChar - 32) + 144;
                    }
                    // printf("This is outChar: %d\n", outChar);
                    fprintf(append, "%X", outChar);
                }
            }
            printf("%s\n", printString);
        } while (!feof(ptr));
        remove(fileNametxt);
        break;
    }
    case 'd':
    case 'D':
        break;

    default:
        printf("This is invalid input.");
        return 0;
    }
}
