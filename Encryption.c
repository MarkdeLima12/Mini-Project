#include <stdio.h>
#include <string.h>
#define MAX 120
/**
 * when it prompts for a text file, put test.txt
 */

int main()
{
    char fileName[] = "test.txt";
    char printString[MAX] = "";
    FILE *ptr, *write;
    char hexEncrypt[MAX * 2] = "";
    int outChar;

    // printf("Please enter the file: ");
    // scanf("%s", fileName);

    ptr = fopen("test.txt", "r");
    // write = fopen("test.txt", "w");

    do
    {
        fgets(printString, MAX, ptr);
        printf("%s\n", printString);
        printf("%d\n", strlen(printString));
        for (int i = 0; (strlen(printString) - 1) > i; i++)
        {
            if (printString[i] == '\n')
            {
                printf("We have to put code here for a return carage.\n");
            }
            else if (printString[i] == '\t')
            {
                printf("We have to put here for a tab.\n");
            }
            else
            {
                outChar = (int)printString[i] - 16;
                if (outChar < 32)
                {
                    outChar = (outChar - 32) + 144;
                }
                printf("This is outChar: %d\n", outChar);
            }
            strcat(hexEncrypt, (char)outChar);
        }
        printf("This is hexEncrypt: %s\n", hexEncrypt);
        printf("%s\n", printString);
    } while (!feof(ptr));

    // writes to the file
    // fprintf(write, "Does this work??");
    // printf("%s", printString);

    /**
     * ***** Has two command line switches *****
     *
     *
     * ***** Uses text file and encrypts the characters by converting *****
     * ***** them to an integer (ASCII), subtracting 16, then converting to hex *****
     *
     * ***** Change file type to .crp. Base file stays the same *****
     *
     * ***** Changes file type to .txt for decryption. Only one can exist *****
     *
     *  will need a loop. also will need to canibalize the code from Lab 5pt3
     *
     */

    // hello mark
}
