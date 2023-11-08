#include <stdio.h>
#include <string.h>
#define MAX 120
int main()
{
    char fileName[] = "encrypt_this.txt";
    char printString[MAX] = "";
    FILE *ptr, *write, *append;
    char hexEncrypt[MAX * 2] = "";
    int charats;

    // printf("Please enter the file: ");
    // scanf("%s", fileName);

    ptr = fopen("encrypt_this.txt", "r");
    append = fopen("encrypt_this.txt", "a");
    append = fopen("encrypt_this.crp", "a");

    do
    {
        fgets(printString, MAX, ptr);
        printf("%s\n", printString);
        printf("%d\n", strlen(printString));
        for (int i = 0; strlen(printString) > i; i++)
            for (int i = 0; strlen(printString) > i; i++)
            {
                if (printString[i] == '\n')
                {
                    fprintf(append, "%s", "\n");
                }
                else if (printString[i] == '\t')
                {
                    fprintf(append, "%s", "TT");
                }
                else
                {
                    printf("%c, %d\n", printString[i], printString[i]);
                    charats = (int)printString[i] - 16;
                    if (charats < 32)
                    {
                        charats = (charats - 32) + 144;
                    }
                    fprintf(append, "%X", charats);
                }
            }
    } while (!feof(ptr));

    // writes to the file
    // write = fopen("test.txt", "w");
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