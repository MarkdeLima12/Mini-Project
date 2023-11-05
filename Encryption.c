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
    char lineChar[] = "";
    char hexEncrypt[] = "";
    int encryptCalc;

    // printf("Please enter the file: ");
    // scanf("%s", fileName);

    ptr = fopen("test.txt", "r");
    // write = fopen("test.txt", "w");

    do
    {
        fgets(printString, MAX, ptr);
        printf("%s\n", printString);
        printf("%d", strlen(printString));
        for (int i = 0; (strlen(printString) - 1) > i; i++)
        {
            lineChar[i] = printString[i];
            encryptCalc = (int)printString[i];
        }

        printf("%s", lineChar);
    } while (!feof(ptr));

    // writes to the file
    // fprintf(write, "Does this work??");
    // printf("%s", printString);

    /**
     * ***** Has two command line switches *****
     *
     * ***** takes a file (type .txt) and reads the text *****
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
