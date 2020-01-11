#include <stdio.h>


void swap(int *a, int *b) {
   // Change outside the scope with addresses
   int tmp = *a;
   *a = *b;
   *b = tmp;
   return;
}


int main() {
   int a = 55, b = 99;

   printf("a = %d, b = %d\n", a, b);
   swap(&a, &b);  // Now swap using addresses
   printf("a = %d, b = %d\n", a, b);
}
