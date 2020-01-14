#include <stdio.h>


int main() {
   int array[5] = {10, 9, 8, 7, 6};
   int c = 0;

   for(int * i = &array[0]; i < &array[5]; i++) { 
      printf("The value at address %d and index %d is %d\n", i, c, *i);
      c ++;
   }
      printf("Final value: %d\n", &array[5]);
}
