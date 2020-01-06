#include <stdio.h>


int main() {
   char string[10] = "Testing";
   int length = 0;
   char res[10];

   int i;
   for(i = 0; string[i] != '\0'; i++);
   length = i;  // Now we have the length of the string
   printf("The length of %s is %d.\n", string, i);
   
   int c = 0;
   for(int j = i; j > -1; j--) {
      // Iterate backwards
      res[c] = string[j-1];
      c ++;
   }
   printf("The reverse of %s is %s.\n", string, res); 
}

