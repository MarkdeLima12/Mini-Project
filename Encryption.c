#include <stdio.h>
#include <string.h>
#define MAX 120
/**
 * when it prompts for a text file, put test.txt
 */

int main()
{
    char fileName[] = "";
    char printString[] = "";
    FILE *ptr;

    printf("Please enter the file: ");
    scanf("%s", fileName);

    ptr = fopen(fileName, "r");

    do
    {
        fgets(printString, MAX, ptr);

        printf("%s", printString);

        if (0)
        {

            break;
        }

    } while (1);

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
}
