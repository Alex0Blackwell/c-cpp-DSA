#include <stdio.h>


int sort(int * ptr,int array[], int len) {
   int res[len];

   int c = 0;
   for(; ptr < array + len; ptr++) {
      for(int ptrNext = ptr+1; ptrNext < array + len; ptrNext++) {
	 printf("ptr: %d ptrNext: %d\n", ptr, ptrNext);
	 if(* ptrNext < * ptr) {
	    array[c] = * ptrNext;
	 }
      }
   c ++;
   }
   printf("The values in the array are:\n");
   for(int i = 0; i < 8; i ++) {
      printf("%d", array[i]);
   }
}


int main() {
   int array1[8] = {3, 4, 3, 7, 5, 8, 9, 0};
   int * ptr1 = array1;

   sort(ptr1, array1, 8);
   /*printf("The values of returned are:\n");
   for(int i = 0; i < 8; i++)
      printf("%d ", returned[i]);
   printf("\n");*/
}
