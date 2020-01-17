#include <stdio.h>
#include <string.h>
#include <unistd.h>


char bruteAnim(char string[]) {
   char res[20];  // Strings of 20 in length
   strcpy(res, string);

   // Get string length
   int len = 0;
   while(res[len] != '\0') {
      len ++; 
   }

   char temp[20];
   for(int i = 0; i < len; i++) {
      int a;
      for(a = 0; a < i; a++) {
	 // First part of string normal
	 res[a] = string[a];
      }
      res[a] = string[a] - 32;  // Lower case at [i] change to upper

      for(int b = a+1; b < len; b++) {
	 // Second part of string normal
	 res[b] = string[b];
      }
      printf("\r%s", res);
   
      sleep(1);  // Wait one second
      fflush(stdout);
   }
   printf("\n");
   
}


int main() {
   char usrIn[20]; 
   printf("Enter a sentence: ");
   scanf("%[^\n]", usrIn);
   bruteAnim(usrIn);
}

