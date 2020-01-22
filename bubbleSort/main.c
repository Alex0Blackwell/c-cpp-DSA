#include <stdio.h>


int sort(int *ptr,int array[], int len) {
   int res[len];

   int c = 0;
   for(; ptr < array + len; ptr++) {
      for(int ptrNext = ptr+1; ptrNext < len; ptrNext++) {
	 if(*ptrNext < *ptr) {
	    array[c] = *ptrNext;
	 }
      }
   c ++;
   }
}


int main() {
   int array1[8] = {3, 4, 3, 7, 5, 8, 9, 0};
   int *ptr1 = array1;

   sort(ptr1, array, 8);
}
