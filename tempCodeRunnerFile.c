#include <stdio.h>
#include <string.h>
#define MAX 120

int main(void)
{

  char *filename = "test.crp";
  char charats[] = "";
  FILE *ptr = fopen("test.crp", "r"), *write = fopen("test.txt", "w"), *append = fopen("test.txt", "a");

  if (ptr == NULL)
  {
    printf("Error: could not open file %s", filename);
    return 1;
  }

  // reading line by line, max 256 bytes
  char string[MAX];

  while (fgets(string, MAX, ptr))
  {
    printf("%s", string);

    // close the file

    // DECRYPTION STARTS HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    int hex_converter[MAX];
    for (int m = 0; m < strlen(string); m++)
    {
      charats[m] = fgetc(ptr);
      printf("%c", charats[m]);
    }
  }