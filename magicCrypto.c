#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX 120

int main(int argC, char *argV[])
{
    char *nametxt = "encrypt_this2.txt";
    char *nameCrp = "encrypt_this2.crp";
    char *switchValue = argV[1];
    int count = 120;
    char *endd;

    char printString[MAX] = "";
    char charats[MAX * 2] = "";
    FILE *ptr, *write, *append;
    int outChar;
    char string[MAX];
    long int hex_converter[MAX];

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

        do
        {
            // DECRYPTION STARTS HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            fgets(string, MAX, ptr);
            printf("String Length: %d", strlen(string));
            hex_converter[0] = 0;
            charats[0] = string[0];
            charats[1] = string[1];
            printf("\nCharats: %s", charats);
            hex_converter[0] = strtol(*charats, &endd, 3);

            printf("Hex_Conv: %ld\n", hex_converter[0]);
            if (endd != '\0')
            {
                hex_converter[0] = strtol(charats, &endd, 3);
            }
            else
            {

                if (hex_converter[0] > 112)
                {
                    hex_converter[0] = (hex_converter[0] + 32) - 144;
                    fprintf(append, "%c", (char)hex_converter[0]);
                }
                else if (hex_converter[0] == 128)
                {
                    hex_converter[0] = 32;
                    fprintf(append, "%c", (char)hex_converter[0]);
                }
                else
                {
                    hex_converter[0] = hex_converter[0] + 16;
                    fprintf(append, "%c", (char)hex_converter[0]);
                }

                if (hex_converter[0] == 'T' && hex_converter[1] == 'T')
                { // this is why i set the tab input to 500... just sets it TT
                    fprintf(append, "%s", '\t');
                }
            }
            count--;
            if (count < 100)
                break;
        } while (count > 0);
        fclose(ptr);
    }
    else
    {
        printf("Unknown switch: %s\n", switchValue);
    }
}
