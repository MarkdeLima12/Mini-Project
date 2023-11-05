/*
  I couldn't understand why the file input code wasn't
  working in replit so I just made it so the user can input 
  a sentence.

  We still gotta work on getting input for multiple lines but 
  after that we are good!!
*/

#include <stdio.h>
#include <string.h>
#define MAX 120

int main(void) {
  
  char string[MAX];
  int int_converter[MAX];
  
  printf("Enter word: ");
  fgets(string, MAX, stdin); //gets string input

 for(int i = 0; i < strlen(string)-1; i++){
   
   int_converter[i] = *(string+i); //stores each character as an integer

  if(int_converter[i] == 9){ //this is my tempoary solution for a <tab> 
    int_converter[i] = 500; 
  }
   
  else if(int_converter[i] < 32){ //checking if the character has an ASCII value below 32
     int_converter[i] = (int_converter[i] - 32) + 144;
   }

  else if(int_converter[i] == 32){ //case of space
    int_converter[i] = 128;
  }

  else{
    int_converter[i] = int_converter[i] - 16; //normal character encryption
  }
   
 }

  for(int i = 0; i < strlen(string)-1; i++){

    if(int_converter[i] == 500){ //this is why i set the tab input to 500... just sets it TT
      printf("Value %d: TT", i);
    }
    else{
      printf("Value %d: %X\n", i, int_converter[i]); //converts int to hex
    }
  }
  
  
  return 0;
}
