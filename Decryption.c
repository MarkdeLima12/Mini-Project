#include <stdio.h>
#include <string.h>
#define MAX 120

int main(void)
{

  char *filenamecrp[] = "test.crp";
  char charats[MAX * 2] = "";
  FILE *ptr = fopen("test.crp", "r"), *write = fopen("test.txt", "w"), *append = fopen("test.txt", "a");

  if (ptr == NULL)
  {
    printf("Error: could not open file %s", filenamecrp);
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
  return 0;
}
