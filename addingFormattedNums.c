#include <stdio.h>


int main(void) {
   /* Print two different rows,
   one increasing, one decreasing */

   int highNum, max, scanCode;
   int lowNum = 0;

   printf("Enter the number you want to go up to: ");
   scanCode = scanf("%d", &max);
   highNum = max;

   if(scanCode = 1) {
      // Valid input
      while(lowNum < max) {
	 printf("%3d + %3d = %d\n", lowNum, highNum, max);
	 lowNum += 10;
	 highNum -= 10;
      } 
   }
}
