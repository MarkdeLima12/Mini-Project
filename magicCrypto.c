#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define MAX 120

int main(int argC, char *argV[])
{
    char *nametxt = "encrypt_this2.txt";
    char *nameCrp = "encrypt_this2.crp";
    char *switchValue = argV[1];

    char printString[MAX] = "";
    char charats[MAX * 2] = "";
    FILE *ptr, *write, *append;
    int outChar;

    printf("%s", switchValue);
    if (strcmp(switchValue, "-E") == 0)
    {
        ptr = fopen(nametxt, "r");
        append = fopen(nameCrp, "a");
        printf("%s", nametxt);

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
    }
    else if (strcmp(switchValue, "-D") == 0)
    {
        ptr = fopen(nameCrp, "r");
        append = fopen(nametxt, "a");
        if (ptr == NULL)
        {
            printf("Error: could not open file %s", nameCrp);
            return 1;
        }

        // reading line by line, max 256 characters
        char string[MAX];

        do
        {
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
        } while (!feof(nameCrp));
        fclose(ptr);
    }
    else
    {
        printf("Unknown switch: %s\n", switchValue);
    }
}
