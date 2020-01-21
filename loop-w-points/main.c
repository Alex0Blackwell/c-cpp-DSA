#include <stdio.h>

int main() {
   int array1[5] = {1, 2, 3, 4, 5};
   int *pointArr1= array1;
	           
   for(; pointArr1 < array1 + 5; pointArr1 ++) {
      printf("Value: %d\n", *pointArr1);
   }

   printf("\n");

   char array2[5] = {'a', 'b', 'c', 'd', 'e'};
   char *pointArr2 = array2;

   for(; pointArr2 < array2 + 5; pointArr2 ++) {
      printf("Value: %c\n", *pointArr2);
   }

   printf("\n");

   char array3[5] = "Hello";
   char *pointArr3 = array3;

   for(; pointArr3 < array3 + 5; pointArr3 ++) {
      printf("Value: %c\n", *pointArr3);
   }
}

