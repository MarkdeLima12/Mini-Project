#include <stdio.h>
#include <string.h>
#define MAX 120

int main(void) {

  char *filename = "test.txt";
  FILE *fp = fopen(filename, "r");

  if (fp == NULL)
  {
      printf("Error: could not open file %s", filename);
      return 1;
  }

  // reading line by line, max 256 bytes
  char string[MAX];

  while (fgets(string, MAX, fp))
      printf("%s", string);

  // close the file
  fclose(fp);

  //DECRYPTION STARTS HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  int hex_converter[MAX];

  for(int i = 0; i < strlen(string); i++){
    printf("Position %d: %d\n", i, *(string+i));
  }

  for(int i = 0; i < strlen(string)-1; i++){

    hex_converter[i] = strcat(*(string+i),*(string+(i+1))); //stores each character as an integer

    if(hex_converter[i] == 500){
      hex_converter[i] = 9;
    } 

    else if(hex_converter[i] > 112){
      hex_converter[i] = (hex_converter[i] + 32) - 144;
    }

    else if(hex_converter[i] == 128){
      hex_converter[i] = 32; 
    }

    else{
      hex_converter[i] = hex_converter[i] + 16;
    }
  }

  for(int i = 0; i < strlen(string)-1; i++){

    if(hex_converter[i] == 9){ //this is why i set the tab input to 500... just sets it TT
      printf("\t");
    }
    else{
      printf("%c",hex_converter[i]); //converts int to char
    }
  }
   
  return 0;
}
