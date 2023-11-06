#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define MAX 120

int main(char argC[], char name[])
{
    const char fileNametxt[] = name;
    const char fileNameCrp[] = name;
    char switchCheck = argC[1];
    char printString[MAX] = "";
    char charats[MAX * 2] = "";
    FILE *ptr, *write, *append;
    int outChar;

    strncat(fileNametxt, ".txt", 5);
    strncat(fileNameCrp, ".crp", 5);
    switch (switchCheck)
    {
    case ' ':
    case 'e':
    case 'E':
    {
        ptr = fopen(fileNametxt, "r");
        append = fopen(fileNameCrp, "a");
        printf("%s", fileNameCrp);

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
    {
        ptr = fopen(fileNameCrp, "r");
        append = fopen(fileNametxt, "a");
        if (ptr == NULL)
        {
            printf("Error: could not open file %s", fileNameCrp);
            return 1;
        }

        // reading line by line, max 256 characters
        char string[MAX];

        while (fgets(string, MAX, ptr))
        {
            printf("%s\n", string);

            // close the file

            // DECRYPTION STARTS HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            int hex_converter[MAX];

            for (int i = 0; i < strlen(string); i + 2)
            {
                charats[0] = string[i];
                charats[1] = string[i + 1];
                printf("%s", charats);
                hex_converter[i] = (int)charats;
                printf("\nPosition %d: %d\n", i, *(string + i));

                printf("%d", hex_converter[i]);
                if (hex_converter[i] > 112)
                {
                    hex_converter[i] = (hex_converter[i] + 32) - 144;
                    fprintf(append, "%c", (char)hex_converter[i]);
                }
                else if (hex_converter[i] == 128)
                {
                    hex_converter[i] = 32;
                    fprintf(append, "%c", (char)hex_converter[i]);
                }
                else
                {
                    hex_converter[i] = hex_converter[i] + 16;
                    fprintf(append, "%c", (char)hex_converter[i]);
                }

                if (hex_converter[i] == 'T' && hex_converter[i + 1] == 'T')
                { // this is why i set the tab input to 500... just sets it TT
                    fprintf(append, "%s", '\t');
                }
            }
        }
        fclose(ptr);
        break;
    }
    default:
        printf("This is invalid input.");
        return 0;
    }
}
