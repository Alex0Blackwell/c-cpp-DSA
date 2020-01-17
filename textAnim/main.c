#include <stdio.h>
#include <string.h>
#include <unistd.h>


char getStr(char string[], int index, int len) {
   char res[20];
   strcpy(res, string);
   
   int a;
   for(a = 0; a < index; a++) {
      res[a] = string[a];
   }
   res[a] = string[a] - 32;

   for(int b = a+1; b < len; b++) {
      res[b] = string[b];
   }
   printf("\r%s", res);
}


int main() {
   char usrIn[20]; 
   printf("Enter a sentence: ");
   scanf("%[^\n]", usrIn);

   // Get length
   int len = 0;
   while(usrIn[len] != '\0') {
      len ++; 
   }

   char temp[20];
   for(int i = 0; i < len; i++) {
     getStr(usrIn, i, len);
      sleep(1);  // Wait one second
      fflush(stdout);
   }
   printf("\n");
}

